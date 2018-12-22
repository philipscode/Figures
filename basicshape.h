#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <string>

using string = std::string;
using size_t = std::size_t;

class BasicShape
{
public:
    string getName() const;
    double getTransparency() const;
    void setTransparency(double);
    virtual size_t id() const = 0;
protected:
    string name_;
    double transparency_; //from 0 to 1
};

#endif // BASICSHAPE_H
