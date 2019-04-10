public class DetectCycle {
    /**
     * Definition for singly-linked list.
     * class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) {
     *         val = x;
     *         next = null;
     *     }
     * }
     */
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast != null && fast.equals(slow)) {
                ListNode firstNode = head;
                while (firstNode.equals(slow) == false) {
                    firstNode = firstNode.next;
                    slow = slow.next;
                }
                return firstNode;
            }
        }

        return null;
    }
}
