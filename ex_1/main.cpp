//Задание 1. Шифр Цезаря
#include <iostream>

std::string encrypt_caesar (const std::string& str, int key) {
    std::string new_str;

    for (char i : str) { // 97 - 122
        if (i >= 'a' && i <= 'z'){
            new_str += (i + key <= 'z') ? (char)(i + key) : (char)(96 + i + key - 122);
        } else if (i >= 'A' && i <= 'Z'){
            new_str += (i + key <= 'Z') ? (char)(i + key) :  (char)(64 + i + key - 90);
        } else {
            new_str += i;
        }

    }
    return new_str;
}

std::string decrypt_caesar (const std::string& str, int key) {
    return encrypt_caesar(str, 26 - key);

    /* std::string new_str;

     for (char i : str) { // 97 - 122
         if (i >= 'a' && i <= 'z'){
             new_str += (i - key >= 'a') ? (char)(i - key): (char)(122 - (key - (i - 96)));
         } else if (i >= 'A' && i <= 'Z'){
             new_str += (i - key >= 'A') ? (char)(i - key): (char)(90 - (key - (i - 64)));
         } else {
             new_str += i;
         }

     }
     return new_str;
     */
}

int main() {
    int key;
    std::string text, encrypt_text;

    std::cout << "Input the text for encrypt" << std::endl;
    std::getline (std::cin,text);
    std::cout << "Input the key number for encrypt" << std::endl;
    std::cin >> key;

    encrypt_text = encrypt_caesar(text, key);
    text = decrypt_caesar(encrypt_text, key);

    std::cout << encrypt_text << "\n" <<  std::endl;
    std::cout << text << "\n" << std::endl;

    return 0;
}
