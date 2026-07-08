#ifndef NODE_H
#define NODE_H

template<class T>
class Node{
private:
    T value;
    Node* next;

public:
    Node(Node* n);
    Node(T v, Node* n);
    T get_value();
    Node* get_next();
    void set_next(Node* n);

};

template<typename T>
Node<T>::Node(Node<T>* n){
    this->next = n;
}

template<typename T>
Node<T>::Node(T v, Node<T>* n){
    this->next = n;
    this->value = v;
}

template<typename T>
T Node<T>::get_value(){
    return this->value;
}

template<typename T>
Node<T>* Node<T>::get_next(){
    return this->next;
}

template<typename T>
void Node<T>::set_next(Node* n){
    this->next = n;
}

#endif