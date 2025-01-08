#include "node.h"
#include <string>
#ifndef TRIE_H
#define TRIE_H

class Trie {
private:
  Node *root;

public:
  Trie();
  Trie(const Trie &trie);
  virtual ~Trie();
  void insert(std::string s);
  bool contains(std::string s);
};

Trie::Trie() { this->root = new Node('\0'); }

Trie::Trie(const Trie &trie) { this->root = trie.root; }

Trie::~Trie() { delete this->root; }

void Trie::insert(std::string s) {
  Node *currentRoot = this->root;
  Node *newNode;
  for (char c : s) {
    if (!currentRoot->hasChildrens()) {
      newNode = new Node(c);
      currentRoot->addChildren(newNode);
      currentRoot = newNode;
      continue;
    }
    Node* childrenWithCurrentChar = currentRoot->childrenWith(c);
    if (childrenWithCurrentChar != nullptr) {
      currentRoot = childrenWithCurrentChar;
      continue;
    }
    newNode = new Node(c);
    currentRoot->addChildren(newNode);
    currentRoot = newNode;
  }
}

bool Trie::contains(std::string s)
{
  if (!this->root->hasChildrens())
    return false;
  Node *currentRoot = this->root;
  for (char c : s) {
    Node* childrenWithCurrentChar = currentRoot->childrenWith(c);
    if (childrenWithCurrentChar == nullptr)
      return false;
    currentRoot = childrenWithCurrentChar;
  }
  return true;
}

#endif