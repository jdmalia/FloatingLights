#ifndef OpenGLWindow_H
#define OpenGLWindow_H

#include <QOpenGLWindow>
#include <QOpenGLPaintDevice>
#include <Eigen/Eigen>

#include <QMouseEvent>
#include <QKeyEvent>

#include "pointlight.h"

class OpenGLWindow: public QOpenGLWindow
{
    Q_OBJECT

    typedef QOpenGLWindow BaseClass;
    typedef OpenGLWindow  ThisClass;

public:
    OpenGLWindow();
    ~OpenGLWindow();

public slots:
    void updateSim();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void setupVertex( Eigen::Vector3f& v, Eigen::Vector4f& c );

    // EVENTS
    void mouseMoveEvent(QMouseEvent * e) override;
    void mousePressEvent(QMouseEvent * e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void keyPressEvent(QKeyEvent * e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

private:

    int _m_frame;

    bool _animating;

    float _rotation;
};
#endif // SMOKEWINDOW_H
