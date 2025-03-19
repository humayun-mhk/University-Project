#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the text
string encrypt(const string& text, int shift) {
    string encrypted = "";
    for (size_t i = 0; i < text.length(); i++) { // Traditional loop
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted += char((c - base + shift) % 26 + base);
        } else {
            encrypted += c; // Non-alphabetic characters remain unchanged
        }
    }
    return encrypted;
}

// Function to decrypt the text
string decrypt(const string& text, int shift) {
    string decrypted = "";
    for (size_t i = 0; i < text.length(); i++) { // Traditional loop
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            decrypted += char((c - base - shift + 26) % 26 + base);
        } else {
            decrypted += c; // Non-alphabetic characters remain unchanged
        }
    }
    return decrypted;
}

int main() {
    string message, encryptedMessage, decryptedMessage;
    int shift, privateKey = 1234, enteredKey;

    // Input message and shift key
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    cout << "Enter the shift value (key): ";
    cin >> shift;
    cin.ignore(); // Prevents input issues

    // Encrypt the message
    encryptedMessage = encrypt(message, shift);
    cout << "\nEncrypted Message: " << encryptedMessage << endl;

    // Ask for the private key before decrypting
    cout << "\nTo decrypt the message, please enter the private key: ";
    cin >> enteredKey;

    if (enteredKey == privateKey) {
        decryptedMessage = decrypt(encryptedMessage, shift);
        cout << "Decrypted Message: " << decryptedMessage << endl;
    } else {
        cout << "Incorrect private key! Access denied." << endl;
    }

    return 0;
}

