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
    int i = -1, j = -1, k = -1, t = -1;

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

    Vertex v1, v2 ,v3, vN;
    // Vertex
    v1.x = -x;  v1.y = -y;  v1.z = 0.0; // 0
    v2.x = x;   v2.y = -y;  v2.z = 0.0; // 1
    v3.x = x;   v3.y = y;   v3.z = 0.0; // 2
    vN = crossProduct(v1, v2, v3);

    vertexB[++i] = v1.x;    vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
    normalB[++j] = vN.x;    normalB[++j] = vN.y;    normalB[++j] = vN.z;
    indexB[++k] = 0;
    textureB[++t] = 0.0;    textureB[++t] = 0.0;

    vertexB[++i] = v2.x;    vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
    normalB[++j] = vN.x;    normalB[++j] = vN.y;    normalB[++j] = vN.z;
    indexB[++k] = 1;
    textureB[++t] = 1;    textureB[++t] = 0.0;

    vertexB[++i] = v3.x;    vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
    normalB[++j] = vN.x;    normalB[++j] = vN.y;    normalB[++j] = vN.z;
    indexB[++k] = 2;
    textureB[++t] = 1;    textureB[++t] = 1;

    glVertex3f(-x, -y, 0.0f);
    glVertex3f(x, y, 0.0f);
    glVertex3f(-x, y, 0.0f);

    // Vertex
    v1.x = -x;  v1.y = -y;  v1.z = 0.0;  // 0
    v2.x = x;   v2.y = y;   v2.z = 0.0;  // 2
    v3.x = -x;   v3.y = y;   v3.z = 0.0; // 3
    vN = crossProduct(v1, v2, v3);

    indexB[++k] = 0;

    indexB[++k] = 2;

    vertexB[++i] = v3.x;    vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
    indexB[++k] = 3;
    normalB[++j] = vN.x;    normalB[++j] = vN.y;    normalB[++j] = vN.z;
    textureB[++t] = 0.0;    textureB[++t] = 1;

    plano.nVertices = nVertex;
    plano.nIndex = nIndex;

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
    int i = -1, j = -1, k = -1, t = -1;

    Vertex v0, v1 ,v2, v3, v4, v5, v6, v7;
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

    int indice = -1, first, last;

    v0.x = -x;   v0.y = y;    v0.z = z;
    v1.x = -x;   v1.y = -y;   v1.z = z;
    v2.x = x;    v2.y = -y;   v2.z = z;
    v3.x = x;    v3.y = y;    v3.z = z;

    v4.x = x;    v4.y = y;    v4.z = -z;
    v5.x = x;    v5.y = -y;   v5.z = -z;
    v6.x = -x;   v6.y = -y;   v6.z = -z;
    v7.x = -x;   v7.y = y;    v7.z = -z;

    // Faces
    // Frente
    vertexB[++i] = v0.x;    vertexB[++i] = v0.y;    vertexB[++i] = v0.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = 1;
    indexB[++k] =++indice;
    textureB[++t] = 0.0;    textureB[++t] = 1.0;  
    last = indice;

    vertexB[++i] = v1.x;    vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = 1;
    indexB[++k] =++indice;
    textureB[++t] = 0.0;    textureB[++t] = 0.0;

    vertexB[++i] = v2.x;    vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = 1;
    indexB[++k] =++indice;
    textureB[++t] = 1.0;    textureB[++t] = 0.0;
    first = indice;

    indexB[++k] = first;

    vertexB[++i] = v3.x;    vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = 1;
    indexB[++k] =++indice;
    textureB[++t] = 1.0;    textureB[++t] = 1.0;

    indexB[++k] = last;

    // Tras
    vertexB[++i] = v4.x;    vertexB[++i] = v4.y;    vertexB[++i] = v4.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = -1;
    indexB[++k] =++indice;
    textureB[++t] = 2.0;    textureB[++t] = 1.0;
    last = indice;  

    vertexB[++i] = v5.x;    vertexB[++i] = v5.y;    vertexB[++i] = v5.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = -1;
    indexB[++k] =++indice;
    textureB[++t] = 2.0;    textureB[++t] = 0.0;

    vertexB[++i] = v6.x;    vertexB[++i] = v6.y;    vertexB[++i] = v6.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = -1;
    indexB[++k] =++indice;
    textureB[++t] = 3.0;    textureB[++t] = 0.0;

    first = indice;

    indexB[++k] = first;


    vertexB[++i] = v7.x;    vertexB[++i] = v7.y;    vertexB[++i] = v7.z;
    normalB[++j] = 0;       normalB[++j] = 0;       normalB[++j] = -1;
    indexB[++k] =++indice;
    textureB[++t] = 3.0;    textureB[++t] = 1.0;

    indexB[++k] = last;

    // Direita
    vertexB[++i] = v3.x;    vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
    indexB[++k] =++indice;
    normalB[++j] = 1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 1.0;    textureB[++t] = 1.0;  
    last = indice;

    vertexB[++i] = v2.x;    vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
    indexB[++k] =++indice;
    normalB[++j] = 1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 1.0;    textureB[++t] = 0.0;  

    vertexB[++i] = v5.x;    vertexB[++i] = v5.y;    vertexB[++i] = v5.z;
    indexB[++k] =++indice;
    normalB[++j] = 1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 2.0;    textureB[++t] = 0.0;  

    first = indice;

    indexB[++k] = first;


    vertexB[++i] = v4.x;    vertexB[++i] = v4.y;    vertexB[++i] = v4.z;
    indexB[++k] =++indice;
    normalB[++j] = 1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 2.0;    textureB[++t] = 1.0;  

    indexB[++k] = last;

    // Esquerda
    vertexB[++i] = v6.x;    vertexB[++i] = v6.y;    vertexB[++i] = v6.z;
    indexB[++k] =++indice;
    normalB[++j] = -1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 4.0;    textureB[++t] = 0.0; 
    last = indice;

    vertexB[++i] = v1.x;    vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
    indexB[++k] =++indice;
    normalB[++j] = -1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 5.0;    textureB[++t] = 0.0;

    vertexB[++i] = v0.x;    vertexB[++i] = v0.y;    vertexB[++i] = v0.z;
    indexB[++k] =++indice;
    normalB[++j] = -1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 4.0;    textureB[++t] = 1.0;

    first = indice;

    indexB[++k] = first;


    vertexB[++i] = v7.x;    vertexB[++i] = v7.y;    vertexB[++i] = v7.z;
    indexB[++k] =++indice;
    normalB[++j] = -1;       normalB[++j] = 0;       normalB[++j] = 0;
    textureB[++t] = 5.0;    textureB[++t] = 1.0;

    indexB[++k] = last;

    // Cima 
    vertexB[++i] = v0.x;    vertexB[++i] = v0.y;    vertexB[++i] = v0.z;
    normalB[++j] = 0;       normalB[++j] = 1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 0.0;    textureB[++t] = 0.0;  
    last = indice;
    
    vertexB[++i] = v3.x;    vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
    normalB[++j] = 0;       normalB[++j] = 1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 1.0;    textureB[++t] = 0.0;

    vertexB[++i] = v4.x;    vertexB[++i] = v4.y;    vertexB[++i] = v4.z;
    normalB[++j] = 0;       normalB[++j] = 1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 1.0;    textureB[++t] = 1.0;

    first = indice;

    indexB[++k] = first;


    vertexB[++i] = v7.x;    vertexB[++i] = v7.y;    vertexB[++i] = v7.z;
    normalB[++j] = 0;       normalB[++j] = 1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 0.0;    textureB[++t] = 1.0;

    indexB[++k] = last;

    // Baixo
    vertexB[++i] = v1.x;    vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
    normalB[++j] = 0;       normalB[++j] = -1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 0.0;    textureB[++t] = 1.0;  
    last = indice;

    vertexB[++i] = v6.x;    vertexB[++i] = v6.y;    vertexB[++i] = v6.z;
    normalB[++j] = 0;       normalB[++j] = -1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 0.0;    textureB[++t] = 0.0;

    vertexB[++i] = v5.x;    vertexB[++i] = v5.y;    vertexB[++i] = v5.z;    
    normalB[++j] = 0;       normalB[++j] = -1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 1.0;    textureB[++t] = 0.0;

    first = indice;

    indexB[++k] = first;


    vertexB[++i] = v2.x;    vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
    normalB[++j] = 0;       normalB[++j] = -1;       normalB[++j] = 0;
    indexB[++k] =++indice;
    textureB[++t] = 1.0;    textureB[++t] = 1.0;

    indexB[++k] = last;



    paralelo.nVertices = nVertex;
    paralelo.nIndex = nIndex;

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

    Vertex v1, v2, v3, vN;
    float angRad = angulo*DEG2RAD;

    int iCenterUp, iCircleUp;
    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Top
            v1.x = 0.0;                      v1.y = half;    v1.z = 0.0;                 
            v2.x = raio*sin(fRad);           v2.y = half;    v2.z = raio*cos(fRad);
            v3.x = raio*sin(fRad+angRad);    v3.y = half;    v3.z = raio*cos(fRad+angRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterUp = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            // printf("%f,%f,%f\n",vN.x, vN.y, vN.z );

            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raio*sin(fRad+angRad);  v2.y = -half;       v2.z = raio*cos(fRad+angRad);
            v3.x = raio*sin(fRad);         v3.y = -half;       v3.z = raio*cos(fRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);   normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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
            v1.x = 0.0;                      v1.y = half;    v1.z = 0.0;                 
            v2.x = raio*sin(fRad);           v2.y = half;    v2.z = raio*cos(fRad);
            v3.x = raio*sin(fRad+angRad);    v3.y = half;    v3.z = raio*cos(fRad+angRad);

            indexB[++i] = iCenterUp;

            indexB[++i] = iCircleUp;

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raio*sin(fRad+angRad);  v2.y = -half;       v2.z = raio*cos(fRad+angRad);
            v3.x = raio*sin(fRad);         v3.y = -half;       v3.z = raio*cos(fRad);

            indexB[++i] = iCenterBottom;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            indexB[++i] = iCircleBottom;

            iCircleBottom = indice;

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] =  cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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

    Vertex v1, v2, v3, vN;
    float angRad = angulo*DEG2RAD;

    int iCenterUp, iCircleUp;
    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Top
            v1.x = 0.0;                      v1.y = half;    v1.z = 0.0;                 
            v2.x = raioTop*sin(fRad);           v2.y = half;    v2.z = raioTop*cos(fRad);
            v3.x = raioTop*sin(fRad+angRad);    v3.y = half;    v3.z = raioTop*cos(fRad+angRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterUp = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raioBase*sin(fRad+angRad);  v2.y = -half;       v2.z = raioBase*cos(fRad+angRad);
            v3.x = raioBase*sin(fRad);         v3.y = -half;       v3.z = raioBase*cos(fRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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
            v1.x = 0.0;                      v1.y = half;    v1.z = 0.0;                 
            v2.x = raioTop*sin(fRad);           v2.y = half;    v2.z = raioTop*cos(fRad);
            v3.x = raioTop*sin(fRad+angRad);    v3.y = half;    v3.z = raioTop*cos(fRad+angRad);

            indexB[++i] = iCenterUp;

            indexB[++i] = iCircleUp;

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;
            iCircleUp = indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raioBase*sin(fRad+angRad);  v2.y = -half;       v2.z = raioBase*cos(fRad+angRad);
            v3.x = raioBase*sin(fRad);         v3.y = -half;       v3.z = raioBase*cos(fRad);

            indexB[++i] = iCenterBottom;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
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
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] =sin(fRad+angRad);         normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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

    Vertex v1,v2,v3,vN;
    int first, last, one, two;
    float incG = 1/fatias, incF = 1/fatias, texG = 0, texF = 0;

    for(float inc=0; counter < fatias && inc < (2*M_PI); inc = inc + angulo) {
        f = 0; h = 0;
        if(inc == 0){   // Primeira vez, cria o array
            for(float l=0; counter2 < fatias && l < (2*M_PI); l = l + angulo){
                if(l == 0){
                    v1.x = cos(inc)*(cos(l) * raioI + raioO);         v1.y = sin(inc)*(cos(l) * raioI + raioO);         v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l) * raioI + raioO);  v2.y = sin(inc+angulo)*(cos(l) * raioI + raioO);  v2.z = sin(l)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);  v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);  v3.z= sin(l+angulo)*raioI;

                    vertexB[++i] = v1.x;        vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    lastLine[++f] = last;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;

                    vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    vN = crossProduct(v1, v2, v3);
                    normalB[++j] = cos(inc)*cos(l);        normalB[++j] = sin(inc)*(cos(l));    normalB[++j] = sin(l);
                    normalB[++j] = cos(inc+angulo)*cos(l);        normalB[++j] = sin(inc+angulo)*cos(l);    normalB[++j] = sin(l);
                    normalB[++j] = cos(inc)*cos(l+angulo);        normalB[++j] = sin(inc)*cos(l+angulo);    normalB[++j] = sin(l+angulo);

                    v1.x = cos(inc+angulo)*(cos(l) * raioI + raioO);        v1.y = sin(inc+angulo)*(cos(l) * raioI + raioO);        v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO); v2.y = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);   v2.z = sin(l+angulo)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);        v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);        v3.z = sin(l+angulo)*raioI;

                    indexB[++k] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] = cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] = sin(l+angulo);
                } else {
                    v1.x = cos(inc)*(cos(l) * raioI + raioO);         v1.y = sin(inc)*(cos(l) * raioI + raioO);         v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l) * raioI + raioO);  v2.y = sin(inc+angulo)*(cos(l) * raioI + raioO);  v2.z = sin(l)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);  v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);  v3.z= sin(l+angulo)*raioI;

                    indexB[++k] = first;

                    indexB[++k] = last;
                    last = indice;

                    vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;


                    normalB[++j] = cos(inc)*cos(l+angulo);        normalB[++j] = sin(inc)*cos(l+angulo);    normalB[++j] = sin(l+angulo);

                    v1.x = cos(inc+angulo)*(cos(l) * raioI + raioO);        v1.y = sin(inc+angulo)*(cos(l) * raioI + raioO);        v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO); v2.y = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);   v2.z = sin(l+angulo)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);        v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);        v3.z = sin(l+angulo)*raioI;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
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
                    v1.x = cos(inc)*(cos(l) * raioI + raioO);         v1.y = sin(inc)*(cos(l) * raioI + raioO);         v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l) * raioI + raioO);  v2.y = sin(inc+angulo)*(cos(l) * raioI + raioO);  v2.z = sin(l)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);  v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);  v3.z= sin(l+angulo)*raioI;

                    indexB[++k] = one;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = two;
                    first = two;

                    normalB[++j] = cos(inc+angulo)*cos(l);        normalB[++j] = sin(inc+angulo)*cos(l);    normalB[++j] = sin(l);

                    v1.x = cos(inc+angulo)*(cos(l) * raioI + raioO);        v1.y = sin(inc+angulo)*(cos(l) * raioI + raioO);        v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO); v2.y = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);   v2.z = sin(l+angulo)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);        v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);        v3.z = sin(l+angulo)*raioI;

                    indexB[++k] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = last;

                    indexB[++k] = first;

                    normalB[++j] =  cos(inc+angulo)*cos(l+angulo);        normalB[++j] = sin(inc+angulo)*cos(l+angulo);    normalB[++j] =  sin(l+angulo);
                } else {
                    v1.x = cos(inc)*(cos(l) * raioI + raioO);         v1.y = sin(inc)*(cos(l) * raioI + raioO);         v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l) * raioI + raioO);  v2.y = sin(inc+angulo)*(cos(l) * raioI + raioO);  v2.z = sin(l)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);  v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);  v3.z= sin(l+angulo)*raioI;

                    indexB[++k] = one;

                    indexB[++k] = last;
                    last = indice;

                    indexB[++k] = two;
                    first = two;

                    v1.x = cos(inc+angulo)*(cos(l) * raioI + raioO);        v1.y = sin(inc+angulo)*(cos(l) * raioI + raioO);        v1.z = sin(l)*raioI;
                    v2.x = cos(inc+angulo)*(cos(l+angulo) * raioI + raioO); v2.y = sin(inc+angulo)*(cos(l+angulo) * raioI + raioO);   v2.z = sin(l+angulo)*raioI;
                    v3.x = cos(inc)*(cos(l+angulo) * raioI + raioO);        v3.y = sin(inc)*(cos(l+angulo) * raioI + raioO);        v3.z = sin(l+angulo)*raioI;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
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
    int counter = 0, counter2 = 0, i = -1, j = -1, k = -1, indice = -1, h = -1, f = -1, t = -1;
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

    Vertex v1,v2,v3,vN;
    int flag = 0, first, last, one, two;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    for(float ai = -(M_PI/2); counter < fatias && ai < M_PI/2; ai += alpha){
        f = 0; h = 0;
        if(flag == 0 ){
            flag = 1;
            for(float bi = 0.0f; counter2 < gomos && bi < 2*M_PI; bi += beta){
                if(bi == 0){
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    vertexB[++i] = v1.x;        vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF + incF;           textureB[++t] = texG;

                    vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    vN = crossProduct(v1, v2, v3);
                    normalB[++j] = cos(ai) * sin(bi);               normalB[++j] = sin(ai);             normalB[++j] = cos(ai) * cos(bi);
                    normalB[++j] = cos(ai) * sin(bi + beta);        normalB[++j] = sin(ai);             normalB[++j] = cos(ai) * cos(bi + beta);
                    normalB[++j] = cos(ai + alpha) * sin(bi);       normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi);


                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = first;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                } else {
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = first;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    normalB[++j] = cos(ai) * sin(bi + beta);        normalB[++j] = sin(ai);    normalB[++j] = cos(ai) * cos(bi + beta);
                    
                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = first;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                }
                counter2++;
                texF += incF;
            }
            counter2 = 0;
        } else {
            for(float bi = 0.0f; counter2 < gomos && bi < 2*M_PI; bi += beta){
                one = lastLine[++h];
                two = lastLine[++h];
                if(bi == 0){
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = one;

                    indexB[++k] = two;
                    first = two;

                    vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi);


                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = two;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
                } else {
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = one;

                    indexB[++k] = two;
                    first = two;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = two;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    lastLine[++f] = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;

                    indexB[++k] = last;
                    last = indice;

                    normalB[++j] = cos(ai + alpha) * sin(bi + beta);        normalB[++j] = sin(ai + alpha);    normalB[++j] = cos(ai + alpha) * cos(bi + beta);
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

    // printf("%d -> %d,%d ->%d, %d -> %d\n",nVertex,i,nIndex,k, nNormal, j);

    esfera.nVertices = nVertex;
    esfera.nIndex = nIndex;

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

// ///////////////////////
// Primitivas Auxiliares
// ///////////////////////

Primitiva vboCilindroOpen(float fatias, float gomos, float altura,float raio, Texture texture){
    int nIndex = (fatias * 3) * 2 + (fatias * 6) * gomos;
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

    Vertex v1, v2, v3, vN;
    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raio*sin(fRad+angRad);  v2.y = -half;       v2.z = raio*cos(fRad+angRad);
            v3.x = raio*sin(fRad);         v3.y = -half;       v3.z = raio*cos(fRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);   normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);          normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raio*sin(fRad+angRad);  v2.y = -half;       v2.z = raio*cos(fRad+angRad);
            v3.x = raio*sin(fRad);         v3.y = -half;       v3.z = raio*cos(fRad);

            indexB[++i] = iCenterBottom;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            indexB[++i] = iCircleBottom;

            iCircleBottom = indice;

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            for(float g=half; g > -half; g -= alturaT){
                iBackFirst = backupLine[++c];
                iBackLast = backupLine[++c];
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] =  cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g-alturaT;   v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = raio*cos(fRad+angRad);

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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
    int nIndex = (fatias * 3) * 2 + (fatias * 6) * gomos;
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
    float raioIt = (raioBase-raioTop)/gomos;

    Vertex v1, v2, v3, vN;
    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raioBase*sin(fRad+angRad);  v2.y = -half;       v2.z = raioBase*cos(fRad+angRad);
            v3.x = raioBase*sin(fRad);         v3.y = -half;       v3.z = raioBase*cos(fRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = -1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);
                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raioBase*sin(fRad+angRad);  v2.y = -half;       v2.z = raioBase*cos(fRad+angRad);
            v3.x = raioBase*sin(fRad);         v3.y = -half;       v3.z = raioBase*cos(fRad);

            indexB[++i] = iCenterBottom;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
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
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast; 
                    iSideFirst = iBackLast;

                    normalB[++n] = sin(fRad);        normalB[++n] = 0;    normalB[++n] = cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    normalB[++n] =sin(fRad+angRad);         normalB[++n] = 0;    normalB[++n] = cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackFirst;

                    indexB[++i] = iBackLast;
                    iSideFirst = iBackLast;


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    indexB[++i] = iSideFirst;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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

Primitiva vboConeOpenInv(float fatias, float gomos, float altura,float raioTop,float raioBase, Texture texture){
    int nIndex = (fatias * 3) * 2 + (fatias * 6) * gomos;
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
    float raioIt = (raioBase-raioTop)/gomos;

    Vertex v1, v2, v3, vN;
    float angRad = angulo*DEG2RAD;

    int iCenterBottom, iCircleBottom;
    int iSideLast, iSideFirst;
    int iBackFirst, iBackLast;

    for (int f=0; f < 360; f += angulo){
        float fRad = f*DEG2RAD;

        if(f==0){
            // Bottom
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raioBase*sin(fRad+angRad);  v2.y = -half;       v2.z = raioBase*cos(fRad+angRad);
            v3.x = raioBase*sin(fRad);         v3.y = -half;       v3.z = raioBase*cos(fRad);

            vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
            indexB[++i] = ++indice;
            iCenterBottom = indice;
            textureB[++t] = 0;          textureB[++t] = 0;

            vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
            indexB[++i] = ++indice;      
            textureB[++t] = sin(fRad+angRad);          textureB[++t] = cos(fRad+angRad);


            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
            indexB[++i] = ++indice;
            iCircleBottom = indice;
            textureB[++t] = sin(fRad);          textureB[++t] = cos(fRad);

            vN = crossProduct(v1, v2, v3);
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;
            normalB[++n] = 0;        normalB[++n] = 1;    normalB[++n] = 0;

            // Lateral
            float raio = raioTop;
            for(float g=half; g > -half; g -= alturaT){
                if(g == half){
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    iSideFirst = indice;
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
                    indexB[++i] = ++indice;
                    textureB[++t] = texF;          textureB[++t] = texG;

                    normalB[++n] = -sin(fRad+angRad); normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);
                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = -sin(fRad+angRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;  
                    textureB[++t] = texF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    iSideFirst = indice;

                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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
            v1.x = 0.0;                   v1.y = -half;       v1.z = 0.0;
            v2.x = raioBase*sin(fRad+angRad);  v2.y = -half;       v2.z = raioBase*cos(fRad+angRad);
            v3.x = raioBase*sin(fRad);         v3.y = -half;       v3.z = raioBase*cos(fRad);

            indexB[++i] = iCenterBottom;

            indexB[++i] = iCircleBottom;

            vertexB[++v] = v2.x;        vertexB[++v] = v2.y;    vertexB[++v] = v2.z;
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
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;         v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;         v2.z = raio*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad);  v3.y =g-alturaT;       v3.z = (raio+raioIt)*cos(fRad);  

                    vertexB[++v] = v1.x;        vertexB[++v] = v1.y;    vertexB[++v] = v1.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG;

                    indexB[++i] = iBackLast; 

                    indexB[++i] = iBackFirst;
                    iSideFirst = iBackLast;

                    normalB[++n] = -sin(fRad);        normalB[++n] = 0;    normalB[++n] = -cos(fRad);


                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
                    indexB[++i] = ++indice;
                    iSideLast = indice;
                    backupLine[++b] = indice;
                    textureB[++t] = texF+incF;          textureB[++t] = texG+incG;

                    indexB[++i] = iSideFirst;

                    normalB[++n] = -sin(fRad+angRad);         normalB[++n] = 0;    normalB[++n] = -cos(fRad+angRad);
                } else {
                    v1.x = raio*sin(fRad+angRad);    v1.y = g;           v1.z = raio*cos(fRad+angRad);
                    v2.x = raio*sin(fRad);           v2.y = g;           v2.z = raio*cos(fRad);
                    v3.x = raio*sin(fRad);           v3.y = g-alturaT;   v3.z = raio*cos(fRad);

                    indexB[++i] = iSideLast;
                    backupLine[++b] = iSideLast;

                    indexB[++i] = iBackLast;

                    indexB[++i] = iBackFirst;

                    iSideFirst = iBackLast;

                    v1.x = raio*sin(fRad+angRad);             v1.y = g;      v1.z = raio*cos(fRad+angRad);
                    v2.x = (raio+raioIt)*sin(fRad);           v2.y = g-alturaT;   v2.z = (raio+raioIt)*cos(fRad);
                    v3.x = (raio+raioIt)*sin(fRad+angRad);    v3.y = g-alturaT;   v3.z = (raio+raioIt)*cos(fRad+angRad); 

                    indexB[++i] = iSideLast;

                    vertexB[++v] = v3.x;        vertexB[++v] = v3.y;    vertexB[++v] = v3.z;
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

    cilindro.nVertices = nVertex;
    cilindro.nIndex = nIndex;

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
    int counter = 0, counter2 = 0, i = -1, j = -1, k = -1, indice = -1, h = -1, f = -1, t = -1;
    int *lastLine;

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

    Vertex v1,v2,v3,vN;
    int flag = 0, first, last, one, two;
    float incG = 1/gomos, incF = 1/fatias, texG = 0, texF = 0;

    for(float ai = -(M_PI/2); counter < fatias && ai < M_PI/5; ai += alpha){
        f = 0; h = 0;
        if(flag == 0 ){
            flag = 1;
            for(float bi = 0.0f; counter2 < gomos && bi < 2*M_PI; bi += beta){
                if(bi == 0){
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    vertexB[++i] = v1.x;        vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF;           textureB[++t] = texG;

                    vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF + incF;           textureB[++t] = texG;

                    vN = crossProduct(v1, v2, v3);
                    normalB[++j] = -cos(ai) * sin(bi);               normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi);
                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);             normalB[++j] = -cos(ai) * cos(bi + beta);
                    normalB[++j] = -cos(ai + alpha) * sin(bi);       normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = first;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    first = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG;

                    normalB[++j] = -cos(ai) * sin(bi + beta);        normalB[++j] = -sin(ai);    normalB[++j] = -cos(ai) * cos(bi + beta);
                    
                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = first;

                    indexB[++k] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;
                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                }
                counter2++;
                texF += incF;
            }
            counter2 = 0;
        } else {
            for(float bi = 0.0f; counter2 < gomos && bi < 2*M_PI; bi += beta){
                one = lastLine[++h];
                two = lastLine[++h];
                if(bi == 0){
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = one;

                    vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
                    indexB[++k] = ++indice;
                    last = indice;
                    textureB[++t] = texF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    indexB[++k] = two;
                    first = two;

                    normalB[++j] = -cos(ai + alpha) * sin(bi);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi);


                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = two;

                    indexB[++k] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;
                    lastLine[++f] = indice;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
                } else {
                    v1.x = raio * cos(ai) * sin(bi);            v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi);
                    v2.x = raio * cos(ai) * sin(bi + beta);     v2.y = raio * sin(ai);           v2.z = raio * cos(ai) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);    v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = one;

                    indexB[++k] = last;
                    lastLine[++f] = last;

                    indexB[++k] = two;
                    first = two;

                    v1.x = raio * cos(ai) * sin(bi + beta);             v1.y = raio * sin(ai);           v1.z = raio * cos(ai) * cos(bi + beta);
                    v2.x = raio * cos(ai + alpha) * sin(bi + beta);     v2.y = raio * sin(ai + alpha);   v2.z = raio * cos(ai + alpha) * cos(bi + beta);
                    v3.x = raio * cos(ai + alpha) * sin(bi);            v3.y = raio * sin(ai + alpha);   v3.z = raio * cos(ai + alpha) * cos(bi);

                    indexB[++k] = two;

                    indexB[++k] = last;

                    vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
                    indexB[++k] = ++indice;
                    lastLine[++f] = indice;
                    textureB[++t] = texF+incF;           textureB[++t] = texG+incG;

                    last = indice;

                    normalB[++j] = -cos(ai + alpha) * sin(bi + beta);        normalB[++j] = -sin(ai + alpha);    normalB[++j] = -cos(ai + alpha) * cos(bi + beta);
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

    // printf("%d -> %d,%d ->%d, %d -> %d\n",nVertex,i,nIndex,k, nNormal, j);

    esfera.nVertices = nVertex;
    esfera.nIndex = nIndex;

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
    int counter = 0, i = -1, j = -1, k = -1, indice = -1, t = -1;

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    // Mallocs
    vertexB = (GLfloat *)malloc(sizeof(GLfloat)*nVertex);
    normalB = (GLfloat *)malloc(sizeof(GLfloat)*nNormal);
    indexB = (GLuint *)malloc(sizeof(GLuint)*nIndex);
    textureB = (GLfloat *)malloc(sizeof(GLuint)*nTexture);


    float angulo = (2 * M_PI) / fatias;
    Vertex v1,v2,v3,vN;
    int first, last, first1, last1;

    raio -= borderSize;

    for(float inc=0; counter < fatias && inc < (2*M_PI); inc += angulo){
        if(inc == 0) {
            v1.x = raio*sin(inc);                      v1.y = altura;      v1.z = raio*cos(inc);
            v2.x = (raio+borderSize)*sin(inc);         v2.y = altura;      v2.z = (raio+borderSize)*cos(inc);
            v3.x = (raio+borderSize)*sin(inc+angulo);  v3.y = altura;      v3.z = (raio+borderSize)*cos(inc+angulo);

            vertexB[++i] = v1.x;        vertexB[++i] = v1.y;    vertexB[++i] = v1.z;
            indexB[++k] = ++indice;
            first = indice;
            first1 = first;
            textureB[++t] = 0.1*sin(inc);          textureB[++t] = 0.1*cos(inc);

            vertexB[++i] = v2.x;        vertexB[++i] = v2.y;    vertexB[++i] = v2.z;
            indexB[++k] = ++indice;
            last1 = indice;
            textureB[++t] = sin(inc);          textureB[++t] = cos(inc);

            vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
            indexB[++k] = ++indice;
            last = indice;
            textureB[++t] = sin(inc+angulo);          textureB[++t] = cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;


            v1.x = raio*sin(inc);                      v1.y = altura;      v1.z = raio*cos(inc);
            v2.x = (raio+borderSize)*sin(inc+angulo);  v2.y = altura;      v2.z = (raio+borderSize)*cos(inc+angulo);
            v3.x = raio*sin(inc+angulo);               v3.y = altura;      v3.z = raio*cos(inc+angulo);

            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
            indexB[++k] = ++indice;
            first = indice;
            textureB[++t] = 0.1*sin(inc+angulo);          textureB[++t] = 0.1*cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
        } else {
            v1.x = raio*sin(inc);                      v1.y = altura;      v1.z = raio*cos(inc);
            v2.x = (raio+borderSize)*sin(inc);         v2.y = altura;      v2.z = (raio+borderSize)*cos(inc);
            v3.x = (raio+borderSize)*sin(inc+angulo);  v3.y = altura;      v3.z = (raio+borderSize)*cos(inc+angulo);

            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
            indexB[++k] = ++indice;
            last = indice;
            textureB[++t] = sin(inc+angulo);          textureB[++t] = cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;


            v1.x = raio*sin(inc);                      v1.y = altura;      v1.z = raio*cos(inc);
            v2.x = (raio+borderSize)*sin(inc+angulo);  v2.y = altura;      v2.z = (raio+borderSize)*cos(inc+angulo);
            v3.x = raio*sin(inc+angulo);               v3.y = altura;      v3.z = raio*cos(inc+angulo);

            indexB[++k] = first;

            indexB[++k] = last;

            vertexB[++i] = v3.x;        vertexB[++i] = v3.y;    vertexB[++i] = v3.z;
            indexB[++k] = ++indice;
            first = indice;
            textureB[++t] = 0.1*sin(inc+angulo);          textureB[++t] = 0.1*cos(inc+angulo);

            normalB[++j] = 0;        normalB[++j] = 1;    normalB[++j] = 0;
        }
        ++counter;
    }
    // printf("%d -> %d,%d ->%d\n",nVertex,i,nIndex,k);

    border.nVertices = nVertex;
    border.nIndex = nIndex;

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
    glGenTextures(1,&texture.textudeID);

    glBindTexture(GL_TEXTURE_2D, texture.textudeID);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture.width, texture.height, GL_RGBA, GL_UNSIGNED_BYTE,imageData);
    return texture;
}