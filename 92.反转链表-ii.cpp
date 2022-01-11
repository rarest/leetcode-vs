/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void revertList(ListNode* head) {
        ListNode* preHead = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = preHead;
            preHead = cur;
            cur = next; 
        }
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);    
        ListNode *preLeftNode = &dummy;

        for(int i = 0; i < left - 1; ++i)
            preLeftNode = preLeftNode->next;

        ListNode *rightNode = preLeftNode;
        for(int i= 0; i< right - left +1; ++i)
            rightNode = rightNode->next;
        
        ListNode * leftNode = preLeftNode->next;        
        ListNode * rightNextNode = rightNode->next;
        preLeftNode->next = nullptr;
        rightNode->next = nullptr;

        revertList(leftNode);

        preLeftNode->next = rightNode;
        leftNode->next = rightNextNode;
        
        return dummy.next;
    }
};
// @lc code=end

