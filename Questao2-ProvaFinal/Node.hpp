#ifndef NODE_H
#define NODE_H

template<typename E>
class Node{
private:
    Node<E>* next;
    E data;

public:
    Node(E v, Node<E>* n);
    E get_value();
    Node<E>* get_next();

};  

template<typename E>
Node<E>::Node(E v, Node<E>* n){
    this->data = v;
    this->next = n;
}

template<typename E>
E Node<E>::get_value(){
    return this->data;
}

template<typename E>
Node<E>* Node<E>::get_next(){
    return this->next;
}

#endif