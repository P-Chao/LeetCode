class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int n = nums.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < n; ++i){
            if(hash.end() != hash.find(target-nums[i])){
                return {hash[target-nums[i]], i};
            }
            hash.insert({nums[i], i});
        }
        return {0, 1};
    }
};