#include <bits/stdc++.h>
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


Node* reversellrecursive(Node* &head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* new_head = reversellrecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
}

bool checkequal(Node* head1,Node* head2){
    
    Node* ptr1=head1;
    Node* ptr2=head2;
    
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1->val!=ptr2->val){
            return false;
        }
        
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return(ptr1==NULL and ptr2==NULL);
}
int main(){
    Linklist ll1;
    Linklist ll2;

    for(int i= 1;i<=5;i++){
        ll1.insertattail(i);
        ll2.insertattail(i);
    }
    
    
    ll1.display();
    ll2.display();
    //alternatenode(ll.head);
   // ll.display();
    
    //duplicate(ll.head);
    //ll.display();
    
    //reverseprint(ll.head);
    //ll.display();
    
    // ll.head=reverse(ll.head);
    //ll.display();
   
   //ll.head=reversellrecursive(ll.head);
   //ll.display();
   
    cout<<checkequal(ll1.head,ll2.head);
    
    return 0;
    
}
