class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>>ans;
         unordered_map<string , vector<string> >mp;
         for(auto curr:strs){
            string s=curr;
            sort(s.begin(), s.end());
            mp[s].push_back(curr);
         }
         for(auto [key,strings]:mp){
            ans.push_back(strings);}
         return ans;
    }
};
