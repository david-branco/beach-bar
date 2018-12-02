#include "vbo.h"

// ///////////////////
// Primitivas Puras
// ///////////////////

// Plano
Primitiva vboPlano(float l,float c, Texture texture){
    int nIndex = 6;
    int nVertex = 4 * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva plano;
    int v = -1, i = -1, n = -1, t = -1, indice = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);

    // Plano
    GLfloat x = c/2;
    GLfloat y = l/2;

    int first, last;

    vertexB[++v] = -x;    vertexB[++v] = -y;    vertexB[++v] = 0;
    vertexB[++v] = x;    vertexB[++v] = -y;    vertexB[++v] = 0;
    vertexB[++v] = x;    vertexB[++v] = y;    vertexB[++v] = 0;

    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;

    indexB[++i] = ++indice;
    first = indice;
    indexB[++i] = ++indice;    
    indexB[++i] = ++indice;
    last = indice;

    textureB[++t] = 0;    textureB[++t] = 0;
    textureB[++t] = 1;    textureB[++t] = 0;
    textureB[++t] = 1;    textureB[++t] = 1;

    
    vertexB[++v] = -x;    vertexB[++v] = y;    vertexB[++v] = 0;

    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;

    indexB[++i] = first;
    indexB[++i] = last;
    indexB[++i] = ++indice;

    textureB[++t] = 0;    textureB[++t] = 1;

    plano.nVertices = nVertex;
    plano.nIndex = nIndex;
    plano.textureID = texture.textureID;

    glGenBuffers(1, &plano.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, plano.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &plano.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, plano.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &plano.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, plano.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &plano.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, plano.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return plano;
}

Primitiva vboFloor(float l,float c, Texture texture, int freq){
    int nIndex = 6;
    int nVertex = 4 * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva plano;
    int v = -1, i = -1, n = -1, t = -1, indice = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);

    // Plano
    GLfloat x = c/2;
    GLfloat y = l/2;

    int first, last;

    vertexB[++v] = -x;    vertexB[++v] = -y;    vertexB[++v] = 0;
    vertexB[++v] = x;    vertexB[++v] = -y;    vertexB[++v] = 0;
    vertexB[++v] = x;    vertexB[++v] = y;    vertexB[++v] = 0;

    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;

    indexB[++i] = ++indice;
    first = indice;
    indexB[++i] = ++indice;    
    indexB[++i] = ++indice;
    last = indice;

    textureB[++t] = 0;    textureB[++t] = 0;
    textureB[++t] = freq;    textureB[++t] = 0;
    textureB[++t] = freq;    textureB[++t] = freq;

    
    vertexB[++v] = -x;    vertexB[++v] = y;    vertexB[++v] = 0;

    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;

    indexB[++i] = first;
    indexB[++i] = last;
    indexB[++i] = ++indice;

    textureB[++t] = 0;    textureB[++t] = freq;

    plano.nVertices = nVertex;
    plano.nIndex = nIndex;
    plano.textureID = texture.textureID;

    glGenBuffers(1, &plano.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, plano.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &plano.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, plano.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &plano.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, plano.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &plano.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, plano.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return plano;
}

