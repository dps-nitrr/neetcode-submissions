class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto x:nums) {
            st.insert(x);
        }
         int len=0 , maxlen=0;
         for(auto x:st){
            if(st.find(x-1)==st.end()){
                len=1;
                int curr=x;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
                maxlen = max(maxlen, len);
                
            }
         }

        return maxlen;
        

    }
};
