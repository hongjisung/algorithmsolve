class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        permuteDup(nums, 0, result);
        return result;
    }
private:
    void permuteDup(vector<int> &nums, int idx, vector<vector<int> > &result) {
        result.push_back(nums);
        for(int i=nums.size()-2; i>=idx; i--) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j-1] == nums[j]) {
                    continue;
                }
                push1fromidx(nums, i, j);
                permuteDup(nums, i+1, result);
                pull1fromidx(nums, i, j);
            }
        }
    }
    
    void push1fromidx(vector<int> &nums, int idx, int end) {
        int temp = nums[end];
        for(int i=end; i>idx; i--) {
            nums[i] = nums[i-1];
        }
        nums[idx] = temp;
    }
    void pull1fromidx(vector<int> &nums, int idx, int end) {
        int temp = nums[idx];
        for(int i=idx; i<end; i++) {
            nums[i] = nums[i+1];
        }
        nums[end] = temp;
    }
};