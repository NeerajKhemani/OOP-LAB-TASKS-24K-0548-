#ifndef BOOK
#define BOOK

class Book{
     private:
     string title;
     string author;
     string ISBN;
     public:
     Book(string title,string author,string ISBN) {}

     string getTitle();

     string getAuthor();
     
     string getISBN();

};

#endif