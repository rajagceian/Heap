#include <bits/stdc++.h>
//#include <queue> // to use priority_queue STL
using namespace std;
int main() {
    priority_queue <int> pq; // maxHeap
    pq.push(8);
    pq.push(12);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    priority_queue<int , vector <int>,greater <int>>pq2;
    pq2.push(8);
    pq2.push(12);
    pq2.push(1);
    cout<<pq2.top()<<endl;
    pq2.pop();
    cout<<pq2.top()<<endl;
    return 0;
}
