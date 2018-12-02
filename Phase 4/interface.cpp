#include "interface.h"


bool keys[10];

// FPS Cam
float camX = 0, camY = -60, camZ = -100;
float eyeX = 0, eyeY = 0;

bool mouseDown = false;
float lastx, lasty;

float eyeFac = 1.0;
float moveFac = 1.0;
float eyeFacF = 2.0;
float moveFacF = 10.0;

float eyeFacCamera = 0.5;

void processkeys(){

    float rotX = (eyeX / 180 * M_PI); 
    float rotY = (eyeY / 180 * M_PI); 


    if(keys[8]){
        // W
        if(keys[0]){
            camX -= sin(rotY)*moveFacF;
            camY += sin(rotX)*moveFacF;
            camZ += cos(rotY)*moveFacF;
            if(camY > -2){
                camY = -2;
            }
        }

        // S
        if(keys[1]){
            camX += sin(rotY)*moveFacF;
            camY -= sin(rotX)*moveFacF;
            camZ -= cos(rotY)*moveFacF;
            if(camY > -2){
                camY = -2;
            }
        }

        // A
        if(keys[2]){
            camX += cos(rotY)*moveFacF;
            camZ += sin(rotY)*moveFacF;
        }

        // D
        if(keys[3]){
            camX -= cos(rotY)*moveFacF;
            camZ -= sin(rotY)*moveFacF;
        }

        // I
        if(keys[4]){
            eyeX -= eyeFacF;
        }

        // K
        if(keys[5]){
            eyeX += eyeFacF;
        }

        // J
        if(keys[6]){
            eyeY -= eyeFacF;   
        }

        // L
        if(keys[7]){
            eyeY += eyeFacF;
        }
    }

    if(!keys[8]){
        // W
        if(keys[0]){
            camX -= sin(rotY)*moveFac;
            camY += sin(rotX)*moveFac;
            camZ += cos(rotY)*moveFac;
            if(camY > -2){
                camY = -2;
            }
        }

        // S
        if(keys[1]){
            camX += sin(rotY)*moveFac;
            camY -= sin(rotX)*moveFac;
            camZ -= cos(rotY)*moveFac;
            if(camY > -2){
                camY = -2;
            }
        }

        // A
        if(keys[2]){
            camX += cos(rotY)*moveFac;
            camZ += sin(rotY)*moveFac;
        }

        // D
        if(keys[3]){
            camX -= cos(rotY)*moveFac;
            camZ -= sin(rotY)*moveFac;
        }

        // I
        if(keys[4]){
            eyeX -= eyeFac;
        }

        // K
        if(keys[5]){
            eyeX += eyeFac;
        }

        // J
        if(keys[6]){
            eyeY -= eyeFac;   
        }

        // L
        if(keys[7]){
            eyeY += eyeFac;
        }
    }

    if(keys[9]){
        camX = 0; camY = -15; camZ = -40;
    }
    
}

void updateCam(){
    glRotatef(eyeX,1.0,0.0,0.0);

    glRotatef(eyeY,0.0,1.0,0.0);

    glTranslated(camX, camY, camZ);
}

void key_pressed(unsigned char key, int x, int y) {
    switch(key){
        case 'w' : keys[0] = true; break;

        case 's' : keys[1] = true;break;

        case 'a' : keys[2] = true;break;

        case 'd' : keys[3] = true;break;

        case 'i' : keys[4] = true;break;

        case 'k' : keys[5] = true;break;

        case 'j' : keys[6] = true;break;

        case 'l' : keys[7] = true;break;

        case ' ' : keys[8] = true;break;

        case 'h' : keys[9] = true;break;
    }
    glutPostRedisplay();
}

void key_released(unsigned char key, int x, int y) {
    switch(key){
        case 'w' : keys[0] = false; break;

        case 's' : keys[1] = false;break;

        case 'a' : keys[2] = false;break;

        case 'd' : keys[3] = false;break;

        case 'i' : keys[4] = false;break;

        case 'k' : keys[5] = false;break;

        case 'j' : keys[6] = false;break;

        case 'l' : keys[7] = false;break;

        case ' ' : keys[8] = false;break;

        case 'h' : keys[9] = false;break;

    }
    glutPostRedisplay();
}


void processMouseMotion(int x, int y) {
    int diffx=x-lastx;
    int diffy=y-lasty;
    lastx=x;
    lasty=y;
    eyeX += (float) diffy*eyeFacCamera;
    eyeY += (float) diffx*eyeFacCamera;
}