// Why make a function constant?
    /* 
	 The const keyword at the end of the function ensures that the method 
     does not modify any member variables of the object. This is important 
     for functions that should only read the state of the object without 
     changing it. It helps guarantee the integrity of the object and makes 
     the code easier to reason about. Additionally, it enables compiler 
     optimizations and ensures const-correctness.          
	*/
    
#include <iostream>
#include <string>

using namespace std;

class ValidateString {
    string Str;

public:
    ValidateString(const string& str) : Str(str) {}

    
    bool isValid() const {
    for (size_t i = 0 ; i < Str.size() ; ++i) {
        char c = Str[i];
        if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
            return false;
        }
    }
    return true;
   }
  
};

int main() {
    ValidateString str1("HelloWorld");
    ValidateString str2("Hello123");
    ValidateString str3("!Hello");
    ValidateString str4("ValidString");

    cout << "Is 'HelloWorld' valid? " << (str1.isValid() ? "Yes" : "No") << endl;
    cout << "Is 'Hello123' valid? " << (str2.isValid() ? "Yes" : "No") << endl;
    cout << "Is '!Hello' valid? " << (str3.isValid() ? "Yes" : "No") << endl;
    cout << "Is 'ValidString' valid? " << (str4.isValid() ? "Yes" : "No") << endl;

    return 0;
}

