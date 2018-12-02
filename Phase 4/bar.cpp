#include "bar.h"
#include "objects.h"



Texture metal, wood, wall, stairs, aluminium, chromed, sand, flooring, columns, stall, darkwood, yellwood, blackmetal, yellowT, drink2, beer, lampT,ballT;
Texture power,air, ceiling,sewer,glass,skyT, planks, fabric1,fabric2,greymetal,redmetal, lightply, darkyellwood, whiteplaster, drink,olive, glassGreen, btowel;
Texture pintura1, pintura3, nome, pintura2, wall2;

Object copoMartini, mesa, cadeira, bar, candeeiro,barr1,barr2,barr3,barr4,escada,corrimao,balcao,elem1,elem2,elem3;
Object munch, munch2, gogh, rembrandt,bSalvaVidas;
Primitiva sky, ball, towel;

// Copo
Object martini, stick, tall, caneca, cerveja, water;

// Beach
Object bCadeiraDecor, bCadeiraDecorX, bMesa, bCadeiraG, bMesaPequena, guardaSol, guardaSolP, passadeira, passadeira45, passadeira19,passadeira4, lightCube;

// Inside
Object iMesa, iCadeira, iMesaR, banco, sofa, candeeiroChao, candeeiroTeto, estante, garrafaVinho, garrafaUisque;

// Outside
Object candeeiroTetoBola, mesaPequena, sofaSimples, tikibar, nomebar;

Object lamp;

// Lights
GLfloat amb[3] = {0.2, 0.2, 0.2};

GLfloat diff[3] = {1.0, 1.0, 1.0};
// GLfloat diff[3] = {1.0, 0.0, 0.0};

GLfloat lTetoR1[4] = {80, 30 ,-33, 1.0};
GLfloat lTetoR2[4] = {0, 30 ,-33, 1.0};
GLfloat lTetoR3[4] = {-90.0, 30.0 ,-15.0, 1.0};
GLfloat lChao[4] = {-122.0, 16.5, -39.0, 1.0};

GLfloat lTop1[4] = {0, 66 ,-48, 1.0};
GLfloat lTop2[4] = {60, 66 ,-48, 1.0};
GLfloat lTop3[4] = {120, 66 ,-48, 1.0};
GLfloat lTop4[4] = {-60, 66 ,-48, 1.0};
GLfloat lTop5[4] = {-110.0, 16.5, 12.0, 1.0};

// Main render
void renderAll(){
  renderBar();

  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_LIGHT4);
  glEnable(GL_LIGHT5);
  renderInside();
  setInsideLights();

  // MORE LIGHT NOWWW !!!!1!
  glEnable(GL_LIGHT6);
  glEnable(GL_LIGHT7);
  renderOutside();
  renderBeach();
  setOutsideLights();
}

void renderBar(){
  glPushMatrix();
  glRotatef(-90,1,0,0);
  drawBar(bar,barr1,barr2,barr3,barr4,escada,corrimao,balcao,elem1,elem2,elem3);
  glPopMatrix();

  glPushMatrix();
  glRotatef(180, 1, 0, 0);
  drawVBO(sky);
  glPopMatrix();
}

