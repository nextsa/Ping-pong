#include "ball.h"
#include <cstdlib>

Ball::Ball():
    Shape(0, 67, 15, 15, 15, 15)
{

}

void Ball::OnDraw(QPainter& painter)
{
    painter.drawEllipse(m_x, m_y, m_w, m_h);
}

void Ball::move()
{
    m_x += m_dx;
    m_y += m_dy;

}

void Ball::tryMirror(int x_min, int y_top, int max_x, int max_y)
{
     w = m_x + m_w;
     h = m_y + m_h;

    if (w >= max_x ||  m_x <= x_min)
    {
        m_dx = -m_dx;
    }
    if ( m_y <= y_top)
    {
        m_dy = - m_dy;
    }


    if (h >= max_y )
    {
        m_x = rand()%670;
        m_y = 67;
    }
}

Point Ball::get_point()
{
    Point p;
    p.x = m_x + m_w/2;
    p.y = m_y + m_h;

    return p;
}
