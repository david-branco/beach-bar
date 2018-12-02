#include <GL/glut.h>
#define USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "primitivas.h"

void drawGlassWater(int fatias, float raio, float alturaPe, float alturaBase, float larguraBase, float r, float g, float b){
    float alpha  = (M_PI / 2) / fatias;
    float beta  = (M_PI / 2) / fatias;

    glColor3f(1, 1, 1);

    // Esfera de Fora
    glPushMatrix();
    for(float ai = -(M_PI / 2); ai < M_PI/5; ai += alpha){
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
            glVertex3f(-x1, y1, z1);            
            glVertex3f(-x3, y3, z3);
            glVertex3f(-x2, y2, z2);

            glVertex3f(-x2, y2, z2);
            glVertex3f(-x3, y3, z3);
            glVertex3f(-x4, y4, z4);
            glEnd();
        }
    }
    glPopMatrix();

    // Esfera de dentro
    glColor3f(1, 1, 0);
    glPushMatrix();
    for(float ai = -(M_PI / 2); ai < M_PI/5; ai += alpha){
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
            
            glVertex3f(x3, y3, z3);
            glVertex3f(x2, y2, z2);

            glVertex3f(x2, y2, z2);
            
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(-x1, y1, z1);            
            
            glVertex3f(-x2, y2, z2);
            glVertex3f(-x3, y3, z3);

            glVertex3f(-x2, y2, z2);
            
            glVertex3f(-x4, y4, z4);
            glVertex3f(-x3, y3, z3);
            glEnd();
        }
    }
    glPopMatrix();

    // Pe
    glPushMatrix();
    glTranslatef(0.0, -raio - alturaPe/2, 0.0);
    drawCilindro(fatias, alturaPe, 1,r, g, b);
    glPopMatrix();

    // Base
    glPushMatrix();
    glTranslatef(0.0, -raio - alturaPe - alturaBase/2, 0.0);
    drawCilindro(fatias, alturaBase, larguraBase,r, g, b);
    glPopMatrix();
}

void drawTallGlass(float fatias, float altura, float raio, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;
    float alturaT = 0.5f;
    float border = (raio*0.2)/5;

    glColor3f(1, 1, 0);
    glPushMatrix();
    // Fora    
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
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

    glColor3f(r, g, b);

    raio -= border;
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        if(altura < 1){
            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
            glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
            glVertex3f(raio*sin(i), altura/2, raio*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
            glVertex3f(raio*sin(i+angulo), -altura/2, raio*cos(i+angulo));
            glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
            glEnd();
        } else {

        // Rect
            for(float j=altura/2; j != -(altura/2); j -= alturaT){
                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f(raio*sin(i), j-alturaT, raio*cos(i));
                glVertex3f(raio*sin(i), j, raio*cos(i));
                glEnd();

                glBegin(GL_TRIANGLES);
                glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
                glVertex3f(raio*sin(i+angulo), j-alturaT, raio*cos(i+angulo));
                glVertex3f(raio*sin(i), j-alturaT, raio*cos(i));
                glEnd();
            }
        }

        // Base Down
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -altura/2, 0.f); //Centro
        glVertex3f(raio*sin(i), -altura/2, raio*cos(i));
        glVertex3f(raio*sin(i+angulo), -altura/2, raio*cos(i+angulo));
        glEnd();
    }

    glColor3f(1, 0, 0);
    // Borda
    for(float i=0; i < (2*M_PI); i = i + angulo){
        glBegin(GL_TRIANGLES);
        glVertex3f(raio*sin(i), altura/2, raio*cos(i));
        
        glVertex3f((raio+border)*sin(i+angulo), altura/2, (raio+border)*cos(i+angulo));
        glVertex3f(raio*sin(i+angulo), altura/2, raio*cos(i+angulo));
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(raio*sin(i), altura/2, raio*cos(i));
        
        glVertex3f((raio+border)*sin(i), altura/2, (raio+border)*cos(i));
        glVertex3f((raio+border)*sin(i+angulo), altura/2, (raio+border)*cos(i+angulo));
        glEnd();
    }
    glPopMatrix();
}

