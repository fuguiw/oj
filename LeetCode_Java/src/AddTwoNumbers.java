public class AddTwoNumbers {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode sum = null;
        ListNode pre = null;
        int carry = 0;
        while (l1 != null || l2 != null) {
            ListNode cur = new ListNode(0);
            cur.val = carry;
            if (l1 != null) {
                cur.val += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                cur.val += l2.val;
                l2 = l2.next;
            }
            carry = cur.val / 10;
            cur.val = cur.val % 10;

            if (sum == null) {
                sum = pre = cur;
            } else {
                pre.next = cur;
                pre = cur;
            }
        }
        if (carry > 0) {
            ListNode cur = new ListNode(carry);
            pre.next = cur;
        }

        return sum;
    }
}
