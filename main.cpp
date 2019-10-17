#include <QCoreApplication>
//#include "scanner.h"
#include <tokenizer.h>
#include <iostream>
#include <fstream>
#include <automaton.h>
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
int main(int argc, char *argv[])
{
    Automaton automata;
    automata.inputFile();
    automata.getClausura();
    //automata.readFile();
    //automata.getClausura();

}
