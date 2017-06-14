#ifndef BALL_H
#define BALL_H

#include "shape.h"
#include "line.h"

class Ball : public Shape
{
public:
    Ball();

    int w = 0;
    int h = 0;

    void OnDraw(QPainter& painter) override;
    void move();
    void tryMirror(int x_min, int y_top, int max_x, int max_y);

    Point get_point();

};

#endif // BALL_H
