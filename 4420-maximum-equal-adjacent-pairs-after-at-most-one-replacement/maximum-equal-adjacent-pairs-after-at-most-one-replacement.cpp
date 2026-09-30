class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int base_pairs = 0;
        int max_extra = 0;
        
        struct PairHash {
            size_t operator()(const pair<int, int>& p) const {
                return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };
        
        unordered_map<pair<int, int>, int, PairHash> pair_counts;
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                base_pairs++;
            } else {
                int u = min(nums[i], nums[i+1]);
                int v = max(nums[i], nums[i+1]);
                pair_counts[{u, v}]++;
                max_extra = max(max_extra, pair_counts[{u, v}]);
            }
        }
        
        return base_pairs + max_extra;
    }
};