// Inside
void insideTableRSet(Object mesa , Object cadeira){

  glPushMatrix();
  glTranslatef(0, 2.8, 0);
  drawMesaVidroR(mesa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10, 0, 0);
  glRotatef(-90, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 0, 10);
  glRotatef(180, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 0, -10);
  glRotatef(0, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10, 0, 0);
  glRotatef(90, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();
}

void insideTableSet(Object mesa , Object cadeira){

  glPushMatrix();
  glTranslatef(0, 2.8, 0);
  drawMesaVidro(mesa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(10, 0, 0);
  glRotatef(-90, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 0, 10);
  glRotatef(180, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 0, -10);
  glRotatef(0, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10, 0, 0);
  glRotatef(90, 0, 1, 0);
  drawCadeiraFashion(cadeira);
  glPopMatrix();
}

void renderInside(){
  //Quadros

  //O Grito de Munch
  glPushMatrix();
  glTranslatef(-126,22,25);
  glRotatef(90,0,1,0);
  drawQuadro(munch);
  glPopMatrix();

  //O "Grito" de Joker
  glPushMatrix();
  glTranslatef(-126,22,-45);
  glRotatef(90,0,1,0);
  drawQuadro(munch2);
  glPopMatrix();

  //Starry Night de Vincent van Gogh
  glPushMatrix();
  glTranslatef(-30,22,-62);
  drawQuadro(gogh);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(105, 7.9 , -15);
  glRotatef(45, 0, 1, 0);
  insideTableRSet(iMesaR, iCadeira);
  glPushMatrix();
  glTranslatef(2, 3.9, 2);
  drawTallGlass(tall);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(70, 7.9, -40);
  glRotatef(-30, 0, 1, 0);
  insideTableSet(iMesa, iCadeira);
  glPushMatrix();
  glTranslatef(-2, 4, 0);
  drawCerveja(cerveja);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 7.9, -40);
  glRotatef(25, 0, 1, 0);
  insideTableSet(iMesa, iCadeira);
  glPushMatrix();
  glTranslatef(0, 4.1, 1);
  drawCaneca(caneca);
  glPopMatrix();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-50 , 7.9, -25);
  glRotatef(-15, 0, 1, 0);
  insideTableRSet(iMesaR, iCadeira);
  glPushMatrix();
  glTranslatef(0, 4.1, 1);
  drawMartini(martini);
  glPopMatrix();
  glPopMatrix();

  // Estante
  glPushMatrix();
  glTranslatef(-68, 3, 50);
  glRotatef(-90, 0, 1, 0);
  drawEstante(estante);

  glPushMatrix();
  glTranslatef(0, 16.6, 4);
  drawGlassWater(water);

  for(int i = 1; i< 7; i++){
    glPushMatrix();
    glTranslatef(i*1.2, 0, 0);
    drawGlassWater(water);    
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-i*1.2, 0, 0);
    drawGlassWater(water);    
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 18.4, 4);
  drawGlassWater(water);

  for(int i = 1; i< 6; i++){
    glPushMatrix();
    glTranslatef(i*1, 0, 0);
    drawGlassWater(water);    
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-i*1, 0, 0);
    drawGlassWater(water);    
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 20.2, 4);
  drawGlassWater(water);

  for(int i = 1; i< 5; i++){
    glPushMatrix();
    glTranslatef(i*1, 0, 0);
    drawGlassWater(water);    
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-i*1, 0, 0);
    drawGlassWater(water);    
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 23.3, 4);

  for(int i = 0; i< 6; i++){
    glPushMatrix();
    glTranslatef(i*1.5, 0, 0);
    drawGarrafa(garrafaVinho);
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.5, 23, 4);
  for(int i = 1; i< 4; i++){
    glPushMatrix();
    glTranslatef(-i*2.5, 0, 0);
    drawGarrafa(garrafaUisque);
    glPopMatrix();
  }
  glPopMatrix();

  glPopMatrix();

  // Copos Balcao
  glPushMatrix();
  glTranslatef(-100, 18.8, 30);

  glPushMatrix();
  glTranslatef(0, 0.2, 0);
  drawMartini(martini);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(2, 0, 0);
  drawTallGlass(tall);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(4, 0.2, 0);
  drawCerveja(cerveja);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-4, 0.2, 0);
  drawCerveja(cerveja);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(6, 0, 0);
  for(int i = 0; i < 6; i++){
    glPushMatrix();
    glTranslatef(i*4, 0.2, 0);
    drawCerveja(cerveja);
    glPopMatrix();  
  }

  for(int i = 0; i < 6; i++){
    glPushMatrix();
    glTranslatef(i*4+2, 0.2, 0);
    drawGarrafa(garrafaVinho);
    glPopMatrix();  
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-8, 0.2, 0);
  drawCerveja(cerveja);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-16, 0.2, 0);
  drawCaneca(caneca);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-24, 0.7, 0);
  drawGlassWater(water);
  glPopMatrix();

  glPopMatrix();

  // Bancos
  glPushMatrix();
  glTranslatef(-100, 10.5, 20);

  drawBancoI(banco);

  glPushMatrix();
  glTranslatef(10, 0, 0);
  drawBancoI(banco);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20, 0, 0);
  drawBancoI(banco);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(30, 0, 0);
  drawBancoI(banco);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10, 0, 0);
  drawBancoI(banco);
  glPopMatrix();

  glPopMatrix();

  // Sofa
  glPushMatrix();
  glTranslatef(-122, 2, -28);
  glRotatef(90, 0, 1, 0);
  drawSofa(sofa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-122, 2, -50);
  glRotatef(90, 0, 1, 0);
  drawSofa(sofa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-122, 2, -39);
  drawCandeeiroChao(candeeiroChao);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(80, 34, -33);
  drawCandeeiroTetoCilindro(candeeiroTeto);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 34, -33);
  drawCandeeiroTetoCilindro(candeeiroTeto);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-90, 34, -15);
  drawCandeeiroTetoCilindro(candeeiroTeto);
  glPopMatrix();
}

