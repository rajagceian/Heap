typedef pair<int, pair<int, int>> pip;
class Solution {
public:
    vector<int> minBound(vector<int>& a, vector<int> b) {
        if (a.size() == 0)
            return b;
        if (a[1] - a[0] == b[1] - b[0]) {
            return a[0] < b[0] ? a : b;
        } else {
            if (a[1] - a[0] < b[1] - b[0])
                return a;
            else
                return b;
        }
        return {};
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        int upperBound = INT_MIN;
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i][0], {i, 0}}); // push {ele,{row,col}}
            upperBound = max(upperBound, nums[i][0]);
        }
        vector<int> ans;
        while (true) {
            auto p = minHeap.top();
            int row = p.second.first;
            int col = p.second.second;
            int lowerBound = p.first;
            minHeap.pop();
            ans = minBound(ans, {lowerBound, upperBound});
            if (col + 1 == nums[row].size())
                break;
            int newLowerBound = nums[row][col + 1];
            upperBound = max(upperBound, newLowerBound);
            minHeap.push({newLowerBound, {row, col + 1}});
        }
        return ans;
    }
};
