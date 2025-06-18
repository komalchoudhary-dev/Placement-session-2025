class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lowest = 0;
        int highest = nums.size() - 1;

        while (lowest <= highest) {
            int mid = lowest + (highest - lowest) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lowest = mid + 1;
            else
                highest = mid - 1;
        }

        // At the end, 'left' is the correct insertion index
        return lowest;
            
        
    }
};
