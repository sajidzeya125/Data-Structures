#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* convertArr2DLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev= prev->next;
    }
    return head;
}
Node* deleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    free(prev);
    return head;
}
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    free(tail);
    return head;
}
Node* deleteK(Node* head,int k){
    Node* temp=head;
    int count=0;
    while(temp){
        count++;
        if(count==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==NULL && front==NULL){
        free(temp);
        return NULL;
    }
    else if(prev==NULL){
        return deleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return head;
    }
}
void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    front->back=prev;
    prev->next=front;
    temp->back=temp->next=nullptr;
    free(temp);
}
Node* insertBeforeHead(Node* head,int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    newHead->next=head;
    return newHead;
}
Node* insertBeforeTail(Node* head,int val){
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}
void insertBeforeNode(Node* node,int val){
    Node* prev=node->back;
    Node* newNode= new Node(val,node,prev);
    node->back=newNode;
    prev->next=newNode;
}
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    Node* head=convertArr2DLL(arr);
    // print(head);
    // Node* ans=deleteHead(head);
    // print(ans);
    // Node* ans1=deleteTail(head);
    // print(ans1);
    // head=deleteK(head,1);
    // print(head);
    // deleteNode(head->next->next);
    // print(head);
    // Node* ans3=insertBeforeHead(head,45);
    // print(ans3);
    insertBeforeNode(head->next,45);
    print(head);
}