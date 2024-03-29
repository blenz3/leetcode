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
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null)
        {
            return 0;
        }
        
        int currentValue = (root.val >= L && root.val <= R) ? root.val : 0;
        return currentValue + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R);
    }
}
