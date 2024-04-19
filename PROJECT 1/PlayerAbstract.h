#pragma once
#include <string>
#include "Spell.h"
#include <vector>

#include "Object.h"

class PlayerAbstract
{
public:

	PlayerAbstract(
		const std::string id,
		const std::string name,
		int pvMax,
		int attackMax,
		int attack,
		int defenseMax,
		int defense,
		int manaMax,
		std::string typePlayer
	);

	enum archetypeEnum {
		wizard,
		knight,
		warrior,
		guardian
	};
	std::string getId() const;
	std::string getName() const;


	int getActualPv() const;
	void setActualPv(int pv);

	int getActualAttack() const;
	void setActualAttack(int attack);

	int getActualDefense() const;
	void setActualDefense(int defense);

	int getActualMana() const;
	void setActualMana(int mana);

	std::string getLastSpellName();
	void setLastSpellName(std::string spell_name);

	void getDamage(int damage);
	void getHealth(int heal);

	void afficherInfos();

	void callUsedSpell(Spell usedSpell);

	std::vector<Object*> getInventory();
	Object* getObjectByName(std::string name);

	void getArchetype() {

	}

	std::string getPlayerType();


	virtual void addSpellToList() {
			Spell spellOffensif("offensive", "Attack", attack, 0);	
			Spell spellDefensif("defensive", "Protect", defense, 0);
			Spell spellBuff("buff", "Boost", attack, 0);
			Spell spellUltimate("ultimate", "Ultimate", 2, 0);
			spellList.push_back(spellOffensif);
			spellList.push_back(spellDefensif);
			spellList.push_back(spellBuff);
			spellList.push_back(spellUltimate);
	}

	std::vector<Spell> getSpellList() const {
		return spellList;
	}


	//virtual std::vector<Spell> createSpellList();

	~PlayerAbstract();

protected:

	std::vector<Spell> spellList;
	std::string id;


	int pvMax;
	int pv;

	int attackMax;
	int attack;

	int defenseMax;
	int defense;

	int manaMax;
	int mana;

	Spell basic_spell;

	std::string last_spell_name;

	std::string name;
	std::string typePlayer;

	std::vector<Object*> inventory;

	archetypeEnum archetype;
};