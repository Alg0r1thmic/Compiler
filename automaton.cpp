#include "automaton.h"
#include <sstream>
Automaton::Automaton()
{

}

void Automaton::inputFile()
{
    ifstream inputFile("test1.txt",ios::in);
    if(!inputFile)
    {
        cerr << "not open file" << endl;
        exit(EXIT_FAILURE);
    }
    else{
        inputFile>>numStates;
        int input;
        for (int i=0;i<numStates;i++) {
            inputFile>>input;
            states.push_back(input);
        }
        inputFile>>numAcceptanceStates;
        for (int i=0;i<numAcceptanceStates;i++){
            inputFile>>input;
            acceptanceStates.push_back(input);
        }
        inputFile>>numberEntries;
        for (int i=0;i<numberEntries;i++){
            inputFile>>input;
            entries.push_back(input);
        }
        inputFile>>numTransitions;
        int first,third;
        string second;
        for (int i=0;i<numTransitions;i++){
            inputFile>>first>>second>>third;
            transitions.insert({second,{first,third}});
        }
        for (const auto& s : transitions) {
            cout <<s.second.first <<"<-->" << s.first <<"<-->"<<s.second.second <<  endl;
        }
    }
}
void Automaton::getClausura()
{
    int num,input;
    cin >> num;
    for (int i=0;i<num;i++) {
        cin >> input;
        R.push_back(input);
    }
    for(const auto& op : R){
        Clausura.push_back(op);
        m_stack.push(op);
    }
    //get clausure
    while (!m_stack.empty()) {
        int element=m_stack.top();m_stack.pop();
        for (const auto &itr : transitions) {
            if(itr.first=="-1" and itr.second.first==element){
                if(!(std::find(Clausura.begin(),Clausura.end(),itr.second.second)!=Clausura.end()))
                    Clausura.push_back(itr.second.second);
                m_stack.push(itr.second.second);
                //cout << "enter" << endl;
            }
        }
    }
    cout << "clausure" << endl;
    for(const auto& cur:Clausura){
        cout << cur <<endl;
    }
}

void Automaton::NFA_To_DFA()
{

}
