#include "../include/trie.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Trie trie;
  trie.insert("bear");
  trie.insert("bear");
  trie.insert("bell");
  trie.insert("bid");
  trie.insert("bull");
  trie.insert("stock");
  trie.insert("stop");
  std::cout << "Contains \"bear\": " << trie.contains("bear") << std::endl;
  std::cout << "Contains \"bell\": " << trie.contains("bell") << std::endl;
  std::cout << "Contains \"bid\": " << trie.contains("bid") << std::endl;
  std::cout << "Contains \"bull\": " << trie.contains("bull") << std::endl;
  std::cout << "Contains \"stock\": " << trie.contains("stock") << std::endl;
  std::cout << "Contains \"stop\": " << trie.contains("stop") << std::endl;
  return 0;
}
