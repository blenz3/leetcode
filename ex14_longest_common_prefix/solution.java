class Solution {
    public String longestCommonPrefix(String[] strs) {
        // The input space has nothing in it
        if (strs.length == 0)
            return "";
        
        int end_index = 0;
        boolean continue_checking = true;
        for (int i = 0; i < strs[0].length() && continue_checking; ++i) 
        {
            char c = strs[0].charAt(i);
            for (String s : strs)
            {
                if (s.length() <= end_index || s.charAt(end_index) != c)
                {
                    continue_checking = false;
                    break;
                }   
            }
            
            if (continue_checking)
                ++end_index;
        }
        
        return strs[0].substring(0, end_index);
    }
}
