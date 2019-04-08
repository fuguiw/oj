public class SortList {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */

    private ListNode mergeList(ListNode leftList, ListNode rightList) {
        ListNode head = null;
        ListNode curNode = null;

        while (leftList != null && rightList != null) {
            ListNode nextNode = null;
            if (leftList.val < rightList.val) {
                nextNode = leftList;
                leftList = leftList.next;
            } else {
                nextNode = rightList;
                rightList = rightList.next;
            }

            if (head == null) {
                head = nextNode;
                curNode = head;
            }
            curNode.next = nextNode;
            curNode = nextNode;
        }
        if (leftList != null) {
            curNode.next = leftList;
        } else if (rightList != null) {
            curNode.next = rightList;
        }

        return head;
    }

    private ListNode mergeSort(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        System.out.println(slow.val);
        ListNode rightList = mergeSort(slow.next);
        slow.next = null;
        ListNode leftList = mergeSort(head);

        return mergeList(rightList, leftList);
    }

    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
}
