#pragma once
#include <iostream>
#include "Task.h"
//lecture slides
template <typename T>
class Heap
{
	T* heapArray;
	int size;
	int numOfEle;
	
public:
	Heap():heapArray(new T[size]),size(20),numOfEle(){}
	~Heap();

	//void add(int value);
	//bool peek(int& value);
	//bool remove(int& value);
	//void buildHeap(int* pile, int size);
	
	bool peek(T& val)
	{
		if(numOfEle = 0)return false;
		std::cout << "Highest priority is: " << val;
		return true;
	}
	void reallocate()
	{
		int* old = heapArray;
		size *= 2;
		heapArray = new int[size];
		for(int i = 0; i < numOfEle; i++)
		{
			heapArray[i] = old[i];
		}
		delete[] old;
	}
	void swap(int idx1, int idx2)
	{
		int* tmp1 = &idx1;
		int* tmp2 = &idx2;
		idx2 = *tmp1;
		idx2 = *tmp2;
	}
	void bubbleUp(int idx)
	{
		if(idx == 0)return;
		int parent = (idx - 1) / 2;
		if(heapArray[idx] > heapArray[parent])
		{
			swap(idx, parent);
			bubbleUp(parent);
		}
	}
	void bubbleDown(int idx)
	{
		int max = idx;
		int left = 2 * idx + 1;
		int right = left + 1;

		if(left > numOfEle - 1)return;
		if(right > numOfEle - 1)
		{
			max = right;
		}
		else
		{
			max = (heapArray[idx] > heapArray[max]) ? idx : max;
		}
		if(max != idx)
		{
			swap(idx, max);
			bubbleDown(max);
		}
	}
	void add(T val)
	{
		heapArray[numOfEle] = val;
		bubbleUp(numOfEle);
		numOfEle++;
	}
	void buildHeap()
	{
		for(int index = numOfEle / 2; index >= 0; index--)
		{
			bubbleDown(index);
		}
	}
	T* getHeapArray()
	{
		return heapArray;
	}
};

