#include "objects.h"


// /////////////////////
// Glasses
// /////////////////////

// VBO
Object vboMartini(int fatias, float alturaBase, float alturaPe, float alturaCone, float raioBase, float raioPe, float raioCone, Texture texture){
    int nObjects = 5;
    float border = (raioCone*0.2)/5;
    Object copo;

    copo.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

    copo.primitivas[0] = vboConeOpenInv(fatias, fatias/2, alturaCone, raioCone - border, raioPe - border, texture);

    copo.primitivas[1] = vboConeOpen(fatias, fatias/2, alturaCone, raioCone, raioPe, texture);

    copo.primitivas[2] = vboBorder(fatias, alturaCone/2, raioCone, border, texture);

    copo.primitivas[3] = vboCilindro(fatias, fatias/2, alturaPe, raioPe, texture);

    copo.primitivas[4] = vboCilindro(fatias, 1, alturaBase, raioBase, texture);

    copo.size = nObjects;

    return copo;
}

Object vboMesaVidro (float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, Texture texture){

    int nObjects = 8;
    Object mesa;
    mesa.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

    //Tampo
    mesa.primitivas[0] = vboParalelo(altTampo, compTampo, largTampo, texture);

    //Perna
    mesa.primitivas[1] = vboParalelo(altPerna, largPerna, largPerna, texture);

    //Bases
    mesa.primitivas[2] = vboParalelo(altBase, 1.5*largPerna, 1.5*largPerna, texture);
    mesa.primitivas[3] = vboParalelo(altBase, compBase, compBase, texture);

    //Apoios do Tampo
    mesa.primitivas[4] = vboParalelo(altTampo/3, compTampo/2 - largPerna/2 - altTampo/2, altTampo/2, texture);
    mesa.primitivas[5] = vboParalelo(altTampo/3, altTampo/2, largTampo/2 - largPerna/2 - altTampo/2, texture);
    mesa.primitivas[6] = vboParalelo(altTampo/3, altTampo/2, largTampo/3, texture);
    mesa.primitivas[7] = vboParalelo(altTampo/3, compTampo/3, altTampo/2, texture);
    
    return mesa;
}

Object vboCadeiraFashion(float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco, Texture texture) {

    int nObjects = 7;
    Object cadeira;
    cadeira.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

    //Tampo
    cadeira.primitivas[0] = vboParalelo(largTampo, compTampo, altTampo, texture);
    
    //Costas    
    cadeira.primitivas[1] = vboParalelo(altCostas, compTampo, largCostas, texture);

    //Pernas
    cadeira.primitivas[2] = vboParalelo(largPerna, altPerna, largPerna, texture);
    cadeira.primitivas[3] = vboParalelo(largPerna, compTampo, largPerna, texture);
    cadeira.primitivas[4] = vboParalelo(largPerna, largTampo - largPerna*2, largPerna , texture);
    
    //Bracos
    cadeira.primitivas[5] = vboParalelo(altBraco, largPerna, largPerna, texture);
    cadeira.primitivas[6] = vboParalelo(largPerna, largPerna, largTampo - largPerna, texture);
    
    return cadeira;
}

Object vboBar(Texture texture) {

    int nObjects = 15;
    Object bar;
    bar.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

    // Base
    int lBase = 128;
    int cBase = 256;
    int aBase = 2;

    // Parede
    int aParede = 32;


    //Base
    bar.primitivas[0] = vboPlano(lBase, cBase, texture);

    // Chao
    // Tecto
    bar.primitivas[1] = vboParalelo(lBase, cBase/4, aBase, texture);
    bar.primitivas[2] = vboParalelo(lBase/2, 3 * (cBase/4), aBase, texture);

    // Parede Traseira
    bar.primitivas[3] = vboPlano(aParede, cBase, texture);

    // Parede Esquerda   
    // Parede Esquerda (vista do outro lado)  
    bar.primitivas[4] = vboPlano(aParede, lBase, texture);

    //Parede Esq Frente
    //Parede Esq Frente (vista do outro lado)
    //Parede Esq Frente
    //Parede Esq Frente (vista do outro lado)
    //Parede direita
    //Parede direita (vista de dentro)
    bar.primitivas[5]= vboPlano(aParede, cBase/4, texture);

    //Parede frente esplanada
    //Parede frente esplanada (vista do outro lado)
    bar.primitivas[6]= vboPlano(aParede, (6*cBase)/8, texture);

    //2º Andar
    bar.primitivas[7]= vboParalelo(lBase/4, cBase, aBase, texture);

    //Colunas
    bar.primitivas[8] = vboCilindro(3, 2 ,aParede, 1, texture);

    //Protecções do Fundo
    bar.primitivas[9]= vboPlano((cBase/4)-10, aParede/4, texture);

    //Protecção lado direito fundo
    //Protecção lado esquerdo fundo
    //Protecção lado direito frente
    bar.primitivas[10]= vboPlano(lBase/8, aParede/4, texture);

    //Protecção lado esquerdo
    bar.primitivas[11]= vboPlano((3*cBase)/8 -16, aParede/4, texture);

    //Protecção frente
    bar.primitivas[12]= vboPlano((6*cBase)/8 -10, aParede/4, texture);

    //Protecção frente esquerda
    bar.primitivas[13]= vboPlano(cBase/4 -8, aParede/4, texture);

    //Protecção esquerda (lateral direita)
    bar.primitivas[14]= vboPlano((2*cBase)/8 -8, aParede/4, texture);

    return bar;
}

