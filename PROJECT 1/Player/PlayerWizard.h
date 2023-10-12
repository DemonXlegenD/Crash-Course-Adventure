#pragma once
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

	int useAvadacadavra();
	void surrender();
	void useManaShield();
	void useAtkDebuff();
	void useAtkBuff();

	void useActions(int index);

	

private:

};
