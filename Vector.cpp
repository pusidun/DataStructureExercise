#include "Vector.h"

template<typename T>
void Vector<T>::copyFrom(const T* A,Rank lo,Rank hi) //copy from an array
{
	_elem=new T[_capacity=2*(hi-lo)];
	_size=0;
	for(int i=lo;i<hi;i++)    //A[lo,hi)
	{
		_elem[i]=A[i];
		_size++;
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& V)
{
	int n=V.size();
	if(n>_capacity)
	{
		delete[] _elem;
		_elem=new T[_capacity=2*n];
	}
	copyFrom(V._elem,0,n);
	_size=n;
	return *this;
}

template<typename T>
void Vector<T>::expand()
{
	if(_size<_capacity)
	    return;
	if(_capacity<DEFAULT_CAPACITY)
		_capacity=DEFAULT_CAPACITY;
	T* oldElem=_elem;
	_elem=new T[_capacity<<=1];
	for(int i=0;i<_size;i++)
		_elem[i]=oldElem[i];
	delete[] oldElem;
}

template<typename T>
void Vector<T>::shrink()
{
	if(_capacity<DEFAULT_CAPACITY<<1)return;
	if(_size<<2>_capacity)return;
	T* oldElem=_elem;_elem=new T[_capacity>>=1];
	for(int i=0;i<_size;i++)_elem[i]=oldElem[i];
	delete[] oldElem;
}

template<typename T>
T& Vector<T>::operator[](Rank r)const
{
	return _elem[r];
}

template<typename T>
void permute(Vector<T>& V)
{
	for(int i=V.size();i>0;i--)
		swap(V[i-1],V[rand()%i]);
}

template<typename T>
void Vector<T>::unsort(Rank lo,Rank hi)
{
	T* V=_elem+lo;
	for(Rank i=hi-lo;i>0;i--)
		swap(V[i-1],V[rand()%i]);
}

template<typename T>
Rank Vector<T>::find(const T& e,Rank lo,Rank hi)const
{
	while((lo<hi--)&&(_elem[hi]!=e));
	return hi;
}

template<typename T>
Rank Vector<T>::insert(Rank r,const T& e)
{
	expand();
	for(int i=_size;i>r;i--)
		_elem[i]=_elem[i-1];
	_elem[i]=e;
	_size++;
	return r;
}

template<typename T>
int Vector<T>::remove(Rank lo,Rank hi)
{
	if(lo==hi)
		return 0;
	while(hi<_size)
	{
		_elem[lo++]=_elem[hi++];
	}
	_size=lo;
	shrink();
	return hi-lo;
}

