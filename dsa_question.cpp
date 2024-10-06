#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    
    // Sort the array to use two-pointer technique
    std::sort(nums.begin(), nums.end());
    
    int n = nums.size();
    
    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Move left and right pointers and skip duplicates
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                
                ++left;
                --right;
            } 
            else if (sum < 0) {
                ++left; // Increase sum
            } 
            else {
                --right; // Decrease sum
            }
        }
    }
    
    return result;
}
