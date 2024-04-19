#pragma once

#include <string>
#include "PlayerAbstract.h"
#include <vector>
#include "./Spell.h"
struct TypeCombattantClass {
	std::string name;
	PlayerAbstract type;
};

class GameLoop
{
public:
	GameLoop();
	static int askNumberPlayer();
	static std::string askNameTeam(std::string team);
	static std::string askName(std::string player);
	static PlayerAbstract askType(std::string idPlayer, std::string namePlayer);
	static bool startAgain();
	static std::string askAction(std::vector<std::string> actions);
	static void statsPlayer(PlayerAbstract player);
	static void winOrLose(std::string nameWinnerPlayer, std::string nameLoserPlayer);
	static Spell askSpell(std::vector<Spell> spells);
	~GameLoop();
};

