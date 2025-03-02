#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node *root, int val){
    if(root == nullptr){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return  root;
}

bool search(Node *root, int key){
    if(root == nullptr) return false;
    if(root->data == key) return true;
    if(key<root->data) return search(root->left, key);
    else return search(root->right, key);
}

Node* findMin(Node* root){
    while(root->left != nullptr){
        root=root->left;
    }
    return root;
}

void inorder(Node *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* deleteNode(Node *root, int key){
    if(root == nullptr) return root;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        else if(root->left == nullptr){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Node *root = nullptr;
    root = insert(root,50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout<<(search(root, 100)?"Found" : "Not found")<<endl;

    cout<<findMin(root)->data<<endl;

    deleteNode(root, 50);
    inorder(root);
}
