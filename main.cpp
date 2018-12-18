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


#include <iostream>
#include <fstream>  //to read the file
#include "contact.h"
using namespace std;

int i = 0;  //to keep track of which space we are at in the array

int main() {    //main function
    string filename;
    cout << "Hello!" << endl;
    //name of the .txt file or location
    filename = "phonebook.txt";
    ifstream file;
    file.open(filename);
    string fname;
    string lname;
    int pnum;

    //creating an array of objects
    //* makes it go in stack, not heap, which is important for 200,000 objects
    contact *phonebook= new contact[200000];

    //while not at the end of the file
    while (!file.eof()) {
        file >> fname >> lname >> pnum;
        phonebook[i].setFname(fname);
        phonebook[i].setLname(lname);
        phonebook[i].setPnum(pnum);
        i++;
    }

    //confirmation that the .txt file was loaded into the array
    cout << "Successfully loaded " << i << " Contacts." << endl;

    //creating variables to later store and use temporarily
    int decider = 0;
    string tempFname;
    string tempLname;
    int tempNum;

    //while not 8, will continue prompting
    while (decider != 8) {
        cout << "\nWhat would you like to do next? " << endl;
        cout << "1 to search by name." << endl;
        cout << "2 to search by first name." << endl;
        cout << "3 to search by last name." << endl;
        cout << "4 to enter new name." << endl;
        cout << "5 to delete a name." << endl;
        cout << "6 to read the list." << endl;
        cout << "7 to count the lines." << endl;
        cout << "8 to exit." << endl;
        cin >> decider;

        switch (decider) {
            //search by full name, converts everything to uppercase
            case 1:
                cout << "You entered 1. Search by name." << endl;
                cout << "What first name would you like to search for? ";
                cin >> tempFname;

                //converts to uppercase
                transform(tempFname.begin(), tempFname.end(), tempFname.begin(), ::toupper);

                cout << "\nWhat last name would you like to search for? ";
                cin >> tempLname;
                transform(tempLname.begin(), tempLname.end(), tempLname.begin(), ::toupper);

                cout << "All results with name matching \"" << tempFname;
                cout << " " << tempLname;
                cout << "\": " << endl;

                //compares firstname and lastname while cycling through array
                for (int j = 0; j < i; j++) {
                    if ((phonebook[j].getFname().compare(tempFname) == 0) &&
                        (phonebook[j].getLname().compare(tempLname) == 0)) {
                        cout << phonebook[j];
                    }
                }
                break;

                //search by first name only
            case 2:
                cout << "You entered 2. Search by first name." << endl;
                cout << "What name would you like to search for? ";
                cin >> tempFname;
                transform(tempFname.begin(), tempFname.end(), tempFname.begin(), ::toupper);

                cout << "All results with first name matching \"" << tempFname;
                cout << "\": " << endl;
                cout << tempFname << endl;

                //compares first name while cycling through the array
                for (int j = 0; j < i; j++) {
                    if (phonebook[j].getFname().compare(tempFname) == 0) {
                        cout << phonebook[j];
                    }
                }
                break;

            //search by last name only
            case 3:
                cout << "You entered 3. Search by last name." << endl;
                cout << "What name would you like to search for? ";
                cin >> tempLname;
                transform(tempLname.begin(), tempLname.end(), tempLname.begin(), ::toupper);

                cout << "All results with first name matching \"" << tempLname;
                cout << "\": " << endl;

                //compares last name while cycling through the array
                for (int j = 0; j < i; j++) {
                    if (phonebook[j].getLname() == tempLname) {
                        cout << phonebook[j];
                    }
                }
                break;

                //search by full name
            case 4:
                cout << "You entered 4. Enter a new name." << endl;
                cout << "What first name would you like to add to your phonebook? ";
                cin >> tempFname;
                transform(tempFname.begin(), tempFname.end(), tempFname.begin(), ::toupper);
                cout << "\nWhat last name would you like to add to your phonebook? ";
                cin >> tempLname;
                transform(tempLname.begin(), tempLname.end(), tempLname.begin(), ::toupper);
                cout << "\nAnd what is the phone number? ";
                cin >> tempNum;
                phonebook[i].setFname(tempFname);
                phonebook[i].setLname(tempLname);
                phonebook[i].setPnum(tempNum);
                for (int j = 0; j <= i; j++) {
                    cout << phonebook[j];
                }
                i++;

                break;

                //deletes a name and moves everything past that point up
            case 5:
                cout << "You entered 5. Delete a name." << endl;
                cout << "What first name would you like to delete? ";
                cin >> tempFname;
                transform(tempFname.begin(), tempFname.end(), tempFname.begin(), ::toupper);
                cout << "What last name would you like to delete? ";
                cin >> tempLname;
                transform(tempLname.begin(), tempLname.end(), tempLname.begin(), ::toupper);
                cout << "All results with name matching \"" << tempFname;
                cout << " " << tempLname << "\": " << endl;
                for (int j = 0; j < i; j++) {
                    if ((phonebook[j].getFname().compare(tempFname) == 0) &&
                        (phonebook[j].getLname().compare(tempLname) == 0)) {
                        cout << phonebook[j];

                        //replaces open spot in array with next object data
                        for (int k = j; k < i; k++) {
                            tempFname = phonebook[k + 1].getFname();
                            tempLname = phonebook[k + 1].getLname();
                            tempNum = phonebook[k + 1].getPnum();
                            phonebook[k].setFname(tempFname);
                            phonebook[k].setLname(tempLname);
                            phonebook[k].setPnum(tempNum);
                        }
                    }
                }
                i--;
                for (int j = 0; j < i; j++) {
                    cout << phonebook[j];
                }
                break;

                //reads all the phonebook objects
            case 6:
                cout << "You entered 6. Read the list." << endl;
                for (int j = 0; j < i; j++) {
                    cout << phonebook[j];
                }
                break;

                //counts the number of lines in the phonebook
            case 7:
                cout << "Count the lines in the phonebook." << endl;
                cout << "There are " << i << " lines in the phonebook." << endl;
                break;

                //exits the while loop and switch statement
            case 8:
                cout << "Exiting application." << endl;
                break;

                //default- will prompt to re-enter a decision if program doesn't understand
            default:
                cout << "I'm sorry, I didn't understand that." << endl;
                cout << "Try selecting options 1-8." << endl;
        }
    }
    return 0;
}