#include "GameLoop.h"

GameLoop::GameLoop() {}
std::string GameLoop::askName(std::string player) {
	std::string name;
	do {
		std::cout << player << ", entrez un nom valide : ";
		std::cin >> name;

		// V�rification de la validit� de la saisie (par exemple, si la longueur est sup�rieure � 3 caract�res)
		if (name.length() > 3) {
			std::cout << "Saisie valide : " << name << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. R�essayez." << std::endl;
			// Efface le tampon d'entr�e pour �viter des boucles infinies si l'utilisateur entre des caract�res non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);

	return name;
}

PlayerAbstract GameLoop::askType(std::string player, std::string namePlayer) {
	std::string chosenType;
	std::vector<TypeCombattantClass> types;
	types.push_back({ "Magicien", PlayerWizard(namePlayer, 100, 50, 20, 10, 5, 500)});
	types.push_back({ "Guerrier", PlayerWizard(namePlayer, 100, 50, 20, 10, 5, 500)});
	types.push_back({ "Chevalier", PlayerWizard(namePlayer, 100, 50, 20, 10, 5, 500)});
	types.push_back({ "Gardien", PlayerWizard(namePlayer, 100, 50, 20, 10, 5, 500)});

	do {
		std::cout << player << ", choisissez un type de combattant : " << std::endl;
		int index = 1;
		for (const TypeCombattantClass type : types) {
			std::cout << index << "." << type.name << std::endl;
			index++;
		}

		std::cin >> chosenType;


		// V�rification de la validit� de la saisie (par exemple, si la longueur est sup�rieure � 3 caract�res)
		if (type.length() > 3) {
			std::cout << "Saisie valide : " << type << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. R�essayez." << std::endl;
			// Efface le tampon d'entr�e pour �viter des boucles infinies si l'utilisateur entre des caract�res non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);

	return name;
}

GameLoop::~GameLoop() {}