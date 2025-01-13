#include <iostream>
#include "../include/graph.h"

int main(int argc, char const* argv[]) {
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(4, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4, 3);
    graph.addEdge(3, 5);
    std::cout << "Deep Search Result: " << std::endl;
    graph.deepSearch();
    std::cout << "Deep First Search Result: " << std::endl;
    graph.deepFirstSearch();
    return 0;
}
