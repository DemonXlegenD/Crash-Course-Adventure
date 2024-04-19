#include "PlayerAbstract.h"

#include <iostream>


PlayerAbstract::PlayerAbstract(
	const std::string id,
	const std::string name = "player",
	int pvMax = 100,
	int attackMax = 20,
	int attack = 5,
	int defenseMax = 10,
	int defense = 5,
	int manaMax = 500,
	std::string typePlayer = "Villageois"
) :
	id(id),
	name(name),
	pvMax(pvMax),
	pv(pvMax),
	attackMax(attackMax),
	attack(attack),
	defenseMax(defenseMax),
	defense(defense),
	manaMax(manaMax),
	mana(manaMax),
	basic_spell(basic_spell),
	typePlayer(typePlayer)
{}

std::string PlayerAbstract::getId() const
{
	return id;
}

std::string PlayerAbstract::getName() const
{
	return name;
}

int PlayerAbstract::getActualPv() const {
	return pv;
}

void PlayerAbstract::setActualPv(int newPv) {
	if (newPv > pvMax) {
		pv = pvMax;
	}
	else {
		pv = newPv;
	}
}

int PlayerAbstract::getActualAttack() const {
	return attack;
}

void PlayerAbstract::setActualAttack(int newAttack) {
	if (newAttack > attackMax) {
		attack = attackMax;
	}
	else {
		attack = newAttack;
	}
}

int PlayerAbstract::getActualDefense() const {
	return defense;
}

void PlayerAbstract::setActualDefense(int newDefense) {
	if (newDefense > defenseMax) {
		defense = defenseMax;
	}
	else {
		defense = newDefense;
	}
}

int PlayerAbstract::getActualMana() const {
	return mana;
}

void PlayerAbstract::setActualMana(int newMana) {
	if (newMana > manaMax) {
		mana = manaMax;
	}
	else {
		mana = newMana;
	}
}

std::string PlayerAbstract::getLastSpellName() {
	return last_spell_name;
}

void PlayerAbstract::setLastSpellName(std::string spell_name) {
	last_spell_name = spell_name;
}

void PlayerAbstract::afficherInfos() {
	std::cout << "Nom : " << name << ", Type : " << typePlayer << ", Attack : " << attack << ", Defense : " << defense << ", PV : " << pv << std::endl;
}

void PlayerAbstract::getDamage(int damage)
{
	std::cout << "Joueur subi " << (damage - (defense / 100 * damage)) << " degats." << std::endl;
	pv -= (damage - (defense / 100 * damage));
}

void PlayerAbstract::getHealth(int health)
{
	std::cout << "Joueur a gagne " << health << " pv." << std::endl;
	pv += health;
}

void PlayerAbstract::callUsedSpell(Spell usedSpell) {
	std::cout << "Joueur " << name << " a utiliser le sort " << usedSpell.getName() << "." << std::endl;
}

std::vector<Object*> PlayerAbstract::getInventory() {
	return inventory;
}

Object* PlayerAbstract::getObjectByName(std::string name) {
	for (Object* object : inventory) {
		if (object->getName() == name) return object;
	}
	return nullptr;
}

std::string PlayerAbstract::getPlayerType() {
	return typePlayer;
}



PlayerAbstract::~PlayerAbstract() {}