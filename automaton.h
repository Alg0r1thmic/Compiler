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
    vector<int> getClausura(vector<int> r);
    void NFA_To_DFA();
private:
    vector<int> R,Clausura,states,acceptanceStates,entries;
    multimap<string,pair<int,int>> transitions;
    stack<int> m_stack,initial_state;
    int numStates,numAcceptanceStates,numberEntries,numTransitions;
    multimap<string,vector<int>> d_states;
    vector<int> initialState={0};
};

#endif // AUTOMATON_H
