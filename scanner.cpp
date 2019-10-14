#include "scanner.h"
using std::cout;
using std::vector;

bool  Scanner::isID(const std::string &str)
{
    if(std::isdigit(str[0]))
        return false;
    int counter = 0;
    if(str[0] == '_')
        counter++;

    for(; counter < str.size(); counter++)
        if(!(isalnum(str[counter])))
            return false;

    return true;
}

bool Scanner::isComment(const std::string &str)
{
    return str == "/*" || str == "//";
}

bool Scanner::isDigit(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool Scanner::isString(const std::string &str)
{
    return str[0] == '"' && str[str.size()-1] == '"';
}

bool Scanner::isBool(const std::string &str)
{
    return str == "true" || str == "false";
}

bool Scanner::isLiteral(const std::string &str)
{
    return isDigit(str) || isString(str) || isBool(str);
}

bool Scanner::isKeyword(const std::string &str)
{
    const vector<std::string> keywords{"int", "float", "auto","do", "switch", "return",
                                       "break","case","char","const","continue","default",
                                       "double","else","enum","extern","float","goto",
                                       "if","long","register","return","short","signed",
                                       "sizeof","static","struct","switch","typedef","union",
                                       "unsigned","void","volatile","class","template","iostream"
                                       ,"bool","for","while","cout","public","private","string"};
    for(const auto& keyword : keywords)
        if (keyword == str)
            return true;

    return false;
}
/*
bool Scanner::isStatement(const std::string &str)
{
    const vector<std::string> statements{"for", "while"};
    for(const auto& statement : statements)
        if (statement == str)
            return true;

    return false;
}
*/
bool Scanner::isOperator(const std::string &str)
{
    const vector<std::string> operators{"<", ">", "<=", ">=", "*", "+", "-", "/", "=", "-=", "*=", "+=", "/=", "++", "--", "==",">>","<<"};
    for(const auto& op : operators)
        if (op == str)
            return true;

    return false;
}

bool Scanner::isSeparator(const std::string &str)
{
    const vector<std::string> Separators{"{", "}", ",", "(", ")", ";",":"};
    for(const auto& separate : Separators)
        if (separate == str)
            return true;

    return false;
}

bool Scanner::isNotLegal(const std::string &str)
{
    return str == " " || str == "\n";
}

void Scanner::printRoleOfToken(const std::string &token)
{
    if(isOperator(token))
        cout << "token \t=operator [" << token << "]" << std::endl;
    else if(isSeparator(token))
        cout << "token \t=separator [" << token << "]"<< std::endl;
    else if(isKeyword(token))
        cout << "token \t= keyword [" << token << "]"<< std::endl;
    else if(isLiteral(token))
        cout << "token \t=NUM [" << token << "]"<< std::endl;
    else if(isID(token))
        cout << "token \t=ID [" << token << "]"<< std::endl;
    else if(isComment(token))
        cout << "token \t=comment [" << token << "]"<< std::endl;
    else{
        throw std::runtime_error(token);
    }
}

void Scanner::lexicalAnalyze(const std::string &nameOfFile)
{
    char ch;
    std::string buffer;
    std::fstream file(nameOfFile, std::fstream::in);

    if (!file.is_open())
    {
        cout << "error while opening the file\n";
        exit(0);
    }

    bool miltiCm = false, singleCm = false;
    while (file >> std::noskipws >> ch)
    {
        if(singleCm || miltiCm)
        {
            if(singleCm && ch == '\n')
                singleCm = false;

            if(miltiCm && ch == '*')
            {
                file >> ch;
                if(ch == EOF)
                    break;

                if(ch == '/')
                    miltiCm = false;
            }
            continue;
        }

        if(ch == '/')
        {
            std::string comm(1, ch);
            file >> ch;
            if(ch == EOF)
            {
                printRoleOfToken(comm);
                break;
            }

            if(ch == '*')
            {
                miltiCm = true;
                comm += ch;
            }
            else if(ch == '/')
            {
                singleCm = true;
                comm += ch;
            }
            if(miltiCm || singleCm)
            {
                printRoleOfToken(comm);
                continue;
            }
        }

        if(isNotLegal(std::string(1, ch)))
        {
            if(!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
            continue;
        }

        if(isOperator(std::string(1, ch)))
        {
            if(!buffer.empty() && !isOperator(buffer))
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
        }

        if(isSeparator(std::string(1, ch)))
        {
            if(!buffer.empty())
            {
                printRoleOfToken(buffer);
                buffer = "";
            }
            if(isSeparator(std::string(1, ch)))
            {
                printRoleOfToken(std::string(1, ch));
                continue;
            }
        }
        buffer += ch;
    }
    file.close();
}

