#ifndef TECPROG1_RING_H
#define TECPROG1_RING_H

#include <string>

#include "shape.h"
#include "base-types.h"
#include "Exeptions.h"

class Ring : public Shape{
private:
    double outerRadius_;
    double innerRadius_;
    point_t center_;

public:
    Ring(const point_t& center,const double outerRadius,const double innerRadius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(const double dx, const double dy) override;
    void show() const override;
    void scale(const double k) override;
};


#endif //TECPROG1_RING_H
