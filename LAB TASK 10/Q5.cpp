#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream File("data.txt");
    if (!File) {
        cerr << "Failed to create file." << endl;
        return 1;
    }
    File << "AI is the future. AI will transform the world. Embrace AI now.";
    File.close();

    string searchWord, replacementWord;
    cout << "Enter the word to search: ";
    cin >> searchWord;
    cout << "Enter the replacement word: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word is too long. Exiting." << endl;
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string word;
    streampos pos;
    bool found = false; 
    while (file >> word) {
        if (word.find(searchWord) != string::npos) {
            pos = file.tellg();
            pos -= word.length();
            file.seekp(pos);

            file << replacementWord;
            if (replacementWord.length() < searchWord.length()) {
                for (size_t i = 0; i < searchWord.length() - replacementWord.length(); ++i) {
                    file.put(' ');
                }
            }
            file.seekg(pos + (streamoff)searchWord.length());
            found = true; 
        }
    }

    if (!found) {
        cout << "\nWord not found in the file.\n";
    } else {
        file.clear();
        file.seekg(0);
        string line;
        cout << "\nUpdated file content:\n";
        while (getline(file, line)) {
            cout << line << endl;
    }
}
    file.close();
    return 0;
}
