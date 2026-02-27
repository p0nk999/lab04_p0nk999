// heap.cpp
// Fengxun Li

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start,end);
  int n =vdata.size();
  if (n<=1)return;//1 or 0 element means that its valid

  for(int i =(n/2)/2;i>=0;--i){
    int curr=i;
    while(true){
      //infinite loop
      int leftChild=2*curr+1;
      int rightChild=2*curr+2;
      int min=curr;

      if (leftChild<n&&vdata[leftChild]<vdata[min]){
        min=leftChild;
      }

      if(rightChild<n&&vdata[rightChild]<vdata[min]){
        min=rightChild;
      }
      if(min!=curr){
        int temp=vdata[curr];
        vdata[curr]=vdata[min];
        vdata[min]=temp;
        curr=min;
      }
      else{
        break;
      }

    }
  }

}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int curr=vdata.size()-1;
  while(curr>0){
    int parent=(curr-1)/2;
    if(vdata[curr]<vdata[parent]){
      int temp=vdata[curr];
      vdata[curr]=vdata[parent];
      vdata[parent]=temp;

      curr=parent;
    }
    else{
      break;
    }
  }

}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()){
    return;
  }
  vdata[0]=vdata.back();
  vdata.pop_back();

  int curr=0;
  int n =vdata.size();
  while(true){
    int leftChild=2*curr+1;
    int rightChild=2*curr+2;
    int min=curr;

    if(leftChild<n&&vdata[leftChild]<vdata[min]){
      min=leftChild;
    }
    if (rightChild<n&&vdata[rightChild]<vdata[min]){
      min=rightChild;
    }

    if(min!=curr){
      int temp=vdata[curr];
      vdata[curr]=vdata[min];
      vdata[min]=temp;
      curr=min;
    }
    else{
      break;
    }
  }

}

// Returns the minimum element in the heap
int Heap::top(){
  if(!vdata.empty()){
    return vdata[0];
  }
  return -1;//incase calling top on empty heap.
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    