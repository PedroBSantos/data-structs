#include "../include/edge.h"
#include "../include/vertex.h"

Edge::Edge(Vertex* begin, Vertex* end, float weight) {
    this->begin = begin;
    this->end = end;
    this->weight = weight;
}

Vertex* Edge::getBegin() {
    return this->begin;
}

Vertex* Edge::getEnd() {
    return this->end;
}

float Edge::getWeight() {
    return this->weight;
}

int Edge::getBeginId() {
    return this->begin->getId();
}

int Edge::getEndId() {
    return this->end->getId();
}