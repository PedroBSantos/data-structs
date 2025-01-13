#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include "./vertex.h"

class Graph {
private:
    std::vector<Vertex*> vertexs;
    void auxDeepSearch(Vertex* searchBegin, std::map<int, Vertex*>& passed);
    void auxDeepFirstSearch(Vertex* searchBegin, std::map<int, Vertex*>& passed);
public:
    Graph(int countOfVertexs);
    virtual ~Graph();
    void addEdge(int vertex1, int vertex2, float weight = 0.0, bool directional = false);
    void deepSearch();
    void deepFirstSearch();
};

#endif