// linkedList----> A type of linear data structures that is a collection of nodes.
//LinkedList is a type of dynamic data structures that can grow or shrink at runtime with no more memory wastage
/*Types of linkedList:-
  *Singly LL
  *Doubly LL
  *Circular LL
  *Circular Doubly LL*/
 #include<bits/stdc++.h>
 using namespace std;
 class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
 };
 void insertAtTail(Node* &tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
 }
 void insertAtHead(Node* &head,int d){
    // Create new node
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
 }
 void insertAtPosition(Node* &head,int position, int d){
   // insert at first
   if(position==1){
      insertAtHead(head,d);
      return;
   }
   int cnt=1;
   Node* temp=head;
   while(cnt<position-1){
      temp=temp->next;
      cnt++;
   }
   // creating a node for d
   Node* nodeToInsert=new Node(d);
   nodeToInsert->next=temp->next;
   temp->next=nodeToInsert;
 }
 void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
 }
 int main(){
    Node* node1=new Node(34);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtTail(tail,67);
    print(head);
    insertAtTail(tail,55);
    print(head);
    insertAtPosition(head,1,12);
    print(head);
    return 0;
 }