#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

#define maxWD 800
#define maxHT 800
#define thetaSpeed 0.05

GLfloat angle = 45.0f;
GLfloat x = 0.5f;
GLfloat y = 0.0f;
GLfloat xScale = 0.01f; 
GLfloat yScale = 0.01f;
bool enlarge = true;
int refreshmill = 2;

void timer(int value){
    glutPostRedisplay();
    glutTimerFunc(refreshmill, timer, 0);
}

void execute_scale_tri(){
    if (enlarge && xScale <2.0f){
        xScale += 0.01f;
        yScale += 0.01f;
    } 
    else{
        enlarge = false;
    }

    if (enlarge == false && xScale >0.0f){
        xScale -= 0.01f;
        yScale -= 0.01f;
    } 
    else{
        enlarge = true;
    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glScalef(xScale,yScale,1.0f);
    // glTranslatef(x, 0.0f, 0.0f);
    // glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f( 0.0f, 0.0f);
    glVertex2f( 0.0f, 0.3f);
    glVertex2f( 0.5f, 0.0f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    float temp = x;
    x = y;
    y = temp;

}

void execute_scale_quad(){
    if (enlarge && xScale <2.0f){
        xScale += 0.01f;
        yScale += 0.01f;
    } 
    else{
        enlarge = false;
    }

    if (enlarge == false && xScale >0.0f){
        xScale -= 0.01f;
        yScale -= 0.01f;
    } 
    else{
        enlarge = true;
    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glScalef(xScale,yScale,1.0f);
    // glTranslatef(x, 0.0f, 0.0f);
    // glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    float temp = x;
    x = y;
    y = temp;

}

void execute_scale_circle(){
    if (enlarge && xScale <2.0f){
        xScale += 0.01f;
        yScale += 0.01f;
    } 
    else{
        enlarge = false;
    }

    if (enlarge == false && xScale >0.0f){
        xScale -= 0.01f;
        yScale -= 0.01f;
    } 
    else{
        enlarge = true;
    }
    
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glScalef(xScale,yScale,1.0f);
    // glTranslatef(x, 0.0f, 0.0f);
    // glRotatef(angle, 0.0f, 0.0f, 1.0f);
    float theta;
    int posX = 400;
    int posY = 400;
    int radio = 100;
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
    float temp = x;
    x = y;
    y = temp;

}

void execute_translate_tri(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(x, 0.0f, 0.0f);
    // glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f( 0.0f, 0.0f);
    glVertex2f( 0.0f, 0.3f);
    glVertex2f( 0.5f, 0.0f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    float temp = x;
    x = y;
    y = temp;

}

void execute_translate_quad(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(x, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
    float temp = x;
    x = y;
    y = temp;

}

void execute_translate_circle(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(x, 0.0f, 0.0f);
    float theta;
    int posX = 400;
    int posY = 400;
    int radio = 100;
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
    float temp = x;
    x = y;
    y = temp;

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
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,maxHT,0.0,maxWD);
    float theta;
    int posX = 400;
    int posY = 400;
    int radio = 100;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
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
    int opt_figure;
    switch (opt) {
    case 1:
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
        printf("\nEnter\n\t<1> for triangle"
               "\n\t<2> for square"
               "\n\t<3> for circle\n\t:");
        scanf("%d", &opt_figure);
        switch (opt_figure){
            case 1:
                glutDisplayFunc(execute_translate_tri);
                break;
            
            case 2:
                glutDisplayFunc(execute_translate_quad);
                break;

            case 3:
                glutDisplayFunc(execute_translate_circle);
                break;
            default:
                break;
        }
        break;
    case 3:
        printf("\nEnter\n\t<1> for triangle"
               "\n\t<2> for square"
               "\n\t<3> for circle\n\t:");
        scanf("%d", &opt_figure);
        switch (opt_figure){
            case 1:
                glutDisplayFunc(execute_scale_tri);
                break;
            
            case 2:
                glutDisplayFunc(execute_scale_quad);
                break;

            case 3:
                glutDisplayFunc(execute_scale_circle);
                break;
            default:
                break;
        }
        break;
        break;
    }
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(maxWD,maxHT);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Hello World!");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
