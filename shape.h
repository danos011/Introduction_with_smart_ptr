#ifndef TECPROG1_SHAPE_H
#define TECPROG1_SHAPE_H

#include "base-types.h"

class Shape
{
public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t& center) = 0;

    virtual void move(const double dx, const double dy) = 0;

    virtual void show() const = 0;

    virtual void scale(const double k) = 0;
};

#endif // TECPROG1_SHAPE_H
