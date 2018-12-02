#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"

void drawCadeiraSimples (float compTampo, float altTampo, float profTampo, float compPerna, float altPerna, float profPerna, float raioFerrinho, float altFerrinho, float compEncosto, float profEncosto, float r, float g, float b) {
 
    float xP, yP, zP;
    float xF, yF, zF;
    float xE, yE, zE;

    //Tampo
    drawParalelo(altTampo ,compTampo ,profTampo , r, g, b);
    
    //Pernas
    xP = compTampo/2 - compPerna;
    yP = -(altPerna/2) -(altTampo/2);
    zP = profTampo/2 - profPerna;

    glPushMatrix();
    glTranslatef(xP, yP, -zP);
    drawParalelo(altPerna,compPerna,profPerna, r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-xP, yP, -zP);
    drawParalelo(altPerna,compPerna,profPerna, r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-xP, yP, zP);
    drawParalelo(altPerna,compPerna,profPerna, r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xP, yP, zP);
    drawParalelo(altPerna,compPerna,profPerna, r, g, b);
    glPopMatrix();

    //Ferrinhos
    xF = compTampo/4;
    yF = altFerrinho/2 - altTampo/2;
    zF = -(profTampo/2 + raioFerrinho);

    glPushMatrix();
    glTranslatef(xF, yF, zF);
    drawCilindro(25, altFerrinho, raioFerrinho, r, g, b);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-xF, yF, zF);
    drawCilindro(25, altFerrinho, raioFerrinho, r, g, b);
    glPopMatrix();

    //Encosto
    xE = 0.0;
    yE = altFerrinho - altTampo;
    zE = -profTampo/2 + profEncosto/2;

    glPushMatrix();
    glTranslatef(xE, yE, zE);
    drawParalelo(altFerrinho/2, compEncosto, profEncosto, r, g, b);
    glPopMatrix();
}

void drawCadeiraSimplesTabuas(float compTampo, float altTampo, float profTampo, float compPerna, float altPerna, float altEncosto, int numEncosto, float compEncosto, float r, float g, float b) {
 
    int i, j;
    float distEntreTamposCostas;
    float xP, yP, zP;
    float xB, yB, zB;
    float xL, yL, zL;
    float xV, yV, zV;
    float xE, yE, zE;

    //Tampo
    drawParalelo(altTampo, compTampo, profTampo ,r , g, b);
    
    //Pernas
    xP = compTampo/2 - compPerna;
    yP = altPerna/2 + altTampo/2;
    zP = profTampo/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, zP);
        drawParalelo(altPerna, compPerna, compPerna,r , g, b);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, -zP);
        drawParalelo(altPerna, compPerna, compPerna,r , g, b);
        glPopMatrix();
    }

    //Barras Encostadas ao Tampo 
    xB = compPerna - compTampo/2;
    yB = compPerna/2 + altTampo/2;
    zB = profTampo/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0f, -yB, j*zB);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        drawParalelo(compPerna, compPerna, compTampo -3*compPerna, r, g, b);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, -yB, 0.0f);
        drawParalelo(compPerna, compPerna, profTampo -3*compPerna, r, g, b);
        glPopMatrix();
    }

    //Barras Laterais e do Meio
    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, -yB -altPerna*0.5, 0.0f);
        drawParalelo(compPerna, compPerna, profTampo -3*compPerna, r, g, b);
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(0.0f, -yB -altPerna*0.6, -zB);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    drawParalelo(compPerna, compPerna, compTampo -3*compPerna, r, g, b);
    glPopMatrix();

    //Barras Verticas das Costas
    xV = compTampo/2 - compPerna;
    yV = altEncosto/2 + altTampo/2;
    zV = profTampo/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xV, yV, zV);
        drawParalelo(altEncosto , compPerna, compPerna, r, g, b);
        glPopMatrix();
    }
    //Barras Lateral das Costas
    xL = 0.0;
    yL = altEncosto + altTampo/2 + compPerna/2;
    zL = profTampo/2 - compPerna;

    glPushMatrix();
    glTranslatef(0.0, yL, zL);
    drawParalelo(compPerna, compTampo -compPerna, compPerna, r, g, b);
    glPopMatrix();

    //Encostos
    distEntreTamposCostas = ((altEncosto-compPerna) -(numEncosto*compEncosto))/(numEncosto+1);
    xE = 0.0;
    yE = altEncosto + altTampo/2 - compPerna/2;
    zE = profTampo/2 - compPerna;
    
    for (i = 0, j = 1; i < numEncosto; i++, j+= 2) {
        glPushMatrix();
        glTranslatef(xE, yE - j*distEntreTamposCostas, zE);
        drawParalelo(compEncosto, compTampo -3*compPerna, compPerna/2, r, g, b);
        glPopMatrix();
    }
}

