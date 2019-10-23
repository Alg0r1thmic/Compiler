#include <QCoreApplication>
//#include "scanner.h"
#include <tokenizer.h>
#include <iostream>
#include <fstream>
#include <automaton.h>
#include "utils.h"
using namespace Scanner;
/*void proofScanner(){
    Scanner *scaner=new Scanner;
    scaner->lexicalAnalyze("program.txt");

}*/
void proof(){
    std::string fileSpec = "program.txt";

    std::ifstream in(fileSpec);
    if (!in.good())
    {
        std::cout << "\n  can't open " << fileSpec << "\n\n";
    }
    Toker toker;
    toker.attach(&in);
    while (in.good())
    {
        std::string tok = toker.getTok();
        if (tok == "\n")
            tok = "newline";
        std::cout << "\n -- " << tok;
    }
    std::cout << "\n\n";

}
void proofUtils(){

    Utils u;
    /*string input;
    getline(cin,input);
    cout << "Result is: " << u.evaluatePostfixExpression(input) << endl;*/
    u.tok=u.scanner();
    u.exp();
    cout << "resul is: " << u.evaluatePostfixExpression(u.getExp()) << endl;
}
int main(int argc, char *argv[])
{
    /*Automaton automata;
    automata.inputFile();
    int num,input;
    vector<int> R;
    vector<int> Re;
    cin >> num;
    for (int i=0;i<num;i++) {
        cin >> input;
        R.push_back(input);
    }
    R=automata.getClausura(R);

    //automata.getClausura();
    //automata.readFile();
    //automata.getClausura();
*/
  proofUtils();
}