// Paralelo
Primitiva vboParalelo(float l, float c, float p, Texture texture) {
    int nIndex = 36;
    int nVertex = 24 * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    int v = -1, i = -1, n = -1, t = -1, indice = -1;

    GLuint *indexB;
    GLfloat *vertexB;
    GLfloat *normalB;
    GLfloat *textureB;

    Primitiva paralelo;    

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);

    // Vertices
    GLfloat x = c/2;
    GLfloat y = l/2;
    GLfloat z = p/2;

    int first, last;

    // Front
    vertexB[++v] = -x;  vertexB[++v] = -y;  vertexB[++v] = z;
    vertexB[++v] = x;  vertexB[++v] = -y;  vertexB[++v] = z;
    vertexB[++v] = x;  vertexB[++v] = y;  vertexB[++v] = z;

    indexB[++i] = ++indice;
    first = indice;
    indexB[++i] = ++indice;
    indexB[++i] = ++indice;
    last = indice;

    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = 1;
    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = 1;
    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = 1;

    textureB[++t] = 0;  textureB[++t] = 0;
    textureB[++t] = 1;  textureB[++t] = 0;
    textureB[++t] = 1;  textureB[++t] = 1;

    vertexB[++v] = -x;  vertexB[++v] = y;  vertexB[++v] = z;

    indexB[++i] = first;
    indexB[++i] = last;
    indexB[++i] = ++indice;

    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = 1;

    textureB[++t] = 0;  textureB[++t] = 1;

    // Back
    vertexB[++v] = -x;  vertexB[++v] = -y;  vertexB[++v] = -z;
    vertexB[++v] = -x;  vertexB[++v] = y;  vertexB[++v] = -z;
    vertexB[++v] = x;  vertexB[++v] = -y;  vertexB[++v] = -z;

    indexB[++i] = ++indice;
    indexB[++i] = ++indice;
    first = indice;
    indexB[++i] = ++indice;
    last = indice;

    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = -1;
    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = -1;
    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = -1;

    textureB[++t] = 0;  textureB[++t] = 0;
    textureB[++t] = 0;  textureB[++t] = 1;
    textureB[++t] = 1;  textureB[++t] = 0;

    vertexB[++v] = x;  vertexB[++v] = y;  vertexB[++v] = -z;

    indexB[++i] = first;
    indexB[++i] = ++indice;
    indexB[++i] = last;

    normalB[++n] = 0;   normalB[++n] = 0;   normalB[++n] = -1;

    textureB[++t] = 1;  textureB[++t] = 1;

    // Left
    vertexB[++v] = -x;  vertexB[++v] = -y;  vertexB[++v] = z;
    vertexB[++v] = -x;  vertexB[++v] = y;  vertexB[++v] = z;
    vertexB[++v] = -x;  vertexB[++v] = -y;  vertexB[++v] = -z;

    indexB[++i] = ++indice;
    indexB[++i] = ++indice;
    first = indice;
    indexB[++i] = ++indice;
    last = indice;

    normalB[++n] = -1;   normalB[++n] = 0;   normalB[++n] = 0;
    normalB[++n] = -1;   normalB[++n] = 0;   normalB[++n] = 0;
    normalB[++n] = -1;   normalB[++n] = 0;   normalB[++n] = 0;

    textureB[++t] = 0;  textureB[++t] = 0;
    textureB[++t] = 0;  textureB[++t] = 1;
    textureB[++t] = 1;  textureB[++t] = 0;

    vertexB[++v] = -x;  vertexB[++v] = y;  vertexB[++v] = -z;

    indexB[++i] = first;
    indexB[++i] = ++indice;
    indexB[++i] = last;

    normalB[++n] = -1;   normalB[++n] = 0;   normalB[++n] = 0;
    textureB[++t] = 1;  textureB[++t] = 1;

    // Right
    vertexB[++v] = x;  vertexB[++v] = -y;  vertexB[++v] = z;
    vertexB[++v] = x;  vertexB[++v] = -y;  vertexB[++v] = -z;
    vertexB[++v] = x;  vertexB[++v] = y;  vertexB[++v] = z;

    indexB[++i] = ++indice;
    indexB[++i] = ++indice;
    first = indice;
    indexB[++i] = ++indice;
    last = indice;

    normalB[++n] = 1;   normalB[++n] = 0;   normalB[++n] = 0;
    normalB[++n] = 1;   normalB[++n] = 0;   normalB[++n] = 0;
    normalB[++n] = 1;   normalB[++n] = 0;   normalB[++n] = 0;

    textureB[++t] = 0;  textureB[++t] = 0;
    textureB[++t] = 1;  textureB[++t] = 0;
    textureB[++t] = 0;  textureB[++t] = 1;

    vertexB[++v] = x;  vertexB[++v] = y;  vertexB[++v] = -z;

    indexB[++i] = first;
    indexB[++i] = ++indice;
    indexB[++i] = last;

    normalB[++n] = 1;   normalB[++n] = 0;   normalB[++n] = 0;
    textureB[++t] = 1;  textureB[++t] = 1;

    // Top
    vertexB[++v] = -x;  vertexB[++v] = y;  vertexB[++v] = z;
    vertexB[++v] = x;  vertexB[++v] = y;  vertexB[++v] = z;
    vertexB[++v] = -x;  vertexB[++v] = y;  vertexB[++v] = -z;

    indexB[++i] = ++indice;
    indexB[++i] = ++indice;
    last = indice;
    indexB[++i] = ++indice;
    first = indice;

    normalB[++n] = 0;   normalB[++n] = 1;   normalB[++n] = 0;
    normalB[++n] = 0;   normalB[++n] = 1;   normalB[++n] = 0;
    normalB[++n] = 0;   normalB[++n] = 1;   normalB[++n] = 0;

    textureB[++t] = 0;  textureB[++t] = 0;
    textureB[++t] = 1;  textureB[++t] = 0;
    textureB[++t] = 0;  textureB[++t] = 1;

    vertexB[++v] = x;  vertexB[++v] = y;  vertexB[++v] = -z;

    indexB[++i] = first;
    indexB[++i] = last;
    indexB[++i] = ++indice;

    normalB[++n] = 0;   normalB[++n] = 1;   normalB[++n] = 0;
    textureB[++t] = 1;  textureB[++t] = 1;

    // Bottom
    vertexB[++v] = -x;  vertexB[++v] = -y;  vertexB[++v] = z;
    vertexB[++v] = -x;  vertexB[++v] = -y;  vertexB[++v] = -z;
    vertexB[++v] = x;  vertexB[++v] = -y;  vertexB[++v] = z;

    indexB[++i] = ++indice;
    indexB[++i] = ++indice;
    last = indice;
    indexB[++i] = ++indice;
    first = indice;

    normalB[++n] = 0;   normalB[++n] = -1;   normalB[++n] = 0;
    normalB[++n] = 0;   normalB[++n] = -1;   normalB[++n] = 0;
    normalB[++n] = 0;   normalB[++n] = -1;   normalB[++n] = 0;

    textureB[++t] = 0;  textureB[++t] = 0;
    textureB[++t] = 0;  textureB[++t] = 1;
    textureB[++t] = 1;  textureB[++t] = 0;

    vertexB[++v] = x;  vertexB[++v] = -y;  vertexB[++v] = -z;

    indexB[++i] = first;
    indexB[++i] = last;
    indexB[++i] = ++indice;

    normalB[++n] = 0;   normalB[++n] = -1;   normalB[++n] = 0;
    textureB[++t] = 1;  textureB[++t] = 1;

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    paralelo.nVertices = nVertex;
    paralelo.nIndex = nIndex;
    paralelo.textureID = texture.textureID;

    glGenBuffers(1, &paralelo.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, paralelo.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &paralelo.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, paralelo.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &paralelo.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, paralelo.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &paralelo.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, paralelo.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return paralelo;
}

// Cilindro
Primitiva vboCilindro(float fatias, float gomos, float altura,float raio, Texture texture){
    int nIndex = (fatias * 3) * 2 + (fatias * 6) * gomos;
    int nVertex = ((3 + fatias * 3 + 3) * 2) + ((4+2*(gomos-1)) + (2+(gomos-1))*(fatias-1))*3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    int* backupLine;

    Primitiva cilindro;
    int v = -1, i = -1, n = -1, t = -1;
    int indice = -1, b = -1, c = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);
    backupLine = (int *)malloc(sizeof(int)*gomos*2);

    const float DEG2RAD = 3.14159/180;
    
    float angulo = 360 / fatias;
    float half = altura/2, alturaT = altura/gomos;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    float angRad = angulo*DEG2RAD;

    int iCenterUp, iCircleUp;
    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Top
            vertexB[++v] = 0;        vertexB[++v] = half;    vertexB[++v] = 0;
            indexB[++i] = ++indice;
            iCenterUp = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raio*sin(fRad);        vertexB[++v] = half;    vertexB[++v] = raio*cos(fRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            vertexB[++v] = 0;        vertexB[++v] = -half;    vertexB[++v] = 0;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = raio*sin(fRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad);
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);   normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }

                // Inc Texture of the side
                texG += incG;
            }
        } else {
            // Top
            indexB[++i] = iCenterUp;

            indexB[++i] = iCircleUp;

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            indexB[++i] = iCenterBottom;

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            indexB[++i] = iCircleBottom;

            iCircleBottom = indice;

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] =  cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }
                texG += incG;
            }
        }
        texG = 0;
        texF += incF;
        b = -1;
        c = -1;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    cilindro.nVertices = nVertex;
    cilindro.nIndex = nIndex;
    cilindro.textureID = texture.textureID;

    glGenBuffers(1, &cilindro.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cilindro.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return cilindro;
}

