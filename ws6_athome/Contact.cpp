//Name: (Jessie) Gayeon Ko
//Section: OPP244SGG
//Student ID: 040704124
//Email: gko4@myseneca.ca
//Date: Mar
//class with a resource


#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict{
    Contact::Contact(){
        m_name[0] = '\0';
        m_phoneNum = nullptr;
        m_no = 0;
    }
    
    Contact::Contact(const Contact& src){
        m_phoneNum = nullptr;
        *this = src; // call assignment operator
    }
    
    Contact& Contact::operator=(const Contact& src){
        if(this != &src){ // check self assignment
            // name
            strncpy(m_name, src.m_name, SIZE);
            m_name[SIZE - 1] = '\0';
            
            // number
            m_no = src.m_no;
            
            delete [] m_phoneNum; // deallocate previous dynamic memory
            // phonenumber
            if(src.m_phoneNum != nullptr){
                m_phoneNum = new long long[m_no];
                for(int i=0; i<m_no; i++)
                    m_phoneNum[i] = src.m_phoneNum[i];
            }else
                m_phoneNum = nullptr;
        }
        return *this;
    }
    
    Contact& Contact::operator+=(long long newPhoneNum){
        if(m_name[0] != '\0' && isValid(newPhoneNum)){
            long long* temp = new long long[m_no + 1];
            int i;
            for(i=0; i<m_no; i++){
                temp[i] = m_phoneNum[i];
            }
            m_no++;
            temp[i] = newPhoneNum;
            delete [] m_phoneNum;
            m_phoneNum = temp;
        }
        return *this;
    }

    Contact::Contact(const char name[], const long long phoneNum[], int no){
        int count =0, x=0;

        if(name != nullptr && name[0] != '\0') {
            strncpy(m_name, name, SIZE);
            m_name[SIZE - 1] = '\0';
        }else
            m_name[0] = '\0';

        //number of phonenumber
        if (no > 0) {
            for (int i = 0; i < no; i++) {
                if (isValid(phoneNum[i]))
                    count++;
            }
            m_no = count; // number of phone number
        }else
            m_no = 0;
        
        //phonenumber
        m_phoneNum = new long long[count];
        if (phoneNum != nullptr) {
            for (int i = 0; i < no; i++) {
                if (isValid(phoneNum[i])) {
                    m_phoneNum[x] = phoneNum[i];
                    x++;
                }
            }
        } else
            m_phoneNum = nullptr;
    }
    
    Contact::~Contact(){
        delete [] m_phoneNum;
    }

    //check phone number is valid
    bool Contact::isValid(long long phoneNum) const{
        bool result = false;
        if(phoneNum >11111111111 && phoneNum < 1000000000000)
            result = true;
        return result;

    }

    bool Contact::isEmpty() const{
        bool result = false;
        if(m_name[0] == '\0' && m_phoneNum == nullptr && m_no ==0){
            result = true;
        }
        return result;
    }

    void Contact::display() const{
        long long country, area, num1, num2;
        if(isEmpty())
            cout << "Empty contact!" << endl;
        else{
            cout << m_name << endl;
            for(int i=0; i<m_no; i++) {
                country = m_phoneNum[i] / 10000000000; // ten zero
                area = (m_phoneNum[i] % 10000000000) / 10000000;
                num1 = (m_phoneNum[i] % 10000000) / 10000;
                num2 = (m_phoneNum[i] % 10000000) % 10000;
                cout << "(+" << country << ") " << area << " " << num1 << "-";
                cout.width(4);
                cout.fill('0');
                cout << num2 << endl;
            }
        }
    }
}
