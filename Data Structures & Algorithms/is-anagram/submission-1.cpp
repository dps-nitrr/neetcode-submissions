class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;
        for(auto x:s)mp[x]++;
        
    for(auto it:t)mp[it]--;
    for (auto [k,v]:mp){
        if(v)return false;
    }
    return true;

    }
};
