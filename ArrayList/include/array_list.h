#ifndef ArrayList_H
#define ArrayList_H
#include <ostream>

template <typename T>
class ArrayList
{
public:
	ArrayList(int tamanho = 10);
	ArrayList(const ArrayList<T> &arrayList);
	~ArrayList();
	int size();
	bool isEmpty();
	void add(T elemento);
	void add(T elemento, int posicao);
	int indexOf(T elemento);
	int lastIndexOf(T elemento);
	void resize(int tamanho);
	void clear();
	bool contains(T elemento);
	void sort();
	void quickSort(int inicio, int fim);
	int particionar(int inicio, int fim);
	void insert(T elemento, int pos);
	T remove(int posicao);
	T get(int index);
	T operator[](int index);
	friend std::ostream &operator<<(std::ostream &os, const ArrayList<T> &arrayList)
	{
		if (arrayList.qtdElementos == 0)
		{
			os << "[]";
			return os;
		}
		os << "[";
		for (int i = 0; i < arrayList.qtdElementos; i++)
		{
			os << arrayList.vetor[i];
			if (i != arrayList.qtdElementos - 1)
			{
				os << ", ";
			}
		}
		os << "]";
		return os;
	}

private:
	T *vetor;
	int qtdElementos;
	int tamanho;
};

template <typename T>
inline ArrayList<T>::ArrayList(int tamanho)
{
	this->vetor = new T[tamanho];
	this->qtdElementos = 0;
	this->tamanho = tamanho;
}

template <typename T>
inline ArrayList<T>::~ArrayList()
{
	if (!this->vetor)
	{
		delete[] this->vetor;
	}
}

template <typename T>
inline ArrayList<T>::ArrayList(const ArrayList<T> &arrayList)
{
	this->vetor = arrayList.vetor;
	this->qtdElementos = arrayList.qtdElementos;
	this->tamanho = arrayList.tamanho;
}

template <typename T>
inline int ArrayList<T>::size()
{
	return this->qtdElementos;
}

template <typename T>
inline bool ArrayList<T>::isEmpty()
{
	return this->qtdElementos == 0;
}

template <typename T>
inline void ArrayList<T>::add(T elemento)
{
	if (this->qtdElementos == this->tamanho)
	{
		this->resize(this->tamanho * 2);
	}
	this->vetor[this->qtdElementos] = elemento;
	this->qtdElementos++;
}

template <typename T>
inline void ArrayList<T>::add(T elemento, int posicao)
{
	if (posicao < 0 || posicao > this->qtdElementos)
	{
		return;
	}
	if (posicao == this->qtdElementos)
	{
		this->add(elemento);
	}
	else
	{
		if (this->qtdElementos == this->tamanho)
		{
			this->resize(this->tamanho * 2);
		}
		int contador = this->qtdElementos;
		T aux;
		while (contador > posicao)
		{
			aux = this->vetor[contador];
			this->vetor[contador] = this->vetor[contador - 1];
			this->vetor[contador - 1] = aux;
			contador--;
		}
		this->vetor[posicao] = elemento;
		this->qtdElementos++;
	}
}

template <typename T>
inline T ArrayList<T>::remove(int posicao)
{
	if (this->qtdElementos == 0)
	{
		return T();
	}
	if (posicao < 0 || posicao >= this->qtdElementos)
	{
		return T();
	}
	int contador = posicao + 1;
	T elemento = this->vetor[posicao];
	T aux;
	while (contador < this->qtdElementos)
	{
		aux = this->vetor[contador - 1];
		this->vetor[contador - 1] = this->vetor[contador];
		this->vetor[contador] = aux;
		contador++;
	}
	this->qtdElementos--;
	return elemento;
}

template <typename T>
inline int ArrayList<T>::indexOf(T elemento)
{
	if (this->qtdElementos == 0)
	{
		return -1;
	}
	for (int i = 0; i < this->qtdElementos; i++)
	{
		if (this->vetor[i] == elemento)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
inline int ArrayList<T>::lastIndexOf(T elemento)
{
	if (this->qtdElementos == 0)
	{
		return -1;
	}
	int lastIndex = -1;
	for (int i = 0; i < this->qtdElementos; i++)
	{
		if (this->vetor[i] == elemento)
		{
			lastIndex = i;
		}
	}
	return lastIndex;
}

template <typename T>
inline void ArrayList<T>::resize(int tamanho)
{
	if (tamanho <= this->tamanho)
	{
		return;
	}
	T *novoVetor = new T[tamanho];
	for (int i = 0; i < this->qtdElementos; i++)
	{
		novoVetor[i] = this->vetor[i];
	}
	this->tamanho = tamanho;
	delete[] this->vetor;
	this->vetor = novoVetor;
}

template <typename T>
inline void ArrayList<T>::clear()
{
	delete[] this->vetor;
	this->vetor = new T[this->tamanho];
	this->qtdElementos = 0;
}

template <typename T>
inline T ArrayList<T>::get(int index)
{
	if (index < 0 || index >= this->qtdElementos)
	{
		return T();
	}
	return this->vetor[index];
}

template <typename T>
inline bool ArrayList<T>::contains(T elemento)
{
	if (this->qtdElementos == 0)
	{
		return false;
	}
	for (int i = 0; i < this->qtdElementos; i++)
	{
		if (this->vetor[i] == elemento)
		{
			return true;
		}
	}
	return false;
}

template <typename T>
inline void ArrayList<T>::sort()
{
	this->quickSort(0, this->qtdElementos - 1);
}

template <typename T>
inline void ArrayList<T>::quickSort(int inicio, int fim)
{
	if (inicio > fim)
	{
		return;
	}
	int pivo = this->particionar(inicio, fim);
	this->quickSort(inicio, pivo - 1);
	this->quickSort(pivo + 1, fim);
}

template <typename T>
inline int ArrayList<T>::particionar(int inicio, int fim)
{
	T pivo = this->vetor[inicio], aux;
	int esquerda = inicio, direita = fim;
	while (esquerda < direita)
	{
		while (vetor[esquerda] <= pivo && esquerda < fim)
		{
			esquerda++;
		}
		while (vetor[direita] > pivo && direita > inicio)
		{
			direita--;
		}
		if (esquerda < direita)
		{
			aux = vetor[esquerda];
			vetor[esquerda] = vetor[direita];
			vetor[direita] = aux;
		}
	}
	vetor[inicio] = vetor[direita];
	vetor[direita] = pivo;
	return direita;
}

template <typename T>
inline T ArrayList<T>::operator[](int index)
{
	if (index < 0 || index >= this->qtdElementos)
	{
		return T();
	}
	return this->vetor[index];
}

template <typename T>
inline void ArrayList<T>::insert(T elemento, int pos)
{
	if (pos < 0 || pos >= this->qtdElementos)
	{
		return;
	}
	this->vetor[pos] = elemento;
}
#endif