void drawBanco(float raioTampo, float altTampo, float rT, float gT, float bT, float altPerna, float largPerna, float tamBeira, float largBeira, float largBarra, float r, float g, float b) {

    float angulo;
    float xP, yP, zP;
    float xBe, yBe, zBe;
    float yBa;

    //Desenhar Tampo
    drawCilindro(25, altTampo, raioTampo, rT, gT, bT);

    //Pernas
    xP = raioTampo -largPerna/2;        
    yP = altPerna/2 + altTampo/2;
    zP = raioTampo -largPerna/2;   

    for (angulo = M_PI/4; angulo < 2*M_PI; angulo += M_PI/2) {  
        glPushMatrix();
        glTranslatef(xP * sin(angulo), -yP, zP * cos(angulo));
        drawParalelo(altPerna, largPerna, largPerna, r, g, b);
        glPopMatrix();
    }

    //Beiras encostadas ao Tampo e Barra das Pernas
    xBe = raioTampo -largPerna/2;  
    yBe = altTampo/2 + tamBeira/2;
    zBe = raioTampo -largPerna/2;
    yBa = (altPerna)* 0.70 - altTampo/2;

    for (angulo = M_PI/4; angulo < M_PI; angulo += M_PI/2) {  
        glPushMatrix();
        glTranslatef(0.0f, -yBe, zBe * cos(angulo));
        drawParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -1.7*largPerna, largBeira, r, g, b);
        glTranslatef(0.0f, -yBa, 0.0f);
        drawParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -1.7*largPerna, largBarra, r, g, b);
        glPopMatrix();
    }

    for (angulo = (3*M_PI)/4; angulo < 2*M_PI; angulo += M_PI/2) {  
        glPushMatrix();
        glTranslatef(xBe * sin(angulo), -yBe, 0.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        drawParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -1.7*largPerna , largBeira, r, g, b);
        glTranslatef(0.0f, -yBa, 0.0f);
        drawParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -1.7*largPerna, largBarra, r, g, b);        
        glPopMatrix();
    }
}

