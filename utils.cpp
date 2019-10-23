#include "utils.h"

Utils::Utils()
{

}
int Utils::evaluatePostfixExpression(string inputExpression)
{
    m_stack=new stack<int>;

    std::istringstream iss(inputExpression);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());//Split inputExpression by white space
    for (size_t i=0;i<results.size();i++) {
        if(results[i]!="+" and results[i]!="-" and results[i]!="*" and results[i]!="/"){
            m_stack->push(stringToInt(results[i]));
        }
        else{
            int val1=m_stack->top();m_stack->pop();
            int val2=m_stack->top();m_stack->pop();
            if(results[i]=="*")
                m_stack->push(val2*val1); // *
            else if (results[i]=="+") {
                    m_stack->push(val2+val1);// +
            }
            else if(results[i]=="-"){
                m_stack->push(val2-val1);
            }// -}
            else if(results[i]=="/"){
                m_stack->push(val2/val1);
            }// /
        }
    }
    return m_stack->top();
}

string Utils::infixToPostFixGrammar()
{

}
int Utils::stringToInt(string input)
{
    stringstream str(input);
    int x=0;
    str>>x;
    return x;
}

string Utils::charToString(char lex[])
{
    string s;
    stringstream ss;
    ss<<lex;
    ss>>s;
    return s;
}

void Utils::exp(){
    if(tok==NUM)
    {
        termino();
        resto();
    }
    else {
        error();
    }
}

void Utils::resto(){
    if(tok==MAS)
    {
        parea(MAS);
        termino();
        cout << "+" << endl;
        expressionPostfix+=" +";
        resto();
    }
    else if (tok==MENOS) {
        parea(MENOS);
        termino();
        cout <<("-");
        expressionPostfix+=" -";
        resto();
    }
    else {
        cout << " "<<endl;
    }
}

void Utils::error(){
    cout << "error de sintaxis" << endl;

}

void Utils::parea(int t){
    if(tok==t)
        tok=scanner();
    else
        error();
}

int Utils::scanner(){
    int c,i;
    do c=getchar();while (c==' ');
    if(c=='\n')
        return FIN;
    if(c==MAS or c==MENOS)
        return c;
    if(isdigit(c)){
        i=0;
        do {
            lexema[i++]=c;
            c=getchar();
        }while (isdigit(c));{
            lexema[i]=0;
            ungetc(c,stdin);
            return NUM;
        }
    }
}

void Utils::termino(){
    if(tok==NUM){
        cout << lexema;
        expressionPostfix+=" "+charToString(lexema);
        parea(NUM);
    }
    else
        error();
}


