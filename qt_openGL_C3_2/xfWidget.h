#ifndef xfWIDGET_H
#define xfWIDGET_H


#include <QtCore>
#include <QtGui>
#include <QtOpenGL>
class xfWidget : public QGLWidget
{
        Q_OBJECT

public:
        xfWidget( QWidget* parent = 0 );
        ~xfWidget();

protected:
        void initializeGL();
        void paintGL();
        void resizeGL( int width, int height );
        void keyPressEvent(QKeyEvent *e);
        void mousePressEvent(QMouseEvent *e);
        void mouseMoveEvent(QMouseEvent *e);
        void wheelEvent(QWheelEvent *e);
        void loadGLTextures();
private:
        int base;
        float angle;
        GLuint texture[6];
        GLfloat scaling;
        GLfloat xrot, yrot, zrot;
        QPoint lastPos;
        GLfloat posx,posy;


};

#endif//xfWIDGET_H
