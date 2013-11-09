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

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   // glTranslatef(0.5, 0.5, 0);
    glRotatef(angle, 0.0, 0.0, 1.0);
     glTranslatef(-0.5, -0.5, 0);
     glBegin(GL_TRIANGLES);
     glColor3f(1.0, 0, 0);
     glVertex3f(0.0,0.0,0.0);
     glColor3f(0.0, 1, 0);
     glVertex3f(0.7,0.0,0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.227,0.446,0.0);
     glEnd();
    glutSwapBuffers();
    angle-=0.02;
    
}


void initFunc()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}


int main(int argc, char ** argv)
{
    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    //glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(400 , 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("xf");
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    //  glutSpecialFunc(SpecialKeys);
    glDepthFunc(GL_LEQUAL);
    
    glutDisplayFunc(&myDisplay);
    glutIdleFunc(&myDisplay);
       //  initFunc();
    glutMainLoop();
    
    // insert code here..
    return 0;
}

