#include <GL/glew.h>
#include <GL/glut.h>
#include <IL/il.h>

#include <math.h>

// Temp
#include <stdio.h>


// //////////
// Structs
// //////////
typedef struct sVertex {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Vertex;

typedef struct sTexture{
    GLuint textudeID;
    unsigned int width;
    unsigned int height;
} Texture;

typedef struct sPrimitiva {
    int nVertices;
    int nIndex;
    GLuint vertexB;
    GLuint normalB;
    GLuint indexB;
    GLuint textureB;
} Primitiva;

// ///////////////////
// Primitivas Puras
// ///////////////////
Primitiva vboPlano(float l,float c, Texture texture);
Primitiva vboParalelo(float l, float c, float p, Texture texture);
Primitiva vboCilindro(float fatias, float gomos, float altura,float raio, Texture texture);
Primitiva vboCone(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture);
Primitiva vboTorus(float fatias, float raioI, float raioO, Texture texture);
Primitiva vboEsfera(float fatias, float gomos, float raio, Texture texture);

// ///////////////////////
// Primitivas Auxiliares
// ///////////////////////
Primitiva vboBorder(float fatias, float altura, float raio, float border, Texture texture);
Primitiva vboEsferaCopo(float fatias, float gomos,float raio, Texture texture);
Primitiva vboConeOpen(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture);
Primitiva vboConeOpenInv(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture);
Primitiva vboCilindroOpenInv(float fatias, float gomos, float altura,float raio, Texture texture);
Primitiva vboCilindroOpen(float fatias, float gomos, float altura,float raio, Texture texture);

// ///////////////////
// Draw Func
// ///////////////////
void drawVBO(Primitiva p);

// ///////////////////
// Func Aux
// ///////////////////
Vertex crossProduct(Vertex v1, Vertex v2, Vertex v3);
Texture getTexture(const char *fileName );
void drawNormals(Vertex v, float x , float y, float z);