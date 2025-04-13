#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int idx,int size){
    int largest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if(left<size && arr[largest] < arr[left])
       largest = left;
    if(right<size && arr[largest] < arr[right])
       largest = right;
    if(idx != largest){
        swap(arr[idx],arr[largest]);
        heapify(arr,largest,size);
    }
   }

void buildMaxHeap(int *arr,int n){
    int startIdx = n/2 - 1;
    for(int i=startIdx;i>=0;i--){
        heapify(arr,i,n);
    }
}

void print(int *arr,int n){
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";

   cout<<endl;
}
int main() {
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildMaxHeap(arr,n);

    print(arr,n);
    return 0;
}