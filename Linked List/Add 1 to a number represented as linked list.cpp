/* A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.
Input:
LinkedList: 4->5->6
Output: 457 */

class Solution
{
    public:
    // reversing the linked list through iterative method
    Node* reverse(Node* head){
        Node* prev= NULL;
        Node* curr = head;
        Node* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // reverse the linked list
        head = reverse(head);
        Node* temp = head;
        Node* prev = NULL;
        int carry = 1;
        // iterate over the nodes of the linked list
        while(temp!=NULL){
            // if the node + 1 is not equal to 10 then just add 1 to the node and break and 
            //reverse the linked list again and return it
            if(temp->data +  carry!= 10){
                temp->data = temp->data + carry;
                carry = 0;
                break;
            }
            // otherwise make the data of the node = 0 and move prev and temp one step ahead
            else{
                temp->data = 0;
                carry = 1;
                prev = temp;
                temp = temp->next;
            }
        }
        // if carry == 1 then make a new node and make the prev point to it 
        if(carry == 1){
            Node* n = new Node(1);
            prev->next = n;
            n->next = NULL;
        }
        // lastly again reverse the linked list and return the answer
        return reverse(head);
    }
};
