//Задание 3. Валидация IP-адреса

#include <iostream>
#include <vector>

bool isDotsCountAndCharsCorrect(const std::string& ip){
    int dotCounter = 0;
    for (char i : ip){
        if (i == '.') dotCounter++;
        else if (i < 48 || i > 57) return false;
    }

    if (dotCounter != 3) return false;

    return true;
}

std::vector<std::string> divideNums(const std::string& ip){
    std::vector<std::string> nums;
    std::string strNum;

    for (char i : ip){
        if (i == '.') {
            nums.push_back(strNum);
            strNum = "";
        } else strNum += i;
    }
    nums.push_back(strNum);

    return nums;
}

bool isNumsCorrect(const std::vector<std::string>& nums){
    for (std::string num : nums){
        if (num.empty()) return false;
        if (num[0] == '0' && num.length() != 1) return false;
        if (std::stoi(num) > 255) return false;
    }
    return true;
}

bool isIpCorrect (const std::string& ip){
    if (!isDotsCountAndCharsCorrect(ip)) return false;
    std::vector<std::string> nums = divideNums(ip);
    if (!isNumsCorrect(nums)) return false;

    return true;
}

int main() {
    std::string ip;
    std::cout << "Input a IP-address:" << std::endl;
    std::cin >> ip;

    isIpCorrect(ip) ? std::cout << "Valid" << std::endl : std::cout << "Invalid" << std::endl;

    return 0;
}
