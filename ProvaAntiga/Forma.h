#ifndef FORMA_H
#define FORMA_H

class FormaGeometrica{
    public:
        virtual double area() const = 0;
};

class Triangulo : public FormaGeometrica{
    private:
        double altura;
        double base;
    public:
        Triangulo(double base, double altura) : base(base), altura(altura){}

        double area() const override;
};

class Quadrado : public FormaGeometrica{
    private:
        double lado;
    
    public:
        Quadrado(double lado) : lado(lado){}

        double area() const override;
};

#endif