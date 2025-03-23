#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string pd, string uid, string pub)
        : title(t), publicationDate(pd), uniqueID(uid), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Checked Out: " << (isCheckedOut ? "Yes" : "No") << endl;
    }

    virtual void checkOut() {
        isCheckedOut = true;
    }

    virtual void returnItem() {
        isCheckedOut = false;
    }

    string getTitle() const {
        return title;
    }

    string getPublicationDate() const {
        return publicationDate;
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pd, string uid, string pub,
         string a, string isbn, int pages)
        : Media(t, pd, uid, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director;
    int duration;
    float rating;

public:
    DVD(string t, string pd, string uid, string pub,
        string d, int dur, float r)
        : Media(t, pd, uid, pub), director(d), duration(dur), rating(r) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pd, string uid, string pub,
       string art, int tracks, string g)
        : Media(t, pd, uid, pub), artist(art), numberOfTracks(tracks), genre(g) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
public:
    Magazine(string t, string pd, string uid, string pub)
        : Media(t, pd, uid, pub) {}
};

void searchMedia(const Media& m, string t) {
    if (m.getTitle() == t) {
        cout << "Media found by title:\n";
        m.displayInfo();
    }
}

void searchMedia(const Media& m, int year) {
    if (m.getPublicationDate().find(to_string(year)) != string::npos) {
        cout << "Media found by year:\n";
        m.displayInfo();
    }
}

int main() {
    Book b("C++ Programming", "2020", "B001", "TechPress", "Bjarne Stroustrup", "123456789", 350);
    DVD d("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD c("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop");

    cout << "\n--- Book Info ---\n";
    b.displayInfo();

    cout << "\n--- DVD Info ---\n";
    d.displayInfo();

    cout << "\n--- CD Info ---\n";
    c.displayInfo();

    cout << "\n--- Searching Media ---\n";
    searchMedia(b, "C++ Programming");
    searchMedia(d, 2010);

    return 0;
}
