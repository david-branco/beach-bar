#include <GL/glew.h>
#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "objects.h"

int max_options = 11;
int option = 0;

bool wire = false;

// Camera
float camX = 0.0f, camY = 0.0f, camZ = 8.0f;
float camAlpha = 0.0f, camBeta = 0.0f;
float camRaio = 80.0f;
float left = 0.0, front = 0.0;

// Texture
Texture metal, wood;

// VBOs
Primitiva plano, paralelo, cilindro, cone, torus, esfera, border;

// Objects
Object copoMartini, mesa, cadeira, bar, candeeiro;

bool first = true;

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
    glutPrint(0,25.0,"1 - Plano" ,1.0,1.0,1.0);
    drawVBO(plano);
    break;

    case 1:
    glutPrint(0,25.0,"2 - Paralelo" ,1.0,1.0,1.0);
    drawVBO(paralelo);
    break;

    case 2:
    glutPrint(0,25.0,"3 - Cilindro" ,1.0,1.0,1.0);
    drawVBO(cilindro);
    break;

    case 3:
    glutPrint(0,25.0,"4 - Esfera" ,1.0,1.0,1.0);
    drawVBO(esfera);
    break;

    case 4:
    glutPrint(0,25.0,"5 - Cone" ,1.0,1.0,1.0);
    drawVBO(cone);
    break;

    case 5:
    glutPrint(0,25.0,"6 - Torus" ,1.0,1.0,1.0);
    drawVBO(torus);
    break;

    case 6:
    glutPrint(0,25.0,"8 - Copo Martini" ,1.0,1.0,1.0);
    drawMartini(copoMartini,15,10,10);
    break;

    case 7:
    glutPrint(0,25.0,"9 - Mesa" ,1.0,1.0,1.0);
    drawMesaVidro(mesa, 30.0, 20.0, 2.0, 16.0, 4.0, 14.0, 0.4);
    break;

    case 8:
    glutPrint(0,25.0,"10 - Cadeira" ,1.0,1.0,1.0);
    drawCadeiraFashion(cadeira, 20.0, 20.0, 2.0, 20.0, 2.5, 20.0, 1.5, 6.0);
    break;

    case 9:
    glutPrint(0,25.0,"11 - Candeeiro" ,1.0,1.0,1.0);
    drawCandeeiroTeto(candeeiro, 30, 15, 15, 3, 10, 15);
    break;

    case 10:
    glutPrint(0,25.0,"12 - Bar" ,1.0,1.0,1.0);
    drawBar(bar);
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
    glPolygonMode(GL_BACK, GL_LINE);
  }

  GLfloat amb[3] = {0.2, 0.2, 0.2};
  GLfloat diff[3] = {1.0, 1.0, 1.0};
  GLfloat pos[4] = {0.0, 600.0 ,600.0, 0.0};
  // posição da luz
  glLightfv(GL_LIGHT0, GL_POSITION, pos);
  // cores da luz
  glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
  
  drawDemo();

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

void initFunc(){
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutKeyboardFunc(tecladoListener);
  glutSpecialFunc(specialListener);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(800,800);
  glutCreateWindow("TP 3");

  // Enable texture
  glEnable(GL_TEXTURE_2D);

  // Init the functions
  initFunc();

  // Glew Init
  glewInit();

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  // inicialização da luz
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  updateCam();

  // Load Texture
  wood = getTexture("textures/wood.jpg");

  // Load VBOs
  plano = vboPlano(10,10, wood);
  paralelo = vboParalelo(10, 20, 30, wood);
  cilindro = vboCilindro(30,10,10,10,wood);
  cone = vboCone(30,10, 10,10,15,wood);
  torus = vboTorus(20, 5, 15, wood);
  esfera = vboEsfera(30, 20, 20, wood);
  copoMartini = vboMartini(30, 0.5, 10, 15, 5, 0.5, 10, wood);
  mesa = vboMesaVidro(30, 20, 2, 16, 4, 14, 0.4, wood);
  cadeira = vboCadeiraFashion(20.0, 20.0, 2.0, 20.0, 2.5, 20.0, 1.5, 6.0, wood);
  candeeiro = vboCandeeiroTeto(30, 15, 15, 3, 10, 15, wood);
  bar = vboBar(wood);

  glutMainLoop();

  return 1;
}

