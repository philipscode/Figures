#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include <cstddef>
#include "basicshape.h"


class RegularPolygon : public BasicShape
{
public:
    RegularPolygon();
    RegularPolygon(string, size_t, size_t, size_t);
    RegularPolygon(const RegularPolygon&);
    size_t getNumberOfEdges() const;
    size_t getEdgeLength() const;
    size_t id() const override;
private:
    size_t numberOfEdges_;
    size_t edgeLength_;
};

#endif // REGULARPOLYGON_H
