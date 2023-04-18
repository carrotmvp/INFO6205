#include <bits/stdc++.h>
using namespace std;

/*
test1:
5
1 2 3 4 5
2
output:
[1,2,3,5]

test2:
1
1
1
output:
[]


test2:
2
1 2
1
output:
[1]


*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// solve the question
ListNode *removeN(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;
    while (n--)
        fast = fast->next;
    if (!fast)
        return head->next;
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

int main()
{

    // input
    int n;
    cin >> n; // number of node
    ListNode *head = new ListNode();
    ListNode *now = head;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        now->val = x;
        if (i != n - 1)
        {
            ListNode *node = new ListNode();
            now->next = node;
            now = now->next;
        }
    }
    cin >> n;                // input the remove number
    head = removeN(head, n); // get answer node

    // output
    if (head == nullptr)
    {
        cout << "[]" << endl;
        return 0;
    }
    cout << '[' << head->val;
    while (head->next != nullptr)
    {
        head = head->next;
        cout << ',' << head->val;
    }
    cout << ']' << endl;
}