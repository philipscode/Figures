#include "regularpolygon.h"

RegularPolygon::RegularPolygon()
{
    name_ = "line";
    transparency_ = 1;
    numberOfEdges_ = 1;
    edgeLength_ = 1;
}

RegularPolygon::RegularPolygon(string name,
                               size_t transparency,
                               size_t numberOfEdges,
                               size_t edgeLength)
{
    name_ = name;
    transparency_ = transparency;
    numberOfEdges_ = numberOfEdges;
    edgeLength_ = edgeLength;
}

RegularPolygon::RegularPolygon(const RegularPolygon &other)
{
    name_ = other.getName();
    transparency_ = other.getTransparency();
    numberOfEdges_ = other.getNumberOfEdges();
    edgeLength_ = other.getEdgeLength();
}

size_t RegularPolygon::getNumberOfEdges() const
{
    return numberOfEdges_;
}

size_t RegularPolygon::getEdgeLength() const
{
    return edgeLength_;
}

size_t RegularPolygon::id() const
{
    return 2;
}
