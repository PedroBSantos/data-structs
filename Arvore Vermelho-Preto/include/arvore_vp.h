#ifndef ARVORE_VP
#define ARVORE_VP

#include <sstream>
#include <string>

#include "no.h"

template <typename T>
class ArvoreVP
{
public:
  ArvoreVP();
  ArvoreVP(const ArvoreVP<T> &arvoreVP);
  ~ArvoreVP();
  void adicionar(T elemento);
  bool remover(T elemento);
  bool contains(T elemento) const;
  bool empty() const;
  int size() const;
  std::string percOrdem() const;
  std::string percPreOrdem() const;
  std::string percPosOrdem() const;
  std::string percOrdemInv() const;
  T max() const;
  T min() const;
  T sucessor(T elemento) const;
  T predecessor(T elemento) const;

private:
  No<T> *raiz;
  int qtdElementos;
  void rotacaoEsquerda(No<T> *no);
  void rotacaoDireita(No<T> *no);
  void balancearAdd(No<T> *no);
  void balancearRemover(No<T> *no);
  void auxPercOrdem(std::stringstream &stringStream, No<T> *raiz) const;
  void auxPercPreOrdem(std::stringstream &stringStream, No<T> *raiz) const;
  void auxPercPosOrdem(std::stringstream &stringStream, No<T> *raiz) const;
  void auxPercOrdemInv(std::stringstream &stringStream, No<T> *raiz) const;
  void auxDelete(No<T> *raiz);
  void transplante(No<T> *no1, No<T> *no2);
  No<T> *auxMax(No<T> *raiz) const;
  No<T> *auxMin(No<T> *raiz) const;
  No<T> *getNoElemento(T elemento) const;
  No<T> *auxGetNoElemento(T elemento, No<T> *raiz) const;
  No<T> *auxAdicionar(T elemento, No<T> *raiz);
  No<T> *auxSucessor(T elemento) const;
  No<T> *auxPredecessor(T elemento) const;
};

template <typename T>
inline ArvoreVP<T>::ArvoreVP() : raiz(nullptr), qtdElementos(0) {}

template <typename T>
inline ArvoreVP<T>::~ArvoreVP()
{
  this->auxDelete(this->raiz);
}

/*
      Desaloca os nós em um percuso em pós-ordem
  */
template <typename T>
inline void ArvoreVP<T>::auxDelete(No<T> *raiz)
{
  if (raiz != nullptr)
  {
    this->auxDelete(raiz->getDireita());
    this->auxDelete(raiz->getEsquerda());
    delete raiz;
    raiz = nullptr;
  }
}

template <typename T>
inline ArvoreVP<T>::ArvoreVP(const ArvoreVP<T> &arvoreVP)
    : raiz(arvoreVP.raiz), qtdElementos(arvoreVP.qtdElementos) {}

/*
      Retorna se a árvore está vazia.
  */
template <typename T>
inline bool ArvoreVP<T>::empty() const
{
  return this->raiz == nullptr;
}

/*
      Retorna a quantidade de elementos(nós) que estão na árvore.
  */
template <typename T>
inline int ArvoreVP<T>::size() const
{
  return this->qtdElementos;
}

/*
      Adiciona um elemento a árvore.
  */
template <typename T>
inline void ArvoreVP<T>::adicionar(T elemento)
{
  if (this->raiz == nullptr)
  {
    this->raiz = new No<T>(elemento, nullptr, nullptr, nullptr, "preto");
  }
  else
  {
    No<T> *pai = this->auxAdicionar(elemento, this->raiz);
    No<T> *no_elemento = new No<T>(elemento, pai, "vermelho");
    if (pai->getElemento() > elemento)
    {
      pai->setEsquerda(no_elemento);
    }
    else
    {
      pai->setDireita(no_elemento);
    }
    this->balancearAdd(no_elemento);
    this->raiz->setCor("preto");
  }
  this->qtdElementos++;
}

template <typename T>
inline No<T> *ArvoreVP<T>::auxAdicionar(T elemento, No<T> *raiz)
{
  if (raiz->getElemento() > elemento)
  {
    return raiz->getEsquerda() == nullptr
               ? raiz
               : this->auxAdicionar(elemento, raiz->getEsquerda());
  }
  return raiz->getDireita() == nullptr
             ? raiz
             : this->auxAdicionar(elemento, raiz->getDireita());
}

/*
      Remove um elemento da árvore.
  */
