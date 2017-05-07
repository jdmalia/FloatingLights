#include "openglwindow.h"
#include <QTimer>
#include <QPainter>
#include <iostream>

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
    glClearColor(0.0f, 0.0f,0.0f, 1.0f);

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
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
