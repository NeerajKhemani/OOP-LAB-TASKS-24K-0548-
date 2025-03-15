#include <iostream>
#include <string>
using namespace std;

class Message{
    string text;

    public:
    Message(string t) {
        text = t;
    }
    virtual string toString() const {
        return text;
    }

    string getText() const {
        return text;
    }

    void setText(string text){
        this->text = text;
    }
};

class SMS : public Message{
    string recipientContactNo;

    public:
    SMS(string t , string contact) : Message(t) {
        recipientContactNo = contact;
    }

    void setContact(long Contact){ recipientContactNo = Contact;}
    string getContact(){ return recipientContactNo;}

    string toString() const override {
        return "To: " + recipientContactNo + " | Message: " + getText();
    }

};

class Email : public Message{
    string sender;
    string receiver;
    string subject;

    public:
    Email(string t,string s,string r, string sub) : Message(t) {
        sender = s;
        receiver = r;
        subject = sub;
    }

    void setSender(string sender){ this->sender = sender;}
    string getSender(){ return sender;}

    void setReceiver(string receiver){ this->receiver = receiver;}
    string getReceiver(){ return receiver;}

    void setSubject(string subject){ this->subject = subject;}
    string getSubject(){ return subject;}

    string toString() const override {
        return "From: " + sender + " | To: " + receiver +
               " | Subject: " + subject + " | Message: " + getText();
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    string text = messageObject.getText();
    int textLen = text.length();
    int keywordLen = keyword.length();

    for (int i = 0; i <= textLen - keywordLen; i++) {
        bool found = true;
        for (int j = 0; j < keywordLen; j++) {
            if (text[i + j] != keyword[j]) {
                found = false;
                break;
            }
        }
        if (found)
            return true;
    }
    return false;
}

string EncodeMessage(const string& original) {
    string encoded = "";
    for (int i = 0; i < original.length(); i++) {
        char ch = original[i];
        if ((ch >= 'A' && ch <= 'Y') || (ch >= 'a' && ch <= 'y')) {
            encoded += ch + 1;
        } else if (ch == 'Z') {
            encoded += 'A';
        } else if (ch == 'z') {
            encoded += 'a';
        } else {
            encoded += ch; 
        }
    }
    return encoded;
}

int main() {
    SMS sms("Hello, how are you?", "123-456-7890");
    cout << "SMS:\n" << sms.toString() << endl;

    Email email("Project deadline is Friday.", "teacher@nu.edu.pk", "student@nu.edu.pk", "Project Update");
    cout << "\nEmail:\n" << email.toString() << endl;

    string keyword = "Friday";
    cout << "\nKeyword Search for '" << keyword << "' in Email: "
         << (ContainsKeyword(email, keyword) ? "Found" : "Not Found") << endl;

    string originalText = "This is Java";
    string encoded = EncodeMessage(originalText);
    cout << "\nOriginal Message: " << originalText << endl;
    cout << "Encoded Message: " << encoded << endl;

    return 0;
}
