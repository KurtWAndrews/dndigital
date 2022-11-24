#include <string>
#include <iostream>
#include <fstream>

#include "SaveAndLoad.h"

void LoadLogsFromFile(std::string characterLogFile, std::vector<NPC>& characterLog, std::vector<NPC>& NPCLog, std::vector<NPC>& enemyLog) {
    std::ifstream testFS;
    testFS.open(characterLogFile);
    
    if(!testFS.is_open()) {
        std::cout << "Could not open file teams.txt." << std::endl;
        return;
    }
    std::vector<std::string> name;
    std::string charName;
    std::string raceName;
    
    const int CORESTATS = 7; //represents quantity of core stats
    while (!testFS.fail()) {
        testFS.clear();
        NPC character;
        std::getline(testFS, charName);
        std::getline(testFS, raceName);
        character.SetName(charName);
        character.SetRace(raceName);
        
        std::vector<int> stats;
        int stat;
        for (int i = 0; i < CORESTATS; i++ ) {
            testFS >> stat;
            stats.push_back(stat);
            testFS.ignore();
        }
        character.SetStats(stats);
        if (charName.find("E:") != std::string::npos) {
            enemyLog.push_back(character);
        }
        else if (charName.find("P:") != std::string::npos) {
            characterLog.push_back(character);
        }
        else if (charName.find("N:") != std::string::npos) {
            NPCLog.push_back(character);
        }
    }

    testFS.close();
    }