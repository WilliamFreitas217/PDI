#include <GL/glut.h>
#include <math.h>      // For math routines (such as sqrt & trig).
#include "RgbImage.h"

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
GLuint  texture[1];

void display(void);
void reshape(int x, int y);

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

void loadTextureFromFile(char *filename,int index)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);

   RgbImage theTexMap( filename );

  glGenTextures(1, &texture[index]);                    // Create The Texture
   glBindTexture(GL_TEXTURE_2D, texture[index]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


        // Typical Texture Generation Using Data From The Bitmap

        glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 1, GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() );





}

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
void keyboard(unsigned char key, int x, int y)
{


     if (key == 'l' || key == 'L')
    {
          glEnable(GL_LIGHTING);
    }
    else if (key == 'd' || key == 'D')
    {
        glDisable(GL_LIGHTING);
    }

}

char* filename[] = {"/home/haziel/Programs/PDI/pdi_terceiro_trabalho/Red_Bricks_512x512.bmp",
                    "/home/haziel/Programs/PDI/pdi_terceiro_trabalho/TexturesCom_RooftilesCeramic0066_4_M.bmp",
                    "/home/haziel/Programs/PDI/pdi_terceiro_trabalho/TexturesCom_DoorsWoodSingleOld0243_1_M.bmp"};

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(350,350);
    glutCreateWindow("Teapot -");
    initLighting();
    for ( int  i=0;i<3;i++)
   {
      loadTextureFromFile(filename[i], i);
   }

    xRotated = yRotated = zRotated = 0.0;

    glutIdleFunc(idleFunc);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void display(void)
{
   glMatrixMode(GL_MODELVIEW);
   // clear the drawing buffer.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glLoadIdentity();
   glTranslatef(-0.5,-0.5,-4);
   //glRotatef(yRotated, 0, 1, 0);
   //   glRotatef(zRotated, 0, 0, 1);

   /* main rec */
   // glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.1, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.575, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*back rec*/
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.1, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.1, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.575, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* left rec */
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.1, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.2, 0.1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.2, 0.575, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* right rec */
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.9, 0.1, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.575, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.9, 0.575, 0.5);
    glEnd();


    /* left tri */
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    /* right tri */
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

   glBindTexture(GL_TEXTURE_2D, texture[1]);
    /* roof */
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.575, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.575, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.8, 0.25);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*back roof */
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.575, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.575, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.8, 0.25);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.8, 0.25);
    glEnd();

   glBindTexture(GL_TEXTURE_2D, texture[2]);
    /* door */
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.47, 0.105, 0.6);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.65, 0.105, 0.6);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.65, 0.46, 0.6);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.47, 0.46, 0.6);
    glEnd();

    /* window 1 */
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25,0.6);
    glVertex3f (0.83, 0.25,0.6);
    glVertex3f (0.83, 0.4,0.6);
    glVertex3f (0.72, 0.4,0.6);
    glEnd();

    /* window 2 */
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25,0.6);
    glVertex3f (0.38, 0.25,0.6);
    glVertex3f (0.38, 0.4,0.6);
    glVertex3f (0.27, 0.4,0.6);
    glEnd();

    glPopMatrix();



    glPushMatrix();
    glRotatef(yRotated,0.0,1.0,0.0);
    glTranslatef(5.0,0.0,0.0);
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

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,40.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}
