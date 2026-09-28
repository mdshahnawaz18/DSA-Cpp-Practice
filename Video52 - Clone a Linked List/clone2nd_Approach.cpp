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

        // if(head == NULL){
        //     return head;
        // }

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        // Clone the straight linked list
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        Node *originalNode = head;
        Node *cloneNode = cloneHead;

        // Point the originalNode to cloneNode and cloneNode to originalNode in diagonally
        while (originalNode != NULL && cloneNode != NULL)
        {
            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }

        temp = head;

        // Clone the random of originalNode to cloneNode
        while (temp != NULL)
        {
            if (temp->random != NULL)
            {
                temp->next->random = temp->random->next;
            }
            else
            {
                temp->next->random = temp->random;
            }
            temp = temp->next->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        // Point the originalNode to cloneNode and cloneNode to originalNode in diagonally
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {

                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};