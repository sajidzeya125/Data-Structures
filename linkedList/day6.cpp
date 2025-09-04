#include<bits/stdc++.h>
using namespace std;
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
Node* reverseDLL(Node* head){
    if (head==NULL || head->next==NULL) return head;
    Node* prev=NULL;
    Node* current=head;
    while(current){
        prev=current->back;
        current->back=current->next;
        current->next=prev;
        current=current->back;
    }
    return prev->back;
} 
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    vector<int> arr={1,4,5,6,7,9};
    Node* head=convertArr2DLL(arr);
    // print(head);
    Node* ans=reverseDLL(head);
    print(ans);
}