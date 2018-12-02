#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"


void drawPlano(float l,float c, float r, float g, float b){
    float x = c/2;
    float y = l/2;

    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, -y, 0.0f);
    glVertex3f(x, -y, 0.0f);
    glVertex3f(x, y, 0.0f);
    glVertex3f(-x, -y, 0.0f);
    glVertex3f(x, y, 0.0f);
    glVertex3f(-x, y, 0.0f);
    glEnd();
}

void drawParalelo(float l, float c, float p, float r, float g, float b){
    float x = c/2;
    float y = l/2;
    float z = p/2;

    glColor3f(r, g, b);

    // Front
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, -y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, -y, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);
    glEnd();

    // Left
    glBegin(GL_TRIANGLES);
    glVertex3f(x, -y, z);
    glVertex3f(x, -y, -z);
    glVertex3f(x, y, -z);
    glVertex3f(x, y, z);
    glVertex3f(x, -y, z);
    glVertex3f(x, y, -z);
    glEnd();

    // Right
    glBegin(GL_TRIANGLES);
    glVertex3f(-x, -y, z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, y, -z);
    glVertex3f(-x, -y, z);
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
}

void drawCilindro(int fatias, float altura,float raio, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;
    float alturaT = 0.5f;

    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        glColor3f(r, g, b);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, altura/2, 0.f); //Centro
        glVertex3f(raio*sin(i), altura/2, raio*cos(i));
        glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
        glEnd();

        if(altura < 1){
            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
            glVertex3f(raio*sin(i), altura/2, raio*cos(i));
            glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
            glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
            glVertex3f(raio*sin(i+angulo), -altura/2, raio*cos(i+angulo));
            glEnd();
        } else {

        // Rect
            for(float j=altura/2; j != -(altura/2); j -= alturaT){
                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f(raio*sin(i), j, raio*cos(i));
                glVertex3f(raio*sin(i), j-alturaT, raio*cos(i));
                glEnd();

                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f(raio*sin(i), j-alturaT, raio*cos(i));
                glVertex3f(raio*sin(i+angulo), j-alturaT, raio*cos(i+angulo));
                glEnd();
            }
        }

        // Base Down
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -altura/2, 0.f); //Centro
        glVertex3f(raio*sin(i+angulo), -altura/2, raio*cos(i+angulo));
        glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
        glEnd();
    }
}

void drawEsfera(float raio, int fatias, int gomos, float r, float g, float b){
    float alpha  = (M_PI / 2) / fatias;
    float beta  = (M_PI / 2) / gomos;

    glColor3f(r, g, b);

    for(float ai = 0.0f; ai < (M_PI / 2); ai += alpha){
        for(float bi = 0.0f; bi < M_PI; bi += beta){
            float x1 = raio * cos(ai) * sin(bi);
            float y1 = raio * sin(ai);
            float z1 = raio * cos(ai) * cos(bi);
            float x2 = raio * cos(ai) * sin(bi + beta);
            float y2 = raio * sin(ai);
            float z2 = raio * cos(ai) * cos(bi + beta);
            float x3 = raio * cos(ai + alpha) * sin(bi);
            float y3 = raio * sin(ai + alpha);
            float z3 = raio * cos(ai + alpha) * cos(bi);
            float x4 = raio * cos(ai + alpha) * sin(bi + beta);
            float y4 = raio * sin(ai + alpha);
            float z4 = raio * cos(ai + alpha) * cos(bi + beta);

            glBegin(GL_TRIANGLES);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);
            glVertex3f(x2, y2, z2);
            glVertex3f(x4, y4, z4);
            glVertex3f(x3, y3, z3);
            glEnd();

            glBegin(GL_TRIANGLES);
            glColor3f(r, g, b);
            glVertex3f(-x1, y1, -z1);
            glVertex3f(-x2, y2, -z2);
            glVertex3f(-x3, y3, -z3);
            glVertex3f(-x2, y2, -z2);
            glVertex3f(-x4, y4, -z4);
            glVertex3f(-x3, y3, -z3);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(-x2, -y2, -z2);
            glVertex3f(-x1, -y1, -z1);
            glVertex3f(-x3, -y3, -z3);
            glVertex3f(-x4, -y4, -z4);
            glVertex3f(-x2, -y2, -z2);
            glVertex3f(-x3, -y3, -z3);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(x2, -y2, z2);
            glVertex3f(x1, -y1, z1);
            glVertex3f(x3, -y3, z3);
            glVertex3f(x4, -y4, z4);
            glVertex3f(x2, -y2, z2);
            glVertex3f(x3, -y3, z3);
            glEnd();

        }
    }
}

void drawCone(int fatias, int gomos, float altura,float raioTop,float raioBase, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;
    float it = altura/gomos;
    float raioIt = (raioBase-raioTop)/gomos;

    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        glColor3f(r, g, b);
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, altura/2, 0.f); //Centro
        glVertex3f(raioTop*sin(i), altura/2, raioTop*cos(i));
        glVertex3f(raioTop*sin(i+angulo), altura/2, raioTop*cos(i+angulo));
        glEnd();

        // Rect
        float raio = raioTop;
        for(float j=altura/2; j != -(altura/2); j -= it){
            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f(raio*sin(i), j, raio*cos(i));
            glVertex3f((raio+raioIt)*sin(i), j-it, (raio+raioIt)*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f((raio+raioIt)*sin(i), j-it, (raio+raioIt)*cos(i));
            glVertex3f((raio+raioIt)*sin(i+angulo), j-it, (raio+raioIt)*cos(i+angulo));
            glEnd();
            raio += raioIt;
        }

        // Base Down
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -altura/2, 0.f); //Centro
        glVertex3f(raioBase*sin(i+angulo), -altura/2, raioBase*cos(i+angulo));
        glVertex3f(raioBase*sin(i), -altura/2, raioBase*cos(i));
        glEnd();
    }
}