void setInsideLights(){  
  glLightfv(GL_LIGHT2, GL_POSITION, lTetoR1);
  glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, diff);
  
  glLightfv(GL_LIGHT3, GL_POSITION, lTetoR2);
  glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT3, GL_DIFFUSE, diff);
  
  glLightfv(GL_LIGHT4, GL_POSITION, lTetoR3);
  glLightfv(GL_LIGHT4, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT4, GL_DIFFUSE, diff);

  glLightfv(GL_LIGHT5, GL_POSITION, lChao);
  glLightfv(GL_LIGHT5, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT5, GL_DIFFUSE, diff);
}

// Outside
void outsideSet(Object sofa, Object mesa){

  glPushMatrix();
  glTranslatef(0, -2, 0);
  drawSofa(sofa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, -0.1, 14);
  drawMesaVidro(mesa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-15, -2, 20);
  glRotatef(90, 0, 1, 0);
  drawSofa(sofaSimples);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(15, -2, 20);
  glRotatef(-90, 0, 1, 0);
  drawSofa(sofaSimples);
  glPopMatrix();
}

void renderOutside(){
  glPushMatrix();
  glTranslatef(0, 60, -48);

  glPushMatrix();
  glTranslatef(0, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(30, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(60, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(90, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(120, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-30, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-60, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-90, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-110, 0, 0);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-110, 0, 30);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-110, 0, 60);
  drawCandeeiroTeto(candeeiroTetoBola);
  glPopMatrix();

  glPopMatrix();

  // Sofa
  glPushMatrix();
  glTranslatef(32, 38.5, -55);

  glPushMatrix();
  outsideSet(sofa, mesaPequena);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(65, 0, 0);
  outsideSet(sofa, mesaPequena);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-65, 0, 0);
  outsideSet(sofa, mesaPequena);
  glPopMatrix();

  glPopMatrix();

  glPushMatrix();
  glTranslatef(-97, 36.5, 50);
  drawSofa(sofaSimples);
  glPopMatrix();
}

// Esplanada
void beachSet(Object mesa, Object cadeiraDecor, Object cadeiraDecorX){

  glPushMatrix();
  glTranslatef(0, 2.5, 0);
  drawMesaEsplanada(mesa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-8, -1, 0);
  glRotatef(90, 0, 1, 0);
  drawCadeiraDecor(cadeiraDecor);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, -1, -8);
  drawCadeiraDecorX(cadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(8, -1, 0);
  glRotatef(-90, 0, 1, 0);
  drawCadeiraDecor(cadeiraDecor);
  glPopMatrix();
}

void cadeiraPSet(Object cadeira, Object mesa, Object martini, Object stick, Object guardaSol){

  glPushMatrix();
  glTranslatef(0, 2.5, 0);
  drawCadeiraDecorInc(cadeira);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5, 2.5, -2);
  drawEsplanadaPequena(mesa);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5, 3.6, -2);
  drawMartiniWithStick(martini, stick);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(4, 0.9, -2);
  glRotatef(-20, 0, 0, 1);
  drawGuardaSol(guardaSol);
  glPopMatrix();
}

void passadeiraSet(Object passadeira){
  glPushMatrix();
  glTranslatef(1.5, 0, 0);
  drawPassadeira(passadeira45);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-80, 0, 225);
  drawPassadeira(passadeira19);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-90, 0, 67);
  drawPassadeira(passadeira);
  glPopMatrix();

  // Lights
  glPushMatrix();
  glTranslatef(-9.5, 0, 10);
  for(int i = 0; i < 8; i++){
    glPushMatrix();
    glTranslatef(0, 0, i*29);
    drawFoco(lightCube);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22, 0, i*29);
    drawFoco(lightCube);
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-101, 0, 70);
  for(int i = 0; i < 6; i++){
    glPushMatrix();
    glTranslatef(0, 0, i*28.5);
    drawFoco(lightCube);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22, 0, i*28.5);
    drawFoco(lightCube);
    glPopMatrix();
  }
  glPopMatrix(); 

  glPushMatrix();
  glTranslatef(-101, 0, 238);
  for(int i = 0; i < 8; i++){
    glPushMatrix();
    glTranslatef(0, 0, i*28.5);
    drawFoco(lightCube);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22, 0, i*28.5);
    drawFoco(lightCube);
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45.5, 0, 215);
  drawFoco(lightCube);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45.5, 0, 237);
  drawFoco(lightCube);
  glPopMatrix();
}

