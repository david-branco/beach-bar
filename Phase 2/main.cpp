#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primitivas.h"
#include "lamps.h"
#include "glass.h"
#include "predio.h"
#include "mesas.h"
#include "cadeiras.h"

int max_options = 27;
int option = 0;

bool wire = true;

// Camera
float camX = 0.0f, camY = 0.0f, camZ = 8.0f;
float camAlpha = 0.0f, camBeta = 0.0f;
float camRaio = 80.0f;
float left = 0.0, front = 0.0;

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

void glutPrint(float x, float y, const char* text, float r, float g, float b) { 
  if(!text || !strlen(text)) return; 
  bool blending = false; 
  if(glIsEnabled(GL_BLEND)) blending = true; 
  glEnable(GL_BLEND); 
  glColor3f(r,g,b); 
  glRasterPos2f(x,y); 
  while (*text) { 
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text); 
    text++; 
  } 
  if(!blending) glDisable(GL_BLEND); 
}

void drawDemo(){
  switch(option){
    default: break;
    case 0:
    glutPrint(0,25.0,"1 - Copo Agua" ,1.0,1.0,1.0);
    drawGlassWater(20, 10, 10, 0.5 ,10, 1, 1, 1);
    break;

    case 1:
    glutPrint(0,25.0,"2 - Copo Alto" ,1.0,1.0,1.0);
    drawTallGlass(30, 25, 5, 1, 1, 1);
    break;

    case 2:
    glutPrint(0,25.0,"3 - Copo de Cocktail com Azeitona" ,1.0,1.0,1.0);
    drawMartiniWithStick();
    break;

    case 3:
    glutPrint(0,25.0,"4 - Copo de Cocktail sem Azeitona" ,1.0,1.0,1.0);
    drawMartini(30, 1, 10, 15, 7, 0.5, 10, 0.870588235, 0.870588235, 0.870588235);
    break;

    case 4:
    glutPrint(0,25.0,"5 - Caneca" ,1.0,1.0,1.0);
    drawCaneca(30, 2, 5, 8, 17, 0, 1, 0);
    break;

    case 5:
    glutPrint(0,25.0,"6 - Copo de Cerveja" ,1.0,1.0,1.0);
    drawCerveja(30, 5, 7, 5, 30, 8, 1, 1, 0);
    break;

    case 6:
    glutPrint(0,25.0,"7 - Candeeiro Tecto" ,1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(0, 15, 0);
    drawCandeeiroTeto(30, 15, 3, 10, 15, 1.0, 1.0, 0.0);
    glPopMatrix();
    break;

    case 7:
    glutPrint(0,25.0,"8 - Candeeiro Tecto Cilindro" ,1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(0, 15, 0);
    drawCandeeiroTetoCilindro(30, 20, 1, 5, 5, 10, 1, 1, 1);
    glPopMatrix();
    break;

    case 8:
    glutPrint(0,25.0,"9 - Candeeiro de Chao" ,1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(0, -25, 0);
    drawCandeeiroChao(30, 1, 5, 30, 5, 15, 1, 1, 0);
    glPopMatrix();
    break;

    case 9:
    glutPrint(0,25.0,"10 - Focos" ,1.0,1.0,1.0);
    drawLuzChao(10, 1, 1, 1);
    break;

    case 10:
    glutPrint(0,25.0,"11 - Candeeiro de Mesa" ,1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(0, -15, 0);
    drawCandeeiroChao(30, 1, 5, 15, 15, 15, 1, 0, 0);
    glPopMatrix();
    break;

    case 11:
    glutPrint(0,25.0,"12 - Mesa de Cafe" ,1.0,1.0,1.0);
    drawMesaCafe(16.0, 4.0, 4, 0.8 ,14, 0.5f, 0.25f, 0.0f);
    break;

    case 12:
    glutPrint(0,25.0,"13 - Mesa de Vidro" ,1.0,1.0,1.0);
    drawMesaVidro(28.0, 20.0, 2, 16, 4, 14.0, 0.4, 0.5f, 0.25f, 0.0f, 0.37f, 0.62f, 0.62f);
    break;

    case 13:
    glutPrint(0,25.0,"14 - Mesa de Vidro R" ,1.0,1.0,1.0);
    drawMesaVidroR(14.0, 2.0, 16.0, 4.0, 12.0, 0.4, 0.5f, 0.25f, 0.0f, 0.37f, 0.62f, 0.62f);
    break;

    case 14:
    glutPrint(0,25.0,"15 - Mesa de Esplanada Pequena" ,1.0,1.0,1.0);
    drawEsplanadaPequena(10,16, 1.0, 0.0, 0.0);
    break;

    case 15:
    glutPrint(0,25.0,"16 - Mesa Esplanada" ,1.0,1.0,1.0);
    drawMesaEsplanada(10, 10, 0.5, 8, 0.1, 1, 6, 0.5, 0.8, 0, 0.5f, 0.25f, 0.0, 1.0f, 0.0f, 0.0f);
    break;

    case 16:
    glutPrint(0,25.0,"17 - Cadeira Simples" ,1.0,1.0,1.0);
    drawCadeiraSimples(12.0, 0.8, 8.0, 1, 10, 1, 0.4, 8.0, 11, 0.8, 0.5f, 0.25f, 0.0f);
    break;

    case 17:
    glutPrint(0,15.0,"18 - Cadeira Simples Tabuas" ,1.0,1.0,1.0);
    drawCadeiraSimplesTabuas(6.0, 0.4, 5.0, 0.5, 5.0, 4.0, 3, 0.5, 0.5f, 0.25f, 0.0f);
    break;

    case 18:
    glutPrint(0,15.0,"19 - Banco Pernas Rectas" ,1.0,1.0,1.0);
    drawBanco(4.0, 2.0, 1.0f, 0.0f, 0.0f, 12.0, 1, 1, 0.1, 0.3, 0.5f, 0.25f, 0.0f);
    break;

    case 19:
    glutPrint(0,15.0,"20 - Banco Pernas Inclinadas" ,1.0,1.0,1.0);
    drawBancoI(4.0, 2.0, 1.0f, 0.0f, 0.0f, 12.0, 1, 6, 1, 0.2, 0.6, 0.5f, 0.25f, 0.0f);
    break;

    case 20:
    glutPrint(0,15.0,"21 - Banco Quadrado" ,1.0,1.0,1.0);
    drawBancoQ(12.0, 6.0, 2.0, 1.0f, 0.0f, 0.0f, 12.0, 1, 1, 0.2, 0.6, 0.5f, 0.25f, 0.0f);
    break;

    case 21:
    glutPrint(0,15.0,"22 - Banco Quadrado Pernas Inclinadas" ,1.0,1.0,1.0);
    drawBancoQI(6.0, 6.0, 2.0, 1.0f, 0.0f, 0.0f, 12.0, 1, 6, 1, 0.2, 6, 0.5f, 0.25f, 0.0f);
    break;

    case 22:
    glutPrint(0,15.0,"23 - Banco Redondo" ,1.0,1.0,1.0);
    drawBancoRedondo(4.2, 2.0, 4.0, 8.0, 1.0f, 0.0f, 0.0f, 0.5f, 0.25f, 0.0f);  
    break;

    case 23:
    glutPrint(0,15.0,"24 - Cadeira Decor" ,1.0,1.0,1.0);
    drawCadeiraDecor(8.0, 8.0, 0.6, 10, 0.2, 1.2, 6.0, 1, 1, 2, 0, 8.0, 8.0, 1, 6, 0.5f, 0.25f, 0.0f, 1.0f, 0.0f, 0.0f);
    break;

    case 24:
    glutPrint(0,15.0,"25 - Cadeira Decor Cruzado" ,1.0,1.0,1.0);
    drawCadeiraDecorX(8.0, 8.0, 0.6, 10, 0.2, 1.2, 10.0, 0.6, 1, 2, 0, 8.0, 8.0, 1, 6, 0.5f, 0.25f, 0.0f, 1.0f, 0.0f, 0.0f);
    break;

    case 25:
    glutPrint(0,15.0,"26 - Cadeira Decor Inclinada" ,1.0,1.0,1.0);
    drawCadeiraDecorInc(10.0, 6.0, 0.3, 6, 0.1, 0.8, 3.0, 0.5, 0.5, 1.0, 0.3, 6.0, 6.0, 0.5, 4, 25, 0.5f, 0.25f, 0.0f, 1.0f, 0.0f, 0.0f);
    break;

    case 26:
    glutPrint(0,15.0,"27 - Cadeira Fashion" ,1.0,1.0,1.0);
    drawCadeiraFashion(8.0, 10.0, 1, 10.0, 1.6, 8.0, 0.6, 3, 0.66f, 0.66f, 0.66f, 1.0f, 0.0f, 0.0f);
    break;

    case 27:
    drawBar();
    break;
  }
}

void renderScene(void) {
  // clear buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the camera
  glLoadIdentity();
  gluLookAt(camX,camY,camZ, 
            left,front,0.0,
            0.0f,1.0f,0.0f);
  if(wire){
    glPolygonMode(GL_FRONT,GL_LINE);
    glPolygonMode(GL_BACK, GL_POINT);
  } else {
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_BACK, GL_POINT);
  }

  drawDemo();
  // drawBar();

  glutSwapBuffers();
}

void tecladoListener(unsigned char tecla, int x, int y){
  switch(tecla){
    case 'a': camAlpha += 0.1f ;break;
    case 'd': camAlpha -= 0.1f;break;
    case 'w': camBeta += 0.1f;break;
    case 's': camBeta -= 0.1f;break;
    case 'e': if(camRaio > 1.0f) camRaio -= 3.0f;break;
    case 'q': camRaio += 3.0f;break;
    case 'z': if(option == 0) option = max_options; else option--; break;
    case 'x': if(option == max_options) option = 0; else option++; break;
  }
  updateCam();
  glutPostRedisplay();
}

void specialListener(int tecla, int x, int y){
  switch(tecla){
    case GLUT_KEY_HOME: if(wire) wire=false; else wire=true; break;
    case GLUT_KEY_LEFT: left++;break;
    case GLUT_KEY_RIGHT: left--;break;
    case GLUT_KEY_UP: front++;break;
    case GLUT_KEY_DOWN: front--;break;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800,800);
  glutCreateWindow("TP 2");

  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutKeyboardFunc(tecladoListener);
  glutSpecialFunc(specialListener);

  glEnable(GL_DEPTH_TEST);
  updateCam();

  glutMainLoop();

  return 1;
}

