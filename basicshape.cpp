#include "basicshape.h"

string BasicShape::getName() const
{
    return name_;
}

double BasicShape::getTransparency() const
{
    return transparency_;
}

void BasicShape::setTransparency(double transparency)
{
    transparency_ = transparency;
}
