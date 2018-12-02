#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"


// Camera
float camX = 0.0f, camY = 0.0f, camZ = 8.0f;
float camAlpha = 0.0f, camBeta = 0.0f;
float camRaio = 10.0f;

int option = 0;

void updateCam(){
    camX = camRaio * cos(camBeta) * sin(camAlpha);
    camY = camRaio * sin(camBeta);
    camZ = camRaio * cos(camBeta) * cos(camAlpha);
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window with zero width).
    if(h == 0)
        h = 1;

    // compute window's aspect ratio 
    float ratio = w * 1.0 / h;

    // Set the projection matrix as current
    glMatrixMode(GL_PROJECTION);
    // Load Identity Matrix
    glLoadIdentity();
    
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set perspective
    gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

    // return to the model view matrix mode
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set the camera
    glLoadIdentity();
    gluLookAt(camX,camY,camZ, 
              0.0,0.0,0.0,
              0.0f,1.0f,0.0f);

    glPolygonMode(GL_FRONT,GL_LINE);

    switch(option){
        case 1: drawPlano(1.0f, 2.0f, 1.0f, 0.0f, 1.0f);break;
        case 2: drawParalelo(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f);break;
        case 3: drawCilindro(10 , 5.0f ,1 ,1.0f, 0.0f, 1.0f);break;
        case 4: drawEsfera(3.0f, 20, 20, 0.5f, 0.0f, 1.4f);break;
    }
    glutSwapBuffers();
}


void tecladoListener(unsigned char tecla, int x, int y){
    switch(tecla){
        case 'a': camAlpha += 0.1f ;break;
        case 'd': camAlpha -= 0.1f;break;
        case 'w': camBeta += 0.1f;break;
        case 's': camBeta -= 0.1f;break;
        case 'e': if(camRaio > 1.0f) camRaio -= 0.5f;break;
        case 'q': camRaio++;break;
    }
    updateCam();
}

void menu(int id_op){  
    switch(id_op){
        case 1: option = 1;break;
        case 2: option = 2;break;
        case 3: option = 3;break;
        case 4: option = 4;break;
    }

}

int main(int argc, char **argv) {
    // inicialização
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("Aula2");


    // registo de funções 
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(tecladoListener);

    glutCreateMenu(menu);
    glutAddMenuEntry("Plano", 1);
    glutAddMenuEntry("Paralelo", 2);
    glutAddMenuEntry("Cilindro", 3);
    glutAddMenuEntry("Esfera", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    // alguns settings para OpenGL
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE); // Śó desenha o que está virado para o ecrã o resto ignora.

    // entrar no ciclo do GLUT
    updateCam();
    glutMainLoop();
    
    return 1;
}

