#ifndef EDGE_H
#define EDGE_H

class Edge {
private:
    class Vertex* begin;
    class Vertex* end;
    float weight;
public:
    Edge(Vertex* begin, Vertex* end, float weight = 0.0);
    virtual ~Edge() = default;
    Vertex* getBegin();
    Vertex* getEnd();
    float getWeight();
    int getBeginId();
    int getEndId();
};

#endif