template <typename T>
inline bool ArvoreVP<T>::remover(T elemento)
{
  No<T> *no_elemento = this->getNoElemento(elemento);
  if (no_elemento == nullptr)
  {
    return false;
  }
  if (no_elemento->getEsquerda() != nullptr ||
      no_elemento->getDireita() != nullptr)
  {
    No<T> *aux1 = no_elemento;
    std::string cor_no_elemento = no_elemento->getCor();
    if (no_elemento->getEsquerda() == nullptr)
    {
      aux1 = no_elemento->getDireita();
      this->transplante(no_elemento, no_elemento->getDireita());
    }
    else if (no_elemento->getDireita() == nullptr)
    {
      aux1 = no_elemento->getEsquerda();
      this->transplante(no_elemento, no_elemento->getEsquerda());
    }
    else
    {
      No<T> *sucessor = this->auxMin(no_elemento->getDireita());
      cor_no_elemento = sucessor->getCor();
      aux1 = sucessor->getDireita();
      if (sucessor->getPai() != no_elemento)
      {
        if (sucessor->getDireita() != nullptr)
        {
          this->transplante(sucessor, sucessor->getDireita());
        }
        else
        {
          if (sucessor == sucessor->getPai()->getEsquerda())
          {
            sucessor->getPai()->setEsquerda(nullptr);
          }
          else
          {
            sucessor->getPai()->setDireita(nullptr);
          }
        }
        sucessor->setDireita(no_elemento->getDireita());
        sucessor->getDireita()->setPai(sucessor);
      }
      this->transplante(no_elemento, sucessor);
      sucessor->setEsquerda(no_elemento->getEsquerda());
      sucessor->getEsquerda()->setPai(sucessor);
      sucessor->setCor(no_elemento->getCor());
    }
    if (cor_no_elemento == "preto" && aux1 != nullptr)
    {
      this->balancearRemover(aux1);
    }
  }
  delete no_elemento;
  no_elemento = nullptr;
  this->qtdElementos--;
  return true;
}

/*
      Coloca o no2 no lugar do no1.
  */
template <typename T>
inline void ArvoreVP<T>::transplante(No<T> *no1, No<T> *no2)
{
  if (no1->getPai() == nullptr)
  {
    this->raiz = no2;
  }
  else if (no1->getPai()->getEsquerda() == no1)
  {
    no1->getPai()->setEsquerda(no2);
  }
  else
  {
    no1->getPai()->setDireita(no2);
  }
  no2->setPai(no1->getPai());
}

/*
      Rotaciona o nó(X) passado no parâmetro da função para a esquerda
      no sentido horário. O filho a direita de X passa a ser o pai de X. A
      esquerda do filho a direita de X passa a ser a direita de X.
  */
template <typename T>
inline void ArvoreVP<T>::rotacaoEsquerda(No<T> *no)
{
  No<T> *direita = no->getDireita();
  if (direita != nullptr)
  {
    no->setDireita(direita->getEsquerda());
    if (direita->getEsquerda() != nullptr)
    {
      direita->getEsquerda()->setPai(no);
    }
    direita->setPai(no->getPai());
    if (no->getPai() == nullptr)
    {
      this->raiz = direita;
    }
    else if (no == no->getPai()->getEsquerda())
    {
      no->getPai()->setEsquerda(direita);
    }
    else
    {
      no->getPai()->setDireita(direita);
    }
    direita->setEsquerda(no);
    no->setPai(direita);
  }
}

/*
      Rotaciona o nó(X) passado no parâmetro da função para a direita
      no sentido horário. O filho a esquerda de X passa a ser o pai de X.
      A direita do filho passa a ser X e a esquerda de X passa a ser a direita
      do filho de X. A direita da esquerda vira a esquerda do nó a ser rotacionado
  */
template <typename T>
inline void ArvoreVP<T>::rotacaoDireita(No<T> *no)
{
  No<T> *esquerda = no->getEsquerda();
  if (esquerda != nullptr)
  {
    no->setEsquerda(esquerda->getDireita());
    if (esquerda->getDireita() != nullptr)
    {
      esquerda->getDireita()->setPai(no);
    }
    esquerda->setPai(no->getPai());
    if (no->getPai() == nullptr)
    {
      this->raiz = esquerda;
    }
    else if (no == no->getPai()->getDireita())
    {
      no->getPai()->setDireita(esquerda);
    }
    else
    {
      no->getPai()->setEsquerda(esquerda);
    }
    esquerda->setDireita(no);
    no->setPai(esquerda);
  }
}

