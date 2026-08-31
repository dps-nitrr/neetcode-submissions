class Solution {
public:
    void f(int i,vector<int>& nums, int target , vector<vector<int>>&ans, vector<int>& temp){
        if(target==0){ans.push_back(temp); return ;}
        if(i>=nums.size())return ;
         

        if(target>=nums[i]){temp.push_back(nums[i]);
         f(i, nums, target-nums[i], ans, temp);
         temp.pop_back();}
         f(i+1, nums, target, ans, temp);


    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        f(0, nums, target, ans, temp);
        return ans;
    }
};
