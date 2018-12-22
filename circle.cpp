#include "circle.h"

Circle::Circle()
{
    transparency_ = 1;
    name_ = "circle";
    radiusLength_ = 1;
}

Circle::Circle(size_t transparency, size_t radiusLength)
{
    transparency_ = transparency;
    name_ = "circle";
    radiusLength_ = radiusLength;
}

Circle::Circle(const Circle &other)
{
    transparency_ = other.getTransparency();
    radiusLength_ = other.getRadiusLength();
}

size_t Circle::getRadiusLength() const
{
    return radiusLength_;
}

void Circle::setRadiusLength(size_t radiusLength)
{
    radiusLength_ = radiusLength;
}

size_t Circle::id() const
{
    return 1;
}
