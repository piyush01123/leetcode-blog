/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        ListNode res = new ListNode(-1);
        ListNode cur = res;
        int s=0, c=0;
        while(l1!=null && l2!=null)
        {
            s = c + l1.val + l2.val;
            c=s/10; s%=10;
            cur.next = new ListNode(s);
            cur = cur.next;
            l1 = l1.next; l2=l2.next;
        }
        while(l1!=null)
        {
            s = c + l1.val;
            c=s/10; s%=10;
            cur.next = new ListNode(s);
            cur = cur.next;
            l1 = l1.next;
        }
        while(l2!=null)
        {
            s = c + l2.val;
            c=s/10; s%=10;
            cur.next = new ListNode(s);
            cur = cur.next;
            l2 = l2.next;
        }
        if (c>0) cur.next = new ListNode(c);
        return res.next;
    }
}