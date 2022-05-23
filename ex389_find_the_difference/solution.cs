public class Solution {
    public char FindTheDifference(string s, string t) {
        int diff = SumString(t) - SumString(s);
        return (char)diff;
    }
    
    private int SumString(string s){
        int sum=0;
        foreach(char c in s){
            sum += c;
        }
        return sum;
    }
}
