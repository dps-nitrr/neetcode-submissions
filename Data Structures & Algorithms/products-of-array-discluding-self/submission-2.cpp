class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
            vector<int>  right(n);
         

        // for(int i=1;i<n;i++){
        //         left[i]=left[i-1]*nums[i-1];
        // }

        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
        }
       int  l=1;

        vector<int>ans(n);
        ans[0]=right[0];
        for(int i=1;i<n;i++){
        l=l*nums[i-1];
            ans[i]=l*right[i];
        }
        return ans;

    }
};
