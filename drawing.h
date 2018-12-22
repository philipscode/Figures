#ifndef DRAWING_H
#define DRAWING_H

#include "basicshape.h"
#include "circle.h"
#include "regularpolygon.h"
#include <fstream>


class Drawing
{
public:

    friend std::ostream& operator <<(std::ostream &os, Drawing &drawing)
    {
        for (Drawing::iterator it = drawing.begin();
             it != drawing.end(); it++) {
            if ((*it)->id() == 1) {
                os << "-Circle:" << std::endl;
                Circle *circle = dynamic_cast<Circle*>(*it);
                os << circle->getName() << std::endl
                   << circle->getTransparency() << std::endl
                   << circle->getRadiusLength() << std::endl;
            } else {
                os << "-Regular Polygon:" << std::endl;
                RegularPolygon *regularPolygon =
                        dynamic_cast<RegularPolygon*>(*it);
                os << regularPolygon->getName() << std::endl
                   << regularPolygon->getTransparency() << std::endl
                   << regularPolygon->getNumberOfEdges() << std::endl
                   << regularPolygon->getEdgeLength() << std::endl;
            }
        }
        return os;
    }

    struct Node
    {
        BasicShape *figure;
        Node *next;
    };

    class iterator
    {
    public:
        iterator()
            : itr(nullptr)
        {
        }
        iterator(Node* ptr)
            : itr(ptr)
        {
        }
        iterator& operator++ ()
        {
            itr = itr->next;
            return *this;
        }
        iterator operator++ (int)
        {
            iterator temp(*this);
            itr = itr->next;
            return temp;
        }
        bool operator ==(const iterator& rs) const
        {
            return itr == rs.itr;
        }
        bool operator !=(const iterator& rs) const
        {
            return itr != rs.itr;
        }
        BasicShape* operator *()
        {
            return itr->figure;
        }
    private:
        Node *itr;
    };

    iterator begin() const
    {
        return iterator(first);
    }
    iterator end() const
    {
        if (last == nullptr)
            return iterator(last);
        else
            return iterator(last->next);
    }

    Drawing(); //default constructor
    Drawing(const Drawing&); //copy constructor
    void push(BasicShape*); //insert to the end
    BasicShape* pop(); //remove from the front
    void removeAll(); //remove all
    size_t size() const;
private:
    Node *first, *last;
    size_t size_;
};

#endif // DRAWING_H
