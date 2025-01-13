#include "../include/graph.h"
#include <iostream>
#include <queue>

Graph::Graph(int countOfEdges) {
    for (int i = 0; i < countOfEdges; i++)
        this->vertexs.push_back(new Vertex(i));
}

Graph::~Graph() {
    for (int i = 0; i < this->vertexs.size(); i++)
        delete this->vertexs[i];
}

void Graph::addEdge(int vertex1, int vertex2, float weight, bool directional) {
    Vertex* begin = this->vertexs[vertex1];
    Vertex* end = this->vertexs[vertex2];
    Edge* edge = new Edge(begin, end, weight);
    begin->addEdge(edge);
    if (directional) return;
    edge = new Edge(end, begin, weight);
    end->addEdge(edge);
}

void Graph::auxDeepSearch(Vertex* searchBegin, std::map<int, Vertex*>& passed) {
    std::cout << "Vertex " << searchBegin->getId() << std::endl;
    passed[searchBegin->getId()] = searchBegin;
    std::vector<Edge*> edges = searchBegin->getEdges();
    for (size_t i = 0; i < edges.size(); i++) {
        Vertex* end = edges[i]->getEnd();
        if (passed.find(end->getId()) != passed.end()) continue;
        this->auxDeepSearch(end, passed);
    }
}

void Graph::deepSearch() {
    std::map<int, Vertex*> passed;
    Vertex* searchBegin = this->vertexs[0];
    this->auxDeepSearch(searchBegin, passed);
}

void Graph::auxDeepFirstSearch(Vertex* searchBegin, std::map<int, Vertex*>& passed) {
    std::queue<Vertex*> vertexQueue;
    vertexQueue.push(searchBegin);
    passed[searchBegin->getId()] = searchBegin;
    while (!vertexQueue.empty()) {
        Vertex* currentVertex = vertexQueue.front();
        vertexQueue.pop();
        std::cout << "Vertex " << currentVertex->getId() << std::endl;
        std::vector<Edge*> currentVertexEdges = currentVertex->getEdges();
        for (size_t i = 0; i < currentVertexEdges.size(); i++) {
            Vertex* end = currentVertexEdges[i]->getEnd();
            if (passed.find(end->getId()) != passed.end()) continue;
            vertexQueue.push(end);
            passed[end->getId()] = end;
        }
    }
}

void Graph::deepFirstSearch() {
    std::map<int, Vertex*> passed;
    Vertex* searchBegin = this->vertexs[0];
    this->auxDeepFirstSearch(searchBegin, passed);
}