
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include "defs.h"

using namespace std;


template<typename  T>
class Array {

	public:
		//constructor
		Array();

		//constructor
		Array(const Array&);
				
		//destructor
		~Array();
		
		//other
		void add(T);
		T get(int index);
		int getSize();
		bool isFull();
	
	private:
		int size;
		T* elements;
	
};

template<typename  T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template<typename  T>
Array<T>::~Array(){
	delete [] elements;
}

template<typename  T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template<typename  T>
int Array<T>::getSize(){
	return size;
}

template<typename  T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

template<typename  T>
T Array<T>::get(int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


template<typename  T>
Array<T>::Array(const Array& a) {
	this->elements = new T[MAX_ARR];
	this->size = a.size;
	for (int i = 0; i < this->size; i++)
		this->elements[i] = a.elements[i];
}

#endif