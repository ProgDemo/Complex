#include "Complex.h"

void Complex::add(const Complex& rhs) {
    this->re += rhs.re;
    this->im += rhs.im;
}

//Operators

Complex& Complex::operator +(const Complex& rhs) {
    this->add(rhs);

    return (*this);
}

Complex& Complex::operator =(const Complex& rhs) {
    this->re = rhs.re;
    this->im = rhs.im;

    return (*this);
}

bool Complex::operator ==(const Complex& rhs) {
    return this->re == rhs.re && this->im == rhs.im;
}

std::ostream& operator <<(std::ostream& output, const Complex& out) {
    return output << out.re << (out.im < 0 ? "" : "+") << out.im << "i";
}
