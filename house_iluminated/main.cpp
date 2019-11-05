//header

#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<cstring>

//globals

GLuint elephant;
float elephantrot;
char ch='1';

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=2;
GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0}; //Black Color
GLfloat qaGreen[] = {1.0, 0.0, 0.0, 1.0}; //Green Color
GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0}; //White Color
GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0}; //Red Color

    // Set lighting intensity and color
GLfloat qaAmbientLight[]    = {0.1, 0.1, 0.1, 1.0};
GLfloat qaDiffuseLight[]    = {1, 1, 1, 1.0};
GLfloat qaSpecularLight[]    = {1.0, 1.0, 1.0, 1.0};
GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
    // Light source position
GLfloat qaLightPosition[]    = {0, 0, 0, 1};// Positional Light
GLfloat qaLightDirection[]    = {1, 1, 1, 0};// Directional Light

void display(void);
void reshape(int x, int y);
//other functions and main

//.obj loader code begins


void initLighting()
{

    // Enable lighting
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

     // Set lighting intensity and color
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    ////////////////////////////////////////////////


}

void loadObj(char *fname){
    FILE *fp;
    int read;
    GLfloat x, y, z;
    elephant=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp){
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(elephant, GL_COMPILE);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    while(!(feof(fp))){
        char ch[128];
        fscanf(fp, "%s", ch);
        if ( strcmp( ch, "v" ) == 0 ){
            fscanf(fp, "%f %f %f\n", &x, &y, &z );
            glVertex3f(x,y,z);
        }
        if ( strcmp( ch, "vn" ) == 0 ){
            fscanf(fp, "%f %f %f\n", &x, &y, &z);
            glVertex3f(x,y, z);
        }
        if ( strcmp( ch, "f" ) == 0 ){
            unsigned int x1, x2, x3, y1, y2 ,y3, z1, z2, z3;
            fscanf(fp, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &x1, &y1, &z1,&x2, &y2, &z2, &x3, &y3, &z3);
            glVertex3d(x1,y1, z1);
            glVertex3d(x2,y2, z2);
            glVertex3d(x3,y3, z3);
        }
    }
    glEnd();
    glPopMatrix();
    glEndList();
    fclose(fp);
}

//.obj loader code ends here

void idleFunc(void)
{
    if ( zRotated > 360.0 ) {
        zRotated -= 360.0*floor(zRotated/360.0);   // Don't allow overflow
    }

    if ( yRotated > 360.0 ) {
        yRotated -= 360.0*floor(yRotated/360.0);   // Don't allow overflow
    }
    zRotated += 2;
    yRotated +=2;

    display();
}

void reshape(int w,int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
    //glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	//glOrtho(-25,25,-2,2,0.1,100);
	glMatrixMode(GL_MODELVIEW);
}

void drawCar(){
 	glPushMatrix();
 	glTranslatef(-5.0,-2.0,7.0);
 	glColor3f(1.0,0.23,0.27);
 	//glScalef(0.1,0.1,0.1);
 	//glRotatef(elephantrot,0,1,0);
 	glCallList(elephant);
 	glPopMatrix();
 	//elephantrot=elephantrot+0.6;
 	//if(elephantrot>360)elephantrot=elephantrot-360;
}

void display(void)
{


    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();

    glTranslatef(0.0,0.0,-20.0);

   glPushMatrix();


    glTranslatef(0.0,0.0,0);
    // Set material properties
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaRed);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaRed);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);

    drawCar();
    glPopMatrix();



    glPushMatrix();
    glRotatef(yRotated,0.0,1.0,0.0);
    glTranslatef(25.0,0.0,0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emitLight);   // Make sphere glow (emissive)
    glutSolidSphere(radius/6,25,25);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Noemit);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-yRotated,0.0,1.0,0.0);
    glTranslatef(5.0,0.0,0.0);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glPopMatrix();


    glFlush();
    glutSwapBuffers();

}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(20,20);
	glutCreateWindow("ObjLoader");
	initLighting();
	xRotated = yRotated = zRotated = 0.0;
	glutReshapeFunc(reshape);
    glutDisplayFunc(display);
	glutIdleFunc(idleFunc);
    loadObj("/home/indtusuario/UEA/PDI/house_iluminated/Cyprys_House_obj/Cyprys_House.obj");//replace elepham.obj withp orsche.obj or radar.obj or any other .obj to display it
	glutMainLoop();
	return 0;
}
