//
//  main.cpp
//  OpenGL_C1
//
//  Created by xf on 13-10-28.
//  Copyright (c) 2013年 xf. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    /* glBegin(GL_TRIANGLES);
     glVertex3f(-0.5,-0.5,0.0);
     glVertex3f(0.5,0.0,0.0);
     glVertex3f(0.0,0.5,0.0);
     glEnd();*/
    //glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
    // glFlush();
    glPointSize(5.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.5f,0.0f);
    glEnd();
    glBegin(GL_POINTS);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.5f,0.0f);
    glEnd();
    
    //glFlush();
    glutSwapBuffers();
}


void initFunc()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
}


int main(int argc, char ** argv)
{
    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    //glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(400 , 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("xf");
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    //  glutSpecialFunc(SpecialKeys);
    glDepthFunc(GL_LEQUAL);
    
    glutDisplayFunc(&myDisplay);
    // glutIdleFunc(&myIdle);
       //  initFunc();
    glutMainLoop();
    
    // insert code here..
    return 0;
}

