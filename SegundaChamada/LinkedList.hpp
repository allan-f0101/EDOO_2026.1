#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
#include "List.hpp"

class AccessException{
private:
    std::string message;

public:
    AccessException(const std::string& s) : message(s){}
    const std::string&get_message(){return this->message;}
};

template<typename T>
class LinkedList : public List<T>{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* curr;

public:
    LinkedList();
    ~LinkedList();

    void insert(T item) override;
    T remove() override;
    void prev() override;
    void next() override;
    void move_start() override;
    void move_end() override;
    T get_value() override;

};

template<typename T>
LinkedList<T>::LinkedList(){
    this->head = this->tail = this->curr = new Node<T>(nullptr);
    this->size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    this->curr = this->head;
    while(this->size != 0){
        this->remove();
    }
}

template<typename T>
void LinkedList<T>::insert(T item){
    this->curr -> set_next(new Node<T>(item, this->curr->get_next()));
    if(this->tail == this->curr){
        this->tail = this->curr->get_next();
    }
    this->size++;
}

template<typename T>
T LinkedList<T>::remove(){
    if(this->curr->get_next() == nullptr){
        throw AccessException("Error!");
    }
    else{
        T it = this->curr->get_next()->get_value();
        if(this->tail == this->curr->get_next()){
            this->tail = this->curr;
        }

        Node<T>* temp = this->curr->get_next();
        this->curr->set_next(this->curr->get_next()->get_next());
        this->size--;
        delete temp;
        return it;
    }
}

template<typename T>
void LinkedList<T>::prev(){
    if(this->curr != this->head){
        Node<T>* temp = this->head;

        while(temp->get_next() != this->curr){
            temp = temp->get_next();
        }
        this->curr = temp;  
    }
}

template<typename T>
void LinkedList<T>::next(){
    if(this->curr != this->tail){
        this->curr = this->curr->get_next();
    }
}

template<typename T>
void LinkedList<T>::move_start(){
    this->curr = this->head;
}

template<typename T>
void LinkedList<T>::move_end(){
    this->curr = this->tail;
}

template<typename T>
T LinkedList<T>::get_value(){
    if(this->curr != this->tail){
        return this->curr->get_next()->get_value();
    }
    else{
        throw AccessException("There is no element after the cursor!");
    }
}
#endif