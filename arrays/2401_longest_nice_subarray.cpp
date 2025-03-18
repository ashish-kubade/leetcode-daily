class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        //sliding window, 2 pointers, while loops for maintaining
        //the sliding window
        //base cases
        if(nums.size() == 0) return 0;
        int maxi = 1, left = 0, right = 1, mask = nums[0];
        int n = nums.size();

        //while loop is controlled by right pointer and n
        while(right < n){
            while((mask & nums[right]) !=0 ){
                //skip all the elements from the left for invalid window
                mask ^= nums[left];
                left ++;
            }
            mask |= nums[right];
            maxi = max(maxi, right - left + 1);
            //entend right pointer only after all the computations are made
            right ++;
        }
        return maxi;
    }
};