void drawBancoI(float raioTampo, float altTampo, float rT, float gT, float bT, float altPerna, float largPerna, float inclinacao, float tamBeira, float largBeira, float largBarra, float r, float g, float b) {

    int j;
    float angulo;
    float xP, yP, zP;
    float xBe, yBe, zBe;
    float yBa;
    float incConv = inclinacao*M_PI /180;

    //Desenhar Tampo
    drawCilindro(25, altTampo, raioTampo, rT, gT, bT);

    //Pernas
    xP = raioTampo -largPerna/2;        
    yP = altPerna/2 + altTampo/2;
    zP = raioTampo -largPerna/2;   

    for (angulo = M_PI/4, j = -1; angulo < M_PI; angulo += M_PI/2, j += 2) {  
        glPushMatrix();
        glTranslatef(xP * sin(angulo), -yP, zP * cos(angulo));
        glRotatef(j*inclinacao, 1.0f, 0.0f, 0.0f);
        glRotatef(inclinacao, 0.0f, 0.0f, 1.0f);
        drawParalelo(altPerna, largPerna, largPerna, r, g, b);
        glPopMatrix();
    }

    for (angulo = (5*M_PI/4), j = 1; angulo < 2*M_PI; angulo += M_PI/2, j -= 2) {  
        glPushMatrix();
        glTranslatef(xP * sin(angulo), -yP, zP * cos(angulo));
        glRotatef(j*inclinacao, 1.0f, 0.0f, 0.0f);
        glRotatef(-inclinacao, 0.0f, 0.0f, 1.0f);
        drawParalelo(altPerna, largPerna, largPerna, r, g, b);
        glPopMatrix();
    }

    //Beiras encostadas ao Tampo e Barra das Pernas
    xBe = raioTampo -largPerna/2 - largBarra;  
    yBe = altTampo/2 + tamBeira/2;
    zBe = raioTampo -largPerna/2 - largBarra; 
    yBa = (altPerna)* 0.70 - altTampo/2;

    for (angulo = M_PI/4, j = -1; angulo < M_PI; angulo += M_PI/2, j += 2) {  
        glPushMatrix();
        glTranslatef(0.0, -yBe, zBe * cos(angulo-j*incConv));
        glRotatef(j*inclinacao, 1.0f, 0.0f, 0.0f);
        drawParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -2*largPerna, largBeira, r, g, b);
        glTranslatef(0.0f, -yBa, 0.0f);
        drawParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -1.3*largPerna, largBarra, r, g, b);
        glPopMatrix();
    }

    for (angulo = (3*M_PI)/4, j = -1; angulo < 3*M_PI/2; angulo += M_PI/2, j+=2) {  
        glPushMatrix();
        glTranslatef(xBe * sin(angulo-j*incConv), -yBe, 0.0f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(j*inclinacao, 1.0f, 0.0f, 0.0f);
        drawParalelo(tamBeira, 2*raioTampo*sin(M_PI/4) -2*largPerna, largBeira, r, g, b);
        glTranslatef(0.0f, -yBa, 0.0f);
        drawParalelo(largBarra, 2*raioTampo*sin(M_PI/4) -1.3*largPerna, largBarra, r, g, b);
        glPopMatrix();
    }
}

void drawBancoQ(float compTampo, float largTampo, float altTampo, float rT, float gT, float bT, float altPerna, float largPerna, float tamBeira, float largBeira, float largBarra, float r, float g, float b) {

    int i;
    float xP, yP, zP;
    float xBe, yBe, zBe;
    float yBa;

    //Desenhar Tampo
    drawParalelo(altTampo, compTampo, largTampo, rT, gT, bT);

    //Pernas
    xP = compTampo/2 - largPerna/2;        
    yP = altPerna/2 + altTampo/2;
    zP = largTampo/2 -largPerna/2;   

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xP, -yP, zP);
        drawParalelo(altPerna, largPerna, largPerna ,r, g, b);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) { 
        glPushMatrix();
        glTranslatef(i*xP, -yP, -zP);
        drawParalelo(altPerna, largPerna, largPerna ,r, g, b);
        glPopMatrix();
    }

    //Beiras encostadas ao Tampo e Barra das Pernas
    xBe = compTampo/2 -largBeira/2;  
    yBe = altTampo/2 + tamBeira/2;
    zBe = largTampo/2 -largBeira/2;
    yBa = (altPerna)* 0.70 - altTampo/2;

    for (i = -1; i < 2; i+=2) { 
        glPushMatrix();
        glTranslatef(i*xBe, -yBe, 0.0);
        drawParalelo(tamBeira, largBeira, largTampo - 2*largPerna, r, g, b);
        glTranslatef(0.0, -yBa, 0.0);
        drawParalelo(tamBeira, largBeira, largTampo - 2*largPerna, r, g, b);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) { 
        glPushMatrix();
        glTranslatef(0.0, -yBe, i*zBe);
        drawParalelo(tamBeira, compTampo - 2*largPerna, largBeira, r, g, b);
        glTranslatef(0.0, -yBa, 0.0);
        drawParalelo(tamBeira, compTampo - 2*largPerna, largBeira, r, g, b);
        glPopMatrix();
    }
}

