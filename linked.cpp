#include <iostream>
using namespace std;


class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
        
    }
};

class Linklist{
public:
    Node* head;
    
    Linklist(){
        head=NULL;
    }
    
    void insertattail(int val){
        Node* new_node=new Node(val);
        
        if(head==NULL){
            head=new_node;
            return;
        }
        
        Node* temp=head;
        
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }


void display(){
    
    Node* temp=head;
    
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }cout << "NULL" << endl;
    
}
};


void alternatenode(Node* &head){
    Node* curr=head;
    
    while(curr!=NULL and curr->next!=NULL){
        Node* temp = curr->next;
        curr->next=temp->next;
        free(temp);
        curr=curr->next;
    }
}

void duplicate(Node* &head){
    Node* curr=head;
    
    while(curr!=NULL){
        while(curr->next!=NULL and curr->val==curr->next->val ){
            Node* temp=curr->next;
            curr->next=temp->next;
            free(temp);
        }
        curr=curr->next;
    }
}


void reverseprint(Node* &head){
    if(head==NULL){
        return;
    }
    
    reverseprint(head->next);
    cout<<head->val<<"->";
    
}

Node* reverse(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
   
    
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    Node* new_head=prev;
    return new_head;
}


int main(){
    Linklist ll;


    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.insertattail(3);

    ll.display();
    
    //alternatenode(ll.head);
   // ll.display();
    
    //duplicate(ll.head);
    //ll.display();
    
    //reverseprint(ll.head);
    //ll.display();
    
    ll.head=reverse(ll.head);
    ll.display();
   
    return 0;
    
}
