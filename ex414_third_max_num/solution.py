class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        deduped_list = list(sorted(set(nums)))
        if len(deduped_list) < 3:
            return deduped_list[-1];
        
        return deduped_list[-3];
        
