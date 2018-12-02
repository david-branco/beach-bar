#include "header.h"
#include "objects.h"
#include "interface.h"
#include "bar.h"

bool wire = false;

bool fullscreen = false;

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

  processkeys();
  updateCam();

  // gluLookAt(0,0,0, 
  //           0.0,0.0,0.0,
  //           0.0f,1.0f,0.0f);

  GLfloat solAmb[3] = {0.2, 0.2, 0.2};
  GLfloat solDiff[3] = {1.0, 1.0, 1.0};
  GLfloat solPos[4] = {-200.0, 200.0 ,200.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, solPos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, solAmb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, solDiff);

  GLfloat solAmb2[3] = {0.2, 0.2, 0.2};
  GLfloat solDiff2[3] = {1.0, 1.0, 1.0};
  GLfloat solPos2[4] = {200.0, 200.0 ,-100.0, 1.0};
  glLightfv(GL_LIGHT1, GL_POSITION, solPos2);
  glLightfv(GL_LIGHT1, GL_AMBIENT, solAmb2);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, solDiff2);

  if(wire){
    glPolygonMode(GL_FRONT,GL_LINE);
    glPolygonMode(GL_BACK, GL_POINT);
  } else {
    glPolygonMode(GL_FRONT,GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE);
  }

  // glPushMatrix();
  // glTranslatef(0, 200, 200);
  // glutSolidCube(30);
  // glPopMatrix();
  
  // Render
  renderAll();
  
  // drawMartiniWithStick(copo, stick);
  // drawCandeeiroTeto(copo2);
  // drawMesaCafe(copo);
  // drawCandeeiroTetoCilindro(copo);
  // drawFoco(copo);

  //drawMesaCafe(mesa);
  //drawMesaVidro(mesa);
  //drawMesaVidroR(mesa);
  //drawEsplanadaPequena(mesa);
  //drawMesaEsplanada(mesa);
  //drawCadeiraSimples(cadeira);
  //drawCadeiraSimplesTabuas(cadeira);
  //drawBanco(cadeira);
  //drawBancoI(cadeira);
  //drawBancoQ(cadeira);
  //drawBancoQI(cadeira);
  //drawBancoRedondo(cadeira); 
  //drawCadeiraDecor(cadeira);
  //drawCadeiraDecorX(cadeira);
  //drawCadeiraDecorInc(cadeira);
  //drawCadeiraFashion(cadeira);

  glutSwapBuffers();
}

void processSpecialKeys(int key, int x, int y){
  // Options Keys
  switch (key) {
    case GLUT_KEY_HOME: if(wire) wire=false; else wire=true; break;
    case GLUT_KEY_PAGE_UP: if(fullscreen){glutFullScreen(); fullscreen=false;} else {glutReshapeWindow(800, 800);glutPositionWindow(100,100);fullscreen=true;} break;
  }
}

