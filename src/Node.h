#ifndef MODELERROR_NODE_H
#define MODELERROR_NODE_H

#include "Box.h"
#include "Point.h"

template <class T>
class Node {
public:
    unique_ptr<Box> bounds;
    Point center;
    vector<unique_ptr<Node<T>>> children;
    vector<shared_ptr<T>> data;

    explicit Node(Box toClone);
    void put(shared_ptr<T> shape);
    void query(Box& box, vector<shared_ptr<T>>& result);
    uint getCoord(Point p);
};

#endif //MODELERROR_NODE_H
