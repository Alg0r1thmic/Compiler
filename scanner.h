#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;
class Scanner
{
public:
    Scanner(){};
    void lexicalAnalyze(const std::string &nameOfFile);
private:
    //util functions
    bool isID(const std::string &str);
    bool isComment(const std::string &str);
    bool isDigit(const std::string &str);
    bool isString(const std::string &str);
    bool isBool(const std::string &str);
    bool isLiteral(const std::string &str);
    bool isKeyword(const std::string &str);
   // bool isStatement(const std::string &str);
    bool isOperator(const std::string &str);
    bool isSeparator(const std::string &str);
    bool isNotLegal(const std::string &str);
    void printRoleOfToken(const std::string& token);
};

#endif // SCANNER_H
