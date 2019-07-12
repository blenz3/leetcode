class Solution {
    public String addBinary(String a, String b) {
        int maxLength = Math.max(a.length(), b.length()) + 1;
        StringBuilder out = new StringBuilder("");
        
        int rollover = 0;
        int aIdx = a.length() - 1, bIdx = b.length() - 1;
        while (rollover == 1 || aIdx >= 0 || bIdx >= 0)
        {
            int aVal = (aIdx >= 0) ? a.charAt(aIdx) - '0' : 0;
            int bVal = (bIdx >= 0) ? b.charAt(bIdx) - '0' : 0;
            int localSum = (int) rollover + aVal + bVal;
            
            rollover = (localSum > 1) ? 1 : 0;
            localSum %= 2;
            
            out.append(localSum);
            aIdx--;
            bIdx--;
        }
        
        return out.reverse().toString();
    }
    
/* Naive solution
    public String addBinary(String a, String b) {
        int x = Integer.parseInt(a, 2);
        int y = Integer.parseInt(b, 2);
        
        return Integer.toString(x + y, 2);
    }
*/ 
}
