//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Feb 20 2018

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
// TODO: define the Fraction class
    class Fraction {
        // TODO: declare instance variables
        int m_num;
        int m_denom;
        // TODO: declare private member functions
        int max() const;
        int min() const;
        void reduce();
        int gcd() const;

    public:
        // TODO: declare public member functions
        Fraction();
        Fraction(int num, int denom);
        bool isEmpty() const;
        void display() const;
        // TODO: declare the + operator overload
        Fraction operator+(const Fraction& rhs) const;
    };
}
#endif