void drawMartini(int fatias, float alturaBase, float alturaPe, float alturaCone, float raioBase, float raioPe, float raioCone, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;
    float it = alturaCone/fatias;
    float raioIt = (raioCone-raioPe)/fatias;
    float border = (raioCone*0.2)/5;

    glColor3f(r, g, b);

    // Inside
    glPushMatrix();
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -alturaCone/2, 0.f); //Centro
        glVertex3f(raioPe*sin(i+angulo), -alturaCone/2, raioPe*cos(i+angulo));
        glVertex3f(raioPe*sin(i), -alturaCone/2, raioPe*cos(i));
        glEnd();

        // Rect
        float raio = raioCone;
        for(float j=alturaCone/2; j != -(alturaCone/2); j -= it){
            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f(raio*sin(i), j, raio*cos(i));
            glVertex3f((raio-raioIt)*sin(i), j-it, (raio-raioIt)*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f((raio-raioIt)*sin(i), j-it, (raio-raioIt)*cos(i));
            glVertex3f((raio-raioIt)*sin(i+angulo), j-it, (raio-raioIt)*cos(i+angulo));
            glEnd();
            raio -= raioIt;
        }
    }

    // Outside
    glColor3f(r, g, 0);
    raioCone -= border;
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -alturaCone/2, 0.f); //Centro
        glVertex3f(raioPe*sin(i), -alturaCone/2, raioPe*cos(i));
        glVertex3f(raioPe*sin(i+angulo), -alturaCone/2, raioPe*cos(i+angulo));
        glEnd();

        // Rect
        float raio = raioCone;
        for(float j=alturaCone/2; j != -(alturaCone/2); j -= it){
            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f((raio-raioIt)*sin(i), j-it, (raio-raioIt)*cos(i));
            glVertex3f(raio*sin(i), j, raio*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f((raio-raioIt)*sin(i+angulo), j-it, (raio-raioIt)*cos(i+angulo));
            glVertex3f((raio-raioIt)*sin(i), j-it, (raio-raioIt)*cos(i));
            glEnd();
            raio -= raioIt;
        }
    }

    // Border
    glColor3f(1, 0, 0);
    for(float i=0; i < (2*M_PI); i = i + angulo){
        glBegin(GL_TRIANGLES);
        glVertex3f(raioCone*sin(i), alturaCone/2, raioCone*cos(i));
        
        glVertex3f((raioCone+border)*sin(i+angulo), alturaCone/2, (raioCone+border)*cos(i+angulo));
        glVertex3f(raioCone*sin(i+angulo), alturaCone/2, raioCone*cos(i+angulo));
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(raioCone*sin(i), alturaCone/2, raioCone*cos(i));
        
        glVertex3f((raioCone+border)*sin(i), alturaCone/2, (raioCone+border)*cos(i));
        glVertex3f((raioCone+border)*sin(i+angulo), alturaCone/2, (raioCone+border)*cos(i+angulo));
        glEnd();
    }
    glPopMatrix();

    // Pe
    glPushMatrix();
    glTranslatef(0, -alturaCone/2 - alturaPe/2, 0);
    drawCilindro(fatias, alturaPe, raioPe, r, g, b);
    glPopMatrix();

    // Base
    glPushMatrix();
    glTranslatef(0, -alturaCone/2 - alturaPe - alturaBase, 0);
    drawCone(fatias, 8, 2, raioPe, raioBase, r, g, b);
    glPopMatrix();
}

void drawMartiniStick(int fatias, float alturaStick, float raioStick, float raioAzeitona, float r, float g, float b){
    // Stick
    glPushMatrix();
    glRotatef(-35, 0, 1, 1);
    drawCilindro(fatias, alturaStick, raioStick, r, g, b);
    glPopMatrix();

    // Azeitona
    float raio = alturaStick/4;
    glPushMatrix(),
    glTranslatef(raio*sin(-35), raio , 0);
    drawEsfera(raioAzeitona, fatias, fatias, 0, 1, 0);
    glPopMatrix();
}

void drawMartiniWithStick(){

    drawMartini(30, 1, 10, 15, 7, 0.5, 10, 0.870588235, 0.870588235, 0.870588235);
    glPushMatrix();
    glTranslatef(7, 6, 0);
    drawMartiniStick(30, 15, 0.2, 2, 1, 1, 1);
    glPopMatrix();
}

