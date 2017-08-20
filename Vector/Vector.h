#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<iostream>
#define DEFAULT_CAPACITY 3
typedef int Rank;

template <typename T>
class Vector
{
private:
	Rank _size;int _capacity;T* _elem;
protected:
	void copyFrom(T* const A,Rank lo,Rank hi);
	void expand();
	void shrink();
	bool bubble(Rank lo,Rank hi);
	void bubbleSort(Rank lo,Rank hi);
	void merge(Rank lo,Rank mi,Rank hi);
	void mergeSort(Rank lo,Rank hi);
	Rank partition(Rank lo,Rank hi);
	void quickSort(Rank lo,Rank hi);
	void heapSort(Rank lo,Rank hi);
public:
	//Constructor
	Vector(int c=DEFAULT_CAPACITY){_elem=new T[_capacity=c];_size=0;}
	Vector(T* A,Rank lo,Rank hi){copyFrom(A,lo,hi);	}
	Vector(T* A,Rank n){copyFrom(A,0,n);	}
	Vector(const Vector<T>& V,Rank lo,Rank hi ){copyFrom(V._elem,lo,hi);	}
	Vector(const Vector<T>& V){copyFrom(V._elem,0,V._size);	}
	//Deconstructor
	~Vector(){delete _elem;	}
	//Read Only Interface
	Rank size(){return _size;	}
	bool empty(){return _size<=0;	}
	int disordered() const;
	Rank find(const T& e)const {return find(e,0,(Rank)_size);}
	Rank find(const T& e,Rank lo,Rank hi)const;
	Rank search(const T& e)const
	{return (0>=_size)?-1:search(e,(Rank)0,(Rank)_size);	}
	Rank search(const T& e,Rank lo,Rank hi)const;
	//written interface
	T& operator[](Rank r)const;
	Vector<T>& operator=(const Vector<T>&);
	T remove(Rank r);
	int remove(Rank lo,Rank hi);
	Rank insert(Rank r,const T& e);
	Rank insert(const T& e){return insert(_size,e);	}
	void sort(Rank lo,Rank hi);
	void sort(){sort(0,_size);	}
	void unsort(Rank lo,Rank hi);
	void unsort(){unsort(0,_size);	}
	int deduplicate();
	int uniquify();
	//traverse
	void traverse(void(*)(T&));
	template<typename VST> void traverse(VST&);
}

#endif