/*
    Método utilizado para balancearAdd a árvore após a inserção de um novo
    elemento na árvore. 3 casos: 1 - O pai e o tio do nó inserido é da cor
    vermelha. 2 - O tio do nó inserido é preto e o nó inserido é um filho à
    direita. 3 - O tio do nó inserido é preto e o nó inserido é um filho à
    esquerda. O balanceamento é feito com base na posição do tio do nó inserido.
      Se o tio do nó inserido está a direita e o nó inserido a esquerda do seu
    pai(caso 2), primeiro fazemos uma rotação a direita. Depois trocamos a cor do
    pai do nó inserido para preto e do seu avô para vermelho e fazemos uma
    rotação a direita(caso 3) em relação ao avô do nó inserido. Caso o tio do nó
    inserido esteja a esquerda, basta fazer o que foi descrito acima apenas
    trocando direita por esquerda. O balanceamento no caso 1 não precisa realizar
    rotações na árvore, apenas trocar a cor do tio e do pai do nó para preto e a
    cor do avô para vermelho.
  */
template <typename T>
inline void ArvoreVP<T>::balancearAdd(No<T> *no)
{
  while (no != this->raiz && no->getPai()->getCor() == "vermelho")
  {
    if (no->getPai() == no->getPai()->getPai()->getEsquerda())
    {
      No<T> *tio = no->getPai()->getPai()->getDireita();
      if (tio != nullptr && tio->getCor() == "vermelho") // Trata o caso 1
      {
        tio->setCor("preto");
        no->getPai()->setCor("preto");
        no->getPai()->getPai()->setCor("vermelho");
        no = no->getPai()->getPai();
      }
      else
      {
        if (no == no->getPai()->getDireita()) // Trata o caso 2
        {
          no = no->getPai();
          this->rotacaoEsquerda(no);
        }
        // Trata o caso 3
        no->getPai()->setCor("preto");
        no->getPai()->getPai()->setCor("vermelho");
        this->rotacaoDireita(no->getPai()->getPai());
      }
    }
    else
    {
      No<T> *tio = no->getPai()->getPai()->getEsquerda();
      if (tio != nullptr && tio->getCor() == "vermelho") // Trata o caso 1
      {
        tio->setCor("preto");
        no->getPai()->setCor("preto");
        no->getPai()->getPai()->setCor("vermelho");
        no = no->getPai()->getPai();
      }
      else
      {
        if (no == no->getPai()->getEsquerda()) // Trata o caso 2
        {
          no = no->getPai();
          this->rotacaoDireita(no);
        }
        // Trata o caso 3
        no->getPai()->setCor("preto");
        no->getPai()->getPai()->setCor("vermelho");
        this->rotacaoEsquerda(no->getPai()->getPai());
      }
    }
  }
}

/*
      O balanceamento após remoção possui o mesmo loop while do balanceamento após
    inserção com a mesma condição de parada a diferença é que trocamos por preto
    a cor do nó a ser balanceado e não estamos comparando mais a cor do pai do nó
    a ser balanceado. O balanceamento é feito com base na posição do nó em
    relação ao seu pai. Temos 4 casos a analisar ao realizar o balanceamento após
    remover algum nó da árvore. O balanceamento irá ocorrer no nó que foi
    substituido pelo nó que foi removido. Esse nó a ser balanceado é passado no
    parâmetro da função, o balanceamento só irá ocorrer caso ele seja preto. 1º
    caso: O irmão W do nó a ser balanceado é vermelho. Se W é vermelho, então
    ambos os seus filhos são pretos. Alteramos a cor de W para preto e a cor de
    seu pai para vermelho e fazemos uma rotação a esquerda sobre o pai do nó a
    ser balanceado. A resolução deste caso pode levar aos casos 2, 3 e 4. O loop
    prossegue com W = nó a direita de seu pai. 2º caso: Os filhos de W são
    pretos. Basta alterar a cor de W para vermelho. O loop prossegue com o nó a
    ser balanceado = pai do nó a ser balanceado. 3º caso: O filho a direita de W
    é preto e o filho a esquerda é vermelho. Devemos trocar as cores de W e seu
    filho a esquerda, ou seja, W passa a ser da cor vermelha e o seu filho a
    esquerda passa a ser da cor preta. Por fim realizar uma rotação a direita
    sobre W. O loop prossegue com W = nó a direita de seu pai. 4º caso: o filho a
    direita de W é vermelho. A cor de W passa a ser a cor de seu pai. A cor do
    pai de W e do filho a direita de W passa a ser preta. Por fim, realizar uma
    rotação a esquerda sobre o pai de W. O loop prossegue com o nó a ser
    balanceado = raiz da árvore. Esses casos foram descritos para caso o irmão W
    do nó a ser balanceado esteja a sua direita. Caso o irmão W do nó a ser
    balanceado esteja a sua esquerda, basta fazer os casos acima com esquerda e
    direita trocadas.
  */
