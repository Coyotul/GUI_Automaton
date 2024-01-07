#pragma once
#include <set>
#include <map>
#include <vector>

class Automaton
{
public:
    void adaugaTranzitie(std::pair<char, char> tranzitie,char destinatie);
    void adaugaStare(char stare);
    void adaugaSimbol(char simbol);
    void seteazaSimbolInitial(char initial);
    std::vector<char> getStari();
    std::vector<char> getSimboluri();
    std::map<std::pair<char, char>, std::vector<char>> getTranzitii();
    char getStareInitiala();
    std::vector<char> getStariFinale();
    std::vector<std::pair<int, int>> getPozitieStari();
    std::vector<std::pair<char, char>> getPozitieTranzitie();
    void addPozitieStare(std::pair<int, int> pos);
    void addPozitieTranzitie(std::pair<char, char> pos);
private:
    std::vector<char> Q;
    std::vector<char> Sigma;
    std::map<std::pair<char, char>, std::vector<char>> Delta;
    char q0;
    std::vector<char> F;
    std::vector<std::pair<int, int>> pozitieStari;
    std::vector<std::pair<char, char>> pozitieTranzitie;
};

