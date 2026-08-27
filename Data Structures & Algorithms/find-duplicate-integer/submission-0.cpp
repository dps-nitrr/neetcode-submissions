class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto x:nums){
            if(st.count(x))return x;
            else st.insert(x);
        }
        return -1;
    }
};
