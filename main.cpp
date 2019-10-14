#include <QCoreApplication>
#include "scanner.h"
int main(int argc, char *argv[])
{
    Scanner *scaner=new Scanner;
    scaner->lexicalAnalyze("program.txt");
}
