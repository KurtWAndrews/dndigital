#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cctype>

#include "NPC.hpp"
#include "SaveAndLoad.hpp"

std::string NewLines(int amount) {
    std::string newLine = "";
    for (int i = 0; i < amount; i++) {
        newLine += "\n";
    }
    return newLine;
}
int FindNthOccurance(const std::string& phrase, int Nth, char searchChar) {
    int count = 0;
        for (int i = 0; i < phrase.size(); i++) {
            if (phrase.at(i) == searchChar) {
                count++;
            }
            if (count == Nth) {
                return i;
            }
        }
    return -1;
}
std::string ParcetxtForString(std::string fileName, int nthChar) {
   std::ifstream f(fileName);
   std::string ascii;
   if(f) {
      std::ostringstream ss;
      ss << f.rdbuf();
      ascii = ss.str();
   }
   int startPos = FindNthOccurance(ascii, nthChar, '&') + 1;
   int size = FindNthOccurance(ascii, nthChar + 1, '&') - startPos;
    return ascii.substr(startPos , size);
}

int OccuranceOfNameInScene(std::vector<NPC>& scene, std::string searchName) {
    int count = 1;
    for (auto& character : scene) {
        if (character.GetName() == searchName) {
            count++;
        }
    }
    std::cout << "count:" << count;
    return count;
}

void RemoveCharFromVector(std::vector<NPC>& combatScene) {
    std::string searchName;
    bool found = false;
    std::cout << "Enter a name to delete." << std::endl;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, searchName);
        
    for (auto it = begin(combatScene); it != end(combatScene);) {
        if ((*it).GetName() == searchName) {
            found = true;
            it = combatScene.erase(it);
            break;
        }
        else
            ++it;
    }
    
    if (found) {
        std::cout << searchName << " was deleted.\n\n";
    }
    else if (!found) {
        std::cout << "ERROR: " << searchName << " is not currently in scene.\n\n";
    }
}
void AddCharToSceneFromLog(const std::vector<NPC>& fromLog, std::vector<NPC>& scene) {
    std::string searchName;
    std::cout << "Enter a name from the backlog." << std::endl;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, searchName);
    
    bool found = false;
    for (auto& character : fromLog) {
        if (character.GetName() == searchName) {
            found = true;
            int count = OccuranceOfNameInScene(scene, searchName);
            NPC charToAdd = character;
            charToAdd.SetName(charToAdd.GetName() + std::to_string(count));
            scene.push_back(charToAdd);
            break;
        }
    }
    
    if (found) {
        std::cout << searchName << " added to scene.\n\n";
    } else if (!found) {
        std::cout << "ERROR: " << searchName << " is not currently in backlog\n\n";
    }
    
}

void ExecuteCombatMenu(char userNavChar, std::vector<NPC>& characterLog, std::vector<NPC>& NPCLog, std::vector<NPC>& enemyLog, std::vector<NPC>& scene) {
    char anyChar;
    if (userNavChar == 'p') {
        if (scene.size() == 0) {
            std::cout << "Scene is currently empty." << std::endl;
        }
        else {
            for (auto& character : scene) {
                character.PrintStats();
            }
        }
    }
    else if (userNavChar == 'n') {
        AddCharToSceneFromLog(NPCLog, scene);
    }
    else if (userNavChar == 'r') {
        RemoveCharFromVector(scene);
    }
    else if (userNavChar == 'e') {
        AddCharToSceneFromLog(enemyLog, scene);
    }
    else if (userNavChar == 'v') { //TODO: Organize the view backlog function for better readability
        std::cout << NewLines(100);
        for (auto& currChar : characterLog) {
            currChar.PrintOnlyName();
        }
        std::cout << "\n\n\n";
        for (auto& currChar : NPCLog) {
            currChar.PrintOnlyName();
        }
        std::cout << "\n\n\n";
        for (auto& currChar : enemyLog) {
            currChar.PrintOnlyName();
        }
    }
    if (userNavChar != 'z') {
    std::cout << "Press any character to continue.\n";
    std::cin >> anyChar;
    }
}

void ExecuteBackLogMenu(char userNavChar, std::vector<NPC>& characterLog, std::vector<NPC>& NPCLog, std::vector<NPC>& enemyLog) {
    char anyChar;
    if (userNavChar == 'p') {
        for (auto& currChar : characterLog) {
            currChar.PrintStats(); 
            std::cout << std::endl;
        }
    } else if (userNavChar == 'c') {
        for (auto& currChar : NPCLog) {
            currChar.PrintStats(); 
            std::cout << std::endl;
        }
    } else if (userNavChar == 'e') {
        for (auto& currChar : enemyLog) {
            currChar.PrintStats(); 
            std::cout << std::endl;
        }
    }
    
    if (userNavChar != 'z') {
        std::cout << "Press any character to continue.\n";
        std::cin >> anyChar;
    }
}

void ExecuteMainMenu(char userNavChar, std::vector<NPC>& characterLog, std::vector<NPC>& NPCLog, std::vector<NPC>& enemyLog, std::vector<NPC>& scene) {
    std::vector<char> validChars {'c', 'n', 'l', 'p', 'q'};
    std::string combatMenu = ParcetxtForString("AsciiMenues.txt", 3);
    std::string backLogMenu = ParcetxtForString("AsciiMenues.txt", 5);
    char anyChar;
    try {
        if (find(validChars.begin(), validChars.end(), userNavChar) == validChars.end()) {
            throw std::out_of_range("Error: Invalid Character Input\n");
        }
        
        if (userNavChar == 'c') {
            while (userNavChar != 'z') {
                std::cout << combatMenu << std::endl;
                std::cin >> userNavChar;
                userNavChar = tolower(userNavChar);
                
                ExecuteCombatMenu(userNavChar, characterLog, NPCLog, enemyLog, scene);
                std::cout << NewLines(100) << std::endl;
            }
            std::cout << NewLines(100) << std::endl;
        } else if (userNavChar == 'n') {
            while (userNavChar != 'z') {
                std::cout << backLogMenu << std::endl;
                std::cin >> userNavChar;
                userNavChar = tolower(userNavChar);
                
                ExecuteBackLogMenu(userNavChar, characterLog, NPCLog, enemyLog);
                std::cout << NewLines(100) << std::endl;
            }
        } else if (userNavChar == 'l') {
            std::cout << "You pressed l" << std::endl;
        } else if (userNavChar == 'p') {
            std::cout << "You pressed p" << std::endl;
        }
        
    }
    catch (std::out_of_range &excpt) {
        std::cout << excpt.what() << std::endl;
    }
}


int main() {
    char userNavChar;
    std::vector<NPC> NPCLog, characterLog, enemyLog, scene;

    LoadLogsFromFile("CharacterLog.txt", characterLog, NPCLog, enemyLog);
    std::string mainMenu = ParcetxtForString("AsciiMenues.txt", 1);
    
    for (int i = 0; i < characterLog.size(); i++) {
        scene.push_back(characterLog.at(i));
    }
    
    std::cout << mainMenu << std::endl;
    
    while (userNavChar != 'q') {
    std::cin >> userNavChar;
    userNavChar = tolower(userNavChar);
    
    ExecuteMainMenu(userNavChar, characterLog, NPCLog, enemyLog, scene);
    std::cout << mainMenu << NewLines(10);
    } 

    return 0;
}