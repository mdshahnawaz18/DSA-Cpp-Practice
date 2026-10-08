/** LeetCode
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare{
public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    priority_queue<ListNode* , vector<ListNode*> , compare> minHeap;
    int k = lists.size();

    if(k == 0){
        return nullptr;
    }

    for(int i=0; i<k ; i++){
        if(lists[i] != nullptr){
            minHeap.push(lists[i]);
        }
    }
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while(minHeap.size() > 0){
            ListNode* top = minHeap.top();
            minHeap.pop();

            if(top->next != nullptr){
                minHeap.push(top->next);
            }

            if(head == nullptr){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }

    return head;
    }
};









/*  CodeStudio
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

class compare{
public:
    bool operator()(Node* a , Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){

    priority_queue<Node* , vector<Node*> , compare> minHeap;
    int k = listArray.size();

    if(k == 0){
        return NULL;
    }

    for(int i=0; i<k ; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }
        Node* head = NULL;
        Node* tail = NULL;

        while(minHeap.size() > 0){
            Node* top = minHeap.top();
            minHeap.pop();

            if(top->next != NULL){
                minHeap.push(top->next);
            }

            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }
        }

    return head;
}