void renderBeach(){
  // Beach Sets
  glPushMatrix();
  glTranslatef(-40, 6, 40);
  glRotatef(45, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(80, 6, 40);
  glRotatef(-45, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-20, 6, 100);
  glRotatef(90, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(60, 6, 100);
  glRotatef(-90, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(30, 6, 150);
  glRotatef(190, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(150, 6, 150);
  glRotatef(190, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(200, 6, 10);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(190, 6, 80);
  glRotatef(-100, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(200, 6, 200);
  glRotatef(45, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(100, 6, 200);
  glRotatef(180, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-60, 6, 175);
  glRotatef(160, 0, 1, 0);
  beachSet(bMesa, bCadeiraDecor, bCadeiraDecorX);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(22, 8, 100);
  drawGuardaSol(guardaSol);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(140, 8, 90);
  drawGuardaSol(guardaSol);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(80, 8, 160);
  drawGuardaSol(guardaSol);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-20, 8, 180);
  drawGuardaSol(guardaSol);
  glPopMatrix();

  // CadeiraP Sets
  glPushMatrix();
  glTranslatef(60, 0, 250);

  glPushMatrix();
  cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
  glPopMatrix();

  for(int i = 0; i < 5; i++){
    glPushMatrix();
    glTranslatef(i*30, 0, 0);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-i*30, 0, 0);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(i*30, 0, 30);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-i*30, 0, 30);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200, 0, 80);

  glPushMatrix();
  cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
  glPopMatrix();

  for(int i = 0; i < 5; i++){
    glPushMatrix();
    glTranslatef(0, 0, i*30);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0, i*30);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(300, 0, 0);

  glPushMatrix();
  cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
  glPopMatrix();

  for(int i = 0; i < 5; i++){
    glPushMatrix();
    glTranslatef(0, 0, i*30);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0, i*30);
    cadeiraPSet(bCadeiraG, bMesaPequena, martini, stick, guardaSolP);
    glPopMatrix();
  }
  glPopMatrix();

  passadeiraSet(passadeira);

  glPushMatrix();
  glTranslatef(-200, 5, 200);
  glColor3f(1, 1, 1);
  glutSolidTeapot(2);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(80, 3, 200);
  drawVBO(ball);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-210, 3, 300);
  drawVBO(ball);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(220, 3, 0);
  drawVBO(ball);
  glPopMatrix();

  //Tiki bar
  glPushMatrix();
  glTranslatef(250,4,150);
    float inc=1;
    for(int i=0; i<5; i++)
    {
      glPushMatrix();
      glTranslatef(-10+inc, 8.4, 9);
      glRotatef(180,0,0,1);
      drawTallGlass(tall);
      glPopMatrix();
      inc+=0.9;
    }

    inc=1;
    for(int i=0; i<5; i++)
    {
      if(i==3)
      {
        glPushMatrix();
        glTranslatef(-10+inc, 8.4,7);
        glRotatef(180,0,0,1);
        drawTallGlass(tall);
        glPopMatrix();
      }
      else
      {
        glPushMatrix();
        glTranslatef(-10+inc, 8.4,8);
        glRotatef(180,0,0,1);
        drawTallGlass(tall);
        glPopMatrix();
      }
      inc+=0.9;
    }
  glRotatef(135,0,1,0);
  drawCaipiraBar(tikibar);
  glPopMatrix();

  //Titulo bar
  glPushMatrix();
  glTranslatef(235,13.5,148);
  glRotatef(45,0,1,0);
  drawQuadro(nomebar);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-200, 0.1, 300);
  glRotatef(-90,1, 0,0);
  drawVBO(towel);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-190, 12.5, 290);
  drawCadeiraDecor(bSalvaVidas);
  glPopMatrix();
}

