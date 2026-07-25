class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > minHeap;

        // Push first element of each row
        for(int i = 0; i < min(n, k); i++) {
            minHeap.push({matrix[i][0], i, 0});
        }

        while(--k) {
            auto [val, row, col] = minHeap.top();
            minHeap.pop();

            if(col + 1 < n)
                minHeap.push({matrix[row][col + 1], row, col + 1});
        }

        return get<0>(minHeap.top());
    }
};