template <typename T>
inline void ArvoreVP<T>::balancearRemover(No<T> *no)
{
  No<T> *aux;
  while (no != this->raiz && no->getCor() == "preto")
  {
    if (no == no->getPai()->getEsquerda())
    {
      aux = no->getPai()->getDireita();
      if (aux->getCor() == "vermelho")
      {
        aux->setCor("preto");
        aux->getPai()->setCor("vermelho");
        this->rotacaoEsquerda(aux->getPai());
        aux = no->getPai()->getDireita();
      }
      if (aux->getEsquerda()->getCor() == "preto" &&
          aux->getDireita()->getCor() == "preto")
      {
        aux->setCor("vermelho");
        no = no->getPai();
      }
      else
      {
        if (aux->getDireita()->getCor() == "preto")
        {
          aux->getEsquerda()->setCor("preto");
          aux->setCor("vermelho");
          this->rotacaoDireita(aux);
          aux = no->getPai()->getDireita();
        }
        aux->setCor(no->getPai()->getCor());
        no->getPai()->setCor("preto");
        aux->getDireita()->setCor("preto");
        this->rotacaoEsquerda(no->getPai());
        no = this->raiz;
      }
    }
    else
    {
      aux = no->getPai()->getEsquerda();
      if (aux->getCor() == "vermelho")
      {
        aux->setCor("preto");
        aux->getPai()->setCor("vermelho");
        this->rotacaoDireita(aux->getPai());
        aux = no->getPai()->getEsquerda();
      }
      if (aux->getEsquerda()->getCor() == "preto" &&
          aux->getDireita()->getCor() == "preto")
      {
        aux->setCor("vermelho");
        no = no->getPai();
      }
      else
      {
        if (aux->getEsquerda()->getCor() == "preto")
        {
          aux->getDireita()->setCor("preto");
          aux->setCor("vermelho");
          this->rotacaoEsquerda(aux);
          aux = no->getPai()->getEsquerda();
        }
        aux->setCor(no->getPai()->getCor());
        no->getPai()->setCor("preto");
        aux->getEsquerda()->setCor("preto");
        this->rotacaoDireita(no->getPai());
        no = this->raiz;
      }
    }
  }
  no->setCor("preto");
}

/*
      Retorna o maior elemento da árvore.
  */
template <typename T>
inline T ArvoreVP<T>::max() const
{
  if (this->empty())
  {
    return T();
  }
  No<T> *max = this->auxMax(this->raiz);
  return max == nullptr ? T() : max->getElemento();
}

template <typename T>
inline No<T> *ArvoreVP<T>::auxMax(No<T> *raiz) const
{
  if (raiz->getDireita() == nullptr)
  {
    return raiz;
  }
  return this->auxMax(raiz->getDireita());
}

/*
      Retorna o menor elemento da árvore
  */
template <typename T>
inline T ArvoreVP<T>::min() const
{
  if (this->empty())
  {
    return T();
  }
  No<T> *min = this->auxMin(this->raiz);
  return min == nullptr ? T() : min->getElemento();
}

template <typename T>
inline No<T> *ArvoreVP<T>::auxMin(No<T> *raiz) const
{
  if (raiz->getEsquerda() == nullptr)
  {
    return raiz;
  }
  return this->auxMin(raiz->getEsquerda());
}

template <typename T>
inline No<T> *ArvoreVP<T>::getNoElemento(T elemento) const
{
  No<T> *no_elemento = this->auxGetNoElemento(elemento, this->raiz);
  return no_elemento;
}

template <typename T>
inline No<T> *ArvoreVP<T>::auxGetNoElemento(T elemento, No<T> *raiz) const
{
  if (raiz == nullptr)
  {
    return nullptr;
  }
  if (raiz->getElemento() == elemento)
  {
    return raiz;
  }
  if (raiz->getElemento() > elemento)
  {
    return this->auxGetNoElemento(elemento, raiz->getEsquerda());
  }
  return this->auxGetNoElemento(elemento, raiz->getDireita());
}

/*
      Verifica se um elemento existe ou não na árvore.
  */
template <typename T>
inline bool ArvoreVP<T>::contains(T elemento) const
{
  return this->getNoElemento(elemento) == nullptr ? false : true;
}

