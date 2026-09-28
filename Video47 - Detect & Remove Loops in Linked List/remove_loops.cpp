// Floyd Detection In A Linked List

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

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            cout << "Present at : " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}


Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    // if(intersection == NULL){
    //     return NULL;
    // }

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}



void removeLoop(Node* head){
    if(head == NULL){
        return ;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }

    temp->next = NULL;
}


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
    // print(head);

    insertAtHead(head, 26);
    // print(head);

    insertAtHead(head, 28);
    // print(head);

    insertAtTail(tail, 21);
    // print(head);

    insertAtTail(tail, 36);
    // print(head);

    insertAtPosition(head, tail, 1, 41);
    // print(head);

    insertAtPosition(head, tail, 5, 46);
    // print(head);

    tail->next = head->next;
    // print(head);

    if (floydDetectLoop(head) != NULL)
    {
        cout << "It has loops" << endl;
    }
    else
    {
        cout << "It has not loops" << endl;
    }

    Node* beginningNode = getStartingNode(head);

    cout<<"Beginning Node : " <<beginningNode->data<<endl;

    removeLoop(head);
    print(head);

    
    if (floydDetectLoop(head) != NULL)
    {
        cout << "After removing Loop , It has loops" << endl;
    }
    else
    {
        cout << "After removing Loop , It has not loops" << endl;
    }

    // deleteNode(head, tail, 8);
    // print(head);

    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->next->data << endl;

    return 0;
}