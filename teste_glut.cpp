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

void execute_rotate(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    // glTranslatef(0.5f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    // glBegin(GL_TRIANGLES);
    // glColor3f(0.0f, 0.0f, 1.0f);
    // glVertex2f( 0.0f, 0.0f);
    // glVertex2f( 0.0f, 0.3f);
    // glVertex2f( 0.5f, 0.0f);
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

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void init(void) {
    // glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(0.0, 0.0, 0.0,0.0);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // gluOrtho2D(0.0,maxWD,0.0,maxHT);
}

void drawPoint(int x, int y)
{
    glPointSize(7.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void rotateAroundPt(int px, int py, int cx, int cy)
{
    float theta = 0.0;
    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);
        int xf, yf;

        // update theta anticlockwise rotation
        theta = theta + thetaSpeed;

        // check overflow
        if (theta >= (2.0 * 3.14159))
            theta = theta - (2.0 * 3.14159);

        // actual calculations..
        xf = cx + (int)((float)(px - cx) * cos(theta))
             - ((float)(py - cy) * sin(theta));
        yf = cy + (int)((float)(px - cx) * sin(theta))
             + ((float)(py - cy) * cos(theta));

        // drawing the centre point
        drawPoint(cx, cy);

        // drawing the rotating point
        drawPoint(xf, yf);
        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(10);
    }
}

void translatePoint(int px, int py, int tx, int ty)
{
    int fx = px, fy = py;
    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);

        // update
        px = px + tx;
        py = py + ty;

        // check overflow to keep point in screen
        if (px > maxWD || px < 0 || py > maxHT || py < 0) {
            px = fx;
            py = fy;
        }

        drawPoint(px, py); // drawing the point

        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(10);
    }
}

void scalePoint(int px, int py, int sx, int sy)
{
    int fx, fy;
    while (1) {
        glClear(GL_COLOR_BUFFER_BIT);

        // update
        fx = px * sx;
        fy = py * sy;

        drawPoint(fx, fy); // drawing the point

        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(500);

        glClear(GL_COLOR_BUFFER_BIT);

        // update
        fx = px;
        fy = py;

        // drawing the point
        drawPoint(fx, fy);
        glFlush();
        // creating a delay
        // so that the point can be noticed
        delay(500);
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
        execute_rotate();
        // rotateAroundPt(200, 200, maxWD / 2, maxHT / 2);
        break;
    case 2:
        translatePoint(100, 200, 1, 5);
        break;
    case 3:
        scalePoint(10, 20, 2, 3);
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(maxWD,maxHT);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Hello World!");
    // init();
    glutDisplayFunc(execute_rotate);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
