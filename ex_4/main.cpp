#include <iostream>
#include <vector>

bool isTableIncorrect(const std::vector<std::string>& lines){
    if (lines[0].length() != 3 || lines[1].length() != 3 || lines[2].length() != 3) return true;

    std::string validChars = "XO.";
    for (const std::string& i : lines){
        for (char y : i){
            if (validChars.find(y) == std::string::npos) return true;
        }
    }

    return false;
}

int xCounter(const std::vector<std::string>& lines){
    int count = 0;
    for (const std::string& i : lines){
        for (char y : i){
            if (y == 'X') count++;
        }
    }
    return count;
}

int oCounter(const std::vector<std::string>& lines){
    int count = 0;
    for (const std::string& i : lines){
        for (char y : i){
            if (y == 'O') count++;
        }
    }
    return count;
}

std::string whoWon(const std::vector<std::string>& lines){
    if (isTableIncorrect(lines)) return "Incorrect";

    int xCount = xCounter(lines);
    int oCount = oCounter(lines);
    if (!(xCount == oCount || xCount == oCount+1)) return "Incorrect";

    if (lines[0][0] == 'X' && lines[1][1] == 'X' && lines[2][2] == 'X'
       || lines[0][2] == 'X' && lines[1][1] == 'X' && lines[2][0] == 'X'
       || lines[0][0] == 'X' && lines[0][1] == 'X' && lines[0][2] == 'X'
       || lines[1][0] == 'X' && lines[1][1] == 'X' && lines[1][2] == 'X'
       || lines[2][0] == 'X' && lines[2][1] == 'X' && lines[2][2] == 'X'
       || lines[0][0] == 'X' && lines[1][0] == 'X' && lines[2][0] == 'X'
       || lines[0][1] == 'X' && lines[1][1] == 'X' && lines[2][1] == 'X'
       || lines[0][2] == 'X' && lines[1][2] == 'X' && lines[2][2] == 'X') {
        if (xCount == oCount+1) return "Petya won."; else return "Incorrect";
    }

    if (lines[0][0] == 'O' && lines[1][1] == 'O' && lines[2][2] == 'O'
       || lines[0][2] == 'O' && lines[1][1] == 'O' && lines[2][0] == 'O'
       || lines[0][0] == 'O' && lines[0][1] == 'O' && lines[0][2] == 'O'
       || lines[1][0] == 'O' && lines[1][1] == 'O' && lines[1][2] == 'O'
       || lines[2][0] == 'O' && lines[2][1] == 'O' && lines[2][2] == 'O'
       || lines[0][0] == 'O' && lines[1][0] == 'O' && lines[2][0] == 'O'
       || lines[0][1] == 'O' && lines[1][1] == 'O' && lines[2][1] == 'O'
       || lines[0][2] == 'O' && lines[1][2] == 'O' && lines[2][2] == 'O') {
        if (xCount == oCount) return "Vanya won."; else return "Incorrect";
    }

    return "Nobody";
}

int main() {
    std::cout << "Input a game table:" << std::endl;
    std::vector<std::string> lines;
    std::string line;

    for (int i = 0; i < 3; ++i){
        std::cin >> line;
        lines.push_back(line);
    }

    std::cout << whoWon(lines) << std::endl;
    return 0;
}
