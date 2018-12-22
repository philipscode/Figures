#include "drawing.h"


Drawing::Drawing()
{
    first = last = nullptr;
    size_ = 0;
}

Drawing::Drawing(const Drawing &other)
{
    first = last = nullptr;
    size_ = 0;
    Node *temp = other.first;
    while (temp != nullptr) {
        this->push(temp->figure);
        temp = temp->next;
    }
}

void Drawing::push(BasicShape *object)
{
    Node *temp = new Node();
    temp->figure = object;
    if (last == nullptr) {
        first = temp;
        last = temp;
        first->next = last->next = nullptr;
    } else {
        last->next = temp;
        last = temp;
        last->next = nullptr;
    }
    ++size_;
}

BasicShape* Drawing::pop()
{
    if (size_ > 0) {
        Node *temp = new Node();
        temp = first;
        first = first->next;
        --size_;
        if (size_ == 0) {
            first = last = nullptr;
        }
        return temp->figure;
    } else {
        return nullptr;
    }
}

void Drawing::removeAll()
{
    while (size_ > 0) {
        this->pop();
    }
    first = last = nullptr;
}

size_t Drawing::size() const
{
    return size_;
}
