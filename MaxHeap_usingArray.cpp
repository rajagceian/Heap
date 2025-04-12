#include <bits/stdc++.h>
using namespace std;
class MaxHeap{
    int *arr;
    int size; // size of heap
    int cap; // capacity of array
public:
   MaxHeap(int n){
    arr = new int[n];
    size = 0;
    cap = n;
   }

   // Insertion
   void insert(int val){
    if(size >= cap){
        cout<<"Heap Overflow!"<<endl;
        return;
    }
    arr[size] = val;
    int idx = size;
    size++;
    while(idx>0 && arr[(idx-1)/2]<arr[idx]){
        swap(arr[(idx-1)/2] , arr[idx]);
        idx = (idx-1)/2;
    }
   }

   void heapify(int idx){
    int largest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if(left<size && arr[largest] < arr[left])
       largest = left;
    if(right<size && arr[largest] < arr[right])
       largest = right;
    if(idx != largest){
        swap(arr[idx],arr[largest]);
        heapify(largest);
    }
   }
   // delation
   void Delete(){
    if(size <= 0) {
        cout<<"Heap Underflow!"<<endl;
        return;
    }
    arr[0] = arr[size-1];
    size--;
    if(size == 0) return;
    heapify(0);
   }
   
   void print(){
    if(size==0){
        cout<<"Heap is Empty!"<<endl;
        return;
    }
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
   }
};
int main() {
    MaxHeap h(6);
    h.insert(8);
    h.insert(6);
    h.insert(12);
    h.print();
    h.insert(18);
    h.insert(61);
    h.insert(1);
    h.print();
    h.Delete();
    h.Delete();
    h.print();
    return 0;
}
