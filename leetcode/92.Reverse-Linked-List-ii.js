var reverseBetween = function(head, m, n) {
  let dummy = new ListNode(-1);
  dummy.next = head;
  let pre = dummy;
  
  for (let i = 0; i < m - 1; i++) {
      pre = pre.next
  }
  
  let curr = pre.next, next = curr.next;
  for (let i = 0; i < n - m ; i++){
      curr.next = next.next;
      next.next = pre.next;
      pre.next = next;
      next = curr.next;
  }
  return dummy.next;
};