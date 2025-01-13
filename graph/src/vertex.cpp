#include "../include/vertex.h"

Vertex::Vertex(int id) {
    this->id = id;
}

Vertex::~Vertex() {
    for (int i = 0; i < this->edges.size(); i++)
        delete this->edges[i];
}

void Vertex::addEdge(Edge* edge) {
    this->edges.push_back(edge);
}

int Vertex::getId() {
    return this->id;
}

std::vector<Edge*> Vertex::getEdges() {
    return this->edges;
}