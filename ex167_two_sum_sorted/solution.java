class Solution {
    public int[] twoSum(int[] numbers, int target)
    {
        
        int lowerIndex = 0, upperIndex = numbers.length - 1;
        while (upperIndex > lowerIndex)
        {
            int localSum = numbers[lowerIndex] + numbers[upperIndex];
            if (localSum == target)
            {
                return new int[] { lowerIndex + 1, upperIndex + 1};
            }
            else if (localSum > target)
            {
                upperIndex--;
            }
            else
            {
                lowerIndex++;
            }
        }
        
        
        return new int[] { -1, -1 };
        
    }
}
