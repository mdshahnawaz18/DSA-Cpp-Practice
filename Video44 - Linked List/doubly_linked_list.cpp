// Self
#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data : " << val << endl;
    }
};

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

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
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

        curr->prev = NULL;
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

    insertAtHead(head, tail, 18);
    print(head);

    insertAtHead(head, tail, 26);
    print(head);

    insertAtHead(head, tail, 28);
    print(head);

    insertAtTail(head, tail, 21);
    print(head);

    insertAtTail(head, tail, 36);
    print(head);

    insertAtPosition(head, tail, 1, 41);
    print(head);

    insertAtPosition(head, tail, 5, 46);
    print(head);

    deleteNode(head, tail, 1);
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
//     Node *prev;
//     Node *next;

//     // constructor
//     Node(int d)
//     {
//         this->data = d;
//         this->prev = NULL;
//         this->next = NULL;
//     }

//     ~Node()
//     {
//         int val = this->data;
//         if (next != NULL)
//         {
//             delete next;
//             next = NULL;
//         }
//         cout << "Memory free for node with data " << val << endl;
//     }
// };

// // Traversing a linked list
// void print(Node *head)
// {
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// // Gives length of linked list
// int getLength(Node *head)
// {
//     int len = 0;
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     cout << endl;

//     return len;
// }

// void insertAtHead(Node *&tail, Node *&head, int d)
// {
//     // Empty List
//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         // new node create
//         Node *temp = new Node(d);
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {

//     // Empty List
//     if (tail == NULL)
//     {

//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         // new node create
//         Node *temp = new Node(d);
//         tail->next = temp;
//         temp->prev = tail;
//         tail = temp;
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     // insert at start
//     if (position == 1)
//     {
//         insertAtHead(tail, head, d);
//         return;
//     }

//     Node *temp = head;
//     int cnt = 1;

//     while (cnt < position)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     // inserting at last position
//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // creating a node for d
//     Node *nodeToInsert = new Node(d);

//     nodeToInsert->next = temp->next;
//     temp->next->prev = nodeToInsert;
//     temp->next = nodeToInsert;
//     nodeToInsert->prev = temp;
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {
//     // Deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         temp->next->prev = NULL;
//         head = temp->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         curr->prev = NULL;
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

//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;

//     print(head);
//     // cout << getLength(head) << endl;

//     insertAtHead(tail, head, 11);
//     print(head);

//     insertAtHead(tail, head, 14);
//     print(head);

//     insertAtHead(tail, head, 24);
//     print(head);

//     insertAtTail(tail, head, 48);
//     print(head);

//     insertAtPosition(tail, head, 1, 84);
//     print(head);

//     insertAtPosition(tail, head, 4, 18);
//     print(head);

//     insertAtPosition(tail, head, 5, 58);
//     print(head);

//     insertAtPosition(tail, head, 6, 92);
//     print(head);

//     insertAtPosition(tail, head, 3, 34);
//     print(head);
//     cout << "Head : " << head->data << endl;
//     cout << "Tail : " << tail->data << endl;

//     deleteNode(10, head, tail);
//     print(head);
//     cout << "Head : " << head->data << endl;
//     cout << "Tail : " << tail->data << endl;

//     return 0;
// }