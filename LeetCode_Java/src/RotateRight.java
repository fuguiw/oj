public class RotateRight {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }

        ListNode right = head;
        int length = 0;
        while (k-- > 0) {
            length++;
            right = right.next;
            if (right == null) {
                right = head;
                k %= length;
            }
        }
        ListNode left = head;
        while (right.next != null) {
            left = left.next;
            right = right.next;
        }

        if (left.next != null) {
            right.next = head;
            head = left.next;
            left.next = null;
        }

        return head;
    }
}
