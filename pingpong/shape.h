#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPainter>
#include <QEvent>
#include <QKeyEvent>

class Shape
{
public:
    Shape(int x, int y, int w, int h, int dx, int dy);
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_dx;
    int m_dy;


    virtual void OnDraw(QPainter& painter) = 0;
};

#endif // SHAPE_H