void drawCaneca(int fatias, float raioI, float raioO, float raioCaneca, float alturaCaneca, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;
    float alturaT = 1.0f;
    float border = (raioCaneca*0.8)/5;

    glColor3f(0, 0, 1);
    // Pega
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    for(float i=0; i < (M_PI); i = i + angulo) {
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
    glPopMatrix();

    // Caneca
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(raioCaneca/2 + raioI/2 + raioO/2 - border/2, 0, 0);
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        if(alturaCaneca < 1){
            glBegin(GL_TRIANGLES);
            glVertex3f(raioCaneca*sin(i+angulo), alturaCaneca/2, raioCaneca*cos(i+angulo));
            glVertex3f(raioCaneca*sin(i), alturaCaneca/2, raioCaneca*cos(i));
            glVertex3f(raioCaneca*sin(i), -alturaCaneca/2, raioCaneca*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raioCaneca*sin(i+angulo), alturaCaneca/2, raioCaneca*cos(i+angulo));
            glVertex3f(raioCaneca*sin(i), -alturaCaneca/2, raioCaneca*cos(i));
            glVertex3f(raioCaneca*sin(i+angulo), -alturaCaneca/2, raioCaneca*cos(i+angulo));
            glEnd();
        } else {

        // Rect
            for(float j=alturaCaneca/2; j != -(alturaCaneca/2); j -= alturaT){
                glBegin(GL_TRIANGLES);
                glVertex3f(raioCaneca*sin(i+angulo), j, raioCaneca*cos(i+angulo));
                
                glVertex3f(raioCaneca*sin(i), j, raioCaneca*cos(i));
                glVertex3f(raioCaneca*sin(i), j-alturaT, raioCaneca*cos(i));
                glEnd();

                glBegin(GL_TRIANGLES);
                glVertex3f(raioCaneca*sin(i+angulo), j, raioCaneca*cos(i+angulo));
                
                glVertex3f(raioCaneca*sin(i), j-alturaT, raioCaneca*cos(i));
                glVertex3f(raioCaneca*sin(i+angulo), j-alturaT, raioCaneca*cos(i+angulo));
                glEnd();
            }
        }

        // Base Down
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -alturaCaneca/2, 0.f); //Centro
        glVertex3f(raioCaneca*sin(i+angulo), -alturaCaneca/2, raioCaneca*cos(i+angulo));
        glVertex3f(raioCaneca*sin(i), -alturaCaneca/2, raioCaneca*cos(i));
        glEnd();
    }

     // Caneca Inside
    glColor3f(1, 1, 0);
    raioCaneca -= border;
    for(float i=0; i < (2*M_PI); i = i + angulo){
        // Base Up
        if(alturaCaneca < 1){
            glBegin(GL_TRIANGLES);
            glVertex3f(raioCaneca*sin(i+angulo), alturaCaneca/2, raioCaneca*cos(i+angulo));
            glVertex3f(raioCaneca*sin(i), -alturaCaneca/2, raioCaneca*cos(i));
            glVertex3f(raioCaneca*sin(i), alturaCaneca/2, raioCaneca*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raioCaneca*sin(i+angulo), alturaCaneca/2, raioCaneca*cos(i+angulo));
            glVertex3f(raioCaneca*sin(i+angulo), -alturaCaneca/2, raioCaneca*cos(i+angulo));
            glVertex3f(raioCaneca*sin(i), -alturaCaneca/2, raioCaneca*cos(i));
            glEnd();
        } else {

        // Rect
            for(float j=alturaCaneca/2; j != -(alturaCaneca/2); j -= alturaT){
                glBegin(GL_TRIANGLES);
                glVertex3f(raioCaneca*sin(i+angulo), j, raioCaneca*cos(i+angulo));
                glVertex3f(raioCaneca*sin(i), j-alturaT, raioCaneca*cos(i));
                glVertex3f(raioCaneca*sin(i), j, raioCaneca*cos(i));
                glEnd();

                glBegin(GL_TRIANGLES);
                glVertex3f(raioCaneca*sin(i+angulo), j, raioCaneca*cos(i+angulo));
                glVertex3f(raioCaneca*sin(i+angulo), j-alturaT, raioCaneca*cos(i+angulo));
                glVertex3f(raioCaneca*sin(i), j-alturaT, raioCaneca*cos(i));
                glEnd();
            }
        }

        // Base Down
        glBegin(GL_TRIANGLES);
        glVertex3f(0.f, -alturaCaneca/2, 0.f); //Centro
        glVertex3f(raioCaneca*sin(i), -alturaCaneca/2, raioCaneca*cos(i));
        glVertex3f(raioCaneca*sin(i+angulo), -alturaCaneca/2, raioCaneca*cos(i+angulo));
        glEnd();
    }

    glColor3f(1, 0, 0);
    // Borda
    for(float i=0; i < (2*M_PI); i = i + angulo){
        glBegin(GL_TRIANGLES);
        glVertex3f(raioCaneca*sin(i), alturaCaneca/2, raioCaneca*cos(i));
        glVertex3f((raioCaneca+border)*sin(i+angulo), alturaCaneca/2, (raioCaneca+border)*cos(i+angulo));
        glVertex3f(raioCaneca*sin(i+angulo), alturaCaneca/2, raioCaneca*cos(i+angulo));
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(raioCaneca*sin(i), alturaCaneca/2, raioCaneca*cos(i));
        glVertex3f((raioCaneca+border)*sin(i), alturaCaneca/2, (raioCaneca+border)*cos(i));
        glVertex3f((raioCaneca+border)*sin(i+angulo), alturaCaneca/2, (raioCaneca+border)*cos(i+angulo));
        glEnd();
    }
    glPopMatrix();
}

