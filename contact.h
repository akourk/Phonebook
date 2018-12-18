//Author        :   Alex Kourkoumelis
//Date          :   10/19/2017
//Name          :   Phonebook Application
//Description   :   reads phonebook.txt, stores each line
//                  (of format string_fname string_lname int_pnum)
//                  into an array of objects called "phonebook"
//                  then prompts for a short list of actions to be performed on the phonebook
//                      -search, by first, last, or full name
//                      -delete contact, then consolidates remaining contacts
//                      -add contact to the end of the list
//                      -count the number of contacts
//                      -read the phonebook

#ifndef ATTEMPT3_CONTACT_H
#define ATTEMPT3_CONTACT_H

#include <iostream>
using namespace std;

class contact{
private:
    string fname;
    string lname;
    int pnum;

public:
    contact(){}
    contact(string fname, string lname, int pnum){
        this->fname=fname;
        this->lname=lname;
        this->pnum=pnum;
    }
    const string &getFname() const {
        return fname;
    }

    void setFname(const string &fname) {
        contact::fname = fname;
    }

    const string &getLname() const {
        return lname;
    }

    void setLname(const string &lname) {
        contact::lname = lname;
    }

    int getPnum() const {
        return pnum;
    }

    void setPnum(int pnum) {
        contact::pnum = pnum;
    }

    // Friend function overloaded to print first name, last name and phone number.
    friend ostream& operator<<(ostream& os, contact& c){
        os << c.getFname() << " " << c.getLname() << " " << c.getPnum() << endl;
        return os;
    }
};


#endif //ATTEMPT3_CONTACT_H