Object vboCandeeiroTeto(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera, Texture texture){
    int nObjects = 3;
    Object candeeiro;

    candeeiro.primitivas = (Primitiva *)malloc(sizeof(struct sPrimitiva)*nObjects);

    // Base
    candeeiro.primitivas[0] = vboCilindro(fatias, gomos, alturaBase, raioBase, texture);

    // Fio
    candeeiro.primitivas[1] = vboCilindro(fatias, gomos, alturaFio, 0.5, texture);

    // Esfera
    candeeiro.primitivas[2] = vboEsfera(raioEsfera, fatias, fatias, texture);

    return candeeiro;
}




// Draw
void drawMartini(Object copo, float alturaCone, float alturaPe, float alturaBase){
    drawVBO(copo.primitivas[0]);

    drawVBO(copo.primitivas[1]);

    drawVBO(copo.primitivas[2]);

    glPushMatrix();
    glTranslatef(0, -alturaCone/2 - alturaPe/2, 0);
    drawVBO(copo.primitivas[3]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -alturaCone/2 - alturaPe , 0);
    drawVBO(copo.primitivas[4]);
    glPopMatrix();
}

void drawMesaVidro (Object mesa, float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase){

    int i;
    float yP;
    float yBP, yBG;
    float xA1, yA, zA1;
    float xA2, zA2;

    //Tampo
    drawVBO(mesa.primitivas[0]);

    //Perna
    yP = altPerna/2 + altTampo/2;

    glPushMatrix();
    glTranslatef(0.0, -yP, 0.0);
    drawVBO(mesa.primitivas[1]);
    glPopMatrix();

    //Bases
    yBP = altPerna + altTampo/2 + altBase/2;

    glPushMatrix();
    glTranslatef(0.0, -yBP, 0.0);   
    drawVBO(mesa.primitivas[2]);
    glPopMatrix();

    yBG = altPerna + altTampo/2 + 1.5*altBase;

    glPushMatrix();
    glTranslatef(0.0, -yBG, 0.0);   
    drawVBO(mesa.primitivas[3]);
    glPopMatrix();

    //Apoios do Tampo
    xA1 = largPerna/2 + (compTampo/2 - largPerna/2 - altTampo/2)/2;
    yA = altTampo/2 + altTampo/6;
    zA1 = largPerna/2 + (largTampo/2 - largPerna/2 - altTampo/2)/2;

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xA1, -yA, 0.0);
        drawVBO(mesa.primitivas[4]);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(0.0, -yA, i*zA1);
        drawVBO(mesa.primitivas[5]);
        glPopMatrix();
    }

    xA2 = largPerna/2 + (compTampo/2 - largPerna/2 - altTampo/2) + altTampo/4;
    zA2 = largPerna/2 + (largTampo/2 - largPerna/2 - altTampo/2) + altTampo/4;

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(i*xA2, -yA, 0.0);
        drawVBO(mesa.primitivas[6]);
        glPopMatrix();
    }

    for (i = -1; i < 2; i+=2) {
        glPushMatrix();
        glTranslatef(0.0, -yA, i*zA2);
        drawVBO(mesa.primitivas[7]);
        glPopMatrix();
    }
}

