
#include <vector>


class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		int lower_index(-1), upper_index(-1);
 		for (int i = 0; i < nums.size(); ++i) {
             		for (int j = i + 1; j < nums.size(); ++j) {
	                     if (nums[i] + nums[j] == target) {
			     	lower_index = i;
				upper_index = j;
			     }
			}
		}
		return { lower_index, upper_index };
	}
};

