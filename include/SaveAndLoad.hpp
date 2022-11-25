#ifndef SAVEANDLOAD_HPP_
#define SAVEANDLOAD_HPP_

#include <string>
#include <vector>

#include "NPC.hpp"

void LoadLogsFromFile(std::string characterLogFile, std::vector<NPC>& characterLog, std::vector<NPC>& NPCLog, std::vector<NPC>& enemyLog);

#endif