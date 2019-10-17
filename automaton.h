#ifndef AUTOMATON_H
#define AUTOMATON_H
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
class Automaton
{
public:
    Automaton();
    void inputFile();
    void readFile();
    int stringToInt(string input);
    void getClausura();
    void proofInputFile();
    void NFA_To_DFA();
private:
    vector<int> R,Clausura,states,acceptanceStates,entries;
    multimap<string,pair<int,int>> transitions;
    stack<int> m_stack;
    int numStates,numAcceptanceStates,numberEntries,numTransitions;
};

#endif // AUTOMATON_H
