#include <iostream>

using namespace std;

template <typename E>
class BinaryTree{
private:
    struct Node{
        E data;
        Node* left;
        Node* right;
        Node(E d) : data(d), left(nullptr), right(nullptr) {}
    };  

    Node* root;

    void inOrder(Node* node){
        if(node == nullptr) return;
        inOrder(node -> left);
        cout << node -> data << " ";
        inOrder(node -> right);
    }

    void preOrder(Node* node){
        if(node==nullptr) return;
        cout << node -> data << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }

    void postOrder(Node* node){
        if(node==nullptr) return;
        postOrder(node -> left);
        postOrder(node -> right);
        cout << node -> data << " ";
    }

    int height(Node* node){
        if(node == nullptr) return 0;
        int left = height(node->left);
        int right = height(node->right);
        return 1 + (left > right ? left : right);
    }

    

public:
    BinaryTree() : 
};

int main(){

    return 0;
}