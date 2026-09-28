/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int getLength(Node* head){
    int length = 0;
    Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

Node* kReverse(Node* head, int k) {

if(head == NULL){
    return NULL;
}

Node* next = NULL;
Node* curr = head;
Node* prev = NULL;
int count = 0;

int len = getLength(head); 

if(len<k){
    return head;
}

while(curr != NULL && count < k){
    next = curr->next;
    curr->next = prev; 
    prev = curr;
    curr = next;
    count++;
}

if(next != NULL){
    head->next = kReverse(next , k);
}

return prev;


}