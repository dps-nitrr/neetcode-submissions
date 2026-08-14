class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       unordered_map<int, int>mp;
       for(int i=0;i<n;i++)mp[nums[i]]=i;

       for(int i=0;i<n;i++){
        int complement=target- nums[i];
        if(mp.count(complement) && mp[complement]!=i) return {i, mp[complement] };
       }
       return {-1,-1};
    }
};
