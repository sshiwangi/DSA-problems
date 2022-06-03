 /* Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15 */

// code

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
// Function to find length of the linked lists
int length(Node* head){
    int l =0;
    Node* temp = head;
    while(temp!=NULL){
        temp= temp->next;
        l++;
    }
    return l;
}
//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int l1 = length(head1);
    int l2 = length(head2);
    
    Node* ptr1;
    Node* ptr2;
    int d = 0;
    
    // we will put ptr1 at the head of the longer linked list 
    //and later move it to the differece of the length of the lined lists
    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    // putting ptr1 at the difference of l1 and l2
    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }
    
    while(ptr1!=NULL && ptr2 !=NULL){
        // if ptr1 becomes equal to ptr2, we will get our intersection point
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}
