/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummpy(0, head), *first = head, *second = &dummpy;
        for(int i = 0; i<n; i++) {
            first = first->next;
        }
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        
        return dummpy.next;        
        

    }
};
// @lc code=end

