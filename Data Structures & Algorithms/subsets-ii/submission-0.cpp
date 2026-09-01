class Solution {
public:
    void f(int idx,vector<int>& nums, vector<int>&temp,  vector<vector<int>>&ans ){
        if(idx==nums.size()){
            ans.push_back((temp));
            return ;
        }

        //take
        temp.push_back(nums[idx]);
        f(idx+1, nums, temp, ans);
        temp.pop_back();

        //not take
        int next=idx+1;
        while(next<nums.size() && nums[idx]==nums[next])next++;
        f(next, nums, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        f(0, nums, temp, ans);
        return ans;

    }
};
