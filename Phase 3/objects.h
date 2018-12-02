#include <GL/glew.h>
#include <GL/glut.h>
#include <math.h>

#include "vbo.h"

// //////////
// Structs
// //////////
typedef struct sObject {
    Primitiva *primitivas;
    int size;
} Object;



// /////////////////////
// Glasses
// /////////////////////

// vbo
Object vboMartini(int fatias, float alturaBase, float alturaPe, float alturaCone, float raioBase, float raioPe, float raioCone, Texture texture);
Object vboMesaVidro (float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase, Texture texture);
Object vboCadeiraFashion(float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco, Texture texture);
Object vboBar(Texture texture);
Object vboCandeeiroTeto(int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera, Texture texture);


// draw
void drawMartini(Object copo, float alturaCone, float alturaPe, float alturaBase);
void drawMesaVidro (Object mesa, float compTampo, float largTampo, float altTampo, float altPerna, float largPerna, float compBase, float altBase);
void drawCadeiraFashion(Object cadeira, float compTampo, float largTampo, float altTampo, float altCostas, float largCostas, float altPerna, float largPerna, float altBraco);
void drawBar(Object bar);
void drawCandeeiroTeto(Object candeeiro, int fatias, int gomos, float alturaFio, float alturaBase, float raioBase, float raioEsfera);