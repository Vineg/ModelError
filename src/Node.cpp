#include "Face.h"
#include "Node.h"
#include "Box.h"

template<class T>
Node<T>::Node(Box toClone) : bounds(make_unique<Box>(toClone)) {
    center = bounds->end.add(bounds->start).scl(0.5);
}

template<class T>
void Node<T>::put(shared_ptr<T> shape) {
    Box shapeBounds = shape->bounds();
    if (data.empty() || shapeBounds.maxWidth() * 2 > bounds->maxWidth()) {
        data.push_back(shape);
    } else {
        if (children.empty()) {
            children = vector<unique_ptr<Node>>(shapeBounds.start.totalCombinations());
        }
        auto startCoord = this->getCoord(shapeBounds.start);
        auto endCoord = this->getCoord(shapeBounds.end);
        auto map = startCoord ^ endCoord;
        for (auto d = map; ; d = (d - 1) & map) {
            auto i = startCoord + d;
            if (children[i] == nullptr) {
                children[i] = unique_ptr<Node>(new Node(Box(
                        bounds->start.nthCombination(i, center),
                        center.nthCombination(i, bounds->end)
                )));
            }
            children[i]->put(shape);
            if (d == 0) {
                break;
            }
        }
    }
}

template<class T>
void Node<T>::query(Box &box, vector<shared_ptr<T>> &result) {
    for (auto candidate : data) {
        if (candidate->bounds().intersects(box)) {
            result.push_back(candidate);
        }
    }
    if (children.empty()) {
        return;
    }
    auto startCoord = this->getCoord(box.start);
    auto endCoord = this->getCoord(box.end);
    auto map = startCoord ^ endCoord;
    for (auto d = map; ; d = (d - 1) & map) {
        auto i = startCoord + d;
        if (children[i] != nullptr) {
            children[i]->query(box, result);
        }
        if (d == 0) {
            break;
        }
    }
}

template<class T>
uint Node<T>::getCoord(Point p) {
    uint l = 1;
    uint res = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] > center[i]) {
            res += l;
        }
        l<<=1u;
    }
    return res;
}

template class Node<Face>;