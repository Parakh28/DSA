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

Node* mergeklinklist(vector <Node*> &lists){
    if(lists.size()==0){
        return NULL;
    }
    while(lists.size()>1){
        Node* mergehead = mergelinklist(lists[0],lists[1]);
        lists.push_back(mergehead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

Node* printmid(Node* head){
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

bool detectcycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    
    if(!head){
        return false;
    }
    
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast){
            cout<<slow->val<<endl;
            return true;
        }
    }
    return false;
}


void removecycle(Node* &head){
    Node* slow=head;
    Node* fast=head;
    
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
    
}

bool palindrome(Node* &head){
    Node* slow=head;
    Node* fast=head;
    
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;
    
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    Node* head1=head;
    Node* head2=prev;
    while(head2){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
    
    
}

Node* rotatebyk(Node* & head,int k){
    int n=0;
    Node* temp=head;
    while(temp->next!=NULL){
        n++;
        temp=temp->next;
    }
    n++;
    
    k=k%n;
    if(k==0){
        return head;
    }

    temp->next=head;
    Node* temp2=head;
    
    
    for(int i=0;i<n-k-1;i++){
       temp2=temp2->next;
    }
    Node* new_head=temp2->next;
    temp2->next=NULL;
    return new_head;
    
}

Node* oddeven(Node* &head){
    
    if(!head){
        return head;
    }
    
    Node* evenhead=head->next;
    Node* oddptr=head;
    Node* evenptr=evenhead;
    
    while(evenptr and evenptr->next){
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        evenptr=evenptr->next;
        oddptr=oddptr->next;
    }
    oddptr->next=evenhead;
    return head;
}



Node* alternate(Node* &head){
    
    Node* slow=head;
    Node* fast=head;
    
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node* curr=slow->next;
    slow->next=NULL;
    Node* prev=slow;
    
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    Node* ptr1=head;
    Node* ptr2=prev;
    
    while(ptr1!=ptr2){
        Node* temp=ptr1->next;
        ptr1->next=ptr2;
        ptr1=ptr2;
        ptr2=temp;
    }
    
    return head;
}


int main(){
    
    Linklist ll;
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(3);
    ll.insertattail(4);
    ll.insertattail(5);
    ll.insertattail(6);
    ll.insertattail(7);
    ll.display();
    ll.head=oddeven(ll.head);
    ll.display();
    
    
    
    
    
    //cout<<palindrome(ll.head)<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    Linklist ll1;
    ll1.insertattail(1);
    ll1.insertattail(2);
    ll1.insertattail(3);
    ll1.insertattail(4);
    ll1.insertattail(5);
    ll1.insertattail(6);
    ll1.insertattail(7);
    ll1.insertattail(8);
    ll1.display();
    ll1.head->next->next->next->next->next->next->next->next=ll1.head->next->next;
    
    cout<<detectcycle(ll1.head)<<endl;
    
    cout<<"after removal"<<endl;
    removecycle(ll1.head);
    cout<<detectcycle(ll1.head)<<endl;
    ll1.display();
    
    */
    
    /*
    Node* a = printmid(ll1.head);
    cout<<a->val;
    
    
    Linklist ll2;
    ll2.insertattail(2);
    ll2.insertattail(5);
    ll2.insertattail(8);
    ll2.display();
    
    Linklist ll3;
    ll3.insertattail(3);
    ll3.insertattail(6);
    ll3.insertattail(9);
    ll3.display();
    
    
    vector<Node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);
    
    Linklist mergedll;
    mergedll.head=mergeklinklist(lists);
    mergedll.display();*/
    
    
    /*
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
        */
        
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
