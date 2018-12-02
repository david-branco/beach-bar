#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"

void drawCandeeiroTeto(int fatias, float alturaFio, float alturaBase, float raioBase, float raioEsfera, float r, float g, float b){
    // Base
    glPushMatrix();
    drawCilindro(fatias, alturaBase, raioBase, r, g, b);
    glPopMatrix();

    // Fio
    glPushMatrix();
    glTranslatef(0.0, -(alturaFio/2 + alturaBase/2), 0.0);
    drawCilindro(fatias, alturaFio, 0.5, r, g, b);
    glPopMatrix();

    // Esfera
    glPushMatrix();
    glTranslatef(0.0, -alturaFio - raioEsfera - alturaBase/2, 0.0);
    drawEsfera(raioEsfera, fatias, fatias, r, g, b);
    glPopMatrix();
}

void drawCandeeiroChao(int fatias, float alturaBase, float raioBase, float alturaFio, float larguraTopo, float alturaTopo, float r, float g, float b){
    // Base
    glPushMatrix();
    drawCilindro(fatias, alturaBase, raioBase, r, g, b);
    glPopMatrix();

    // Fio
    glPushMatrix();
    glTranslatef(0.0, (alturaFio/2 + alturaBase/2), 0.0);
    drawCilindro(fatias, alturaFio, 0.5, r, g, b);
    glPopMatrix();

    // Topop
    glPushMatrix();
    glTranslatef(0.0, (alturaFio + alturaBase/2) + alturaTopo/2, 0.0);
    drawCilindro(fatias, alturaTopo, larguraTopo, r, g, b);
    glPopMatrix();
}

void drawLuzChao(float cubo, float r, float g, float b){
    glPushMatrix();
    glTranslatef(2+cubo/2, cubo/2, -cubo/2);
    drawParalelo(cubo-2, cubo-2, cubo-2 ,r ,g , b);
    glPopMatrix();

    float x = cubo/2;
    float y = cubo/2;
    float z = cubo/2;
    glPushMatrix();
    glTranslatef(cubo/2, cubo/2, -cubo/2);
     // Front
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glEnd();

    // Back
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, -y, -z);
    glVertex3f(x, y, -z);
    glVertex3f(x, -y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(x, y, -z);
    glEnd();

    // Top
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, y, z);
    glVertex3f(x, y, z);
    glVertex3f(x, y, -z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, y, z);
    glVertex3f(x, y, -z);
    glEnd();

    // Bottom
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(x, -y, z);
    glVertex3f(-x, -y, -z);
    glVertex3f(x, -y, -z);
    glVertex3f(-x, -y, z);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, cubo, 0.0);
    glVertex3f(-cubo, 0.0, 0.0);

    glVertex3f(0.0, 0.0, -cubo);
    glVertex3f(-cubo, 0.0, -cubo);
    glVertex3f(0.0, cubo, -cubo);

    glVertex3f(-cubo, 0.0, 0.0);
    glVertex3f(0.0, cubo, 0.0);
    glVertex3f(-cubo, 0.0, -cubo);

    glVertex3f(0.0, cubo, 0.0);
    glVertex3f(0.0, cubo, -cubo);
    glVertex3f(-cubo, 0.0, -cubo);

    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-cubo, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -cubo);

    glVertex3f(0.0, 0.0, -cubo);
    glVertex3f(-cubo, 0.0, 0.0);
    glVertex3f(-cubo, 0.0, -cubo);
    glEnd();
    glPopMatrix();
}

void drawCandeeiroTetoCilindro(int fatias, float alturaFio, float alturaBase, float raioBase, float altura, float raio, float r, float g, float b){
    // Base
    glPushMatrix();
    drawCilindro(fatias, alturaBase, raioBase, r, g, b);
    glPopMatrix();

    // Fio
    glPushMatrix();
    glTranslatef(0.0, -(alturaFio/2 + alturaBase/2), 0.0);
    drawCilindro(fatias, alturaFio, 0.5, r, g, b);
    glPopMatrix();

    // Cilindro
    glPushMatrix();
    glTranslatef(0.0, -alturaFio - altura/2 - alturaBase/2, 0.0);
    drawCilindro(fatias, altura, raio, r, g, b);
    glPopMatrix();
}