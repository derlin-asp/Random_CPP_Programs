#include <vector>
#include <iostream>

using namespace std;

template <class T> class DequeIterator;

template <class T>
class Deque {
public:
	typedef DequeIterator<T> iterator;
	
	Deque(): vecOne(), vecTwo() { }
	Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2), initial) { }
	Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) { }
        ~Deque() { } // destructors for vecOne and vecTwo are automatically called
                     // never call a destructor explicitly
        Deque & operator=(const Deque<T> & d);

	T & operator[](unsigned int);
	T & front();
	T & back();
	bool empty();
	iterator begin();
	iterator end();
	void erase(const iterator &);
	void erase(const iterator &, const iterator &);
	void insert(const iterator &, const T &);
	int size();
	void push_front(const T & value);
	void push_back(const T & value);
	void pop_front();
	void pop_back();
protected:
	vector<T> vecOne;
	vector<T> vecTwo;
};

// Your code goes here ...

template <class T>
class DequeIterator {
	friend class Deque<T>;
	typedef DequeIterator<T> iterator;
public:
	DequeIterator(): theDeque(0), index(0) { }
	DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) { }
	DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index) { }

	T & operator*();
	iterator & operator++();
	iterator operator++(int);
	iterator & operator--();
	iterator operator--(int);
	bool operator==(const iterator & r);
	bool operator!=(const iterator & r);
	bool operator<(const iterator & r);
	T & operator[](unsigned int i);
	iterator operator=(const iterator & r);
	iterator operator+(int i);
	iterator operator-(int i);
protected:
	Deque<T> * theDeque;
	int index;
};




int main(){




}


template <class T>
bool Deque<T>::empty()
{
    return ( vecOne.empty() && vecTwo.empty() );
}

template <class T>
iterator Deque<T>::begin()
{
    return iterator(this, 0);
}


template <class T>
iterator Deque<T>::begin()
{
    return iterator(this, size());
}


template <class T>
int Deque<T>::size()
{
    return vecOne.size() + vecTwo.size();
}




template <class T>
T& Deque<T>::front()
{
    if(VecOne.empty())
        return vecTwo.front();
    else
        return vecOne.back();
}

template <class T>
void Deque<T>::pop_front()
{
    if(!VecOne.empty())
       vecOne.pop_back();
    else
        vecTwo.erase(vecTwo.begin());        
}

template <class T>
T& Deque<T>::operator[](unsigned int index)
{
    int n = vecOne.size();
    if(index <= n)
        return vecOne (n-1)-index];
    else
        return vecTwo[index-n];
}

template <class T>
deque<T>::iterator dequeIterator<T>::operator++(int)
{
    deque<T>::iterator clone(theDeque, index);
    index++;
    return clone;
}

template <class T>
void Deque<T>::erase(Deque<T>::iterator & itr)
{
    int index = itr.index;
    int n = vecOne.size();
    if(index < n)
        vecOne.erase(vecOne.begin() + ((n-1)-index));
    else
        vecTwo.erase(vecTwo.begin()+ (n-index));
}




