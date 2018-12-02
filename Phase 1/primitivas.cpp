#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"

void drawCilindro(int fatias, float altura,int raio, float r, float g, float b){
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
            glVertex3f(r*sin(i+angulo), altura/2, r*cos(i+angulo));
            glVertex3f(r*sin(i), altura/2, r*cos(i));
            glVertex3f(r*sin(i), -altura/2, r*cos(i));
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