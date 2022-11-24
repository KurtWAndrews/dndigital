#ifndef NPC_HPP_
#define NPC_HPP_

#include <vector>
#include <string>
#include <iomanip>

class NPC {
    
    public:
        void SetStats(std::vector<int> stats);
        void PopulateCharacterStats();
        
        void SetName(std::string npcName);
        std::string GetName() const;
        
        void SetRace(std::string race);
        std::string GetRace() const;
        
        void PrintStats();
        void PrintOnlyName();
        
        void SetStrength(int Str);
        void SetDexterity(int Dex);
        void SetConstitution(int Const);
        void SetWisdom(int Wis);
        void SetIntelligence(int Int);
        void SetCharisma(int Cha);
        
        void SetMaxHP(int health);
        int GetMaxHP();
        
    private:
        std::string name;
        std::string race;
        
        int strength;
        int dexterity;
        int constitution;
        int wisdom;
        int intelligence;
        int charisma;
        
        int maxHP;
        
        std::vector<std::string> inventory;
};

#endif