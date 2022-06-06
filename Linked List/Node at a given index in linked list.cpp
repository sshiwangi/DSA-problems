/*
Given a singly linked list with N nodes and a number X. The task is to find the node at the given index (X)(1 based index) of linked list. */

int GetNth(struct node* head, int index){
  // Code here
    int count = 1;
    node* temp = head;
    while(temp!=NULL){
        if(count == index){
            return temp->data;
        }
        count++;
        temp = temp->next;
  }
}
