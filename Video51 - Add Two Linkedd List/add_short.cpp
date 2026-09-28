/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution
{
private:
    Node *reverse(Node *first)
    {

        Node *prev = NULL;
        Node *curr = first;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node *&head, Node *&tail, int value)
    {
        Node *temp = new Node(value);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    Node *add(Node *first, Node *second)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;

            if (first != NULL)
            {
                val1 = first->data;
            }

            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if (first != NULL)
            {
                first = first->next;
            }
            if (second != NULL)
            {
                second = second->next;
            }
        }
        return ansHead;
    }

public:
    Node *addTwoLists(Node *head1, Node *head2)
    {
        // code here
        while (head1 != NULL && head1->data == 0 && head1->next != NULL)
        {
            head1 = head1->next;
        }
        while (head2 != NULL && head2->data == 0 && head2->next != NULL)
        {
            head2 = head2->next;
        }

        Node *first = reverse(head1);
        Node *second = reverse(head2);

        Node *ans = add(first, second);
        ans = reverse(ans);

        return ans;
    }
};