/*
      Retorna o sucessor de um elemento da árvore.
  */
template <typename T>
inline T ArvoreVP<T>::sucessor(T elemento) const
{
  No<T> *sucessor = this->auxSucessor(elemento);
  return sucessor == nullptr ? T() : sucessor->getElemento();
}

template <typename T>
inline No<T> *ArvoreVP<T>::auxSucessor(T elemento) const
{
  No<T> *no_elemento = this->getNoElemento(elemento);
  if (no_elemento == nullptr)
  {
    return nullptr;
  }
  No<T> *direita = no_elemento->getDireita();
  if (direita != nullptr)
  {
    No<T> *sucessor = this->auxMin(direita);
    return sucessor;
  }
  No<T> *pai = no_elemento->getPai();
  while (pai != nullptr && no_elemento == pai->getDireita())
  {
    no_elemento = pai;
    pai = pai->getPai();
  }
  return pai;
}

/*
      Retorna o antecessor de um elemento na árvore.
  */
template <typename T>
inline T ArvoreVP<T>::predecessor(T elemento) const
{
  No<T> *predecessor = this->auxPredecessor(elemento);
  return predecessor == nullptr ? T() : predecessor->getElemento();
}

template <typename T>
inline No<T> *ArvoreVP<T>::auxPredecessor(T elemento) const
{
  No<T> *no_elemento = this->getNoElemento(elemento);
  if (no_elemento == nullptr)
  {
    return nullptr;
  }
  No<T> *esquerda = no_elemento->getEsquerda();
  if (esquerda != nullptr)
  {
    No<T> *predecessor = this->auxMax(esquerda);
    return predecessor;
  }
  No<T> *pai = no_elemento->getPai();
  while (pai != nullptr && no_elemento == pai->getEsquerda())
  {
    no_elemento = pai;
    pai = pai->getPai();
  }
  return pai;
}

/*
      Realiza um percurso in-order.
  */
template <typename T>
inline std::string ArvoreVP<T>::percOrdem() const
{
  std::stringstream stringStream;
  this->auxPercOrdem(stringStream, this->raiz);
  return stringStream.str();
}

template <typename T>
inline void ArvoreVP<T>::auxPercOrdem(std::stringstream &stringStream,
                                      No<T> *raiz) const
{
  if (raiz != nullptr)
  {
    this->auxPercOrdem(stringStream, raiz->getEsquerda());
    stringStream << raiz->getElemento() << "\t";
    this->auxPercOrdem(stringStream, raiz->getDireita());
  }
}

/*
      Realiza um percurso pre-order.
  */
template <typename T>
inline std::string ArvoreVP<T>::percPreOrdem() const
{
  std::stringstream stringStream;
  this->auxPercPreOrdem(stringStream, this->raiz);
  return stringStream.str();
}

template <typename T>
inline void ArvoreVP<T>::auxPercPreOrdem(std::stringstream &stringStream,
                                         No<T> *raiz) const
{
  if (raiz != nullptr)
  {
    stringStream << raiz->getElemento() << "\t";
    this->auxPercPreOrdem(stringStream, raiz->getEsquerda());
    this->auxPercPreOrdem(stringStream, raiz->getDireita());
  }
}

/*
      Realiza um percurso post-order.
  */
template <typename T>
inline std::string ArvoreVP<T>::percPosOrdem() const
{
  std::stringstream stringStream;
  this->auxPercPosOrdem(stringStream, this->raiz);
  return stringStream.str();
}

template <typename T>
inline void ArvoreVP<T>::auxPercPosOrdem(std::stringstream &stringStream,
                                         No<T> *raiz) const
{
  if (raiz != nullptr)
  {
    this->auxPercPosOrdem(stringStream, raiz->getDireita());
    this->auxPercPosOrdem(stringStream, raiz->getEsquerda());
    stringStream << raiz->getElemento() << "\t";
  }
}

/*
      Realiza um percurso post-order-inv.
  */
template <typename T>
inline std::string ArvoreVP<T>::percOrdemInv() const
{
  std::stringstream stringStream;
  this->auxPercOrdemInv(stringStream, this->raiz);
  return stringStream.str();
}

template <typename T>
inline void ArvoreVP<T>::auxPercOrdemInv(std::stringstream &stringStream,
                                         No<T> *raiz) const
{
  if (raiz != nullptr)
  {
    this->auxPercOrdemInv(stringStream, raiz->getDireita());
    stringStream << raiz->getElemento() << "\t";
    this->auxPercOrdemInv(stringStream, raiz->getEsquerda());
  }
}
#endif