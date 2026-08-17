class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<int> depth(n, 0);
        depth[0] = 1;
        int height = 1;
        for(int i = 1; i < n; i++) {
            if(depth[i] != 0) continue;
            vector<int> path;
            int node = i;
            while(depth[node] == 0) {
                path.push_back(node);
                node = parent[node];
            }
            int d = depth[node];
            for(int j = path.size() - 1; j >= 0; j--) {
                d++;
                depth[path[j]] = d;
            }
        }
        for(int i = 0; i < n; i++) {
            height = max(height, depth[i]);
        }
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += 1LL * nums[i] * (height - depth[i] + 1);
        }
        return sum;
    }
};