#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "RgbImage.h"


//____________________________________________________________________________________

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

//____________________________________________________________________________________
// GLfloat xRotated, yRotated, zRotated;
GLuint  texture[1];         // Storage For One Texture ( NEW )
/*
* Read a texture map from a BMP bitmap file.
*/



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

/*
* Draw the texture in the OpenGL graphics window
*/
void drawScene(void)
{
   glMatrixMode(GL_MODELVIEW);
   // clear the drawing buffer.
   glClear(GL_COLOR_BUFFER_BIT);
   // clear the identity matrix.
   glLoadIdentity();

   glTranslatef(0.0,0.0,-20.0);

   glPushMatrix();


   // glTranslatef(0.0,0.0,0);
   // Set material properties
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaRed);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaRed);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);
      glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);
//_____________________________________________________________________________________

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, texture[0]);
   glLoadIdentity();
   glTranslatef(-0.5,-0.5,-4);
   //glRotatef(yRotated, 0, 1, 0);
   //   glRotatef(zRotated, 0, 0, 1);

   /* main rec */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (.5, .75, .35);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.1, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.575, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*back rec*/
    glColor3f (.5, .75, .35);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.1, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.1, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.575, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* left rec */
    glColor3f (.75, 0.75, .25);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.1, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.2, 0.1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.2, 0.575, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* right rec */
    glColor3f (.75, 0.75, .25);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.9, 0.1, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.1, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.575, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.9, 0.575, 0.5);
    glEnd();


    /* left tri */
    glColor3f (.5, 0.5, .25);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    /* right tri */
    glColor3f (.5, 0.5, .25);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

   glBindTexture(GL_TEXTURE_2D, texture[1]);
    /* roof */
    glColor3f (.55, 0.35, .2);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.575, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.575, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.8, 0.25);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*back roof */
    glColor3f (.55, 0.35, .2);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.2, 0.575, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.9, 0.575, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.9, 0.8, 0.25);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.2, 0.8, 0.25);
    glEnd();

   glBindTexture(GL_TEXTURE_2D, texture[2]);
    /* door */
    glColor3f (.15, 0.2, .3);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f); glVertex3f (0.47, 0.105, -0.005);
    glTexCoord2f(1.0f, 0.0f); glVertex3f (0.65, 0.105, -0.005);
    glTexCoord2f(1.0f, 1.0f); glVertex3f (0.65, 0.46, -0.005);
    glTexCoord2f(0.0f, 1.0f); glVertex3f (0.47, 0.46, -0.005);
    glEnd();

    /* window 1 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25,-0.005);
    glVertex3f (0.83, 0.25,-0.005);
    glVertex3f (0.83, 0.4,-0.005);
    glVertex3f (0.72, 0.4,-0.005);
    glEnd();

    /* window 2 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25,-0.005);
    glVertex3f (0.38, 0.25,-0.005);
    glVertex3f (0.38, 0.4,-0.005);
    glVertex3f (0.27, 0.4,-0.005);
    glEnd();

//_______________________________________________________________________________________________
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
   glDisable(GL_TEXTURE_2D);
   
}

void resizeWindow(int x, int y)
{
 if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

char* filename[] = {"/home/haziel/Programs/PDI/pdi_terceiro_trabalho/Red_Bricks_512x512.bmp",
                    "/home/haziel/Programs/PDI/pdi_terceiro_trabalho/TexturesCom_RooftilesCeramic0066_4_M.bmp",
                    "/home/haziel/Programs/PDI/pdi_terceiro_trabalho/TexturesCom_DoorsWoodSingleOld0243_1_M.bmp"};
void idleFunc(void)
{

     if ( zRotated > 360.0 ) {
        zRotated -= 360.0*floor(zRotated/360.0);   // Don't allow overflow
    }

    if ( yRotated > 360.0 ) {
        yRotated -= 360.0*floor(yRotated/360.0);   // Don't allow overflow
    }
    zRotated += 0.2;
    yRotated +=0.2;

    drawScene();
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

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(1920, 1920);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   initLighting();
   xRotated = yRotated = zRotated = 0.0;
   for ( int  i=0;i<3;i++)
   {
      loadTextureFromFile(filename[i], i);
   }

   glutDisplayFunc(drawScene);
   glutReshapeFunc(resizeWindow);
   glutKeyboardFunc(keyboard);
   glutIdleFunc(idleFunc);
   glutMainLoop();
   return 0;
}
