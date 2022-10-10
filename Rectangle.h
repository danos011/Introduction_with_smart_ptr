#ifndef TECPROG1_RECTANGLE_H
#define TECPROG1_RECTANGLE_H

#include <string>
#include <cmath>

#include "base-types.h"
#include "shape.h"
#include "Exeptions.h"

class Rectangle : public Shape
{
private:
    point_t bottomLeft_;
    point_t upperRight_;
    point_t center_;

public:
    Rectangle(const point_t& bottomLeft, const point_t& upperRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(const double dx, const double dy) override;
    void show() const override;
    void scale(const double k) override;
};

#endif // TECPROG1_RECTANGLE_H
