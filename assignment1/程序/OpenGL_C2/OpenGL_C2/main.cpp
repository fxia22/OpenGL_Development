//
//  main.cpp
//  OpenGL_C1
//
//  Created by xf on 13-10-28.
//  Copyright (c) 2013年 xf. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
float angle = 0.0;
bool paint  = true;
void myDisplay()
{
    if (paint) glShadeModel(GL_SMOOTH);
         else glShadeModel(GL_FLAT);
   // glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //glScalef(0.2, 0.2, 0.2);
    glTranslatef(1,2,3);
    glTranslatef(0, 0, -10.0f);
    
    glRotatef(angle, 1, 0, 0.0);
   
    glBegin(GL_QUADS);
    // Front face
   glColor3f(-0.5f, -0.5f, 0.5f);
   glVertex3f(-0.5f, -0.5f, 0.5f);
   glColor3f(0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glColor3f(0.5f, 0.5f, 0.5f);
   glVertex3f( 0.5f,  0.5f, 0.5f);
    glColor3f(-0.5f, 0.5f, 0.5f);
   glVertex3f(-0.5f,  0.5f, 0.5f);
    glEnd();
    
    glBegin(GL_QUADS);
    // Back face
    glColor3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glColor3f(0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glColor3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glEnd();
    
    
    glBegin(GL_QUADS);
    // Top face
    glColor3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glColor3f(-0.5f, 0.5f,  0.5f);
    
    glVertex3f(-0.5f, 0.5f,  0.5f);
    glColor3f( 0.5f, 0.5f,  0.5f);
    
    glVertex3f( 0.5f, 0.5f,  0.5f);
    glColor3f( 0.5f, 0.5f, -0.5f);
    
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glEnd();
    
    // Bottom face
    
    glBegin(GL_QUADS);
    glColor3f(-0.5f, -0.5f, -0.5f);
    
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor3f( 0.5f, -0.5f, -0.5f);
    
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glColor3f( 0.5f, -0.5f,  0.5f);
    
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glColor3f(-0.5f, -0.5f,  0.5f);
    
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glEnd();
    
    // Right face
    glBegin(GL_QUADS);
    glColor3f(0.5f, -0.5f, -0.5f);
    
    glVertex3f(0.5f, -0.5f, -0.5f);
    glColor3f(0.5f,  0.5f, -0.5f);
    
    glVertex3f(0.5f,  0.5f, -0.5f);
    glColor3f(0.5f,  0.5f,  0.5f);
    
    glVertex3f(0.5f,  0.5f,  0.5f);
    glColor3f(0.5f, -0.5f,  0.5f);
    
    glVertex3f(0.5f, -0.5f,  0.5f);
    glEnd();
    
    // Left face
    glBegin(GL_QUADS);
    glColor3f(-0.5f, -0.5f, -0.5f);
    
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor3f(-0.5f, -0.5f,  0.5f);
    
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glColor3f(-0.5f,  0.5f,  0.5f);
    
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glColor3f(-0.5f,  0.5f, -0.5f);
    
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glEnd();

    glutSwapBuffers();
    angle-=0.05;
    // std::cout<<paint;
}

void processNormalKeys(unsigned char key, int x, int y) {
    
    if (key == ' ')
        paint  = !paint;
}

void initFunc()
{
    glClearColor(0.5f, 0.0f, 0.0f, 0.0f);
}
void reshape( int width, int height )
{
    height = height?height:1;
    glViewport( 0, 0, (GLint)width, (GLint)height );
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char ** argv)
{
    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(400 , 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("xf");
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    glDepthFunc(GL_LEQUAL);
    glutKeyboardFunc(&processNormalKeys);
    glutDisplayFunc(&myDisplay);
    glutIdleFunc(&myDisplay);
    glutReshapeFunc(&reshape);
    glutMainLoop();
    return 0;
}

