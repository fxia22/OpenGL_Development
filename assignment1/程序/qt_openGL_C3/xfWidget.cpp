#include "xfWidget.h"
#include <OpenGL/glu.h>
xfWidget::xfWidget( QWidget* parent )
    : QGLWidget( parent )
{
    setGeometry( 150, 100, 1024, 576 );
    scaling = 1.0;
    xrot = yrot = zrot = 0.0f;
    posx = posy = 0.0f;
    showMaximized();
}

xfWidget::~xfWidget()
{
}

void xfWidget::initializeGL()
{

    loadGLTextures();
    glEnable(GL_TEXTURE_2D);
   // glEnable(GL_TEXTURE_3D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void xfWidget::loadGLTextures()
{
    QString images[6] = {"1.png", "2.png", "3.png","4.png", "5.png", "6.png"};
    glGenTextures(6, &texture[0]);
    for (int i = 0; i < 6; ++i) {
        QImage t;
        QString now = QString("/Volumes/Macintosh HD/dev/OpenGL/OpenGL_Development/qt_openGL_helloworld/images/")+images[i];
        QImage b(now);
        t = QGLWidget::convertToGLFormat(b);

        glBindTexture(GL_TEXTURE_2D, texture[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());
        //glTexImage3D(GL_TEXTURE_3D, 0, 3, t.width(), t.height(),0, 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
}


void xfWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(posx,-posy,-6.0f);
    glScalef(scaling, scaling, scaling);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glRotatef(zrot, 0.0f, 0.0f, 1.0f);

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    // Front face
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_QUADS);
    // Back face
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_QUADS);
    // Top face
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    glEnd();

    // Bottom face
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glEnd();

    // Right face
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f,  1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f,  1.0f);
    glEnd();

    // Left face
    glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
    glEnd();

}

void xfWidget::resizeGL( int width, int height )
{
    height = height?height:1;
    glViewport( 0, 0, (GLint)width, (GLint)height );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void xfWidget::keyPressEvent(QKeyEvent *e)
{
    switch (e->key()) {
    case Qt::Key_Enter:
        if (isFullScreen())
            showNormal();
        else
            showFullScreen();
        break;
     case Qt::Key_Escape:
        exit(0);
    default:
        QGLWidget::keyPressEvent(e);
    }
}

void xfWidget::mousePressEvent(QMouseEvent *e)
{
    lastPos = e->pos();
}

void xfWidget::mouseMoveEvent(QMouseEvent *e)
{
    GLfloat dx = GLfloat(e->x() - lastPos.x()) / width();
    GLfloat dy = GLfloat(e->y() - lastPos.y()) / height();
    if (e->buttons() & Qt::LeftButton) {
        xrot += 180 * dy;
        yrot += 180 * dx;
        updateGL();
    } else if (e->buttons() & Qt::RightButton) {
        xrot -= 180 * dy;
        zrot -= 180 * dx;
        updateGL();
    } else if (e->buttons() & Qt::MiddleButton) {
        posx+=dx*10.24;
        posy+=dy*5.76;
     updateGL();
     }
    lastPos = e->pos();

}


void xfWidget::wheelEvent(QWheelEvent *e)
{
    double numDegrees = -e->delta() / 8.0;
    double numSteps = numDegrees / 15.0;
    scaling *= pow(1.125, numSteps);
    updateGL();
}
