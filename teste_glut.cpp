#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

#define maxWD 640
#define maxHT 480
#define thetaSpeed 0.05

GLfloat angle = 45.0f;
int refreshmill = 1;

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(refreshmill, timer, 0);
}
void execute_rotate_quad(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.2;
}

void execute_rotate_circle(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    float theta;
    int posX = 400;
    int posY = 400;
    int radio = 100;
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f( 0.0f, 0.0f);
    glVertex2f( 0.0f, 0.3f);
    glVertex2f( 0.5f, 0.0f);
    for(int i=0; i<360; i++){
        theta = i*3.1416/180;
        glVertex2f(posX + radio*cos(theta), posY + radio*sin(theta));
    }
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.2;
}

void execute_rotate_tri(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    // glTranslatef(0.5f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f( 0.0f, 0.0f);
    glVertex2f( 0.0f, 0.3f);
    glVertex2f( 0.5f, 0.0f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.2;
}

void reshape(GLsizei width, GLsizei height){
    if(height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height){
        gluOrtho2D(-1.0*aspect, 1.0*aspect, -1.0, 1.0);
    }
    else{
        gluOrtho2D(-1.0, 1.0, 1.0/aspect, 1.0/aspect);
    }
}

void lineSegment(void) {
    float theta;
    int posX = 400;
    int posY = 400;
    int radio = 100;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.4,0.2);
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++){
        theta = i*3.1416/180;
        glVertex2f(posX + radio*cos(theta), posY + radio*sin(theta));
    }
    glEnd();
    glFlush();
}


// Actual display function
void myDisplay(void)
{
    int opt;
    printf("\nEnter\n\t<1> for rotation"
           "\n\t<2> for translate"
           "\n\t<3> for scaling\n\t:");
    scanf("%d", &opt);
    printf("\nGo to the window...");
    switch (opt) {
    case 1:
        int opt_figure;
        printf("\nEnter\n\t<1> for triangle"
               "\n\t<2> for square"
               "\n\t<3> for circle\n\t:");
        scanf("%d", &opt_figure);
        switch (opt_figure){
            case 1:
                glutDisplayFunc(execute_rotate_tri);
                break;
            
            case 2:
                glutDisplayFunc(execute_rotate_quad);
                break;

            case 3:
                glutDisplayFunc(execute_rotate_circle);
                break;
            default:
                break;
        }
        break;
    case 2:
        break;
    case 3:
        break;
    }
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(maxWD,maxHT);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Hello World!");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
