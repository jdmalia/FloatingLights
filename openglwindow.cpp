#include "openglwindow.h"
#include <QTimer>
#include <QPainter>
#include <iostream>
#include <GLUT/glut.h>

OpenGLWindow::OpenGLWindow ()
    : BaseClass(BaseClass::NoPartialUpdate)
    , _m_frame(0)
    , _animating(true)
    , _rotation(0.0f)
{

    setSurfaceType(QWindow::OpenGLSurface);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSim()));

    int frame_rate = 30;
    timer->start(1000/frame_rate);
}

OpenGLWindow ::~OpenGLWindow ()
{
}


void OpenGLWindow::initializeGL()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, -1, 0.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    //glColorMaterial ( GL_FRONT_AND_BACK, GL_EMISSION ) ;
    glEnable ( GL_COLOR_MATERIAL ) ;

    // Enable Transparency
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLWindow::resizeGL(int w, int h)
{
    //NOT IMPLEMENTED
    (void)w;
    (void)h;
}

void OpenGLWindow::paintGL()
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glScalef(1,1,1);
    glLoadIdentity();
    GLUquadricObj *quadric=gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    glColor4f(1,1,1,.5);
    gluSphere(quadric, 0.1, 360,360);
    glTranslatef(.1,.1,0);
    gluSphere(quadric, 0.1, 360,360);
    gluDeleteQuadric(quadric);
    glPopMatrix();
}


void OpenGLWindow::setupVertex( Eigen::Vector3f& v, Eigen::Vector4f& c )
{
    glColor4f(c[0],c[1],c[2], c[3]);
    glVertex3f(v[0],v[1],v[2]);
}


void OpenGLWindow::updateSim()
{
    paintGL();
    update();
}


void OpenGLWindow::mouseMoveEvent(QMouseEvent* e)
{
}

void OpenGLWindow::mousePressEvent(QMouseEvent* e)
{
}

void OpenGLWindow::mouseReleaseEvent(QMouseEvent* e)
{
}

void OpenGLWindow::keyPressEvent(QKeyEvent* e)
{
}

void OpenGLWindow::keyReleaseEvent(QKeyEvent* e)
{
}
