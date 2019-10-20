#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;

const float t = -0.6;

void delay(unsigned int mseconds) 
{ 
    clock_t goal = mseconds + clock(); 
    while (goal > clock()); 
}
 
void translate(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f( 0.0 + t, 0.0 + t);
        glVertex2f( 0.0 + t, 0.3 + t);
        glVertex2f( 0.5 + t, 0.0 + t);
    glEnd();
    glFlush();
}

void translatePoint(){
    while(true){
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
            // glVertex3f(0.5, 0.0, 0.5);
            // glVertex3f(0.5, 0.0, 0.0);
            // glVertex3f(0.0, 0.5, 0.0);
            // glVertex3f(0.0, 0.0, 0.5);
            glVertex2f( 0.0, 0.0);
            glVertex2f( 0.0, 0.3);
            glVertex2f( 0.5, 0.0);
        glEnd();
        translate();
        glFlush();
        glutDisplayFunc(translatePoint);
        delay(1000);
    }
}

void myDisplay(){ 
    int opt; 
    printf("\nEnter\n\t<1> for translation"
           "\n\t<2> for rotation"
           "\n\t<3> for scaling\n\t:"); 
    scanf("%d", &opt); 
    printf("\nGo to the window..."); 
    switch (opt) { 
    case 1: 
        translatePoint(); 
        break; 
    case 2: 
        // rotateAroundPt(200, 200, maxWD / 2, maxHT / 2); 
        // point will circle around 
        // the centre of the window 
        break; 
    case 3: 
        // scalePoint(10, 20, 2, 3); 
        break; 
    } 
}
 
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}