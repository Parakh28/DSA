#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

Node* buildtree(Node* root) {
    cout << "Enter data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter the Left element of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter the Right Element of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->val << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void buildfromlevelorder(Node* &root){
    queue<Node*> q;
    cout<<"Enter the data for root : "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        cout<<"Enter left node for : "<<temp->val<<endl;
        int leftdata;
        cin>>leftdata;
        
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }
        
        cout<<"Enter right node for : "<<temp->val<<endl;
        int rightdata;
        cin>>rightdata;
        
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
        
    }
    
}



int main() {
    Node* root = NULL;
    buildfromlevelorder(root);
    levelordertraversal(root);
    /* 1 3 5 7 11 -1 -1 -1 -1 -1 -1 -1
    root = buildtree(root);
    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;*/

    return 0;
}
