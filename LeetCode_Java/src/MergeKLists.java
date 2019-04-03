import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

/**
     * Definition for singly-linked list.
     */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class MergeKLists {

    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.val));

        for (ListNode list : lists) {
            if (list != null) {
                pq.add(list);
            }
        }

        ListNode head = null;
        ListNode cur = null;

        while (!pq.isEmpty()) {
            ListNode tmp = pq.poll();
            if (head == null) {
                head = tmp;
            } else {
                cur.next = tmp;
            }

            cur = tmp;
            if (cur.next != null) {
                pq.add(cur.next);
            }
        }

        return head;
    }
}