void drawCadeiraFashion(Object cadeira, float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco) {

    int j;
    float xC, yC, zC;
    float xP, yP, zP;
    float xB, yB, zB;
    float xBr1, yBr1, zBr1;
    float xBr2, yBr2, zBr2;


    //Tampo
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    drawVBO(cadeira.primitivas[0]);
    glPopMatrix();

    xC = 0.0;
    yC = altCostas/2 + altTampo/2;
    zC = largTampo/2 -largCostas/2;

    //Costas
    glPushMatrix();
    glTranslatef(xC, yC, -zC);
    drawVBO(cadeira.primitivas[1]);
    glPopMatrix();

    //Pernas
    xP = compTampo/2 + largPerna/2;
    yP = altPerna/2 -altTampo/2;
    zP = largTampo/2 - largPerna*1.5;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xP, -yP, zP);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        drawVBO(cadeira.primitivas[2]);
        glPopMatrix();
    }

    //Base
    xB = compTampo/2 + largPerna/2;
    yB = altPerna -altTampo/2 -largPerna/2;
    zB = largTampo/2 -largPerna/2 ;

    glPushMatrix();
    glTranslatef(0.0, -yB, -zB);
    drawVBO(cadeira.primitivas[3]);
    glPopMatrix();

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xB, -yB, -largPerna);
        glRotatef(90, 0.0, 1.0, 0.0);
        drawVBO(cadeira.primitivas[4]);
        glPopMatrix();
    }

    //Bracos
    xBr1 = compTampo/2 + largPerna/2;
    yBr1 = altBraco/2 + altTampo/2;
    zBr1 = largTampo/2 - largPerna*1.5;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr1, yBr1, zBr1);
        drawVBO(cadeira.primitivas[5]);
        glPopMatrix();
    }

    xBr2 = compTampo/2 + largPerna/2;
    yBr2 = altBraco + largPerna/2 +altTampo/2;
    zBr2 = largPerna/2;

    for (j = -1; j < 2; j+=2) {
        glPushMatrix();
        glTranslatef(j*xBr2, yBr2, -zBr2);
        drawVBO(cadeira.primitivas[6]);
        glPopMatrix();    
    }
}