void drawBancoQI(float compTampo, float largTampo, float altTampo, float rT, float gT, float bT, float altPerna, float largPerna, float inclinacao, float tamBeira, float largBeira, float largBarra, float r, float g, float b) {

    int i, j;
    float xP, yP, zP;
    float xBe, yBe, zBe;
    float yBa;
    float incConv = inclinacao*M_PI /180;

    //Desenhar Tampo
    drawParalelo(altTampo, compTampo, largTampo, rT, gT, bT);

    // //Pernas
    xP = compTampo/2 - largPerna/2;        
    yP = altPerna/2 + altTampo/2;
    zP = largTampo/2 -largPerna/2;  

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xP, -yP, zP);
        glRotatef(-inclinacao, 1.0f, 0.0f, 0.0f);
        glRotatef(i*inclinacao, 0.0f, 0.0f, 1.0f);
        drawParalelo(altPerna, largPerna, largPerna ,r, g, b);
        glPopMatrix();
    }

    for (i = 1; i > -2; i-=2) {
        glPushMatrix();
        glTranslatef(i*xP, -yP, -zP);
        glRotatef(inclinacao, 1.0f, 0.0f, 0.0f);
        glRotatef(i*inclinacao, 0.0f, 0.0f, 1.0f);
        drawParalelo(altPerna, largPerna, largPerna ,r, g, b);
        glPopMatrix();
    }

    // //Beiras encostadas ao Tampo e Barra das Pernas
    xBe = compTampo/2 -largBeira/2 -altPerna*sin(incConv);  
    yBe = altTampo/2 + tamBeira/2;
    zBe = largTampo/2 -largBeira/2 -altPerna*sin(incConv);
    yBa = (altPerna)* 0.70 - altTampo/2;

    for (i = -1; i < 2; i+=2) { 
        glPushMatrix();
        glTranslatef(i*xBe, -yBe, 0.0);
        glRotatef(i*inclinacao, 0.0f, 0.0f, 1.0f);
        drawParalelo(tamBeira, largBeira, largTampo - 2.5*largPerna, r, g, b);
        glTranslatef(0.0, -yBa, 0.0);
        drawParalelo(tamBeira, largBeira, largTampo - 1.5*largPerna, r, g, b);
        glPopMatrix();
    }

    for (i = -1, j = 1; i < 2; i+=2, j -=2) { 
        glPushMatrix();
        glTranslatef(0.0, -yBe, i*zBe);
        glRotatef(j*inclinacao, 1.0f, 0.0f, 0.0f);
        drawParalelo(tamBeira, compTampo - 2*largPerna, largBeira, r, g, b);
        glTranslatef(0.0, -yBa, 0.0);
        drawParalelo(tamBeira, compTampo - 1.5*largPerna, largBeira, r, g, b);
        glPopMatrix();
    }
}

