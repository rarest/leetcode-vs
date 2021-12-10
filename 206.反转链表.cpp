/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList1(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;            
        }
        return prev;

    }
};
// @lc code=end

