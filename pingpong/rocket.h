#ifndef ROCKET_H
#define ROCKET_H

#include "shape.h"
#include "line.h"

class Rocket : public Shape
{
public:
    Rocket();

    void OnDraw(QPainter& painter) override;

    void move_left();
    void move_right();

    Line get_line();

};

#endif // ROCKET_H