void initFunc(){
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutKeyboardFunc(key_pressed);
  glutKeyboardUpFunc(key_released);
  glutSpecialFunc(processSpecialKeys);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(1024,800);
  glutCreateWindow("TP 3");
  glutFullScreen();
  // Enable Texture
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
  glEnable(GL_LIGHT1);
  glShadeModel(GL_SMOOTH);

  // Load Texture
  loadTextures();

  // copo = vboCandeeiroChao(20, 0.3, 3, 6, 3, 7, wood);
  // copo = vboCandeeiroTetoCilindro(20,4 ,3, 0.3, 3, 3, 7, wood
  // copo = vboFocoC(4, wood);
  // vboCandeeiroTeto(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera, Texture texture)
  // copo2 = vboCandeeiroTeto(20, 4, 2, 0.5, 2, 3, wood);
  // copo = vboMartini(30, 0.01, 0.5, 0.5, 0.3, 0.05, 0.5, wood);
  // copo = vboTallGlass(20, 2, 1, 0.2, wood);
  // stick = vboMartiniStick(20, 0.5, 0.01, 0.15, wood);
  // Object vboCerveja(float fatias, float gomos, float alturaBase, float raioBase, float raioBaseTopo, float alturaCopo, float raioCopo, Texture texture)
  // copo = vboCerveja(20, 1, 0.06, 0.08, 0.07, 0.5, 0.1, wood);

  // Load VBOs
  loadAll();
  // Object vboGlassWater(int fatias, float raio, float alturaPe, float alturaBase, float larguraBase, Texture texture);  
  // copo = vboMartini(30, 0.5, 10, 15, 5, 0.5, 10, wood);
  // copo = vboTallGlass(30,5, 25, 5, wood);
  // copo = vboMartiniStick(30, 15, 0.2, 2, wood);
  // Object vboCaneca(float fatias, float raioI, float raioO, float raioCaneca, float alturaCaneca, Texture texture);
  // copo = vboCaneca(20, 0.05, 0.2, 0.2, 0.5, wood);
  // candeeiro = vboCandeeiroChao(30, 1, 5, 30, 5, 15, wood);
  // candeeiro = vboCandeeiroTetoCilindro(30,5, 10, 1, 5, 10, 10, wood);
  // plano = vboFoco(10,wood);
  // candeeiro = vboFocoC(10,wood);
  // candeeiro = vboCandeeiroTeto(30, 10, 15, 3, 10, 15, wood);
  // copo = vboCerveja(20, 5, 5, 7, 5, 30, 8, wood);
  // bar = vboBar(wood);
  //mesa = vboMesaCafe(16.0, 4.0, 4, 0.8 ,14, wood);
  //mesa = vboMesaVidro(30, 20, 2, 16, 4, 14, 0.4, wood);
  //mesa = vboMesaVidroR(15.0, 2.0, 16.0, 4.0, 12.0, 0.4, wood);
  //mesa = vboEsplanadaPequena(30,30, wood);
  //mesa =   vboMesaEsplanada(30.0, 30.0, 1.5, 10, 0.1, 1.5, 15, 2.0, 2.0, wood);

  //cadeira = vboCadeiraSimples(12.0, 0.8, 8.0, 1, 10, 1, 0.4, 8.0, 11, 0.8, wood);
  //cadeira = vboCadeiraSimplesTabuas(20.0, 1.0, 20.0, 2.0, 17.0, 15.0, 3.0, 3, wood);
  //cadeira = vboBanco(10.0, 6.0, 30.0, 3.0, 2.0, 0.8, 1.5, wood);  
  //cadeira = vboBancoI(10.0, 6.0, 30.0, 3.0, 6, 2.0, 0.8, 1.5, wood);
  //cadeira = vboBancoQ(15.0, 15.0, 4.0, 30.0, 3.0, 2.0, 1.0, 1.5, wood);
  //cadeira = vboBancoQI(15.0, 15.0, 4.0, 30.0, 3.0, 6, 2.0, 0.8, 1.5, wood);
  //cadeira = vboBancoRedondo(10.4, 4.0, 10.0, 15.0, wood); 
  //cadeira = vboCadeiraDecor(20.0, 20.0, 2.0, 6, 0.3, 2.0, 15.0, 2.0, 2.0, 6.0, 0, 20.0, 20.0, 2.0, 5, wood);
  //cadeira = vboCadeiraDecorX(20.0, 20.0, 2.0, 6, 0.3, 2.0, 25.0, 2.0, 2.0, 7.0, 0, 20.0, 20.0, 2.0, 5, wood);
  //cadeira = vboCadeiraDecorInc(30.0, 20.0, 2.0, 10, 0.3, 2.0, 15.0, 2.0, 2.0, 6.0, 1.0, 20.0, 20.0, 2.0, 5, 25, wood);
  //cadeira = vboCadeiraFashion(20.0, 20.0, 2.0, 20.0, 2.5, 20.0, 1.5, 6.0, wood);
  // garrafa = vboGarrafa(10, 3, 2, 1, 2, wood);

  glutMainLoop();

  return 1;
}
