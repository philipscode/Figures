#ifndef CIRCLE_H
#define CIRCLE_H

#include "basicshape.h"


class Circle : public BasicShape
{
public:
    Circle();
    Circle(size_t, size_t);
    Circle(const Circle&);
    size_t getRadiusLength() const;
    void setRadiusLength(size_t);
    size_t id() const override;
private:
    size_t radiusLength_;
};

#endif // CIRCLE_H
