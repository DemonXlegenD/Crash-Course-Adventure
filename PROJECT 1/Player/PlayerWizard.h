#pragma once
#include <iostream>

#include "../PlayerAbstract.h"

class PlayerWizard : public PlayerAbstract
{
	using PlayerAbstract::PlayerAbstract;

public:
	
	PlayerWizard(
		const std::string id,
		const std::string name,
		int pvMax,
		int attackMax,
		int attack,
		int defenseMax,
		int defense,
		int manaMax
	);

	virtual void addSpellToList() override {
		std::cout << "OVERIDE" << std::endl;
		Spell spellOffensif("offensive", "yayaya", attack, 0);
		Spell spellDefensif("defensive", "yoyoyo", defense, 0);
		Spell spellBuff("buff", "yiyiyi", attack, 0);
		Spell spellUltimate("ultimate", "yuyuyu", 2, 0);
		spellList.push_back(spellOffensif);
		spellList.push_back(spellDefensif);
		spellList.push_back(spellBuff);
		spellList.push_back(spellUltimate);
	}

	

private:

};