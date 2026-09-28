// Self
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

    insertNode(tail, 104, 118);
    print(tail);

    insertNode(tail, 118, 200);
    print(tail);

    insertNode(tail, 200, 204);
    print(tail);

    deleteNode(tail, 100);
    print(tail);

    deleteNode(tail, 200);
    print(tail);

    deleteNode(tail, 24);
    print(tail);

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

//     // Constructor
//     Node(int d)
//     {
//         this->data = d;
//         this->next = NULL;
//     }

//     // Destructor
//     ~Node()
//     {
//         int value = this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             next = NULL;
//         }
//         cout << "Memory is free for node with data : " << value << endl;
//     }
// };

// void insertNode(Node *&tail, int element, int d)
// {

//     // Empty List
//     if (tail == NULL)
//     {
//         Node *newNode = new Node(d);
//         tail = newNode;
//         newNode->next = newNode;
//     }
//     else
//     {
//         // Non-empty list
//         // Assuming that the element is present in the list

//         Node *curr = tail;

//         while (curr->data != element)
//         {
//             curr = curr->next;
//         }

//         // Element found -> curr is representing element wala node
//         Node *temp = new Node(d);
//         temp->next = curr->next;
//         curr->next = temp;
//     }
// }

// void print(Node *tail)
// {
//     Node *temp = tail;

//     if (tail == NULL)
//     {
//         cout << "List is empty" << endl;
//     }

//     do
//     {
//         cout << tail->data << " ";
//         tail = tail->next;
//     } while (tail != temp);

//     cout << endl;
// }

// void deleteNode(Node *&tail, int value)
// {

//     // empty list
//     if (tail == NULL)
//     {
//         cout << "List is empty , Please check again " << endl;
//         return;
//     }

//     else
//     {
//         // Non - empty

//         // assuming that value is present in the linked list
//         Node *prev = tail;
//         Node *curr = prev->next;

//         while (curr->data != value)
//         {
//             prev = curr;
//             curr = curr->next;
//         }

//         prev->next = curr->next;

//         // 1 Node linked list
//         if (curr == prev)
//         {
//             tail = NULL;
//         }

//         //>=2 Node linked list
//         if (tail == curr)
//         {
//             tail = prev;
//         }

//         curr->next = NULL;
//         delete curr;
//     }
// }

// int main()
// {

//     Node *tail = NULL;

//     insertNode(tail, 5, 4);
//     print(tail);

//     insertNode(tail, 4, 5);
//     print(tail);

//     insertNode(tail, 5, 14);
//     print(tail);

//     insertNode(tail, 14, 45);
//     print(tail);

//     insertNode(tail, 45, 24);
//     print(tail);

//     insertNode(tail, 24, 18);
//     print(tail);

//     insertNode(tail, 18, 48);
//     print(tail);

//     deleteNode(tail, 45);
//     print(tail);

//     deleteNode(tail, 24);
//     print(tail);

//     // cout << "Tail : " << tail->data << endl;

//     return 0;
// }