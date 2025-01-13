#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "./edge.h"

class Vertex {
private:
    int id;
    std::vector<Edge*> edges;
public:
    Vertex(int id);
    ~Vertex();
    void addEdge(Edge* edge);
    int getId();
    std::vector<Edge*> getEdges();
};

#endif