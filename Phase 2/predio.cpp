#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"

void drawBar(){
    // Base
    int lBase = 128;
    int cBase = 256;
    int aBase = 2;

    // Parede
    int aParede = 32;

    // drawParalelo(float l, float c, float p, float r, float g, float b)

    // Base
    glPushMatrix();
    drawPlano(lBase, cBase, 1, 1, 0);
    glPopMatrix();

    // Chao
    glPushMatrix();
    glTranslatef(-3*(cBase/8), 0, aBase/2);
    drawParalelo(lBase, cBase/4, aBase, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8, lBase/4, aBase/2);
    drawParalelo(lBase/2, 3 * (cBase/4), aBase, 1, 1, 1);
    glPopMatrix();

    // Parede Traseira
    glPushMatrix();
    glTranslatef(0, lBase/2, aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    drawPlano(aParede, cBase, 1, 0, 0);
    glPopMatrix();

    // Parede Traseira
    //glPushMatrix();
    //glTranslatef(0, lBase/2, aParede/2 + aBase);
    //glRotatef(-90, 1, 0, 0);
    //drawPlano(aParede, cBase, 1, 0, 0);
    //glPopMatrix();

    // Parede Esquerda
    glPushMatrix();
    glTranslatef(-cBase/2, 0, aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    drawPlano(aParede, lBase, 1, 0, 0);
    glPopMatrix();

    // Parede Esquerda
    glPushMatrix();
    glTranslatef(-cBase/2, 0, aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 1, 0);
    drawPlano(aParede, lBase, 1, 0, 0);
    glPopMatrix();

    //Parede Esq Frente
    glPushMatrix();
    glTranslatef(-3*(cBase/8), -lBase/2, aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    drawPlano(aParede, cBase/4, 1, 0, 0);
    glPopMatrix();

    //Parede Esq Frente (vista do outro lado)
    glPushMatrix();
    glTranslatef(-3*(cBase/8), -lBase/2, aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    drawPlano(aParede, cBase/4, 1, 0, 0);
    glPopMatrix();

    //Parede Esq Frente
    glPushMatrix();
    glTranslatef(-lBase/2,-cBase/8,aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    glRotatef(90,0,1,0);
    drawPlano(aParede, cBase/4, 1, 0, 0);
    glPopMatrix();

    //Parede Esq Frente (vista do outro lado)
    glPushMatrix();
    glTranslatef(-lBase/2,-cBase/8,aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90,0,1,0);
    drawPlano(aParede, cBase/4, 1, 0, 0);
    glPopMatrix();

    //Parede frente esplanada
    glPushMatrix();
    glTranslatef(cBase/8,0,aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    drawPlano(aParede, (6*cBase)/8, 1, 0, 0);
    glPopMatrix();

    //Parede frente esplanada (vista do outro lado)
    glPushMatrix();
    glTranslatef(cBase/8,0,aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    drawPlano(aParede, (6*cBase)/8, 1, 0, 0);
    glPopMatrix();

    //Parede direita
    glPushMatrix();
    glTranslatef(cBase/2,lBase/4,aParede/2 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    drawPlano(aParede, cBase/4, 1, 0, 0);
    glPopMatrix();

    //Parede direita (vista de dentro)
    glPushMatrix();
    glTranslatef(cBase/2,lBase/4,aParede/2 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,1,0);
    drawPlano(aParede, cBase/4, 1, 0, 0);
    glPopMatrix();

    // Tecto
    glPushMatrix();
    glTranslatef(-3*(cBase/8), 0, aParede + aBase);
    drawParalelo(lBase, cBase/4, aBase, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8, lBase/4, aParede + aBase);
    drawParalelo(lBase/2, 3 * (cBase/4), aBase, 1, 1, 1);
    glPopMatrix();

    //2º Andar
    glPushMatrix();
    glTranslatef(0, (3*lBase)/8, 2*aParede + aBase);
    drawParalelo(lBase/4, cBase, aBase, 1, 1, 1);
    glPopMatrix();


    //Colunas de suporte -> Da direita para a esquerda

    //Coluna fundo 1
    glPushMatrix();
    glTranslatef(cBase/2, (2*lBase)/4, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Coluna frente 1
    glPushMatrix();
    glTranslatef(cBase/2, (2*lBase)/8, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Protecção 1
    glPushMatrix();
    glTranslatef((3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Coluna fundo 2
    glPushMatrix();
    glTranslatef(cBase/4, lBase/2, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Coluna frente 2
    glPushMatrix();
    glTranslatef(cBase/4, (2*lBase)/8, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Protecção 2
    glPushMatrix();
    glTranslatef(cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Coluna fundo 3
    glPushMatrix();
    glTranslatef(0, lBase/2, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Coluna frente 3
    glPushMatrix();
    glTranslatef(0, (2*lBase)/8, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Protecção 3
    glPushMatrix();
    glTranslatef(-cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Coluna fundo 4
    glPushMatrix();
    glTranslatef(-cBase/4, lBase/2, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Coluna frente 4
    glPushMatrix();
    glTranslatef(-cBase/4, (2*lBase)/8, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Protecção 4
    glPushMatrix();
    glTranslatef((-3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((-3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawPlano((cBase/4)-10, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Coluna fundo 5
    glPushMatrix();
    glTranslatef(-cBase/2, lBase/2, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Coluna frente 5
    glPushMatrix();
    glTranslatef(-cBase/2, (2*lBase)/8, (3*aParede)/2 + aBase);
    //void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    glRotatef(90,1,0,0);
    drawCilindro(3,aParede,1,0,1,0);
    glPopMatrix();

    //Protecção lado direito fundo
    glPushMatrix();
    glTranslatef(cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(-90,0,1,0);
    drawPlano(lBase/8, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(90,0,1,0);
    drawPlano(lBase/8, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Protecção lado esquerdo fundo
    glPushMatrix();
    glTranslatef(-cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(-90,0,1,0);
    drawPlano(lBase/8, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(90,0,1,0);
    drawPlano(lBase/8, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Protecção lado direito frente
    glPushMatrix();
    glTranslatef(cBase/2,lBase/8,(9*aParede)/8 + aBase);
    glRotatef(-90,0,1,0);
    drawPlano(lBase/8, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/2,lBase/8,(9*aParede)/8 + aBase);
    glRotatef(90,0,1,0);
    drawPlano(lBase/8, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Protecção lado esquerdo
    glPushMatrix();
    glTranslatef(-cBase/2,-lBase/8,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    drawPlano((3*cBase)/8 -16, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/2,-lBase/8,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    glRotatef(-90,1,0,0);
    drawPlano((3*cBase)/8 -16, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Protecção frente
    glPushMatrix();
    glTranslatef(cBase/8,0,(9*aParede)/8 + aBase);
    glRotatef(90,0,0,1);
    glRotatef(-90,0,1,0);
    drawPlano((6*cBase)/8 -10, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8,0,(9*aParede)/8 + aBase);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
    drawPlano((6*cBase)/8 -10, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Protecção frente esquerda
    glPushMatrix();
    glTranslatef((-3*cBase)/8,-lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,0,0,1);
    glRotatef(90,0,1,0);
    drawPlano(cBase/4 -8, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((-3*cBase)/8,-lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,0,0,1);
    glRotatef(-90,0,1,0);
    drawPlano(cBase/4 -8, aParede/4, 0, 0, 1);
    glPopMatrix();

    //Protecção esquerda (lateral direita)
    glPushMatrix();
    glTranslatef(-cBase/4,(-lBase)/4,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glRotatef(-90,0,0,1);
    drawPlano((2*cBase)/8 -8, aParede/4, 0, 0, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/4,(-lBase)/4,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(-90,0,1,0);
    glRotatef(-90,0,0,1);
    drawPlano((2*cBase)/8 -8, aParede/4, 0, 0, 1);
    glPopMatrix();
}
