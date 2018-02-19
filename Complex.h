#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <ostream>

class Complex {
    private:
        double re;
        double im;

    public:
        Complex(double re = 0, double im = 0): re(re), im(im) {}
        double getRe() const {return this->re; }
        double getIm() const {return this->im; }
        void setRe(double re) {(*this).re = re; }
        void setIm(double im) {(*this).im = im; }
        void add(const Complex& rhs);

        Complex& operator +(const Complex& rhs);
        Complex& operator =(const Complex& rhs);
        bool operator ==(const Complex &rhs);
        friend std::ostream& operator <<(std::ostream& output, const Complex& out);
};

/*inline std::ostream& operator <<(std::ostream& output, const Complex& out) {
    return output << out.re << (out.im < 0 ? "+" : "-") << out.im;
}*/

#endif // COMPLEX_H_INCLUDED
