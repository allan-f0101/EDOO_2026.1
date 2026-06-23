#include <iostream>
#include <string>

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

    Node* searchHealper(Node* current, int data){
        Node* current = root;

        while(current != nullptr && current->data != data){

            if(current->data > data){
                current = current->leftChild;
            }
            else{
                current = current->rightChild;
            }
        }

        return current;
    }

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

    Node* removeHealper(Node* current, int key){

    }

public:
    BST() : root(nullptr) {}

    bool search(int data){
        return (searchHealper(root, data) != nullptr);
    }

    void insert(int data){
        Node* tempNode = new Node;
    }

};

int main(){
    return 0;
}

