/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *cloneLinkedList(Node *head)
    {

        if (head == NULL)
        {
            return head;
        }

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        unordered_map<Node *, Node *> oldToNewNode;

        Node *originalNode = head;
        Node *cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};