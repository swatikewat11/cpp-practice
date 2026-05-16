#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;
int main(){
std::vector<std::string> tokenize(const std::string& line) {
    std::vector<std::string> tokens;
    int i = 0;
    int n = line.length();

    while (i < n) {

        // Skip whitespace
        if (isspace(line[i])) {
            i++;
            continue;
        }

        // Identifier or keyword
        if (isalpha(line[i]) || line[i] == '_') {
            std::string token = "";
            while (i < n && (isalnum(line[i]) || line[i] == '_')) {
                token += line[i];
                i++;
            }
            tokens.push_back(token);
        }

        // Number
        else if (isdigit(line[i])) {
            std::string token = "";
            while (i < n && isdigit(line[i])) {
                token += line[i];
                i++;
            }
            tokens.push_back(token);
        }

        // Operators and punctuation
        else if (line[i] == '=' || line[i] == ';' || line[i] == '+' ||
                 line[i] == '-' || line[i] == '*' || line[i] == '/' ||
                 line[i] == '(' || line[i] == ')' || line[i] == '{' ||
                 line[i] == '}' || line[i] == ',') {
            tokens.push_back(std::string(1, line[i]));
            i++;
        }

        // Unknown — skip
        else {
            i++;
        }
    }

    return tokens;
}

int main() {
    std::string line;
    std::cout << "Enter a line of code: ";
    std::getline(std::cin, line);

    std::vector<std::string> tokens = tokenize(line);

    std::cout << "\nTokens:\n";
    for (const std::string& token : tokens) {
        std::cout << token << "\n";
    }

    return 0;
}
return 0;
 }
