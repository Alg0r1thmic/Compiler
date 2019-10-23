#ifndef UTILS_H
#define UTILS_H
#define MAS '+'
#define MENOS '-'
#define NUM 256
#define FIN -1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Utils
{
public:
    Utils();
    int evaluatePostfixExpression(string);
    string infixToPostFixGrammar();
    string getExp()
    {
        return this->expressionPostfix;
    }
    int scanner();
    void exp();
    int tok;
private:
    string name;
    stack<int> *m_stack;
    int stringToInt(string input);
    string charToString(char []);
    string expressionPostfix;
    //infix to postfix
    char lexema[80];
    void resto();
    void error();
    void parea(int t);
    void termino();

};

#endif // UTILS_H