// Cone
Primitiva vboCone(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture){
    int nIndex = (fatias * 3) * 2 + (fatias * 6) * gomos;
    int nVertex = ((3 + fatias * 3 + 3) * 2) + ((4+2*(gomos-1)) + (2+(gomos-1))*(fatias-1))*3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    int* backupLine;

    Primitiva cilindro;
    int v = -1, i = -1, n = -1, t = -1;
    int indice = -1, b = -1, c = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);
    backupLine = (int *)malloc(sizeof(int)*gomos*2);

    const float DEG2RAD = 3.14159/180;
    
    float angulo = 360 / fatias;
    float half = altura/2, alturaT = altura/gomos;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;
    float raioIt = (raioBase-raioTop)/gomos;

    float angRad = angulo*DEG2RAD;

    int iCenterUp, iCircleUp;
    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Top
            vertexB[++v] = 0.0;        vertexB[++v] = half;    vertexB[++v] = 0.0;
            indexB[++i] = ++indice;
            iCenterUp = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raioTop*sin(fRad);        vertexB[++v] = half;    vertexB[++v] = raioTop*cos(fRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = raioTop*sin(fRad+angRad);        vertexB[++v] = half;    vertexB[++v] = raioTop*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            vertexB[++v] = 0.0;        vertexB[++v] = -half;    vertexB[++v] = 0.0;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raioBase*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = raioBase*sin(fRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad);
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = (raio+raioIt)*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] =  g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] =  (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }

                raio += raioIt;
                texG += incG;
            }
        } else {
            // Top

            indexB[++i] = iCenterUp;

            indexB[++i] = iCircleUp;

            vertexB[++v] = raioTop*sin(fRad+angRad);        vertexB[++v] = half;    vertexB[++v] = raioTop*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            indexB[++i] = iCenterBottom;

            vertexB[++v] =  raioBase*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad+angRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            indexB[++i] = iCircleBottom;

            iCircleBottom = indice;

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] =sin(fRad+angRad);         normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }
                raio += raioIt;
                texG += incG;
            }
        }
        texG = 0;
        texF += incF;
        b = -1;
        c = -1;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    cilindro.nVertices = nVertex;
    cilindro.nIndex = nIndex;
    cilindro.textureID = texture.textureID;

    glGenBuffers(1, &cilindro.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cilindro.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return cilindro;
}

// Torus
Primitiva vboTorus(float fatias, float raioI, float raioO, Texture texture){
    int nIndex = 6 * fatias * fatias;
    int nVertex = ((4 + 2*(fatias-1)) +  ((2 + (fatias-1)) * (fatias-1))) * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva torus;
    int i = -1, j = -1, k = -1, indice = -1, f = -1, h = -1, t = -1, counter = 0, counter2 = 0;
    int *lastLine;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLfloat)*nTexture);
    lastLine = (int *)malloc(sizeof(int)*fatias*2);

    float angulo = (2 * M_PI) / fatias;

    int first, last, one, two;
    float incG = 1/fatias, incF = 1/fatias, texG = 0, texF = 0;

    for(float inc=0; counter < fatias && inc < (2*M_PI); inc = inc + angulo) {
        f = 0; h = 0;
        if(inc == 0){   // Primeira vez, cria o array
            for(float l=0; counter2 < fatias && l < (2*M_PI); l = l + angulo){
                if(l == 0){
                    vertexB[++i] = cos(inc)*(cos(l) * raioI + raioO);        vertexB[++i] = sin(inc)*(cos(l) * raioI + raioO);    vertexB[++i] = sin(l)*raioI;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = cos(inc+angulo)*(cos(l) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l) * raioI + raioO);    vertexB[++i] = sin(l)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    lastLine[++f] = last;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;

                    vertexB[++i] =  cos(inc)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    normalB[++j] = cos(inc)*cos(l);        normalB[++j] = sin(inc)*(cos(l));    normalB[++j] = sin(l);
                    normalB[++j] = cos(inc+angulo)*cos(l);        normalB[++j] = sin(inc+angulo)*cos(l);    normalB[++j] = sin(l);
                    normalB[++j] = cos(inc)*cos(l+angulo);        normalB[++j] = sin(inc)*cos(l+angulo);    normalB[++j] = sin(l+angulo);


                    indexB[++k] = last;

                    vertexB[++i] =cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] =  sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                } else {
                    indexB[++k] = first;

                    indexB[++k] = last;
                    last = indice;

                    vertexB[++i] = cos(inc)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;


                    normalB[++j] = cos(inc)*cos(l+angulo);        normalB[++j] = sin(inc)*cos(l+angulo);    normalB[++j] = sin(l+angulo);


                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] =cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                }
                counter2++;
                texF += incF;
            }
            counter2 = 0;
        } else {        // Usa o array        
            for(float l=0; counter2 < fatias && l < (2*M_PI); l = l + angulo){
                one = lastLine[++h];
                two = lastLine[++h];
                if(l == 0){
                    indexB[++k] = one;

                    vertexB[++i] = cos(inc+angulo)*(cos(l) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l) * raioI + raioO);    vertexB[++i] =  sin(l)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = two;
                    first = two;

                    normalB[++j] = cos(inc+angulo)*cos(l);        normalB[++j] = sin(inc+angulo)*cos(l);    normalB[++j] = sin(l);


                    indexB[++k] = last;

                    vertexB[++i] = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] =  cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] =  sin(l+angulo);
                } else {

                    indexB[++k] = one;

                    indexB[++k] = last;
                    last = indice;

                    indexB[++k] = two;
                    first = two;


                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                }
                counter2++;
                texF += incF;
            }
            counter2 = 0;
        }
        counter++;
        texF = 0;
        texG += incG;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,i,nIndex,k);

    torus.nVertices = nVertex;
    torus.nIndex = nIndex;
    torus.textureID = texture.textureID;

    glGenBuffers(1, &torus.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, torus.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &torus.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, torus.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &torus.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, torus.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &torus.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, torus.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);
    free(lastLine);

    return torus;
}

