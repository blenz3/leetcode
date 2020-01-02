class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1
        
        pivot = self.find_pivot(nums)
        if target == nums[pivot]:
            return pivot
        
        lower_search = self.binary_search(nums[pivot:], target)
        if lower_search != -1:
            return pivot + lower_search
        
        upper_search = self.binary_search(nums[:pivot], target)
        if upper_search != -1:
            return upper_search 
        
        return -1
    
    def find_pivot(self, l):
        left, right = 0, len(l) - 1
        
        while left < right:
            mid = (left + right) / 2
            if mid == left:
                break
                
            if l[mid] < l[left]:
                right = mid
            else:
                left = mid
                
        return right if l[right] < l[left] else left
                
    def binary_search(self, l, target):
        left, right = 0, len(l) - 1
        
        while left <= right:
            
            mid = (left + right) / 2
            if l[mid] == target:
                return mid
            elif l[mid] < target:
                left = mid + 1
            elif l[mid] > target:
                right = mid - 1
                
        return -1

            
            
