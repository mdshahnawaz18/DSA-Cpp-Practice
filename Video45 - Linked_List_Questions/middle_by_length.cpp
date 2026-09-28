/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int getLength(Node *head)
{
    int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}

Node *findMiddle(Node *head)
{

    int len = getLength(head);
    int ans = (len / 2);

    int cnt = 0;

    Node *temp = head;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;
}
