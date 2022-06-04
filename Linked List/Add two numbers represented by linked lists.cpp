/*Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.
The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0). */
// code

class Solution
{
    public:
    // Function to find the length of linked list
    int length(Node* head){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    // Function to reverse linked list
    struct Node* reverse(struct Node* head){
        Node* prevptr = NULL;
        Node* currptr = head;
        Node* nextptr;
        while(currptr!=NULL){
            nextptr = currptr -> next;
            currptr -> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        
        int l1 = length(first);
        int l2 = length(second);
        // swaping first and second
        if(l1 < l2){
            Node* temp = first;
            first = second;
            second = temp;
        }
        Node* temp1 = first;
        Node* temp2 = second;
        int carry = 0;
       // This while loop will break when we traverse along the linked list of smaller length
        while(temp2!=NULL){
            temp1->data += temp2->data + carry;
            
            if(temp1->data > 9){
                temp1->data -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        // This while loop runs after we are done traversing the smaller length linked list and
        // there is still nodes left in the linked list of larger length
        while(temp1!=NULL){
            // since there is only one linked list left add only carry to the data each time
            temp1->data += carry;
            
            if(temp1->data > 9){
                temp1->data -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            
            temp1 = temp1 -> next;
        }
        //re reverse the first to give the answer
        first = reverse(first);
        // if carry is 1 then make a new node and make its next point to the first node
        if(carry == 1){
            Node* n = new Node(1);
            n->next = first;
            // now our head will be n so store n in the first
            first = n;
        }
        // and return the answer
        return first;
    }
};
