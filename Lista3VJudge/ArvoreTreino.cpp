#include <iostream>

//==============
// CLASSE NODE   
//==============
template<typename T>
class Node{
private:
    Node<T>* left;
    Node<T>* right;
    T value;

public:
    Node(T val, Node<T>* l = nullptr, Node<T>* r = nullptr);
    
    T get_value();
    Node<T>* get_left();
    Node<T>* get_right();  

    void set_value(T val){this->value = val;}
    void set_left(Node<T>* l);
    void set_right(Node<T>* r);
};

template<typename T>
Node<T>::Node(T val, Node<T>* l, Node<T>* r){
    this->value = val;
    this->left = l;
    this->right = r;
}

template<typename T>
Node<T>* Node<T>::get_left(){
    return this->left;
}

template<typename T>
Node<T>* Node<T>::get_right(){
    return this->right;
}

template<typename T>
void Node<T>::set_left(Node<T>* l){
    this->left = l;
}

template<typename T>
void Node<T>::set_right(Node<T>* r){
    this->right = r;
}

//===========================
//CLASSE COM MÉTODOS DA BST
//===========================
template<typename T>
class BSTmethods{
public:
    virtual ~BSTmethods(){}
    virtual Node<T>* insertHealper(Node<T>* current, T item) = 0;
    virtual Node<T>* removeHealper(Node<T>* current, T item) = 0;
    virtual Node<T>* searchHealper(Node<T>* current, T item) = 0;
    virtual Node<T>* getMin(Node<T>* current) = 0;
    virtual int length() = 0;
    virtual void clear() = 0;

};

//============
//CLASSE BST
//============
template<typename T>
class BST : public BSTmethods<T>{
private:
    Node<T>* root;
    int size;

    void clearHealper(Node<T>* current){
        if(current != nullptr){
            clearHealper(current->get_left());
            clearHealper(current->get_right());
            delete current;
        }
    }

public:
    BST() : root(nullptr), size(0){}
    ~BST(){
        clear();
    }

    Node<T>* insertHealper(Node<T>* current,T item) override{
        if(current == nullptr){
            this->size++;
            return new Node<T>(item);
        }

        if(item < current->get_value()){
            current->set_left(insertHealper(current->get_left, item));
        }
        else{
            current->set_right(insertHealper(current->get_right, item));
        }   
        
        return current;
    }

    Node<T>* getMin(Node<T>* current) override{
        if(current->get_left() == nullptr){
            return current;
        }
        return getMin(current->get_left());
    }

    Node<T>* removeHealper(Node<T>* current, T item) override{
        if(current == nullptr){
            return nullptr;
        }

        if(item < current->get_value()){
            current->set_left(removeHealper(current->set_left(), item));
        }
        else if(item > current->get_value()){
            current->set_right(removeHealper(current->set_right(), item));
        }
        else{
            size--;
            if(current->get_left() == nullptr){
                Node* temp = current->get_right();
                delete current;
                return temp;
            }

            else if(current->get_right() == nullptr){
                Node* temp = current->get_left();
                delete current;
                return temp;
            }

            else{
                Node* temp = getMin(current->get_right());
                current->value = temp->value;
                current->right = removeHealper(current->right, temp->data);
            }
        }
        return current;
    }

    Node<T>* searchHealper(Node<T>* current, T item) override{
        if(current == nullptr || current->get_value() == item){
            return current;
        }

        if(item < current->get_value()){
            return searchHealper(current->get_left(), item);
        }

        return searchHealper(current->get_right(), item);
    }

    int length() override{
        return this->size;
    }

    void clear() override{
        clearHealper(this->root);
        this->root = nullptr;
        this->size = 0;
    }

};