#include <iostream>

using namespace std;

class BST{
private:
    struct Node{
        int data;
        Node *leftChild;
        Node *rightChild;

        Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
    };  

    Node* root;

    Node* insertHealper(Node* current, int key){
        if(current == nullptr){
            return new Node(key);
        }

        if(key < current->data){
            current->leftChild = insertHealper(current->leftChild, key);
        }
        else{
            current->rightChild = insertHealper(current->rightChild, key);
        }
        return current;
    }

    void PreOrderTraversal(Node* current){
        if(current == nullptr){
            return;
        }

        cout << " " << current->data;
        PreOrderTraversal(current->leftChild);
        PreOrderTraversal(current->rightChild);
    }

    void inOrderTraversal(Node* current){
        if(current == nullptr){
            return;
        }
        
        inOrderTraversal(current->leftChild);
        cout << " " << current->data;
        inOrderTraversal(current->rightChild);
    }

    void PostOrderTraversal(Node* current){
        if(current == nullptr){
            return;
        }

        PostOrderTraversal(current->leftChild);
        PostOrderTraversal(current->rightChild);
        cout << " " << current->data;
    }

public:
    BST() : root(nullptr) {}

    void insert(int key){
        root = insertHealper(root, key);
    }

    void print(){
        cout << "Pre order : ";
        PreOrderTraversal(root);
        cout << "\n";

        cout << "In order  : ";
        inOrderTraversal(root);
        cout << "\n";

        cout << "Post order: ";
        PostOrderTraversal(root);
        cout << "\n";
    }
};

int main(){
    
    int num;
    cin >> num;
        
    BST tree;

    for(int i = 0; i < num; i++){
        int valor;
        cin >> valor;
        tree.insert(valor);
    }

    tree.print();

    return 0;
}