#include "rocket.h"

Rocket::Rocket():
    Shape(90, 470, 100, 10, 5, 5)
{

}

void Rocket::OnDraw(QPainter& painter)
{
    painter.drawRect(m_x, m_y, m_w, m_h);
}

void Rocket::move_left()
{
    m_x -= m_dx ;
}

void Rocket::move_right()
{
    m_x += m_dx ;
}

Line Rocket::get_line()
{
    Line ln;
    ln.x1 = m_x;
    ln.y1 = m_y;
    ln.x2 = m_w + m_x;
    ln.y2 = m_y;

    return ln;
}