void drawCadeiraDecor(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, float r1, float g1, float b1, float r2, float g2, float b2) {

    int i, j;
    float distEntreTamposBase, distEntreTamposCostas;
    float xB, yB, zB;
    float xT, yT, zT;
    float xP, yP, zP;
    float xBr, yBr, zBr;
    float xA1, yA1, zA1;
    float xA2, yA2, zA2;
    float xC, yC, zC;
    float xTC, yTC, zTC;

    //Base
    xB = largBase/2 -altBase/2;
    yB = 0.0;
    zB = compBase/2 + altBase/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, j*zB);
        drawParalelo(altBase, largBase, altBase , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        drawParalelo(altBase, compBase, altBase, r1, g1, b1);
        glPopMatrix();
    }

    //Tampos da Base
    distEntreTamposBase = (compBase -(numTamposBase*compTampos))/(numTamposBase+1);
    xT = 0.0;
    yT = altBase/2 +altTampos/2;
    zT = compBase/2 - compTampos/2;

    for (i = 0; i < numTamposBase; i++) {
        glPushMatrix();
        glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*compTampos);
        drawParalelo(altTampos, largBase, compTampos, r2, g2, b2);
        glPopMatrix();
    }

    //Pernas
    xP = largBase/2 + largPerna/2;
    yP = altPerna/2 + altBase/2;
    zP = compBase/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, zP);
        drawParalelo(altPerna, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, -zP);
        drawParalelo(altPerna, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    //Bracos
    xBr = xP;
    yBr = altBracos/2 -altBase/2;
    zBr = zP;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(xBr, yBr, j*zBr);
        drawParalelo(altBracos, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(-xBr, yBr, j*zBr);
        drawParalelo(altBracos, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr, yBr + altBracos/2 + largPerna/2, 0.0);
        drawParalelo(largPerna ,largPerna , compBase -compPerna, r1, g1, b1);
        glPopMatrix();
    }

    //Apoio Base
    xA1= largBase/2 + largPerna/2;
    yA1 = -altBase; 
    zA1 = compBase/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0, yA1, j*zA1);
        drawParalelo(altBase, largBase, altBase , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
         glPushMatrix();
         glTranslatef(j*xA1, yA1, 0.0);
         drawParalelo(altBase, altBase, compBase -3*largPerna , r1, g1, b1);
         glPopMatrix();
    }

    xA2 = compCostas/2 + largCostas/2;
    yA2 = altBase/2 + largCostas/2; 
    zA2 = compBase/2 - compPerna/2 + 1.5*altBase + difTampoeCostas/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xA2, -yA2, -zA2);
        drawParalelo(largCostas, largCostas, 2*altBase + compPerna + difTampoeCostas, r1, g1, b1);
        glPopMatrix();   
    }

    //Base Costas
    xC = compCostas/2 + largCostas/2;
    yC = altCostas/2 -altBase/2; 
    zC = compBase/2 + 2.5*altBase + difTampoeCostas -largCostas/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xC, yC, -zC);
        drawParalelo(altCostas, largCostas, largCostas, r1, g1, b1);
        glPopMatrix();
    }

    yC = largCostas/2 + altBase/2; ;

    for (i = 0, j = 0; i < 2; i++, j+= altCostas) {
        glPushMatrix();
        glTranslatef(0.0, j -yC, -zC);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawParalelo(largCostas, compCostas, largCostas, r1, g1, b1);
        glPopMatrix();
    }

    //Tampos das costas
    distEntreTamposCostas = ((altCostas - 2*largCostas) -(numTamposCostas*compTampos))/(numTamposCostas+1);
    xTC = 0.0;
    yTC = altCostas - altBase/2 - largCostas/2 - compTampos;
    zTC = compBase/2 + 2.5*altBase + difTampoeCostas -largCostas;

    for (i = 0; i < numTamposCostas; i++) {
        glPushMatrix();
        glTranslatef(0.0, yTC - ((i+1)*distEntreTamposCostas + (i)*compTampos), -zTC);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawParalelo(altTampos, compCostas, compTampos, r2, g2, b2);
        glPopMatrix();
    }
}

