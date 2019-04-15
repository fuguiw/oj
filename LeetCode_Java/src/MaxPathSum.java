public class MaxPathSum {
    /**
     * Definition for a binary tree node.
     * public class TreeNode {
     *     int val;
     *     TreeNode left;
     *     TreeNode right;
     *     TreeNode(int x) { val = x; }
     * }
     */
    private int result = Integer.MIN_VALUE;

    private int findMaxSum(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftSum = Math.max(0, findMaxSum(root.left));
        int rightSum = Math.max(0, findMaxSum(root.right));
        result = Math.max(result, root.val + leftSum + rightSum);
        return root.val + (leftSum > rightSum ? leftSum : rightSum);
    }

    public int maxPathSum(TreeNode root) {
        findMaxSum(root);
        return result;
    }
}