void drawCerveja(int fatias, float alturaBase, float raioBase, float raioBaseTopo, float alturaCopo, float raioCopo, float r, float g, float b){
    float angulo = (2 * M_PI) / fatias;
    float it = alturaCopo/fatias;
    float raioIt = (raioBaseTopo-raioCopo)/fatias;
    float border = (raioCopo*0.2)/5;

    // Base
    glPushMatrix();
    glTranslatef(0, -alturaCopo/2 - alturaBase/2, 0);
    drawCone(fatias, 2, alturaBase, raioBaseTopo, raioBase, r, g, b);
    glPopMatrix();

    glColor3f(r, g, 1);
    glPushMatrix();
    for(float i=0; i < (2*M_PI); i = i + angulo){
        float raio = raioCopo;
        for(float j=alturaCopo/2; j != -(alturaCopo/2); j -= it){
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
    }
    glColor3f(0, g, b);
    raioCopo -= border;
    for(float i=0; i < (2*M_PI); i = i + angulo){
        float raio = raioCopo;
        for(float j=alturaCopo/2; j != -(alturaCopo/2); j -= it){
            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f((raio+raioIt)*sin(i), j-it, (raio+raioIt)*cos(i));
            glVertex3f(raio*sin(i), j, raio*cos(i));
            glEnd();

            glBegin(GL_TRIANGLES);
            glVertex3f(raio*sin(i+angulo), j, raio*cos(i+angulo));
            glVertex3f((raio+raioIt)*sin(i+angulo), j-it, (raio+raioIt)*cos(i+angulo));
            glVertex3f((raio+raioIt)*sin(i), j-it, (raio+raioIt)*cos(i));
            glEnd();
            raio += raioIt;
        }
    }

    glColor3f(1, 0, 0);
    // Borda
    for(float i=0; i < (2*M_PI); i = i + angulo){
        glBegin(GL_TRIANGLES);
        glVertex3f(raioCopo*sin(i), alturaCopo/2, raioCopo*cos(i));
        
        glVertex3f((raioCopo+border)*sin(i+angulo), alturaCopo/2, (raioCopo+border)*cos(i+angulo));
        glVertex3f(raioCopo*sin(i+angulo), alturaCopo/2, raioCopo*cos(i+angulo));
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex3f(raioCopo*sin(i), alturaCopo/2, raioCopo*cos(i));
        
        glVertex3f((raioCopo+border)*sin(i), alturaCopo/2, (raioCopo+border)*cos(i));
        glVertex3f((raioCopo+border)*sin(i+angulo), alturaCopo/2, (raioCopo+border)*cos(i+angulo));
        glEnd();
    }

    glPopMatrix();
}