// Esfera
Primitiva vboEsfera(float fatias, float gomos,float raio, Texture texture){
    int nIndex = 6* fatias * gomos;
    int nVertex = ((4 + 2*(gomos-1)) +  ((2 + (gomos-1)) * (fatias-1))) * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva esfera;
    int i = -1, j = -1, k = -1, indice = -1, h = -1, f = -1, t = -1;
    int *lastLine;
    raio = raio/2;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLfloat)*nTexture);
    lastLine = (int *)malloc(sizeof(int)*gomos*2);
    
    float alpha = M_PI / fatias;
    float beta = (2 * M_PI) / gomos;

    int flag = 0, first, last, one, two;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    for(float ai = -(M_PI/2); ai < M_PI/2; ai += alpha){
        f = 0; h = 0;
        if(flag == 0 ){
            flag = 1;
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                if(bi == 0){
                    vertexB[++i] = raio * cos(ai) * sin(bi);        vertexB[++i] =  raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF + incF;           textureB[++t] = texG;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    normalB[++j] = cos(ai) * sin(bi);               normalB[++j] = sin(ai);             normalB[++j] = cos(ai) * cos(bi);
                    normalB[++j] = cos(ai) * sin(bi + beta);        normalB[++j] = sin(ai);             normalB[++j] = cos(ai) * cos(bi + beta);
                    normalB[++j] = cos(ai + alpha) * sin(bi);       normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi);


                    indexB[++k] = first;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                } else {

                    indexB[++k] = first;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    normalB[++j] = cos(ai) * sin(bi + beta);        normalB[++j] = sin(ai);    normalB[++j] = cos(ai) * cos(bi + beta);
                    

                    indexB[++k] = first;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        } else {
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                one = lastLine[++h];
                two = lastLine[++h];
                if(bi == 0){

                    indexB[++k] = one;

                    indexB[++k] = two;
                    first = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi);


                    indexB[++k] = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                } else {
                    indexB[++k] = one;

                    indexB[++k] = two;
                    first = two;

                    indexB[++k] = last;
                    lastLine[++f] = last;


                    indexB[++k] = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] =  raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    lastLine[++f] = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        }
        texF = 0;
        texG += incG;
    }

    // printf("%d -> %d,%d ->%d, %d -> %d\n",nVertex,i,nIndex,k, nNormal, j);

    esfera.nVertices = nVertex;
    esfera.nIndex = nIndex;
    esfera.textureID = texture.textureID;

    glGenBuffers(1, &esfera.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esfera.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);
    free(lastLine);

    return esfera;
}

Primitiva vboTriangulo(float scale, Texture texture) {

    int nIndex = 6;
    int nVertex = 3 * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva triangulo;
    int v = -1, i = -1, n = -1, t = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);


    //Face Frente
    vertexB[++v] = -scale;    vertexB[++v] = 0;           vertexB[++v] = 0;
    vertexB[++v] = scale;     vertexB[++v] = 0;           vertexB[++v] = 0;
    vertexB[++v] = 0;         vertexB[++v] = 2*scale;     vertexB[++v] = 0;

    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = 1;

    indexB[++i] = 0;
    indexB[++i] = 1;
    indexB[++i] = 2;

    textureB[++t] = 0;      textureB[++t] = 0;
    textureB[++t] = 1;      textureB[++t] = 0;
    textureB[++t] = 0.5;    textureB[++t] = 1;

    //Face Tras
    indexB[++i] = 0;
    indexB[++i] = 2;
    indexB[++i] = 1;

    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = -1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = -1;
    normalB[++n] = 0;    normalB[++n] = 0;    normalB[++n] = -1;

    textureB[++t] = 0;      textureB[++t] = 0;
    textureB[++t] = 0.5;    textureB[++t] = 1;
    textureB[++t] = 1;      textureB[++t] = 0;

    triangulo.nVertices = nVertex;
    triangulo.nIndex = nIndex;
    triangulo.textureID = texture.textureID;

    glGenBuffers(1, &triangulo.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, triangulo.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &triangulo.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, triangulo.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &triangulo.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, triangulo.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &triangulo.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, triangulo.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return triangulo;
}

// ///////////////////////
// Primitivas Auxiliares
// ///////////////////////

Primitiva vboCilindroOpen(float fatias, float gomos, float altura,float raio, Texture texture){
    int nIndex = (fatias * 3) + (fatias * 6) * gomos;
    int nVertex = (3 + fatias * 3 + 3) + ((4+2*(gomos-1)) + (2+(gomos-1))*(fatias-1))*3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    int* backupLine;

    Primitiva cilindro;
    int v = -1, i = -1, n = -1, t = -1;
    int indice = -1, b = -1, c = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);
    backupLine = (int *)malloc(sizeof(int)*gomos*2);

    const float DEG2RAD = 3.14159/180;
    
    float angulo = 360 / fatias;
    float half = altura/2, alturaT = altura/gomos;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            vertexB[++v] = 0.0;        vertexB[++v] = -half;    vertexB[++v] = 0.0;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = raio*sin(fRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad);
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);   normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }

                // Inc Texture of the side
                texG += incG;
            }
        } else {
            // Bottom
            indexB[++i] = iCenterBottom;

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            indexB[++i] = iCircleBottom;

            iCircleBottom = indice;

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);



                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] =  cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }
                texG += incG;
            }
        }
        texG = 0;
        texF += incF;
        b = -1;
        c = -1;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    cilindro.nVertices = nVertex;
    cilindro.nIndex = nIndex;
    cilindro.textureID = texture.textureID;

    glGenBuffers(1, &cilindro.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cilindro.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return cilindro;
}

