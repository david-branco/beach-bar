#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"

void drawMesaCafe (float raioTampo, float alturaTampo, int numPernas, float raioPerna, float alturaPerna, float r, float g, float b) {

    float i = 0.0f;
    float x, y, z;
    float angulo = (2*M_PI) / numPernas;

    glPushMatrix();
    glTranslatef(0, (alturaTampo + alturaPerna)/2, 0);
    drawCilindro(25, alturaTampo, raioTampo, r, g, b);
    glPopMatrix();

    x = raioTampo - raioPerna;
    y = 0.0f;
    z = raioTampo - raioPerna;

    for (i = 0.0f; i < 2*M_PI; i+= angulo) {
        glPushMatrix();
        glTranslatef(x *sin(i), y, z *cos(i));
        drawCilindro(25 , alturaPerna, raioPerna, r, g ,b);
        glPopMatrix();
    }  
}

void drawMesaVidro (float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, float r, float g, float b, float rT, float gT, float bT) {

    int i;
    float yP;
    float yBP, yBG;
    float xA1, yA, zA1;
    float xA2, zA2;

    //Tampo
    drawParalelo(altTampo, compTampo, largTampo, rT, gT, bT);

    //Perna
    yP = altPerna/2 + altTampo/2;

    glPushMatrix();
    glTranslatef(0.0, -yP, 0.0);
    drawParalelo(altPerna, largPerna, largPerna, r, g, b);
    glPopMatrix();

    //Bases
    yBP = altPerna + altTampo/2 + altBase/2;

    glPushMatrix();
    glTranslatef(0.0, -yBP, 0.0);   
    drawParalelo(altBase, 1.5*largPerna, 1.5*largPerna, r, g, b);
    glPopMatrix();

    yBG = altPerna + altTampo/2 + 1.5*altBase;

    glPushMatrix();
    glTranslatef(0.0, -yBG, 0.0);   
    drawParalelo(altBase, compBase, compBase, r, g, b);
    glPopMatrix();

    //Apoios do Tampo
    xA1 = largPerna/2 + (compTampo/2 - largPerna/2 - altTampo/2)/2;
    yA = altTampo/2 + altTampo/6;
    zA1 = largPerna/2 + (largTampo/2 - largPerna/2 - altTampo/2)/2;

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xA1, -yA, 0.0);
        drawParalelo(altTampo/3, compTampo/2 - largPerna/2 - altTampo/2, altTampo/2, r, g, b);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(0.0, -yA, i*zA1);
        drawParalelo(altTampo/3, altTampo/2, largTampo/2 - largPerna/2 - altTampo/2, r, g, b);
        glPopMatrix();
    }

    xA2 = largPerna/2 + (compTampo/2 - largPerna/2 - altTampo/2) + altTampo/4;
    zA2 = largPerna/2 + (largTampo/2 - largPerna/2 - altTampo/2) + altTampo/4;

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xA2, -yA, 0.0);
        drawParalelo(altTampo/3, altTampo/2, largTampo/3, r, g, b);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(0.0, -yA, i*zA2);
        drawParalelo(altTampo/3, compTampo/3, altTampo/2, r, g, b);
        glPopMatrix();
    }
}

void drawMesaVidroR (float raioTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, float r, float g, float b, float rT, float gT, float bT) {

    int i;
    float yP;
    float yBP, yBG;
    float xA1, yA, zA1;
    float xA2, zA2;

    //Tampo
    drawCilindro(25, altTampo, raioTampo, rT, gT, bT);

    //Perna
    yP = altPerna/2 + altTampo/2;

    glPushMatrix();
    glTranslatef(0.0, -yP, 0.0);
    drawParalelo(altPerna, largPerna, largPerna, r, g, b);
    glPopMatrix();

    //Bases
    yBP = altPerna + altTampo/2 + altBase/2;

    glPushMatrix();
    glTranslatef(0.0, -yBP, 0.0);   
    drawParalelo(altBase, 1.5*largPerna, 1.5*largPerna, r, g, b);
    glPopMatrix();

    yBG = altPerna + altTampo/2 + 1.5*altBase;

    glPushMatrix();
    glTranslatef(0.0, -yBG, 0.0);   
    drawParalelo(altBase, compBase, compBase, r, g, b);
    glPopMatrix();

    //Apoios do Tampo
    xA1 = largPerna/2 + (raioTampo - largPerna/2 - altTampo/2 - altTampo/3)/2;
    yA = altTampo/2 + altTampo/6;
    zA1 = largPerna/2 + (raioTampo - largPerna/2 - altTampo/2 - altTampo/3)/2;

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xA1, -yA, 0.0);
        drawParalelo(altTampo/3, raioTampo - largPerna/2 - altTampo/2 - altTampo/3, altTampo/2, r, g, b);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(0.0, -yA, i*zA1);
        drawParalelo(altTampo/3, altTampo/2, raioTampo - largPerna/2 - altTampo/2 - altTampo/3, r, g, b);
        glPopMatrix();
    }

    xA2 = largPerna/2 + (raioTampo - largPerna/2 - altTampo/2 - altTampo/3) + altTampo/4;
    zA2 = largPerna/2 + (raioTampo - largPerna/2 - altTampo/2 - altTampo/3) + altTampo/4;

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xA2, -yA, 0.0);
        drawParalelo(altTampo/3, altTampo/2, raioTampo/3, r, g, b);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(0.0, -yA, i*zA2);
        drawParalelo(altTampo/3, raioTampo/3, altTampo/2, r, g, b);
        glPopMatrix();
    }
}

