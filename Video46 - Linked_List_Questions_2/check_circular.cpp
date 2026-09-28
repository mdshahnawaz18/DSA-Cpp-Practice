#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for Node with data : " << value << endl;
    }
};

bool detectCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head;

    while (temp != head && temp != NULL)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        cout << "Temp : " << temp->data << endl;
        return true;
    }

    return false;
}

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

void deleteNode(Node *&tail, int element)
{

    if (tail == NULL)
    {
        cout << "List is empty , Please try again " << endl;

        return;
    }

    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // only 1 node
        if (curr == prev)
        {
            tail = NULL;
        }

        // 2 or more than 2 nodes present
        if (curr == tail)
        {
            tail = prev;
        }

        curr->next = NULL;

        delete curr;
    }
}

int main()
{

    Node *tail = NULL;

    insertNode(tail, 18, 24);
    print(tail);

    insertNode(tail, 24, 42);
    print(tail);

    insertNode(tail, 42, 100);
    print(tail);

    insertNode(tail, 100, 104);
    print(tail);

    if (detectCircular(tail))
    {
        cout << "Linked list is circular " << endl;
    }
    else
    {
        cout << "Linked list is not circular " << endl;
    }

    // insertNode(tail, 104, 118);
    // print(tail);

    // insertNode(tail, 118, 200);
    // print(tail);

    // insertNode(tail, 200, 204);
    // print(tail);

    // deleteNode(tail, 100);
    // print(tail);

    // deleteNode(tail, 200);
    // print(tail);

    // deleteNode(tail, 24);
    // print(tail);

    cout << "Tail : " << tail->data << endl;

    return 0;
}