void drawBar(Object bar) {

    // Base
    int lBase = 128;
    int cBase = 256;
    int aBase = 2;

    // Parede
    int aParede = 32;

    // Base
    glPushMatrix();
    drawVBO(bar.primitivas[0]);
    glPopMatrix();

    // Chao
    glPushMatrix();
    glTranslatef(-3*(cBase/8), 0, aBase/2);
    drawVBO(bar.primitivas[1]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8, lBase/4, aBase/2);
    drawVBO(bar.primitivas[2]);
    glPopMatrix();

    // Parede Traseira
    glPushMatrix();
    glTranslatef(0, lBase/2, aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    drawVBO(bar.primitivas[3]);
    glPopMatrix();

    // Parede Esquerda
    glPushMatrix();
    glTranslatef(-cBase/2, 0, aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    drawVBO(bar.primitivas[4]);
    glPopMatrix();

    // Parede Esquerda (vista do outro lado) 
    glPushMatrix();
    glTranslatef(-cBase/2, 0, aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 1, 0);
    drawVBO(bar.primitivas[4]);
    glPopMatrix();

    //Parede Esq Frente
    glPushMatrix();
    glTranslatef(-3*(cBase/8), -lBase/2, aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    drawVBO(bar.primitivas[5]);
    glPopMatrix();

    //Parede Esq Frente (vista do outro lado)
    glPushMatrix();
    glTranslatef(-3*(cBase/8), -lBase/2, aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    drawVBO(bar.primitivas[5]);
    glPopMatrix();

    //Parede Esq Frente
    glPushMatrix();
    glTranslatef(-lBase/2,-cBase/8,aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[5]);
    glPopMatrix();

    //Parede Esq Frente (vista do outro lado)
    glPushMatrix();
    glTranslatef(-lBase/2,-cBase/8,aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[5]);
    glPopMatrix();

    //Parede frente esplanada
    glPushMatrix();
    glTranslatef(cBase/8,0,aParede/2 + aBase);
    glRotatef(90, 1, 0, 0);
    drawVBO(bar.primitivas[6]);
    glPopMatrix();

    //Parede frente esplanada (vista do outro lado)
    glPushMatrix();
    glTranslatef(cBase/8,0,aParede/2 + aBase);
    glRotatef(-90, 1, 0, 0);
    drawVBO(bar.primitivas[6]);
    glPopMatrix();

    //Parede direita
    glPushMatrix();
    glTranslatef(cBase/2,lBase/4,aParede/2 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[5]);
    glPopMatrix();

    //Parede direita (vista de dentro)
    glPushMatrix();
    glTranslatef(cBase/2,lBase/4,aParede/2 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[5]);
    glPopMatrix();

    // Tecto
    glPushMatrix();
    glTranslatef(-3*(cBase/8), 0, aParede + aBase);
    drawVBO(bar.primitivas[1]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8, lBase/4, aParede + aBase);
    drawVBO(bar.primitivas[2]);
    glPopMatrix();

    //2º Andar
    glPushMatrix();
    glTranslatef(0, (3*lBase)/8, 2*aParede + aBase);
    drawVBO(bar.primitivas[7]);
    glPopMatrix();


    //Colunas de suporte -> Da direita para a esquerda

    //Coluna fundo 1
    glPushMatrix();
    glTranslatef(cBase/2, (2*lBase)/4, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Coluna frente 1
    glPushMatrix();
    glTranslatef(cBase/2, (2*lBase)/8, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Protecção 1
    glPushMatrix();
    glTranslatef((3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    //Coluna fundo 2
    glPushMatrix();
    glTranslatef(cBase/4, lBase/2, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Coluna frente 2
    glPushMatrix();
    glTranslatef(cBase/4, (2*lBase)/8, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Protecção 2
    glPushMatrix();
    glTranslatef(cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    //Coluna fundo 3
    glPushMatrix();
    glTranslatef(0, lBase/2, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Coluna frente 3
    glPushMatrix();
    glTranslatef(0, (2*lBase)/8, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Protecção 3
    glPushMatrix();
    glTranslatef(-cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    //Coluna fundo 4
    glPushMatrix();
    glTranslatef(-cBase/4, lBase/2, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Coluna frente 4
    glPushMatrix();
    glTranslatef(-cBase/4, (2*lBase)/8, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Protecção 4
    glPushMatrix();
    glTranslatef((-3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((-3*cBase)/8,lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,1,0,0);
    glRotatef(-90,0,0,1);
    drawVBO(bar.primitivas[9]);
    glPopMatrix();

    //Coluna fundo 5
    glPushMatrix();
    glTranslatef(-cBase/2, lBase/2, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Coluna frente 5
    glPushMatrix();
    glTranslatef(-cBase/2, (2*lBase)/8, (3*aParede)/2 + aBase);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[8]);
    glPopMatrix();

    //Protecção lado direito fundo
    glPushMatrix();
    glTranslatef(cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[10]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[10]);
    glPopMatrix();

    //Protecção lado esquerdo fundo
    glPushMatrix();
    glTranslatef(-cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[10]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/2,(3*lBase)/8,(9*aParede)/8 + aBase);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[10]);
    glPopMatrix();

    //Protecção lado direito frente
    glPushMatrix();
    glTranslatef(cBase/2,lBase/8,(9*aParede)/8 + aBase);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[10]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/2,lBase/8,(9*aParede)/8 + aBase);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[10]);
    glPopMatrix();

    //Protecção lado esquerdo
    glPushMatrix();
    glTranslatef(-cBase/2,-lBase/8,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    drawVBO(bar.primitivas[11]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/2,-lBase/8,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,0,1);
    glRotatef(-90,1,0,0);
    drawVBO(bar.primitivas[11]);
    glPopMatrix();

    //Protecção frente
    glPushMatrix();
    glTranslatef(cBase/8,0,(9*aParede)/8 + aBase);
    glRotatef(90,0,0,1);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[12]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cBase/8,0,(9*aParede)/8 + aBase);
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[12]);
    glPopMatrix();

    //Protecção frente esquerda
    glPushMatrix();
    glTranslatef((-3*cBase)/8,-lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,0,0,1);
    glRotatef(90,0,1,0);
    drawVBO(bar.primitivas[13]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((-3*cBase)/8,-lBase/2,(9*aParede)/8 + aBase);
    glRotatef(-90,0,0,1);
    glRotatef(-90,0,1,0);
    drawVBO(bar.primitivas[13]);
    glPopMatrix();

    //Protecção esquerda (lateral direita)
    glPushMatrix();
    glTranslatef(-cBase/4,(-lBase)/4,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glRotatef(-90,0,0,1);
    drawVBO(bar.primitivas[14]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-cBase/4,(-lBase)/4,(9*aParede)/8 + aBase);
    glRotatef(90,1,0,0);
    glRotatef(-90,0,1,0);
    glRotatef(-90,0,0,1);
    drawVBO(bar.primitivas[14]);
    glPopMatrix();
}

void drawCandeeiroTeto(Object candeeiro, int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera) {

    // Base
    drawVBO(candeeiro.primitivas[0]);

    // Fio
    glPushMatrix();
    glTranslatef(0.0, -(alturaFio/2 + alturaBase/2), 0.0);
    drawVBO(candeeiro.primitivas[1]);
    glPopMatrix();

    // Esfera
    glPushMatrix();
    glTranslatef(0.0,-alturaFio - raioEsfera - alturaBase/2, 0.0);
    drawVBO(candeeiro.primitivas[2]);
    glPopMatrix();
}