void drawEsplanadaPequena (float c, float p, float r, float g, float b) {

    float eachBar = p /9;
    float spaceBetween = .15;
    float posZ = -(6* eachBar + 5 *spaceBetween) /2;

    //tampo
    for ( int i=0; i<6; i++) {
        glPushMatrix();
        glTranslatef(0, .45, posZ);
        drawParalelo(0.6, c, eachBar, r, g, b);
        glPopMatrix();
        posZ += eachBar + spaceBetween;
    }

    //barras baixo do tampo
    glPushMatrix();
    glTranslatef(c /2 - eachBar /2, 0,  - p/18); // y é metade da altura do tampo e metade da altura da barra de baixo
    drawParalelo(0.3, eachBar /2, c, 1, 1, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( -( c /2 - eachBar /2), 0, - p/18); // y é metade da altura do tampo e metade da altura da barra de baixo
    drawParalelo(0.3, eachBar /2, c, 1, 1, 0);
    glPopMatrix();

    // pernas
    for ( int j =-1; j <2; j+=2) {
    glPushMatrix();
    glTranslatef(j * (c /2 - eachBar/2 + eachBar /8), -(0.3 + 0.15 + (c/2) * sin(M_PI/4) - eachBar /2), - p/18); 
    glRotatef(-45, 1.0f, 0.0f, 0.0f);
    drawParalelo(c, 0.3, eachBar /2, 1, 1, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( j* (c /2 - eachBar/2- eachBar /8), -(0.3 + 0.15 + (c/2) * sin(M_PI/4) - eachBar /2), - p/18); 
    glRotatef(45, 1.0f, 0.0f, 0.0f);
    drawParalelo(c, 0.3, eachBar /2, 1, 1, 0);
    glPopMatrix();
    
    }

    //barras
    glPushMatrix();
    glTranslatef( 0, -c *0.7 + eachBar, -(c/4 + eachBar/2));
    glRotatef(45, 1.0f, 0.0f, 0.0f);
    drawParalelo( 0.6, c - 2*spaceBetween - eachBar/2, 0.3, 1, 1, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef( 0, -c *0.7 + eachBar, c/4 -p/18);
    glRotatef(-45, 1.0f, 0.0f, 0.0f);
    drawParalelo( 0.6, c - 2*spaceBetween - eachBar/2, 0.3, 1, 1, 0);
    glPopMatrix();
}

void drawMesaEsplanada(float compBase, float largBase, float altBase, int numTamposBase, float altTampos, float compTampos, float altPerna, float compPerna, float largPerna, float difTampoeCostas, float r1, float g1, float b1, float r2, float g2, float b2) {

    int i, j;
    float distEntreTamposBase;
    float xB, yB, zB;
    float xT, yT, zT;
    float xP, yP, zP;
    float xA1, yA1, zA1;

    //Base
    xB = largBase/2 -altBase/2;
    yB = 0.0;
    zB = compBase/2 -altBase/2;

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
        drawParalelo(altBase, compBase -altBase*2, altBase, r1, g1, b1);
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
    xP = largBase/2 - largPerna/2;
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

    //Apoio Base
    xA1= largBase/2 - compPerna/2;
    yA1 = -altBase +altBase/4; 
    zA1 = compBase/2 - compPerna;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(0.0, yA1, j*zA1);
        drawParalelo(altBase/2, largBase -largPerna*2 , compPerna , r1, g1, b1);
        glPopMatrix();
    }

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xA1, yA1, 0.0);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        drawParalelo(altBase/2, compBase - 2*largPerna, compPerna, r1, g1, b1);
        glPopMatrix();
    }
}

