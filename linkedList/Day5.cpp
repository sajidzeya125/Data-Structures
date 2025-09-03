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
        deleteHead(head);
        return head;
    }
    else if(front==NULL){
        deleteTail(head);
        return head;
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
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={28,29};
    Node* head=convertArr2DLL(arr);
    // print(head);
    // Node* ans=deleteHead(head);
    // print(ans);
    // Node* ans1=deleteTail(head);
    // print(ans1);
    Node* ans2=deleteK(head,1);
    print(ans2);
}