void setOutsideLights(){
  glLightfv(GL_LIGHT7, GL_POSITION, lTetoR1);
  glLightfv(GL_LIGHT7, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT7, GL_DIFFUSE, diff);

  glLightfv(GL_LIGHT2, GL_POSITION, lTop1);
  glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, diff);
  
  glLightfv(GL_LIGHT3, GL_POSITION, lTop2);
  glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT3, GL_DIFFUSE, diff);
  
  glLightfv(GL_LIGHT4, GL_POSITION, lTop3);
  glLightfv(GL_LIGHT4, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT4, GL_DIFFUSE, diff);

  glLightfv(GL_LIGHT5, GL_POSITION, lTop4);
  glLightfv(GL_LIGHT5, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT5, GL_DIFFUSE, diff);

  glLightfv(GL_LIGHT6, GL_POSITION, lTop5);
  glLightfv(GL_LIGHT6, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT6, GL_DIFFUSE, diff);

}

// Loads
void loadAll(){
  loadBar();
  loadBeach();
  loadInside();
  loadOutside();
}

void loadBar(){
  barr1=vboBarreira(54,metal);
  barr2=vboBarreira(16,metal);
  barr3=vboBarreira(180,metal);
  barr4=vboBarreira(56,metal);
  escada=vboEscada(stairs);
  corrimao=vboCorrimao(52,aluminium);
  balcao=vboBalcao(stall);
  elem1=vboElements(8,8,power);
  elem2=vboElements(8,16,air);
  elem3=vboElements(4,4,sewer);
  bar = vboBar(flooring,wall,sand,columns,metal,ceiling,glass);

  // Sky
  sky = vboSky(20, 20, 1000, skyT);

  lightCube = vboFoco(1, lampT);
}

void loadBeach(){
  // Cadeira
  bCadeiraDecor = vboCadeiraDecor(4.0, 4.0, 0.3, 5, 0.1, 0.6, 4.0, 0.5, 0.5, 1.5, 0, 4.0, 4.0, 0.5, 3, darkwood, lightply);
  bSalvaVidas = vboCadeiraDecor(4.0, 4.0, 0.3, 5, 0.1, 0.6, 12.0, 0.5, 0.5, 1.5, 0, 4.0, 4.0, 0.5, 3, darkwood, lightply);
  bCadeiraDecorX = vboCadeiraDecorX(4.0, 4.0, 0.3, 5, 0.1, 0.6, 5.0, 0.3, 0.5, 1.5, 0, 4.0, 4.0, 0.5, 3, darkwood, lightply);
  bMesa = vboMesaEsplanada(6, 6, 0.5, 8, 0.1, 0.5, 7, 0.5, 0.5, darkwood, lightply);
  
  bCadeiraG = vboCadeiraDecorInc(7.0, 4.0, 0.3, 8, 0.1, 0.6, 2.0, 0.5, 0.3, 1.0, 0.3, 4.0, 4.0, 0.4, 5, 25, yellwood);
  bMesaPequena = vboEsplanadaPequena(3,3, lightply,darkwood);
  martini = vboMartini(30, 0.01, 0.6, 0.8, 0.3, 0.05, 0.6, drink);
  stick = vboMartiniStick(20, 0.5, 0.01, 0.15, olive, lightply);

  guardaSol = vboGuardaSol(10, 5, 4, 20, 0.5, 20, metal, yellowT);
  guardaSolP = vboGuardaSol(10, 5, 4, 10, 0.2, 15, metal, yellowT);
  passadeira45 = vboPassadeira(45, 0, 1.0, 18.0, 4.0, planks);
  passadeira19 = vboPassadeira(19, 90, 1.0, 18.0, 4.0, planks);
  passadeira = vboPassadeira(89, 0, 1.0, 18.0, 4.0, planks);
  passadeira4 = vboPassadeira(4, 0, 0.5, 18.0, 4.0, planks);
  ball = vboEsfera(10, 10, 6, ballT);

  munch = vboQuadro(6,6,0.1,pintura1);
  munch2 = vboQuadro(6,6,0.1,pintura2);
  gogh = vboQuadro(8,6,0.1,pintura3);

  tikibar = vboCaipiraBar(12,25,wall2,darkyellwood,planks,redmetal);
  nomebar = vboQuadro(4,8,1,nome);
  towel = vboPlano(25, 10, btowel);
}

