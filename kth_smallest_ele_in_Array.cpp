#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> Arr,int k)
{
    int n = Arr.size();
    priority_queue<int> pq; //maxHeap
    for(int i=0;i<k;i++){
        pq.push(Arr[i]);
    }

    for(int i=k;i<n;i++){
        if(pq.top()>Arr[i]){
        pq.pop();
        pq.push(Arr[i]);
        }
    }
    return pq.top();
}
int main(){
    vector <int> nums = {15,8,7,1,9,3,10,4};
    cout<<kthSmallest(nums,3)<<endl;
}
