# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
        NodeRecorder = []
        NodeRecorder.append(head)
        RecorderSize = 1
        while head != None:
            if head.next != None:
                head = head.next
                NodeRecorder.append(head)
                RecorderSize += 1
            else:
                break
            
        for i in range(RecorderSize-1):
            if i % 2 == 0:
                index = int(round(i/2.0))
                NodeRecorder[index].next = NodeRecorder[-(index + 1)]
            else:
                index = int(round(i/2.0) * -1)
                NodeRecorder[index].next = NodeRecorder[-(index)]
                
        if RecorderSize > 1:
            NodeRecorder[int(round((RecorderSize-1)/2.0))].next = None
            
            

            
        