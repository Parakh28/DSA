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

int length(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
    
}

Node* movetillk(Node* head,int k){
    Node* temp=head;
    
    while(k--){
        temp=temp->next;
    }
    return temp;
}


Node* getintersection(Node* head1,Node* head2){
    
    int l1=length(head1);
    int l2=length(head2);
    
    Node* ptr1;
    Node* ptr2;
    
    if(l1>l2){
        int k=l1-l2;
        ptr1=movetillk(head1,k);
        ptr2=head2;
    }
    else{
        int k=l2-l1;
        ptr1=head1;
        ptr2=movetillk(head2,k);
    }
    
    
    while(ptr1){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return NULL;
    
}

void deletefromposend(Node* &head,int k){
    
    Node* pos1=head;
    Node* pos2=head;
    int count=k;
    while(count--){
        pos2=pos2->next;
    }
    
    if(pos2==NULL){
        Node* temp=head;
        head=head->next;
        free(temp);
        return;
    }
    
    
    while(pos2->next!=NULL){
        pos1=pos1->next;
        pos2=pos2->next;
    }
    
    
    Node* temp=pos1->next;
    
    pos1->next=temp->next;
    free(temp);
}

Node* mergelinklist(Node* head1,Node* head2){
    
    Node* dummayhead= new Node(-1);
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* ptr3=dummayhead;
    
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1->val < ptr2->val){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1){
        ptr3->next=ptr1;
    }
    else{
        ptr3->next=ptr2;
    }
    
    return dummayhead->next;
}
int main(){
    
    Linklist ll1;
    Linklist ll2;
    Linklist ll3;
    

    
        ll1.insertattail(1);
        ll1.insertattail(3);
        ll1.insertattail(5);
        ll2.insertattail(2);
        ll2.insertattail(4);
        ll1.display();
        ll2.display();
        ll3.head=mergelinklist(ll1.head,ll2.head);
        ll3.display();
        
        
        //ll1.display();
        //deletefromposend(ll1.head,5);
        //ll1.display();
        //ll2.insertattail(1);
        //ll2.insertattail(2);*/
        //l2.head->next->next=ll1.head->next->next->next;

        //ll2.display();
    
       /*Node* interaction = getintersection(ll1.head,ll2.head);
        if(interaction){
            cout<<interaction->val<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }*/
    
    //ll1.display();
    //ll2.display();
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
   
    //cout<<checkequal(ll1.head,ll2.head);
    
    return 0;
    
}
