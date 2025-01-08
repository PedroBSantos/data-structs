#ifndef NODE_H
#define NODE_H

#include <map>

class Node {
private:
  std::map<char, Node *> childrens;
  char value;

public:
  Node(char value);
  Node(const Node &node);
  virtual ~Node();
  char getValue();
  bool hasChildrens();
  Node* childrenWith(char c);
  bool containsValue(char value);
  void addChildren(Node *children);
};

Node::Node(char value) { this->value = value; }

Node::Node(const Node &node) {
  this->value = node.value;
  this->childrens = childrens;
}

Node::~Node() {
  for (auto item : this->childrens)
    delete item.second;
}

char Node::getValue() { return this->value; }

bool Node::hasChildrens() { return !this->childrens.empty(); }

Node* Node::childrenWith(char c)
{
  auto nodeIterator = this->childrens.find(c);
  return nodeIterator != this->childrens.end() ? nodeIterator->second : nullptr;
}

bool Node::containsValue(char value) { return this->value = value; }

void Node::addChildren(Node *node) {
  if (node == nullptr)
    return;
  std::pair<char, Node *> newEntry(node->getValue(), node);
  this->childrens.insert(newEntry);
}

#endif