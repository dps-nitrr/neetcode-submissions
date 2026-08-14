class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto it:nums)mp[it]++;
        priority_queue< pair<int, int>>p;
        for(auto [key,val]:mp)p.push({val,key});
        vector<int>ans;
        while(k){
            ans.push_back(p.top().second );
            p.pop();
            k--;

        }
        return ans;


    }
};
