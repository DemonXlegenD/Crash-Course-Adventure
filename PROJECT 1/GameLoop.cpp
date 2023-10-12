#include "GameLoop.h"

GameLoop::GameLoop() {}


int GameLoop::askNumberPlayer() {
	int numberPlayer = 0;
	do {
		std::cout << "Combien de joueurs dans la partie (2,4,6,8): ";
		std::cin >> numberPlayer;

		// V�rification de la validit� de la saisie (par exemple, si la longueur est sup�rieure � 3 caract�res)
		if (numberPlayer > 1 && numberPlayer % 2 == 0 && numberPlayer < 9) {
			std::cout << "Saisie valide, nombre de joueurs = " << numberPlayer << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. R�essayez." << std::endl;
			// Efface le tampon d'entr�e pour �viter des boucles infinies si l'utilisateur entre des caract�res non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
	return numberPlayer;
}

std::string GameLoop::askNameTeam(std::string team) {
	std::string name;
	do {
		std::cout << team << ", entrez un nom d'�quipe valide : ";
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

std::string GameLoop::askName(std::string player) {
	std::string name;
	do {
		std::cout << player << ", entrez un nom valide : ";
		std::cin >> name;

		// V�rification de la validit� de la saisie (par exemple, si la longueur est sup�rieure � 3 caract�res)
		if (name.length() >= 3) {
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

PlayerAbstract GameLoop::askType(std::string idPlayer, std::string namePlayer) {
	std::string chosenType;
	std::vector<TypeCombattantClass> combattants;
	combattants.push_back({ "Magicien", PlayerWizard(idPlayer, namePlayer, 100, 50, 20, 10, 5, 500) });
	combattants.push_back({ "Guerrier", PlayerWarrior(idPlayer, namePlayer, 100, 50, 20, 10, 5, 500) });
	combattants.push_back({ "Chevalier", PlayerKnight(idPlayer, namePlayer, 100, 50, 20, 10, 5, 500) });
	combattants.push_back({ "Gardien", PlayerGuardian(idPlayer, namePlayer, 100, 50, 20, 10, 5, 500) });

	do {
		std::cout << namePlayer << ", choisissez un type de combattant : " << std::endl;
		int index = 1;
		for (const TypeCombattantClass combattant : combattants) {
			std::cout << index << "." << combattant.name << std::endl;
			index++;
		}

		std::cin >> chosenType;
		index = 1;
		for (const TypeCombattantClass combattant : combattants) {
			if (chosenType == combattant.name || chosenType == std::to_string(index)) {
				return combattant.type;
			}
			index++;
		}
		std::cout << "Saisie invalide. R�essayez." << std::endl;
	} while (true);
}


bool GameLoop::startAgain() {
	std::string response;
	bool stopPlaying = false;
	do {
		std::cout << "Voulez-vous relancer une partie? ";
		std::cin >> response;

		// V�rification de la validit� de la saisie (par exemple, si la longueur est sup�rieure � 3 caract�res)
		if (response == std::string("yes") || response == std::string("Yes") || response == std::string("Y") || response == std::string("y")) {
			std::cout << "Merci d'avoir joue!" << std::endl;
			stopPlaying = true;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else if (response == std::string("no") || response == std::string("No") || response == std::string("N") || response == std::string("n")) {
			std::cout << "C'est partie pour un nouveau tour!" << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		} else {
			std::cout << "Saisie invalide. R�essayez." << std::endl;
			// Efface le tampon d'entr�e pour �viter des boucles infinies si l'utilisateur entre des caract�res non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);

	return stopPlaying;
}

GameLoop::~GameLoop() {}