Primitiva vboCilindroOpenInv(float fatias, float gomos, float altura,float raio, Texture texture){
    int nIndex = (fatias * 3) + (fatias * 6) * gomos;
    int nVertex = (3 + fatias * 3 + 3) + ((4+2*(gomos-1)) + (2+(gomos-1))*(fatias-1))*3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    int* backupLine;

    Primitiva cilindro;
    int v = -1, i = -1, n = -1, t = -1;
    int indice = -1, b = -1, c = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);
    backupLine = (int *)malloc(sizeof(int)*gomos*2);

    const float DEG2RAD = 3.14159/180;
    
    float angulo = 360 / fatias;
    float half = altura/2, alturaT = altura/gomos;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            vertexB[++v] = 0.0;        vertexB[++v] = -half;    vertexB[++v] = 0.0;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raio*sin(fRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad);
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    normalB[++n] = sin(fRad+angRad);   normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;  
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;
                    iSideFirst = indice;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    indexB[++i] = iSideLast;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }

                // Inc Texture of the side
                texG += incG;
            }
        } else {
            // Bottom
            indexB[++i] = iCenterBottom;

            indexB[++i] = iCircleBottom;

            vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raio*cos(fRad+angRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            iCircleBottom = indice;

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    indexB[++i] = iBackFirst;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    indexB[++i] = iSideLast;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] =  cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;

                    indexB[++i] = iBackFirst;


                    indexB[++i] = iSideLast;

                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }
                texG += incG;
            }
        }
        texG = 0;
        texF += incF;
        b = -1;
        c = -1;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    cilindro.nVertices = nVertex;
    cilindro.nIndex = nIndex;
    cilindro.textureID = texture.textureID;

    glGenBuffers(1, &cilindro.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cilindro.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cilindro.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, cilindro.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return cilindro;
}

Primitiva vboConeOpen(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture){
    int nIndex = (fatias * 3) + (fatias * 6) * gomos;
    int nVertex = (3 + fatias * 3 + 3) + ((4+2*(gomos-1)) + (2+(gomos-1))*(fatias-1))*3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    int* backupLine;

    Primitiva cone;
    int v = -1, i = -1, n = -1, t = -1;
    int indice = -1, b = -1, c = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);
    backupLine = (int *)malloc(sizeof(int)*gomos*2);

    const float DEG2RAD = 3.14159/180;
    
    float angulo = 360 / fatias;
    float half = altura/2, alturaT = altura/gomos;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;
    float raioIt = (raioBase-raioTop)/gomos;

    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            vertexB[++v] =0.0;        vertexB[++v] = -half;    vertexB[++v] = 0.0;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raioBase*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = raioBase*sin(fRad);        vertexB[++v] =  -half;    vertexB[++v] = raioBase*cos(fRad);
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    vertexB[++v] =raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] =  raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = (raio+raioIt)*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] =  g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }

                raio += raioIt;
                texG += incG;
            }
        } else {
            // Bottom
            indexB[++i] = iCenterBottom;

            vertexB[++v] = raioBase*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad+angRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            indexB[++i] = iCircleBottom;

            iCircleBottom = indice;

            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] =sin(fRad+angRad);         normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] =  (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] =  g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                }
                raio += raioIt;
                texG += incG;
            }
        }
        texG = 0;
        texF += incF;
        b = -1;
        c = -1;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    cone.nVertices = nVertex;
    cone.nIndex = nIndex;
    cone.textureID = texture.textureID;

    glGenBuffers(1, &cone.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, cone.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cone.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, cone.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cone.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cone.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cone.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, cone.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return cone;
}

Primitiva vboConeOpenInv(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture){
    int nIndex = (fatias * 3) + (fatias * 6) * gomos;
    int nVertex = (3 + fatias * 3 + 3) + ((4+2*(gomos-1)) + (2+(gomos-1))*(fatias-1))*3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    int* backupLine;

    Primitiva cone;
    int v = -1, i = -1, n = -1, t = -1;
    int indice = -1, b = -1, c = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);
    backupLine = (int *)malloc(sizeof(int)*gomos*2);

    const float DEG2RAD = 3.14159/180;
    
    float angulo = 360 / fatias;
    float half = altura/2, alturaT = altura/gomos;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;
    float raioIt = (raioBase-raioTop)/gomos;

    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            vertexB[++v] =0.0;        vertexB[++v] = -half;    vertexB[++v] = 0.0;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = raioBase*sin(fRad);        vertexB[++v] =  -half;    vertexB[++v] = raioBase*cos(fRad);
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vertexB[++v] = raioBase*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad+angRad);
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    vertexB[++v] =raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] =  raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = (raio+raioIt)*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad);
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    vertexB[++v] = raio*sin(fRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad);
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    normalB[++n] = -sin(fRad+angRad); normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);
                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);


                    indexB[++i] = iSideLast;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = -sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    vertexB[++v] = (raio+raioIt)*sin(fRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad);
                    indexB[++i] = ++indice;  
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    iSideFirst = indice;

                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);


                    indexB[++i] = iSideLast;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] =  g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = -sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                }

                raio += raioIt;
                texG += incG;
            }
        } else {
            // Bottom
            indexB[++i] = iCenterBottom;

            indexB[++i] = iCircleBottom;

            vertexB[++v] = raioBase*sin(fRad+angRad);        vertexB[++v] = -half;    vertexB[++v] = raioBase*cos(fRad+angRad);
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            iCircleBottom = indice;

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    vertexB[++v] = raio*sin(fRad+angRad);        vertexB[++v] = g;    vertexB[++v] = raio*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    indexB[++i] = iBackFirst;

                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);


                    indexB[++i] = iSideLast;

                    vertexB[++v] = (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] = g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = -sin(fRad+angRad);         normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                } else {
                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;

                    indexB[++i] = iBackFirst;



                    indexB[++i] = iSideLast;

                    vertexB[++v] =  (raio+raioIt)*sin(fRad+angRad);        vertexB[++v] =  g-alturaT;    vertexB[++v] = (raio+raioIt)*cos(fRad+angRad);
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = -sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                }
                raio += raioIt;
                texG += incG;
            }
        }
        texG = 0;
        texF += incF;
        b = -1;
        c = -1;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,v,nIndex,i);

    cone.nVertices = nVertex;
    cone.nIndex = nIndex;
    cone.textureID = texture.textureID;

    glGenBuffers(1, &cone.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, cone.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cone.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, cone.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cone.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cone.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &cone.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, cone.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return cone;
}

