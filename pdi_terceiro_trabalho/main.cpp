#include <GL/gl.h>
#include <GL/glut.h>
#include "RgbImage.h"

//angle of rotation
GLfloat angle = 0.0;

//diffuse light color variables
GLfloat dlr = 1.0;
GLfloat dlg = 1.0;
GLfloat dlb = 1.0;

//ambient light color variables
GLfloat alr = 1.0;
GLfloat alg = 1.0;
GLfloat alb = 1.0;

//light position variables
GLfloat lx = 0.0;
GLfloat ly = 0.0;
GLfloat lz = 1.0;
GLfloat lw = 0.0;

GLuint  texture[1];

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

//draw the cube
void cube (void) {
    glRotatef(angle, 1.0, 0.0, 0.0); //rotate on the x axis
    glRotatef(angle, 0.0, 1.0, 0.0); //rotate on the y axis
    glRotatef(angle, 0.0, 0.0, 1.0); //rotate on the z axis

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glLoadIdentity();
    glTranslatef(-0.5, -0.5, -4);
   //glRotatef(yRotated, 0, 1, 0);
   //glRotatef(zRotated, 0, 0, 1);

   glPushMatrix();
   /* main rec */
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
}

void init (void) {
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glEnable (GL_LIGHT1); //enable LIGHT1, our Ambient Light
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader

}

void display (void) {
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glLoadIdentity();
    GLfloat DiffuseLight[] = {dlr, dlg, dlb}; //set DiffuseLight [] to the specified values
    GLfloat AmbientLight[] = {alr, alg, alb}; //set AmbientLight [] to the specified values
    glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight); //change  the light accordingly
    glLightfv (GL_LIGHT1, GL_AMBIENT, AmbientLight); //change  the light accordingly
    GLfloat LightPosition[] = {lx, ly, lz, lw}; //set the LightPosition to the specified values
    glLightfv (GL_LIGHT0, GL_POSITION, LightPosition); //change the light accordingly
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //camera position, x,y,z, looking at x,y,z, Up Positions of the camera
    cube(); //call the cube drawing function
    glutSwapBuffers(); //swap the buffers
    angle++; //increase the angle
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport  to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void keyboard (unsigned char key, int x, int y) {
    if (key=='r') {
        dlr = 1.0; //change light to red
        dlg = 0.0;
        dlb = 0.0;
    }
    if (key=='g') {
        dlr = 0.0; //change light to green
        dlg = 1.0;
        dlb = 0.0;
    }
    if (key=='b') {
        dlr = 0.0; //change light to blue
        dlg = 0.0;
        dlb = 1.0;
    }
    if (key=='w') {
        ly += 10.0; //move the light up
    }
    if (key== 's') {
        ly -= 10.0; //move the light down
    }
    if (key=='a') {
        lx -= 10.0; //move the light left
    }
    if (key=='d') {
        lx += 10.0; //move the light right
    }
}

char* filename[] = {"/home/indtusuario/UEA/PDI/pdi_terceiro_trabalho/Red_Bricks_512x512.bmp",
                    "/home/indtusuario/UEA/PDI/pdi_terceiro_trabalho/TexturesCom_RooftilesCeramic0066_4_M.bmp",
                    "/home/indtusuario/UEA/PDI/pdi_terceiro_trabalho/TexturesCom_DoorsWoodSingleOld0243_1_M.bmp"};

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); //set the display to Double buffer, with depth
    glutInitWindowSize (500, 500); //set the window size glutInitWindowPosition (100, 100); //set the position of the window
    glutCreateWindow ("A basic OpenGL Window"); //the caption  of the window
    init (); //call the init function
    for ( int  i=0;i<3;i++)
   {
      loadTextureFromFile(filename[i], i);
   }
    glutDisplayFunc (display); //use the display function to draw everything
    glutIdleFunc (display); //update any variables in display,  display can be changed to anyhing, as long as you move the variables to be updated, in this case, angle++;
    glutReshapeFunc (reshape); //reshape the window accordingly

    glutKeyboardFunc (keyboard); //check the keyboard
    glutMainLoop (); //call the main loop
    return 0;
}