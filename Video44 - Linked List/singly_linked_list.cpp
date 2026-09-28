// Self
#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {

        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for Node with " << val << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = head;
    head = nodeToInsert;
}

void insertAtTail(Node *&tail, int d)
{
    Node *nodeToInsert = new Node(d);
    tail->next = nodeToInsert;
    tail = nodeToInsert;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
    }

    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node *&head, Node *&tail, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    else
    {

        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;

        if (prev->next == NULL)
        {
            tail = prev;
        }

        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(24);

    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 18);
    print(head);

    insertAtHead(head, 26);
    print(head);

    insertAtHead(head, 28);
    print(head);

    insertAtTail(tail, 21);
    print(head);

    insertAtTail(tail, 36);
    print(head);

    insertAtPosition(head, tail, 1, 41);
    print(head);

    insertAtPosition(head, tail, 5, 46);
    print(head);

    deleteNode(head, tail, 8);
    print(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    return 0;
}

// Babbar

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }

//     // destructor
//     ~Node()
//     {
//         int value = this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " Memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {
//     // new node create
//     Node *temp = new Node(d);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     // new node create
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp;
// }

// void insertAtPosition(Node *&head, Node *&tail, int position, int d)
// {

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }

//     Node *temp = head;
//     int cnt = 1;

//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     // inserting at last position
//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // creating a node for d
//     Node *nodeToInsert = new Node(d);

//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {

//     // deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         // memory free start node
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         // deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;

//         if (prev->next == NULL)
//         {

//             tail = prev;
//         }

//         delete curr;
//     }
// }

// int main()
// {
//     // created a new node
//     Node *node1 = new Node(24);
//     // cout << node1->data << endl;
//     // cout << node1->next << endl;

//     // head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtHead(head, 12);
//     print(head);

//     insertAtTail(tail, 18);
//     print(head);

//     insertAtTail(tail, 42);
//     print(head);

//     insertAtPosition(head, tail, 5, 72);
//     print(head);

//     cout << "Head : " << head->data << endl;
//     cout << "Tail : " << tail->data << endl;

//     deleteNode(4, head, tail);
//     print(head);
//     cout << "Tail : " << tail->data << endl;

//     return 0;
// }