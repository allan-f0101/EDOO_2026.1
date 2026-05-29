#include <iostream>

using namespace std;

template<typename T, typename U>
class Par{
    private:
        T primeiro;
        U segundo;
    public:
        Par(T primeiro, U segundo);

        T getPrimeiro() const;
        U getSegundo() const;

        void setPrimeiro(T valor);
        void setSegundo(U valor);

        Par<U,T> invertido() const;

        operator<<
};

int main(){
    Par <int, double> p(10, 34.5);
    return 0;
}