#include <bits/stdc++.h>
using namespace std;
void heapify(int *arr,int lo,int hi){
    int largest = lo;
    int left = 2*lo + 1;
    int right = 2*lo + 2;
    if(left<hi && arr[largest] < arr[left])
      largest = left;
    if(right<hi && arr[largest] < arr[right])
      largest = right;
    if(largest != lo){
        swap(arr[largest],arr[lo]);
        heapify(arr,largest,hi);
    }
}
void heapSort(int *arr,int n){
    for(int i=n-1;i>=0;i--){ 
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
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
    heapSort(arr,n);

    print(arr,n);
    return 0;
}