void drawCadeiraDecorX(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, float r1, float g1, float b1, float r2, float g2, float b2) {

    int i, j;
    float distEntreTamposBase, distEntreTamposCostas;
    float xB, yB, zB;
    float xT, yT, zT;
    float xP, yP, zP;
    float xBr, yBr, zBr;
    float xA1, yA1, zA1;
    float xA2, yA2, zA2;
    float xC, yC, zC;
    float xTC, yTC, zTC;

    //Base
    xB = largBase/2 -altBase/2;
    yB = 0.0;
    zB = compBase/2 + altBase/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, j*zB);
        drawParalelo(altBase, largBase, altBase , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        drawParalelo(altBase, compBase, altBase, r1, g1, b1);
        glPopMatrix();
    }

    //Tampos da Base
    distEntreTamposBase = (compBase -(numTamposBase*compTampos))/(numTamposBase+1);
    xT = 0.0;
    yT = altBase/2 +altTampos/2;
    zT = compBase/2 - compTampos/2;

    for (i = 0; i < numTamposBase; i++) {
        glPushMatrix();
        glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*compTampos);
        drawParalelo(altTampos, largBase, compTampos, r2, g2, b2);
        glPopMatrix();
    }

    // Pernas
    xP = largBase/2 + largPerna/2;
    yP = (altPerna/2)* sin(M_PI/4) + altBase/2 -compPerna/2;
    zP = compBase/2 -(altPerna/2)* sin(M_PI/4);

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, -zP);
        glRotatef(-45.0, 1.0, 0.0, 0.0);
        drawParalelo(altPerna, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, zP);
        glRotatef(45.0, 1.0, 0.0, 0.0);
        drawParalelo(altPerna, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    // Bracos
    xBr = xP;
    yBr = altBracos/2 -altBase/2;
    zBr = compPerna/2 - ((compBase + 2*altBase) -4*compPerna)/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(xBr, yBr, j*zBr);
        drawParalelo(altBracos, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(-xBr, yBr, j*zBr);
        drawParalelo(altBracos, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr, yBr + altBracos/2 + largPerna/2, 0.0);
        drawParalelo(largPerna ,largPerna , compBase -2*compPerna, r1, g1, b1);
        glPopMatrix();
    }

    // Apoio Base
    xA1= largBase/2 + largPerna/2;
    yA1 = -altBase; 
    zA1 = compBase/2 -compPerna/2 -altBase;;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0, yA1, j*zA1);
        drawParalelo(altBase, largBase, altBase , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
         glPushMatrix();
         glTranslatef(j*xA1, yA1, 0.0);
         drawParalelo(altBase, altBase, compBase -3*largPerna , r1, g1, b1);
         glPopMatrix();
    }

    xA2 = compCostas/2 + largCostas/2;
    yA2 = altBase/2 + largCostas/2; 
    zA2 = compBase/2 - compPerna/2 + 1.5*altBase + difTampoeCostas/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xA2, -yA2, -zA2);
        drawParalelo(largCostas, largCostas, altBase + compPerna + difTampoeCostas, r1, g1, b1);
        glPopMatrix();   
    }

    //Base Costas
    xC = compCostas/2 + largCostas/2;
    yC = altCostas/2 -altBase/2; 
    zC = compBase/2 + 2*altBase + difTampoeCostas -largCostas/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xC, yC, -zC);
        drawParalelo(altCostas, largCostas, largCostas, r1, g1, b1);
        glPopMatrix();
    }

    yC = largCostas/2 + altBase/2; ;

    for (i = 0, j = 0; i < 2; i++, j+= altCostas) {
        glPushMatrix();
        glTranslatef(0.0, j -yC, -zC);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawParalelo(largCostas, compCostas, largCostas, r1, g1, b1);
        glPopMatrix();
    }

    //Tampos das costas
    distEntreTamposCostas = ((altCostas - 2*largCostas) -(numTamposCostas*compTampos))/(numTamposCostas+1);
    xTC = 0.0;
    yTC = altCostas - altBase/2 - largCostas/2 - compTampos;
    zTC = compBase/2 + 2.0*altBase + difTampoeCostas -largCostas;

    for (i = 0; i < numTamposCostas; i++) {
        glPushMatrix();
        glTranslatef(0.0, yTC - ((i+1)*distEntreTamposCostas + (i)*compTampos), -zTC);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        drawParalelo(altTampos, compCostas, compTampos, r2, g2, b2);
        glPopMatrix();
    }
}

