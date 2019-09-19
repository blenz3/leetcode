/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) 
            return null;
        
        TreeNode node = new TreeNode(getNodeValue(t1) + getNodeValue(t2));
        node.left = mergeTrees(getLeftSubtree(t1), getLeftSubtree(t2));
        node.right = mergeTrees(getRightSubtree(t1), getRightSubtree(t2));
        
        return node;
    }
    
    private int getNodeValue(TreeNode t)
    {
        if (t == null)
            return 0;
        
        return t.val;
    }
    
    private TreeNode getLeftSubtree(TreeNode t)
    {
        if (t == null) 
            return null;
        
        return t.left;
    }
    
    private TreeNode getRightSubtree(TreeNode t)
    {
        if (t == null)
            return null;
        
        return t.right;
    }
}
