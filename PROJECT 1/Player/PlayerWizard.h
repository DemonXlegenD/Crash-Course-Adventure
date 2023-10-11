#pragma once
#include "../PlayerAbstract.h"


class PlayerWizard : public PlayerAbstract
{
	using PlayerAbstract::PlayerAbstract;

public:
	
	PlayerWizard(
		const std::string name,
		int pv_max,
		int attack_max,
		int attack,
		int defense_max,
		int defense,
		int mana_max
	);

	

	

private:
	int useAvadacadavra();
	void surrender();
	void useManaShield();
	void useAtkDebuff();
	void useAtkBuff();

	void useActions(int index)
	Spell avadacadavra;
};

