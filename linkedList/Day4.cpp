#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;

    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node* arr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node* deleteK(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* prev=NULL;
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* deleteElement(Node* head,int val){
    if(head==NULL) return head;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* insertAtHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}
Node* insertAtK(Node* head,int val,int k){
    if(head==NULL){
        if(k==1) return new Node(val);
    }
    if(k==1){
        Node* x=new Node(val,head);
        return x;
    }
    int count=0;
    Node* temp=head;
    while(temp){
        count++;
        if(count==k-1){
            Node* y=new Node(val);
            y->next=temp->next;
            temp->next=y;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr={1,4,56,7,8,9};
    Node* head=arr2LL(arr);
    // Node* temp=head;
    // while(temp){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    // head=deleteK(head,4);
    // head=deleteElement(head,56);
    // head=insertAtHead(head,13);
    // print(head);
    // cout<<endl;
    Node* A=insertAtK(head,99,4);
    print(A);

}