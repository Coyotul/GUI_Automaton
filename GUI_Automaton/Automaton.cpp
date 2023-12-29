#include "Automaton.h"

void Automaton::adaugaTranzitie(std::pair<char, char> tranzitie, char destinatie)
{
    auto it = Delta.find(tranzitie);
    if (it != Delta.end())
    {
        it->second.emplace_back(destinatie);
    }
    else
    {
        Delta[tranzitie].emplace_back(destinatie);
    }
}

void Automaton::adaugaStare(char stare)
{
	Q.push_back(stare);
}

void Automaton::adaugaSimbol(char simbol)
{
	Sigma.push_back(simbol);
}

void Automaton::seteazaSimbolInitial(char initial)
{
	q0 = initial;
}

std::vector<char> Automaton::getStari()
{
	return this->Q;
}

std::vector<char> Automaton::getSimboluri()
{
	return this->Sigma;
}

std::map<std::pair<char, char>, std::vector<char>> Automaton::getTranzitii()
{
	return this->Delta;
}

char Automaton::getStareInitiala()
{
	return q0;
}

std::vector<char> Automaton::getStariFinale()
{
	return this->F;
}

std::vector<std::pair<int, int>> Automaton::getPozitieStari()
{
    return this->pozitieStari;
}
std::vector<std::pair<char, char>> Automaton::getPozitieTranzitie()
{
    return this->pozitieTranzitie;
}

void Automaton::addPozitieStare(std::pair<int, int> pos)
{
    this->pozitieStari.push_back(pos);
}

void Automaton::addPozitieTranzitie(std::pair<char, char> pos)
{
    this->pozitieTranzitie.push_back(pos);
}

