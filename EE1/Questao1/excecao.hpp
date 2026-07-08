#ifndef EXCECAO_H
#define EXCECAO_H

#include <iostream>
#include <exception>
#include <string>

class IndexOutOfBounds : public std::exception{
private:
    std::string error_msg;

public:
    IndexOutOfBounds(int index) {
        error_msg = "IndexOutOfBounds: " + std::to_string(index);
    }

    std::string get_errormsg() const{
        return error_msg;
    }
};

#endif