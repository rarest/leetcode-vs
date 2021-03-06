/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPair1(ListNode* head) {
        ListNode dummpy, *p = &dummpy, *first, *second;
        p->next = head;
        while (p->next && p->next->next) {
            first = p->next;
            second = p->next->next;
            p->next = second;
            first->next = second->next;
            second->next = first;           
            p = first;
        }
        return dummpy.next;
    }
     ListNode* swapPairs(ListNode* head) {
        ListNode dummy, *pHead = &dummy, *first, *second;
        pHead->next = head;
        while (pHead->next && pHead->next->next)    
        {
            first = pHead->next;
            second = pHead->next->next;
            pHead->next =second;
            first->next = second->next;
            second->next = first;
            pHead = first;
        }
        
        return dummy.next;
     }
};
// @lc code=end

