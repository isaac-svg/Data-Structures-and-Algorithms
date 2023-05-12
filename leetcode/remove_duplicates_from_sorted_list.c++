//
/**
 * @brief 83 remove duplicates from linked list
 *
 */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeDuplicates(ListNode *head)
{
    ListNode *currNode = head;
    ListNode *tempNode = nullptr;
    ListNode *delMe = nullptr;
    {
        if (currNode->val == currNode->next->val)
        {
            tempNode = currNode->next;

            while (tempNode->val == tempNode->next->val)
            {
                tempNode = tempNode->next;
            }
            delMe = tempNode;
            currNode->next = tempNode->next;
            delete delMe;
        }
    }
    return head;
}
