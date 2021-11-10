/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    // Brute force
    //  * Guess each number from 1 to n
    // Better Solution
    //  * Binary search 
    int guessNumber(int n) {
        return guessNumberBinarySearch(n);
        //return guessNumberBruteForce(n);
    }
private:
        int guessNumberBruteForce(int n) {
            for (int i = 0; i < n; ++i) {
                if (guess(i) == 0) {
                    return i;
                }
            }
            return INT_MIN;
        }
    
        int64_t guessNumberBinarySearch(int64_t n) { 
            int64_t start = 1, end = n;
            while (start < end) {
                int64_t midpoint = (start + end) / 2;
                int result = guess(midpoint);
                    
                // guessed correctly
                if (result == 0) {
                    return midpoint;
                } else if (result == -1) {
                    end = midpoint - 1;
                } else if (result == 1) {
                    start = midpoint + 1;
                }
            }
            return start;
        }
};