Primitiva vboEsferaCopo(float fatias, float gomos,float raio, Texture texture){
    int nIndex = 6* fatias * gomos;
    int nVertex = ((4 + 2*(gomos-1)) +  ((2 + (gomos-1)) * (fatias-1))) * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva esfera;
    int i = -1, j = -1, k = -1, indice = -1, h = -1, f = -1, t = -1;
    int *lastLine;
    raio = raio/2;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLfloat)*nTexture);
    lastLine = (int *)malloc(sizeof(int)*gomos*2);
    
    float alpha = M_PI / fatias;
    float beta = (2 * M_PI) / gomos;

    int flag = 0, first, last, one, two;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    for(float ai = -(M_PI/2); ai < M_PI/5; ai += alpha){
        f = 0; h = 0;
        if(flag == 0 ){
            flag = 1;
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                if(bi == 0){
                    vertexB[++i] = raio * cos(ai) * sin(bi);        vertexB[++i] =  raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF + incF;           textureB[++t] = texG;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    normalB[++j] = -cos(ai) * sin(bi);               normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi);
                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi + beta);
                    normalB[++j] = -cos(ai + alpha) * sin(bi);       normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    indexB[++k] = first;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    
                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {

                    indexB[++k] = first;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    indexB[++k] = last;

                    lastLine[++f] = last;

                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);    normalB[++j] = -cos(ai) * cos(bi + beta);
                    

                    indexB[++k] = first;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        } else {
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                one = lastLine[++h];
                two = lastLine[++h];
                if(bi == 0){

                    indexB[++k] = one;

                    first = two;

                    indexB[++k] = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    indexB[++k] = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {
                    indexB[++k] = one;

                    first = two;

                    indexB[++k] = two;

                    indexB[++k] = last;
                    lastLine[++f] = last;


                    indexB[++k] = two;
                    
                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] =  raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    lastLine[++f] = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;

                    indexB[++k] = last;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        }
        texF = 0;
        texG += incG;
    }

    // printf("%d -> %d,%d ->%d, %d -> %d\n",nVertex,i,nIndex,k, nNormal, j);

    esfera.nVertices = nVertex;
    esfera.nIndex = nIndex;
    esfera.textureID = texture.textureID;

    glGenBuffers(1, &esfera.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esfera.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);
    free(lastLine);

    return esfera;
}

Primitiva vboEsferaCopoInv(float fatias, float gomos,float raio, Texture texture){
    int nIndex = 6* fatias * gomos;
    int nVertex = ((4 + 2*(gomos-1)) +  ((2 + (gomos-1)) * (fatias-1))) * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva esfera;
    int i = -1, j = -1, k = -1, indice = -1, h = -1, f = -1, t = -1;
    int *lastLine;
    raio = raio/2;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLfloat)*nTexture);
    lastLine = (int *)malloc(sizeof(int)*gomos*2);
    
    float alpha = M_PI / fatias;
    float beta = (2 * M_PI) / gomos;

    int flag = 0, first, last, one, two;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    for(float ai = -(M_PI/2); ai < M_PI/5; ai += alpha){
        f = 0; h = 0;
        if(flag == 0 ){
            flag = 1;
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                if(bi == 0){
                    vertexB[++i] = raio * cos(ai) * sin(bi);        vertexB[++i] =  raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF + incF;           textureB[++t] = texG;

                    normalB[++j] = -cos(ai) * sin(bi);               normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi);
                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi + beta);
                    normalB[++j] = -cos(ai + alpha) * sin(bi);       normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;
                    
                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {

                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    lastLine[++f] = last;

                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);    normalB[++j] = -cos(ai) * cos(bi + beta);
                    

                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        } else {
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                one = lastLine[++h];
                two = lastLine[++h];
                if(bi == 0){

                    indexB[++k] = one;

                    first = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = two;

                    normalB[++j] = -cos(ai + alpha) * sin(bi);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    indexB[++k] = two;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {
                    indexB[++k] = one;

                    first = two;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    indexB[++k] = two;


                    indexB[++k] = two;

                    indexB[++k] = last;
                    
                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] =  raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    lastLine[++f] = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        }
        texF = 0;
        texG += incG;
    }

    // printf("%d -> %d,%d ->%d, %d -> %d\n",nVertex,i,nIndex,k, nNormal, j);

    esfera.nVertices = nVertex;
    esfera.nIndex = nIndex;
    esfera.textureID = texture.textureID;

    glGenBuffers(1, &esfera.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esfera.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);
    free(lastLine);

    return esfera;
}

Primitiva vboSky(float fatias, float gomos,float raio, Texture texture){
    int nIndex = 6* fatias * gomos;
    int nVertex = ((4 + 2*(gomos-1)) +  ((2 + (gomos-1)) * (fatias-1))) * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva esfera;
    int i = -1, j = -1, k = -1, indice = -1, h = -1, f = -1, t = -1;
    int *lastLine;
    raio = raio/2;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLfloat)*nTexture);
    lastLine = (int *)malloc(sizeof(int)*gomos*2);
    
    float alpha = (M_PI/2) / fatias;
    float beta = (2 * M_PI) / gomos;

    int flag = 0, first, last, one, two;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    for(float ai = -(M_PI/2); ai < 0; ai += alpha){
        f = 0; h = 0;
        if(flag == 0 ){
            flag = 1;
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                if(bi == 0){
                    vertexB[++i] = raio * cos(ai) * sin(bi);        vertexB[++i] =  raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF + incF;           textureB[++t] = texG;

                    normalB[++j] = -cos(ai) * sin(bi);               normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi);
                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi + beta);
                    normalB[++j] = -cos(ai + alpha) * sin(bi);       normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;
                    
                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {

                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai) * sin(bi + beta);        vertexB[++i] = raio * sin(ai);    vertexB[++i] = raio * cos(ai) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    lastLine[++f] = last;

                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);    normalB[++j] = -cos(ai) * cos(bi + beta);
                    

                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        } else {
            for(float bi = 0.0f; bi < 2*M_PI; bi += beta){
                one = lastLine[++h];
                two = lastLine[++h];
                if(bi == 0){

                    indexB[++k] = one;

                    first = two;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi);
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = two;

                    normalB[++j] = -cos(ai + alpha) * sin(bi);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    indexB[++k] = two;

                    indexB[++k] = last;

                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] = raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {
                    indexB[++k] = one;

                    first = two;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    indexB[++k] = two;


                    indexB[++k] = two;

                    indexB[++k] = last;
                    
                    vertexB[++i] = raio * cos(ai + alpha) * sin(bi + beta);        vertexB[++i] = raio * sin(ai + alpha);    vertexB[++i] =  raio * cos(ai + alpha) * cos(bi + beta);
                    indexB[++k] = ++indice;
                    lastLine[++f] = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                texF += incF;
            }
        }
        texF = 0;
        texG += incG;
    }

    // printf("%d -> %d,%d ->%d, %d -> %d\n",nVertex,i,nIndex,k, nNormal, j);

    esfera.nVertices = nVertex;
    esfera.nIndex = nIndex;
    esfera.textureID = texture.textureID;

    glGenBuffers(1, &esfera.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, esfera.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &esfera.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, esfera.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);
    free(lastLine);

    return esfera;
}