void drawElipse(int fatias, int gomos, float raiox, float raioy, float raioz, float r, float g, float b){
    float alpha  = (M_PI / 2) / fatias;
    float beta  = (M_PI / 2) / gomos;

    glColor3f(r, g, b);
    for(float i = -M_PI/2; i <= (M_PI/2); i += alpha){
        glBegin(GL_TRIANGLE_STRIP);
        for(float j = -M_PI; j <= M_PI; j += beta){
            glVertex3f(raiox * cos(i) * cos(j), raioy * cos(i) * sin(j), raioz * sin(i));
            glVertex3f(raiox * cos(i+alpha) * cos(j), raioy * cos(i+alpha) * sin(j), raioz * sin(i+alpha));
        }
        glEnd();
    }
}

void drawTorus(int fatias, float raioI, float raioO, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;

    glColor3f(r, g, b);
    for(float i=0; i < (2*M_PI); i = i + angulo) {
        for(float j=0; j < (2*M_PI); j = j + angulo){
            float x1 = cos(i)*(cos(j) * raioI + raioO);
            float y1 = sin(i)*(cos(j) * raioI + raioO);
            float z1 = sin(j)*raioI;
            float x2 = cos(i+angulo)*(cos(j) * raioI + raioO);
            float y2 = sin(i+angulo)*(cos(j) * raioI + raioO);
            float z2 = sin(j)*raioI;
            float x3 = cos(i)*(cos(j+angulo) * raioI + raioO);
            float y3 = sin(i)*(cos(j+angulo) * raioI + raioO);
            float z3 = sin(j+angulo)*raioI;
            float x4 = cos(i+angulo)*(cos(j+angulo) * raioI + raioO);
            float y4 = sin(i+angulo)*(cos(j+angulo) * raioI + raioO);
            float z4 = sin(j+angulo)*raioI;

            glBegin(GL_TRIANGLES);
            glVertex3f(x1,y1,z1);
            glVertex3f(x2,y2,z2);
            glVertex3f(x3,y3,z3);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(x2,y2,z2);
            glVertex3f(x4,y4,z4);
            glVertex3f(x3,y3,z3);
            glEnd();
        }
    }
}

void drawElipsoide(int fatias, float raioX, float raioY, float raioZ, float altura, float r, float g, float b){
    float alpha  = (M_PI / 2) / fatias;
    float beta  = (M_PI / 2) / fatias;

    glColor3f(r, g, b);
    for(float ai = -(M_PI/2); ai < (M_PI / 2); ai += alpha){
        for(float bi = -M_PI; bi < M_PI; bi += beta){
            float x1 = raioX * cos(ai) * cos(bi);
            float y1 = raioY * cos(ai) * sin(bi);
            float z1 = raioZ * sin(ai);

            float x2 = raioX * cos(ai+alpha) * cos(bi);
            float y2 = raioY * cos(ai+alpha) * sin(bi);
            float z2 = raioZ * sin(ai+alpha);

            float x3 = raioX * cos(ai) * cos(bi+beta);
            float y3 = raioY * cos(ai) * sin(bi+beta);
            float z3 = raioZ * sin(ai);

            float x4 = raioX * cos(ai+alpha) * cos(bi+beta);
            float y4 = raioY * cos(ai+alpha) * sin(bi+beta);
            float z4 = raioZ * sin(ai+alpha);

            glBegin(GL_TRIANGLES);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);

            glVertex3f(x2, y2, z2);
            glVertex3f(x4, y4, z4);
            glVertex3f(x3, y3, z3);
            glEnd();
        }
    }
}

void drawCilindroEnc(){
    int fatias = 30;
    float angulo = (2 * M_PI) / fatias;
    float raio =10;
    float aux = raio;
    float altura = 20;
    float x = raio/fatias;
    float y = altura/fatias;

    glColor3f(1, 1, 1);
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, altura/2, 0.f); //Centro
        glVertex3f(raio*sin(i), altura/2, raio*cos(i));
        glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
        glEnd();

        for(float j=altura/2; j > -(altura/2); j -= y){
            if(j > 0){
                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f(raio*sin(i), j, raio*cos(i));
                glVertex3f((raio-x)*sin(i), j-y, (raio-x)*cos(i));
                glEnd();

                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f((raio-x)*sin(i), j-y, (raio-x)*cos(i));
                glVertex3f((raio-x)*sin(i+angulo), j-y, (raio-x)*cos(i+angulo));
                glEnd();
                raio -= x;
            } else {
                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f(raio*sin(i), j, raio*cos(i));
                glVertex3f((raio+x)*sin(i), j-y, (raio+x)*cos(i));
                glEnd();

                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f((raio+x)*sin(i), j-y, (raio+x)*cos(i));
                glVertex3f((raio+x)*sin(i+angulo), j-y, (raio+x)*cos(i+angulo));
                glEnd();
                raio += x;
            }
        }

        // Base Down
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -altura/2, 0.f); //Centro
        glVertex3f(raio*sin(i+angulo), -altura/2, raio*cos(i+angulo));
        glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
        glEnd();
        raio = aux;
    }
}