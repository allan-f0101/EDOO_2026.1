#ifndef LISTAS_HPP
#define LISTAS_HPP

#include <iostream>

template <typename Elem>
class List{
private:
    void operator = (const List&){}

    List(const List&){}

public:
    List(){}

    virtual ~List(){}

    virtual void clear() = 0;

    virtual bool insert(const Elem&) = 0;

    virtual bool append(const Elem&) = 0;

    virtual Elem remove() = 0;

    virtual void movetoStart() = 0;

    virtual void movetoEnd() = 0;

    virtual void prev() = 0;

    virtual void next() = 0;

    virtual int leftLength() const = 0;
    virtual int rightLength() const = 0;

    virtual void movetoPos(int pos) = 0;

    virtual const Elem& getValue() const = 0;
};

#endif
//Listas: lista ligada ou lista com array
//Fila ou pilha: listas ligadas