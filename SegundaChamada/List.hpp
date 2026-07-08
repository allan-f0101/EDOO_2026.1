#ifndef LIST_H
#define LIST_H

template<typename T>
class List{
protected:
    int size;

public:
    List() : size(0){}
    virtual ~List(){};

    virtual void insert(T item) = 0;
    virtual T remove() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual void move_start() = 0;
    virtual void move_end() = 0;
    virtual T get_value() = 0;
    int get_size() {return this->size;}

};

#endif