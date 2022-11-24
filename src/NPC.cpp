#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ostream>

#include "NPC.h"

void NPC::SetStats(std::vector<int> stats) {
    this->strength = stats.at(0);
    this->dexterity = stats.at(1);
    this->constitution = stats.at(2);
    this->wisdom = stats.at(3);
    this->intelligence = stats.at(4);
    this->charisma = stats.at(5);
    this->maxHP = stats.at(6);
}

void NPC::PopulateCharacterStats() {
    std::string name;
    int stat;
    
    std::cout << "Input character's name.\n";
    std::getline(std::cin, name);
    this->SetName(name);
    
    std::cout << "Input character's strength.\n";
    std::cin >> stat;
    this->SetStrength(stat);
    
    std::cout << "Input character's dexterity.\n";
    std::cin >> stat;
    this->SetDexterity(stat);
    
    std::cout << "Input character's constitution.\n";
    std::cin >> stat;
    this->SetConstitution(stat);
    
    std::cout << "Input character's intelligence.\n";
    std::cin >> stat;
    this->SetIntelligence(stat);
    
    std::cout << "Input character's wisdom.\n";
    std::cin >> stat;
    this->SetWisdom(stat);
    
    std::cout << "Input character's charisma.\n";
    std::cin >> stat;
    this->SetCharisma(stat);
    
}

void NPC::SetStrength(int Str) {
    this->strength = Str;
}
void NPC::SetDexterity(int Dex) {
    this->dexterity = Dex;
}
void NPC::SetConstitution(int Const) {
    this->constitution = Const;
}
void NPC::SetWisdom(int Wis) {
    this->wisdom = Wis;
}
void NPC::SetIntelligence(int Int) {
    this->intelligence = Int;
}
void NPC::SetCharisma(int Cha) {
    this->charisma = Cha;
}
        
void NPC::PrintStats() {
        std::cout << std::setw(24) << std::setfill('_') << "\n" << std::setfill(' ')
                  << this->GetName() << " (" << this->GetRace() << ")\n"
                  << std::setw(24) << std::setfill('-') << "\n"
                  << "Strength: " << this->strength << "\n"
                  << "Dexterity: " << this->dexterity << "\n"
                  << "Constitution: " << this->constitution << "\n"
                  << "Intelligence: " << this->wisdom << "\n"
                  << "Wisdom: " << this->intelligence << "\n"
                  << "Charisma: " << this->charisma << "\n"
                  << "HP: " << this->maxHP << "\n"
                  << std::setw(24) << std::setfill('_') << "\n" << std::endl << std::endl << std::setfill(' ');
}

void NPC::PrintOnlyName() {
    std::cout << "--------------------\n";
    std::cout << this->GetName() << std::endl;
    std::cout << "--------------------\n";
}
    
void NPC::SetName(std::string npcName) {
    name = npcName;
    }
std::string NPC::GetName() const {
    return this->name;
}

void NPC::SetRace(std::string race) {
    this->race = race;
}
std::string NPC::GetRace() const {
    return this->race;
}

void NPC::SetMaxHP(int health) {
    this->maxHP = health;
}
int NPC::GetMaxHP() {
    return this->maxHP;
}