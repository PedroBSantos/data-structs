#ifndef ArrayList_H
#define ArrayList_H
#include <ostream>

template <typename T>
class ArrayList
{
public:
	ArrayList(int length = 10);
	ArrayList(const ArrayList<T>& arrayList);
	~ArrayList();
	int size();
	bool isEmpty();
	void add(T element);
	void add(T element, int pos);
	int indexOf(T element);
	int lastIndexOf(T element);
	void resize(int length);
	void clear();
	bool contains(T element);
	void sort();
	void quickSort(int begin, int end);
	int partition(int begin, int end);
	void insert(T element, int pos);
	T remove(int pos);
	T get(int index);
	T operator[](int index);
	friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& arrayList)
	{
		if (arrayList.count == 0)
		{
			os << "[]";
			return os;
		}
		os << "[";
		for (int i = 0; i < arrayList.count; i++)
		{
			os << arrayList.array[i];
			if (i != arrayList.count - 1)
			{
				os << ", ";
			}
		}
		os << "]";
		return os;
	}

private:
	T* array;
	int count;
	int length;
};

template <typename T>
inline ArrayList<T>::ArrayList(int length)
{
	this->array = new T[length];
	this->count = 0;
	this->length = length;
}

template <typename T>
inline ArrayList<T>::~ArrayList()
{
	if (!this->array)
	{
		delete[] this->array;
	}
}

template <typename T>
inline ArrayList<T>::ArrayList(const ArrayList<T>& arrayList)
{
	this->array = arrayList.array;
	this->count = arrayList.count;
	this->length = arrayList.length;
}

template <typename T>
inline int ArrayList<T>::size()
{
	return this->count;
}

template <typename T>
inline bool ArrayList<T>::isEmpty()
{
	return this->count == 0;
}

template <typename T>
inline void ArrayList<T>::add(T element)
{
	if (this->count == this->length)
	{
		this->resize(this->length * 2);
	}
	this->array[this->count] = element;
	this->count++;
}

template <typename T>
inline void ArrayList<T>::add(T element, int pos)
{
	if (pos < 0 || pos > this->count)
	{
		return;
	}
	if (pos == this->count)
	{
		this->add(element);
	}
	else
	{
		if (this->count == this->length)
		{
			this->resize(this->length * 2);
		}
		int count = this->count;
		T aux;
		while (count > pos)
		{
			aux = this->array[count];
			this->array[count] = this->array[count - 1];
			this->array[count - 1] = aux;
			count--;
		}
		this->array[pos] = element;
		this->count++;
	}
}

template <typename T>
inline T ArrayList<T>::remove(int pos)
{
	if (this->count == 0)
	{
		return T();
	}
	if (pos < 0 || pos >= this->count)
	{
		return T();
	}
	int count = pos + 1;
	T element = this->array[pos];
	T aux;
	while (count < this->count)
	{
		aux = this->array[count - 1];
		this->array[count - 1] = this->array[count];
		this->array[count] = aux;
		count++;
	}
	this->count--;
	return element;
}

template <typename T>
inline int ArrayList<T>::indexOf(T element)
{
	if (this->count == 0)
	{
		return -1;
	}
	for (int i = 0; i < this->count; i++)
	{
		if (this->array[i] == element)
		{
			return i;
		}
	}
	return -1;
}

template <typename T>
inline int ArrayList<T>::lastIndexOf(T element)
{
	if (this->count == 0)
	{
		return -1;
	}
	int lastIndex = -1;
	for (int i = 0; i < this->count; i++)
	{
		if (this->array[i] == element)
		{
			lastIndex = i;
		}
	}
	return lastIndex;
}

template <typename T>
inline void ArrayList<T>::resize(int length)
{
	if (length <= this->length)
	{
		return;
	}
	T* newArray = new T[length];
	for (int i = 0; i < this->count; i++)
	{
		newArray[i] = this->array[i];
	}
	this->length = length;
	delete[] this->array;
	this->array = newArray;
}

template <typename T>
inline void ArrayList<T>::clear()
{
	delete[] this->array;
	this->array = new T[this->length];
	this->count = 0;
}

template <typename T>
inline T ArrayList<T>::get(int index)
{
	if (index < 0 || index >= this->count)
	{
		return T();
	}
	return this->array[index];
}

template <typename T>
inline bool ArrayList<T>::contains(T element)
{
	if (this->count == 0)
	{
		return false;
	}
	for (int i = 0; i < this->count; i++)
	{
		if (this->array[i] == element)
		{
			return true;
		}
	}
	return false;
}

template <typename T>
inline void ArrayList<T>::sort()
{
	this->quickSort(0, this->count - 1);
}

template <typename T>
inline void ArrayList<T>::quickSort(int begin, int end)
{
	if (begin > end)
	{
		return;
	}
	int pivot = this->partition(begin, end);
	this->quickSort(begin, pivot - 1);
	this->quickSort(pivot + 1, end);
}

template <typename T>
inline int ArrayList<T>::partition(int begin, int end)
{
	T pivot = this->array[begin], aux;
	int left = begin, right = end;
	while (left < right)
	{
		while (array[left] <= pivot && left < end)
		{
			left++;
		}
		while (array[right] > pivot && right > begin)
		{
			right--;
		}
		if (left < right)
		{
			aux = array[left];
			array[left] = array[right];
			array[right] = aux;
		}
	}
	array[begin] = array[right];
	array[right] = pivot;
	return right;
}

template <typename T>
inline T ArrayList<T>::operator[](int index)
{
	if (index < 0 || index >= this->count)
	{
		return T();
	}
	return this->array[index];
}

template <typename T>
inline void ArrayList<T>::insert(T element, int pos)
{
	if (pos < 0 || pos >= this->count)
	{
		return;
	}
	this->array[pos] = element;
}
#endif