void drawCadeiraDecorInc(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float altBracos, float difTampoeCostas, float altCostas, float compCostas, float largCostas, int numTamposCostas, float inclinacao, float r1, float g1, float b1, float r2, float g2, float b2) {

    int i, j;
    float distEntreTamposBase, distEntreTamposCostas;
    float xB, yB, zB;
    float xT, yT, zT;
    float xP, yP, zP;
    float xBr, yBr, zBr;
    float xA1, yA1, zA1;
    float xA2, yA2, zA2;
    float xC1, yC1, zC1;
    float xC2, yC2, zC2;
    float xTC, yTC, zTC;
    float incConv = (inclinacao * M_PI)/180;

    //Base
    xB = largBase/2 -altBase/2;
    yB = 0.0;
    zB = compBase/2 + altBase/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, j*zB);
        drawParalelo(altBase, largBase, altBase , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        drawParalelo(altBase, compBase, altBase, r1, g1, b1);
        glPopMatrix();
    }

    //Tampos da Base
    distEntreTamposBase = (compBase -(numTamposBase*compTampos))/(numTamposBase+1);
    xT = 0.0;
    yT = altBase/2 +altTampos/2;
    zT = compBase/2 - compTampos/2;

    for (i = 0; i < numTamposBase; i++) {
        glPushMatrix();
        glTranslatef(0.0, yT, -zT + (i+1)*distEntreTamposBase + (i)*compTampos);
        drawParalelo(altTampos, largBase, compTampos, r2, g2, b2);
        glPopMatrix();
    }

    //Pernas
    xP = largBase/2 + largPerna/2;
    yP = altPerna/2 + altBase/2;
    zP = compBase/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, zP);
        drawParalelo(altPerna, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, -zP);
        drawParalelo(altPerna, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    //Bracos
    xBr = xP;
    yBr = altBracos/2 -altBase/2;
    zBr = zP;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(xBr, yBr, j*zBr);
        drawParalelo(altBracos, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(-xBr, yBr, j*zBr);
        drawParalelo(altBracos, largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr, yBr + altBracos/2 + largPerna/2, 0.0);
        drawParalelo(largPerna ,largPerna , compBase -compPerna, r1, g1, b1);
        glPopMatrix();
    }

    //Apoio Base
    xA1= largBase/2 + largPerna/2;
    yA1 = -altBase; 
    zA1 = compBase/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0, yA1, j*zA1);
        drawParalelo(altBase, largBase, altBase , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
         glPushMatrix();
         glTranslatef(j*xA1, yA1, 0.0);
         drawParalelo(altBase, altBase, compBase -3*largPerna , r1, g1, b1);
         glPopMatrix();
    }

    xA2 = compCostas/2 + largCostas/2;
    yA2 = altBase/2 + largCostas/2; 
    zA2 = compBase/2 - compPerna/2 + 1.5*altBase + difTampoeCostas/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xA2, -yA2, -zA2);
        drawParalelo(largCostas, largCostas, 2*altBase + compPerna + difTampoeCostas, r1, g1, b1);
        glPopMatrix();   
    }

    // //Base Costas
    xC1 = compCostas/2 + largCostas/2;
    yC1 = altCostas/2 -altBase/2 - largCostas/2; 
    zC1 = compBase/2 + 2.5*altBase + difTampoeCostas -largCostas/2 +(sin(incConv)*altCostas)/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xC1, yC1, -zC1);
        glRotatef(-inclinacao, 1.0f, 0.0f, 0.0f);
        drawParalelo(altCostas, largCostas, largCostas, r1, g1, b1);
        glPopMatrix();
    }

    xC2 = compCostas/2 + largCostas/2;
    yC2 = largCostas/2 + altBase/2; 
    zC2 = compBase/2 + 2.5*altBase + difTampoeCostas -largCostas/2;

    glPushMatrix();
    glTranslatef(0.0,-yC2, -zC2);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    drawParalelo(largCostas, compCostas, largCostas, r1, g1, b1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, altCostas - yC2 - largCostas +largCostas/4, -(zC1 +(sin(incConv)*(altCostas - yC2 - largCostas +largCostas/4)/2) +largCostas/4));
    glRotatef(-inclinacao, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    drawParalelo(largCostas, compCostas, largCostas, r1, g1, b1);
    glPopMatrix();

    // //Tampos das costas
    distEntreTamposCostas = ((altCostas - 2*largCostas) -(numTamposCostas*compTampos))/(numTamposCostas+1);
    xTC = 0.0;
    yTC = altCostas - altBase/2 - largCostas/2 - compTampos;
    zTC = compBase/2 + 2.5*altBase + difTampoeCostas +largCostas/4 +altTampos/2;

    for (i = 0; i < numTamposCostas; i++) {
        glPushMatrix();
        glTranslatef(0.0, yTC - ((i+1)*distEntreTamposCostas + (i)*compTampos), -(zTC + ((sin(incConv)*altCostas)/2) - i*largCostas +1.6*altTampos));
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glRotatef(-inclinacao, 1.0, 0.0, 0.0);
        drawParalelo(altTampos, compCostas, compTampos, r2, g2, b2);
        glPopMatrix();
    }
}