Primitiva vboBorder(float fatias, float altura, float raio, float borderSize, Texture texture){
    int nIndex = (6 * (fatias+1));
    int nVertex = (3 * (fatias+2)) * 2;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva border;
    int i = -1, j = -1, k = -1, indice = -1, t = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);


    float angulo = (2 * M_PI) / fatias;
    int first, last, first1, last1;

    raio -= borderSize;

    for(float inc=0; inc < (2*M_PI); inc += angulo){
        if(inc == 0) {
            vertexB[++i] = raio*sin(inc);        vertexB[++i] = altura;    vertexB[++i] = raio*cos(inc);
            indexB[++k] = ++indice;
            first = indice;
            first1 = first;
            textureB[++t] = 0.1*sin(inc);          textureB[++t] = 0.1*cos(inc);

            vertexB[++i] = (raio+borderSize)*sin(inc);        vertexB[++i] = altura;    vertexB[++i] = (raio+borderSize)*cos(inc);
            indexB[++k] = ++indice;
            last1 = indice;
            textureB[++t] = sin(inc);          textureB[++t] = cos(inc);

            vertexB[++i] = (raio+borderSize)*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = (raio+borderSize)*cos(inc+angulo);
            indexB[++k] = ++indice;
            last = indice;
            textureB[++t] = sin(inc+angulo);          textureB[++t] = cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;

            
            indexB[++k] = first;
            
            indexB[++k] = last;
            
            vertexB[++i] =  raio*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = raio*cos(inc+angulo);
            indexB[++k] = ++indice;
            first = indice;
            textureB[++t] = 0.1*sin(inc+angulo);          textureB[++t] = 0.1*cos(inc+angulo);
            
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
        } else {
            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] = (raio+borderSize)*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = (raio+borderSize)*cos(inc+angulo);
            indexB[++k] = ++indice;
            last = indice;
            textureB[++t] = sin(inc+angulo);          textureB[++t] = cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;


            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] =  raio*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = raio*cos(inc+angulo);
            indexB[++k] = ++indice;
            first = indice;
            textureB[++t] = 0.1*sin(inc+angulo);          textureB[++t] = 0.1*cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
        }
    }
    // printf("%d -> %d,%d ->%d\n",nVertex,i,nIndex,k);

    border.nVertices = nVertex;
    border.nIndex = nIndex;
    border.textureID = texture.textureID;

    glGenBuffers(1, &border.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, border.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &border.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, border.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &border.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, border.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &border.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, border.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return border;
}

Primitiva vboBorder2(float fatias, float altura, float raio, float borderSize, Texture texture){
    int nIndex = (6 * (fatias));
    int nVertex = (3 * (fatias+1)) * 2;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva border;
    int i = -1, j = -1, k = -1, indice = -1, t = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);


    float angulo = (2 * M_PI) / fatias;
    int first, last, first1, last1;

    raio -= borderSize;

    for(float inc=0; inc < (2*M_PI); inc += angulo){
        if(inc == 0) {
            vertexB[++i] = raio*sin(inc);        vertexB[++i] = altura;    vertexB[++i] = raio*cos(inc);
            indexB[++k] = ++indice;
            first = indice;
            first1 = first;
            textureB[++t] = 0.1*sin(inc);          textureB[++t] = 0.1*cos(inc);

            vertexB[++i] = (raio+borderSize)*sin(inc);        vertexB[++i] = altura;    vertexB[++i] = (raio+borderSize)*cos(inc);
            indexB[++k] = ++indice;
            last1 = indice;
            textureB[++t] = sin(inc);          textureB[++t] = cos(inc);

            vertexB[++i] = (raio+borderSize)*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = (raio+borderSize)*cos(inc+angulo);
            indexB[++k] = ++indice;
            last = indice;
            textureB[++t] = sin(inc+angulo);          textureB[++t] = cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;

            
            indexB[++k] = first;
            
            indexB[++k] = last;
            
            vertexB[++i] =  raio*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = raio*cos(inc+angulo);
            indexB[++k] = ++indice;
            first = indice;
            textureB[++t] = 0.1*sin(inc+angulo);          textureB[++t] = 0.1*cos(inc+angulo);
            
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
        } else {
            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] = (raio+borderSize)*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = (raio+borderSize)*cos(inc+angulo);
            indexB[++k] = ++indice;
            last = indice;
            textureB[++t] = sin(inc+angulo);          textureB[++t] = cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;


            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] =  raio*sin(inc+angulo);        vertexB[++i] = altura;    vertexB[++i] = raio*cos(inc+angulo);
            indexB[++k] = ++indice;
            first = indice;
            textureB[++t] = 0.1*sin(inc+angulo);          textureB[++t] = 0.1*cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
        }
    }
    // printf("%d -> %d,%d ->%d\n",nVertex,i,nIndex,k);

    border.nVertices = nVertex;
    border.nIndex = nIndex;
    border.textureID = texture.textureID;

    glGenBuffers(1, &border.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, border.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &border.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, border.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &border.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, border.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &border.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, border.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);

    return border;
}

