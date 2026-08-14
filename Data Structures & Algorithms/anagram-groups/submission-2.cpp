class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>>ans;
         unordered_map<string , vector<string> >mp;
         for(auto curr:strs){
             
            vector<int>freq(26,0);
            for(char c:curr){
                freq[c-'a']++;
            }
            string temp="";
            for(int i=0;i<26;i++)temp+=to_string(freq[i]) + "#";

            mp[temp].push_back(curr);
         }
         for(auto [key,strings]:mp){
            ans.push_back(strings);
            }
         return ans;
    }
};
