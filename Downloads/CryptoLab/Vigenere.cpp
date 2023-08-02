#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encryptVigenereCipher(string plaintext, string key) {
    string ciphertext = "";
    int keyLength = key.length();

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char c = plaintext[i];
        char k = key[i % keyLength];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encryptedChar = ((c - base + (toupper(k) - 'A')) % 26) + base;
            ciphertext += encryptedChar;
        } else {
            ciphertext += c; // If the character is not a letter, leave it unchanged.
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    getline(cin, key);

    string encryptedText = encryptVigenereCipher(plaintext, key);

    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
