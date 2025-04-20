class Solution {
public:
    int distance(vector <int>&point){
        int x = point[0];
        int y = point[1];
        return (x*x + y*y); // sqrt is not required,because it is a comparison
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<int,vector<int>>> pq;
        for(auto &row : points){
            pq.push({distance(row),row});
            if(pq.size()>k) pq.pop();
        }
        vector <vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