Primitiva vboTorusHalf(float fatias, float raioI, float raioO, Texture texture){
    int nIndex = 6 * fatias * fatias/2;
    int nVertex = ((4 + 2*(fatias-1)) +  ((2 + (fatias-1)) * (fatias-1)/2)) * 3;
    int nNormal = nIndex * 3;
    int nTexture = nIndex * 2;
    GLfloat *vertexB;
    GLuint *indexB;
    GLfloat *normalB;
    GLfloat *textureB;
    Primitiva torus;
    int i = -1, j = -1, k = -1, indice = -1, f = -1, h = -1, t = -1;
    int *lastLine;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLfloat)*nTexture);
    lastLine = (int *)malloc(sizeof(int)*fatias*2);

    float angulo = (2 * M_PI) / fatias;

    int first, last, one, two;
    float incG = 1/fatias, incF = 1/fatias, texG = 0, texF = 0;

    for(float inc=0; inc < (M_PI); inc = inc + angulo) {
        f = 0; h = 0;
        if(inc == 0){   // Primeira vez, cria o array
            for(float l=0; l < (2*M_PI); l = l + angulo){
                if(l == 0){
                    vertexB[++i] = cos(inc)*(cos(l) * raioI + raioO);        vertexB[++i] = sin(inc)*(cos(l) * raioI + raioO);    vertexB[++i] = sin(l)*raioI;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = cos(inc+angulo)*(cos(l) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l) * raioI + raioO);    vertexB[++i] = sin(l)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    lastLine[++f] = last;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;

                    vertexB[++i] =  cos(inc)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    normalB[++j] = cos(inc)*cos(l);        normalB[++j] = sin(inc)*(cos(l));    normalB[++j] = sin(l);
                    normalB[++j] = cos(inc+angulo)*cos(l);        normalB[++j] = sin(inc+angulo)*cos(l);    normalB[++j] = sin(l);
                    normalB[++j] = cos(inc)*cos(l+angulo);        normalB[++j] = sin(inc)*cos(l+angulo);    normalB[++j] = sin(l+angulo);


                    indexB[++k] = last;

                    vertexB[++i] =cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] =  sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                } else {
                    indexB[++k] = first;

                    indexB[++k] = last;
                    last = indice;

                    vertexB[++i] = cos(inc)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;


                    normalB[++j] = cos(inc)*cos(l+angulo);        normalB[++j] = sin(inc)*cos(l+angulo);    normalB[++j] = sin(l+angulo);


                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] =cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                }
                texF += incF;
            }
        } else {        // Usa o array        
            for(float l=0; l < (2*M_PI); l = l + angulo){
                one = lastLine[++h];
                two = lastLine[++h];
                if(l == 0){
                    indexB[++k] = one;

                    vertexB[++i] = cos(inc+angulo)*(cos(l) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l) * raioI + raioO);    vertexB[++i] =  sin(l)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = two;
                    first = two;

                    normalB[++j] = cos(inc+angulo)*cos(l);        normalB[++j] = sin(inc+angulo)*cos(l);    normalB[++j] = sin(l);


                    indexB[++k] = last;

                    vertexB[++i] = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] =  cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] =  sin(l+angulo);
                } else {

                    indexB[++k] = one;

                    indexB[++k] = last;
                    last = indice;

                    indexB[++k] = two;
                    first = two;


                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO);        vertexB[++i] = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);    vertexB[++i] = sin(l+angulo)*raioI;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                }
                texF += incF;
            }
        }
        texF = 0;
        texG += incG;
    }

    // printf("%d -> %d,%d ->%d\n",nVertex,i,nIndex,k);

    torus.nVertices = nVertex;
    torus.nIndex = nIndex;
    torus.textureID = texture.textureID;

    glGenBuffers(1, &torus.vertexB);
    glBindBuffer(GL_ARRAY_BUFFER, torus.vertexB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nVertex, vertexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &torus.normalB);
    glBindBuffer(GL_ARRAY_BUFFER, torus.normalB);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*nNormal, normalB ,GL_STATIC_DRAW);

    glGenBuffers(1, &torus.indexB);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, torus.indexB);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*nNormal, indexB ,GL_STATIC_DRAW);

    glGenBuffers(1, &torus.textureB);
    glBindBuffer(GL_ARRAY_BUFFER, torus.textureB);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * nTexture, textureB, GL_STATIC_DRAW);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    free(vertexB);
    free(indexB);
    free(normalB);
    free(textureB);
    free(lastLine);

    return torus;
}

// ///////////////////
// Draw Func
// ///////////////////
void drawVBO(Primitiva p){
    // Vertex Buffer
    glBindBuffer(GL_ARRAY_BUFFER,p.vertexB);
    glVertexPointer(3,GL_FLOAT,0,0);

    // Normal
    glBindBuffer(GL_ARRAY_BUFFER,p.normalB);
    glNormalPointer(GL_FLOAT,0,0);

    // Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,p.indexB);

    // Texture
    glBindTexture(GL_TEXTURE_2D, p.textureID);
    glBindBuffer(GL_ARRAY_BUFFER, p.textureB);
    glTexCoordPointer(2, GL_FLOAT, 0, 0);

    //  Desenhar
    // glDrawArrays(GL_TRIANGLES, 0, p.nVertices);
    glDrawElements(GL_TRIANGLES, p.nIndex ,GL_UNSIGNED_INT, 0);
}


// ///////////////////
// Func Aux
// ///////////////////

Vertex crossProduct(Vertex v1, Vertex v2, Vertex v3){
    Vertex vector1, vector2, vNormal;
    vector1.x = v2.x - v1.x; 
    vector1.y = v2.y - v1.y;
    vector1.z = v2.z - v1.z;

    vector2.x = v3.x - v1.x;
    vector2.y = v3.y - v1.y;
    vector2.z = v3.z - v1.z;

    vNormal.x = vector1.y * vector2.z - vector1.z * vector2.y;
    vNormal.y = vector1.z * vector2.x - vector1.x * vector2.z;
    vNormal.z = vector1.x * vector2.y - vector1.y * vector2.x;

    GLfloat l12 = sqrt(vNormal.x*vNormal.x+vNormal.y*vNormal.y+vNormal.z*vNormal.z);
    vNormal.x = vNormal.x / l12; 
    vNormal.y = vNormal.y / l12; 
    vNormal.z = vNormal.z / l12;
    return vNormal;
}

Texture getTexture(const char *fileName ){
    unsigned int ima;
    Texture texture;

    // Il setup
    ilInit();
    ilGenImages(1,&ima);
    ilBindImage(ima);
    // Load Image
    ilLoadImage((ILstring) fileName);

    // Get size
    texture.width = ilGetInteger(IL_IMAGE_WIDTH);
    texture.height = ilGetInteger(IL_IMAGE_HEIGHT);
    // Convert image
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    unsigned char *imageData = ilGetData();

    // send to memory
    glGenTextures(1,&texture.textureID);

    glBindTexture(GL_TEXTURE_2D, texture.textureID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture.width, texture.height, GL_RGBA, GL_UNSIGNED_BYTE,imageData);

    return texture;
}