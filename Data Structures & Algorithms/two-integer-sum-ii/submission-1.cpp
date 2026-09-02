class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int curSum = numbers[l] + numbers[r];

            if (curSum > target) {
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                return { l + 1, r + 1 };
            }
        }
        return {};
    }
};
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int start=0, end=numbers.size()-1;
//         while(start<end){
//             if(numbers[start]+numbers[end]==target){
//                 return {numbers[start],numbers[end]};
//             }
//             else if(numbers[start]+numbers[end]<target)start++;
//             else end--;
//         }
//         return {-1,-1};
//     }

// };
