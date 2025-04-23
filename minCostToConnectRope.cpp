int minCost(vector<int>& arr) {
    // code here
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int ele : arr){
        pq.push(ele);
    }
    int cost = 0;
    while(pq.size()>1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        cost +=x+y;
        pq.push(x+y);
    }
    return cost;
}
