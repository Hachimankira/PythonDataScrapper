#include <iostream>
#include <string>

using namespace std;

string encryptCaesarCipher(string plaintext, int key) {
    string ciphertext = "";

    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encryptedChar = ((c - base + key) % 26) + base;
            ciphertext += encryptedChar;
        } else {
            ciphertext += c; // If the character is not a letter, leave it unchanged.
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    int key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key (an integer): ";
    cin >> key;

    string encryptedText = encryptCaesarCipher(plaintext, key);

    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
