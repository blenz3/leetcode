class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        int bestSum = -1;
        for (int i = 0; i < A.length; ++i) 
        {
            for (int j = i + 1; j < A.length; ++j)
            {
                int localSum = A[i] + A[j];
                if (localSum < K)
                    bestSum = Math.max(localSum, bestSum);
            }
        }
        
        return bestSum;
    }
}