void loadInside(){
  tall = vboTallGlass(20, 3, 1.5, 0.3, drink);
  caneca = vboCaneca(20, 0.2, 0.6, 0.7, 2, drink);
  cerveja = vboCerveja(20, 1, 0.2, 0.3, 0.25, 1.5, 0.4, drink, beer);
  water = vboGlassWater(20, 1, 1, 0.02, 0.5, drink);


  //Tampo Perna
  iMesa = vboMesaVidro(9.0, 9.0, 0.5, 8.0, 1.0, 3.0, 0.1, greymetal,drink2);
  iMesaR = vboMesaVidroR(4.5, 0.5, 8.0, 1.0, 3.0, 0.1, greymetal,drink2);

  iCadeira = vboCadeiraFashion(4.0, 5.0, 0.5, 5.0, 0.8, 6.0, 0.3, 1.5, greymetal,redmetal);
  banco = vboBancoI(2.0, 1.5, 8, 0.5, 6, 0.5, 0.1, 0.3, fabric2,redmetal);
  sofa = vboSofa(2, 16, 3, 7, 2, 7, 0.5, 3, 8, 1.2, 0.4, 0.2, fabric2,fabric1);
  candeeiroChao = vboCandeeiroChao(20, 0.1, 3, 12, 2, 5, blackmetal,whiteplaster, lampT);
  candeeiroTeto = vboCandeeiroTetoCilindro(20,4 ,3, 0.3, 3, 3, 7, blackmetal, sand, lampT);
  estante = vboEstante(28, 21, 1, 5, 1, darkyellwood);
  garrafaVinho = vboGarrafa(20, 2, 0.5, 0.5, 0.2, 0.6, glassGreen);
  garrafaUisque = vboGarrafa(4, 1.5, 1, 0.2, 0.2, 0.4, glassGreen);
}

void loadOutside(){
  candeeiroTetoBola = vboCandeeiroTeto(30, 10, 0.01, 0.5, 1, 3, blackmetal, sand);
  mesaPequena = vboMesaVidro(9.0, 9.0, 0.5, 2.0, 1.0, 3.0, 0.1, blackmetal,whiteplaster);
  sofaSimples = vboSofa(2, 5, 2, 5, 2, 6, 0.5, 1, 6.5, 1.2, 0.4, 0.2, fabric2,fabric1);
}

void loadTextures(){
  /*As que estão em comentário não são usadas no momento
  mas como têm sido úteis para testes deixei assim até à versão final*/
  wood = getTexture("textures/wood.jpg");
  wall = getTexture("textures/wall2.jpg");
  wall2 = getTexture("textures/bambu.jpg");
  stairs = getTexture("textures/stairs.jpg");
  metal = getTexture("textures/metal.jpg");
  aluminium = getTexture("textures/aluminium.jpg");
  planks = getTexture("textures/planks.jpg");
  sand = getTexture("textures/sand.jpg");
  columns = getTexture("textures/columns.jpg");
  flooring = getTexture("textures/wood2.jpg");
  stall = getTexture("textures/balcao.jpg");
  power=getTexture("textures/power.jpg");
  ceiling=getTexture("textures/ceiling.jpg");
  air=getTexture("textures/airconditioned.jpg");
  glass=getTexture("textures/glass.jpg");
  sewer=getTexture("textures/sewer.jpg");
  skyT = getTexture("textures/sky.png");
  fabric1 = getTexture("textures/fabric1.jpg");
  fabric2 = getTexture("textures/fabric2.jpg");
  greymetal = getTexture("textures/greymetal.jpg");
  redmetal = getTexture("textures/redmetal.jpg");
  lightply = getTexture("textures/lightply.jpg");
  darkwood = getTexture("textures/darkwood.jpg");
  yellwood = getTexture("textures/yellwood.jpg");
  darkyellwood = getTexture("textures/darkyellwood.jpg");
  blackmetal = getTexture("textures/blackmetal.jpg");
  whiteplaster = getTexture("textures/white.jpg");
  yellowT = getTexture("textures/yellow.jpg");
  drink = getTexture("textures/glass2.jpg");
  drink2 = getTexture("textures/glass3.jpg");
  glassGreen = getTexture("textures/glassGreen.jpg");
  olive = getTexture("textures/olive.jpg");
  beer = getTexture("textures/beer.jpg");
  lampT = getTexture("textures/yellowLamp.jpg");
  ballT = getTexture("textures/ball.jpg");
  pintura1 = getTexture("textures/gritomunch.jpg");
  pintura2 = getTexture("textures/gritomunch2.jpg");
  pintura3 = getTexture("textures/starrynight.jpg");
  nome = getTexture("textures/nomebar.jpg");
  btowel = getTexture("textures/btowel.jpg");
}
