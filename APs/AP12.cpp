#include <iostream>
#include <string>

using namespace std;

class BST{
private:
    struct Node{
        int data;
        Node* leftChild;
        Node* rightChild;

        Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr){}
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

    void preOrder(Node* current){
        if(current == nullptr){
            return;
        }

        cout << " " <<current->data;
        preOrder(current->leftChild);
        preOrder(current->rightChild);
    }

    void inOrder(Node* current){
        if(current == nullptr){
            return;
        }

        inOrder(current->leftChild);
        cout << " " << current->data;
        inOrder(current->rightChild);
    }   

    void postOrder(Node* current){
        if(current == nullptr){
            return;
        }

        postOrder(current->leftChild);
        postOrder(current->rightChild);
        cout << " " <<current->data;
    }

    
public:
    BST() : root(nullptr){}
    
    void insert(int key){
        root = insertHealper(root, key);
    }

    void printPreOrder(){
        return preOrder(root);
    }

    void printInOrder(){
        return inOrder(root);
    }

    void printPostOrder(){
        return postOrder(root);
    }

};

int main(){

    int num;

    cin >> num;

    BST tree;
    for(int i = 0; i < num; i++){
        string operation;
        cin >> operation;

        if(operation == "insert"){
            int valor;
            cin >> valor;
            
            tree.insert(valor);
        }
        else if(operation == "pre"){
            tree.printPreOrder();
            cout << "\n";
        }

        else if(operation == "in"){
            tree.printInOrder();
            cout << "\n";
        }
        else if(operation == "post"){
            tree.printPostOrder();
            cout << "\n";
        }
    }

    return 0;
}