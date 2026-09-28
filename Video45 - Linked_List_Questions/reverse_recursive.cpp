/****************************************************************

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
        

*****************************************************************/

//Short Recursive Approach 

Node* reverse1(Node* head){
    if(head->next == NULL){
        return head;
    }

    Node* chhotaHead = reverse1(head->next);

    head->next->next = head;
    head->next = NULL;

    return chhotaHead;
}

//Better Recursive Approach
void reverse(Node* &head , Node* curr , Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverse(head , forward , curr);

    curr->next = prev;


}

//main function that reverses the linked list and returns the new head
Node* reverseLinkedList(Node *head)
{

Node* curr = head;
Node* prev = NULL;

reverse(head , curr , prev);

return head;

}
