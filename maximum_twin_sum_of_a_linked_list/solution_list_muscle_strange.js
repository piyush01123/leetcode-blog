/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var pairSum = function(head) {
        let A=[];
        while(head!=null){A.push(head.val); head=head.next;}
        let res=0, n=A.length;
        for(let i=0; i<n/2; i++) 
            res = Math.max(res, A.at(i)+A.at(n-i-1));
        return res;
  
};