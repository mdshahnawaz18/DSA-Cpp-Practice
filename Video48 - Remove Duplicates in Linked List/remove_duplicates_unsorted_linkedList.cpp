#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
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
    };
*****************************************************************/


#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
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
    };
*****************************************************************/
//Brute Force Approach
Node *removeDuplicates(Node *head)
{
    if(head == NULL)
        return NULL;

    Node *curr = head;

    while(curr != NULL)
    {
        Node *temp = curr;
        while(temp->next != NULL)
        {
            if(temp->next->data == curr->data)
            {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

//Brute Force Approach

Node *removeDuplicates(Node *head)
{

    if(head == NULL){
        return NULL;
    }

    Node* curr = head;


    while(curr != NULL){
        Node* prev = curr;
        Node* temp = curr->next;
        
        while(temp != NULL){
            if(curr->data == temp->data){
                prev->next = temp->next; 
                Node* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;

            }
            else{
                prev = temp;
                temp = temp->next;
                
            } 
        }
        curr = curr->next;
    }
    return head;
}


//Optimal Approach using Hashing

Node *removeDuplicates(Node *head)
{
    if(head == NULL)
        return NULL;

    unordered_set<int> st;

    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL)
    {
        if(st.find(curr->data) != st.end())
        {
            // Duplicate node
            prev->next = curr->next;

            Node *nodeToDelete = curr;
            curr = curr->next;
            delete nodeToDelete;
        }
        else
        {
            st.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}