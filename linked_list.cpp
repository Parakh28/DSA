#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void insertathead(Node* &head, int val) {
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertatend(Node*& head, int val) {

    Node* new_node = new Node(val);
    Node* temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
     
}


void insertatpos(Node* &head,int val,int pos){

    Node* new_node= new Node(val);
    Node* temp=head;
    int current_pos=0;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void updateatpos(Node* &head,int val,int pos){
    Node* temp=head;
    int curr=0;

    while(curr!=pos){
        temp=temp->next;
        curr++;
    }
    temp->val=val;
}

void deleteathead(Node* &head){
    Node* temp=head;
    head=head->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    insertathead(head, 2);
    display(head);
    insertathead(head, 1);
    display(head);
    insertatend(head,3);
    display(head);

    insertatpos(head,4,3);
        display(head);

    updateatpos(head,4,2);
    display(head);

    deleteathead(head);
    display(head);
    return 0;
}
