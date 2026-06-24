#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BST{
private:
    struct Node{
        char data;
        Node* leftChild;
        Node* rightChild;

        Node(char val) : data(val), leftChild(nullptr), rightChild(nullptr){}
    };

    Node* root;

    Node* insertHealper(Node* current, char key){
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

        cout << current->data;
        preOrder(current->leftChild);
        preOrder(current->rightChild);
    }

public:
    BST() : root(nullptr) {}

    void insert(char key){
        root = insertHealper(root, key);
    }

    void printPreOrder(){
        preOrder(root);
    }
};

int main(){
    
    vector<string> raws;

    while(true){
        string raw;
        cin >> raw;

        if(raw == "*" || raw == "$"){

            BST tree;

            for(int i = raws.size() - 1; i >= 0 ; i--){
                string palavraAtual = raws[i];
                for(char letra : palavraAtual){
                    tree.insert(letra);
                }
            }

            tree.printPreOrder();
            cout << "\n";

            raws.clear();

            if(raw == "$"){
                break;
            }
        }
        else{
            raws.push_back(raw);
        }
    }

    for(string raw: raws){
        cout << raw;
    }

    return 0;
}