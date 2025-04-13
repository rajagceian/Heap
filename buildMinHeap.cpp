#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int idx,int size){
    int lowest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    if(left<size && arr[lowest] > arr[left])
       lowest = left;
    if(right<size && arr[lowest] > arr[right])
       lowest = right;
    if(idx != lowest){
        swap(arr[idx],arr[lowest]);
        heapify(arr,lowest,size);
    }
   }

void buildMinHeap(int *arr,int n){
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

    buildMinHeap(arr,n);

    print(arr,n);
    return 0;
}