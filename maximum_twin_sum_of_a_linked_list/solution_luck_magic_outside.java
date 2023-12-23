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
    public int pairSum(ListNode head) {
        List<Integer> A = new ArrayList<Integer>();
        while(head!=null){A.add(head.val); head=head.next;}
        int res=0, n=A.size();
        for(int i=0; i<n/2; i++) 
            res = Math.max(res, A.get(i)+A.get(n-i-1));
        return res;
    }
}