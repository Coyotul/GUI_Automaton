#pragma once
#include <set>
#include <vector>
class Automaton
{
public:
    void adaugaTranzitie(std::pair<char, char> tranzitie);
    void adaugaStare(char stare);
    void adaugaSimbol(char simbol);
    void seteazaSimbolInitial(char initial);
private:
    std::set<char> Q;
    std::set<char> Sigma;
    std::map<std::pair<char, char>, std::vector<char>> Delta;
    char q0;
    std::set<char> F;
};

