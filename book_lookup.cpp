#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>
//#include "booklist.txt"
using namespace std;
//includes booklist.txt as a line of code
#include "booklist.txt"
//Class to store book details
class Book
{
    private:
        string title, author, publisher, publication_date, category;

    public:
        Book(string, string, string, string, string);
        string getAuthor();
        string findcategory();
        string findpublicationyear();
        void paste();
};

//Class Functions Definitions
//constructor to initialize the member variables
Book::Book(string t,string a,string p,string pd,string c)
{
    title = t;
    author = a;
    publisher = p;
    publication_date = pd;
    category = c;
}

string Book::findcategory()
{
    return category;
}

string Book::getAuthor()
{
    return author;
}

string Book::findpublicationyear()
{
    string year = "";
    int i, yearlength;
    yearlength = publication_date.length();
    //finding year by finding the last 4 characters from the publication date
    for (i = yearlength - 4; i < yearlength; i++)
    {
        year += publication_date[i];
    }
    return year;
}
//shows the relevent info
void Book::paste()
{
    cout << title << "--" << author << "--" << publisher << "--" << publication_date << "--" << 
    category << endl;
}



void menu()
{
    cout << "\n Enter your Choice: " << endl;
    cout << "\n1) Display all books in a year range" << endl
         << "2) Search for an author" << endl
         << "3) Display all books for a category" << endl
         << "\n Enter Q or q to exit" << endl;
}


void displayYearRange(vector<Book> data)
{
    string year;
    string startyear, endyear;
    int found = 0;
    //user enters years for program to search between3
    cout << "\n Enter the Starting year (yyyy): ";
    cin >> startyear;
    cout << "Enter the end year: ";
    cin >> endyear;
    //check each record
    for (int i = 0;i < data.size(); i++)
    {
        year = data[i].findpublicationyear();
        //if a match is found while looping
        if (year >= startyear && year <= endyear)
        {
            //display findings
            data[i].paste();
            found = 1;
        }

    }
    if (found == 0)
    {
        cout << "No books have been found between those years" << endl;
    }

}

void searchAuthor (vector<Book> data)
{
    string author, dataauthor;
    int found = 0;
    cout << "\n Enter Authors Name: ";
    getline (cin, author);
    //inputting again
    getline (cin, author);

    //converting input to lowercase
    transform (author.begin(), author.end(), author.begin(), :: tolower);
    //loop checking through each record
    for (int i = 0; i < data.size(); i++)
    {
        dataauthor = data[i].getAuthor();
        //transforming to lowercase
        transform(dataauthor.begin(), dataauthor.end(), dataauthor.begin(), ::tolower);
        //if a match is found, ouput data
        if (author == dataauthor)
        {
            data[i].paste();
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "Author was not found within the file! " << endl;
    }
}

void displayAllCategory(vector<Book> data)
{
    string categoryinput, categorydata;
    int found = 0;
    cout << "\nEnter a Category to be searched: ";
    getline(cin, categoryinput);
    //input again, the first one take's '\n' after input
    getline(cin, categoryinput);

    //transform input to lowercase
    transform(categoryinput.begin(),categoryinput.end(),categoryinput.begin(), ::tolower);

    //check each record
    for (int i = 0; i < data.size(); i++)
    {
        categorydata = data[i].findcategory();
        //transofrming data to lowercase
        transform(categorydata.begin(),categorydata.end(),categorydata.begin(), ::tolower);
        //if the data matches the input, paste the data
        if(categoryinput == categorydata)
        {
            data[i].paste();
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "No book was found in that category!" << endl;
    }
}

int main()
{
//initialize the book vector
    vector<Book> Bookdata;
    //putting number of books in an array named data
    int numberofBooks = sizeof(data)/sizeof(data[0]);
    char menuinput;
    //inputting records of data array into Bookdata vector
    for (int i = 0;i < numberofBooks; i++)
    {
        Book Books(data[i][0],data[i][1],data[i][2],data[i][3],data[i][4]);
        Bookdata.push_back(Books);
    }
    menu();
    cin >> menuinput;
    while (menuinput != 'Q' && menuinput != 'q')
    {
        switch(menuinput)
        {
            case '1':
                displayYearRange(Bookdata);
                break;
            case '2':
                searchAuthor(Bookdata);
                break;
            case '3':
                displayAllCategory(Bookdata);
                break;
            default:
                cout << "Invalid Choice please try again " << endl;   
        }
        menu();
        cin >> menuinput;
    }
    return 0;
}