void drawCadeiraFashion(float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco, float r1, float g1, float b1, float r2, float g2, float b2) {

    int j;
    float xC, yC, zC;
    float xP, yP, zP;
    float xB, yB, zB;
    float xBr1, yBr1, zBr1;
    float xBr2, yBr2, zBr2;

    //Tampo
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    drawParalelo(largTampo, compTampo, altTampo ,r2, g2, b2);
    glPopMatrix();

    xC = 0.0;
    yC = altCostas/2 + altTampo/2;
    zC = largTampo/2 -largCostas/2;

    //Costas
    glPushMatrix();
    glTranslatef(xC, yC, -zC);
    drawParalelo(altCostas, compTampo, largCostas ,r2, g2, b2);
    glPopMatrix();

    //Pernas
    xP = compTampo/2 + largPerna/2;
    yP = altPerna/2 -altTampo/2;
    zP = largTampo/2 - largPerna*1.5;

    //Costas
    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, zP);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        drawParalelo(largPerna, altPerna, largPerna ,r1, g1, b1);
        glPopMatrix();
    }

    //Base
    xB = compTampo/2 + largPerna/2;
    yB = altPerna -altTampo/2 -largPerna/2;
    zB = largTampo/2 -largPerna/2 ;
 
    glPushMatrix();
    glTranslatef(0.0, -yB, -zB);
    drawParalelo(largPerna, compTampo, largPerna ,r1, g1, b1);
    glPopMatrix();

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, -yB, -largPerna);
        glRotatef(90, 0.0, 1.0, 0.0);
        drawParalelo(largPerna, largTampo - largPerna*2, largPerna ,r1, g1, b1);
        glPopMatrix();
    }

    //Bracos
    xBr1 = compTampo/2 + largPerna/2;
    yBr1 = altBraco/2 + altTampo/2;
    zBr1 = largTampo/2 - largPerna*1.5;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr1, yBr1, zBr1);
        drawParalelo(altBraco, largPerna, largPerna ,r1, g1, b1);
        glPopMatrix();
    }

    xBr2 = compTampo/2 + largPerna/2;
    yBr2 = altBraco + largPerna/2 +altTampo/2;
    zBr2 = largPerna/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr2, yBr2, -zBr2);
        drawParalelo(largPerna, largPerna, largTampo - largPerna ,r1, g1, b1);
        glPopMatrix();    
    }
}

void drawBancoRedondo(float raioTampo, float altTampo, float raioPerna, float altPerna, float rT, float gT, float bT, float rP, float gP, float bP ) {

    //Tampo
    drawCilindro(25, altTampo, raioTampo, rT, gT, bT);

    glPushMatrix();
    glTranslatef(0.0, -(altTampo/2 + altPerna/2), 0.0);
    drawCilindro(25, altPerna, raioPerna, rP, gP, bP);
    glPopMatrix();
}