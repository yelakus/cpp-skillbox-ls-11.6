//Задание 2. Проверка корректности email-адреса
#include <iostream>

std::string findFirstPart(const std::string& email, int atPosition){
    return email.substr (0,atPosition);
}

std::string findSecondPart(const std::string& email, int atPosition){
    return email.substr (atPosition+1);
}

bool checkFirstPart(const std::string& str){
    if (str.empty() || str.length() > 64
        || str[0] == '.' || str[str.length()-1] == '.' )
        return false;

    std::string validCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!#$%&'*+-/=?^_`{|}~.";

    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] == '.' && str[i+1] == '.')
            || (validCharacters.find(str[i]) == std::string::npos))
            return false;
    }

    return true;
}

bool checkSecondPart(const std::string& str){
    if (str.empty() || str.length() > 63
        || str[0] == '.' || str[str.length()-1] == '.' )
        return false;

    std::string validCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";

    for (int i = 0; i < str.length(); ++i) {
        if ((str[i] == '.' && str[i+1] == '.')
            || (validCharacters.find(str[i]) == std::string::npos))return false;
    }

    return true;
}

bool isCorrectEmail(const std::string& email){
    int atPosition = email.find('@');
    if (atPosition == -1) return false;

    std::string firstPart = findFirstPart(email, atPosition);
    std::string secondPart = findSecondPart(email, atPosition);

    return (checkFirstPart(firstPart) && checkSecondPart(secondPart));
}

int main() {
    std::string email;
    std::cout << "Input the e-mail address:" << std::endl;
    std::getline (std::cin,email);

    isCorrectEmail(email) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

    return 0;
}
