//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Mar 
//class with a resource

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict{
    const int SIZE = 20;
    class Contact{
        char m_name[SIZE];
        long long* m_phoneNum;
        int m_no;

    public:
        Contact();
        Contact(const Contact&);
        Contact& operator=(const Contact&);
        Contact& operator+=(long long);
        Contact(const char [], const long long [], int);
        ~Contact();
        bool isValid(long long) const;
        bool isEmpty() const;
        void display() const;
    };
}
#endif
