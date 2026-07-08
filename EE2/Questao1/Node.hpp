#ifndef NODE_H
#define NODE_H

class Node{
public:
    Node* next;
    int valor;

    Node(int val) : valor(val), next(nullptr){}
};

#endif