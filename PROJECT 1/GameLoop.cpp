#include "GameLoop.h"

#include <chrono>
#include <iostream>
#include <fstream>
#include <map>
#include <thread>

#include "Player/PlayerGuardian.h"
#include "Player/PlayerKnight.h"
#include "Player/PlayerWarrior.h"
#include "Player/PlayerWizard.h"

GameLoop::GameLoop() {}



int GameLoop::askNumberPlayer() {
	int numberPlayer = 0;
	do {

		std::cout << "Combien de joueurs dans la partie (2): ";
		std::cin >> numberPlayer;

		// Verification de la validite de la saisie (par exemple, si la longueur est superieure à 3 caractères)
		if (numberPlayer > 1 && numberPlayer % 2 == 0 && numberPlayer < 9) {
			std::cout << "Saisie valide, nombre de joueurs = " << numberPlayer << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. Reessayez." << std::endl;
			// Efface le tampon d'entree pour eviter des boucles infinies si l'utilisateur entre des caractères non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
	} while (true);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
	return numberPlayer;
}

std::string GameLoop::askNameTeam(std::string team) {
	std::string name;
	do {
		std::cout << team << ", entrez un nom d'equipe valide : ";
		std::cin >> name;

		// Verification de la validite de la saisie (par exemple, si la longueur est superieure à 3 caractères)
		if (name.length() > 3) {
			std::cout << "Saisie valide : " << name << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. Reessayez." << std::endl;
			// Efface le tampon d'entree pour eviter des boucles infinies si l'utilisateur entre des caractères non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
	} while (true);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
	return name;
}

std::string GameLoop::askName(std::string player) {
	std::string name;
	do {
		std::cout << player << ", entrez un nom valide : ";
		std::cin >> name;

		// Verification de la validite de la saisie (par exemple, si la longueur est superieure à 3 caractères)
		if (name.length() >= 3) {
			std::cout << "Saisie valide : " << name << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. Reessayez." << std::endl;
			// Efface le tampon d'entree pour eviter des boucles infinies si l'utilisateur entre des caractères non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
	} while (true);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");

	return name;
}

PlayerAbstract GameLoop::askType(std::string idPlayer, std::string namePlayer) {

	std::string classFile = "./Data/Class.txt";
	std::ifstream fichier(classFile);
	std::string chosenType;
	std::vector<TypeCombattantClass*> combattants;

	if (fichier.is_open()) {
		std::string categorieActuelle;

		std::map<std::string, std::map<std::string, int>> personnages;

		std::string ligne;
		std::string personnage_actuel;
		while (std::getline(fichier, ligne)) {
			if (ligne.empty()) {
				continue; // Ignorez les lignes vides.
			}

			if (ligne[0] == '[' && ligne[ligne.length() - 1] == ']') {
				// Il s'agit d'une ligne définissant un nouveau personnage.
				personnage_actuel = ligne.substr(1, ligne.length() - 2);
				personnages[personnage_actuel] = std::map<std::string, int>();
			}
			else {
				size_t pos = ligne.find(":");
				if (pos != std::string::npos) {
					std::string attribut = ligne.substr(0, pos);
					int valeur = std::stoi(ligne.substr(pos + 1));
					personnages[personnage_actuel][attribut] = valeur;
				}
				/*1H Merci Victor*/
			}
		}

		std::string wizard("wizard");
		if (personnages.find(wizard) != personnages.end()) {
			std::map<std::string, int>& attributs = personnages[wizard];
				int pvMax = attributs["pvMax"];
				int attackMax = attributs["attackMax"];
				int attack = attributs["attack"];
				int defenseMax = attributs["defenseMax"];
				int defense = attributs["defense"];
				int manaMax = attributs["manaMax"];


				combattants.push_back(new TypeCombattantClass{ "Magicien", PlayerWizard(idPlayer, namePlayer, pvMax, attackMax, attack, defenseMax, defense, manaMax) });

			
		}

		std::string  warrior("warrior");
		if (personnages.find(warrior) != personnages.end()) {
			std::map<std::string, int>& attributs = personnages[warrior];
				int pvMax = attributs["pvMax"];
				int attackMax = attributs["attackMax"];
				int attack = attributs["attack"];
				int defenseMax = attributs["defenseMax"];
				int defense = attributs["defense"];
				int manaMax = attributs["manaMax"];

				combattants.push_back(new TypeCombattantClass{ "Guerrier", PlayerWarrior(idPlayer, namePlayer, pvMax, attackMax, attack, defenseMax, defense, manaMax) });

			
		}


		std::string  knight("knight");
		if (personnages.find(knight) != personnages.end()) {
			std::map<std::string, int>& attributs = personnages[knight];
				int pvMax = attributs["pvMax"];
				int attackMax = attributs["attackMax"];
				int attack = attributs["attack"];
				int defenseMax = attributs["defenseMax"];
				int defense = attributs["defense"];
				int manaMax = attributs["manaMax"];

				combattants.push_back(new TypeCombattantClass{ "Chevalier", PlayerKnight(idPlayer, namePlayer, pvMax, attackMax, attack, defenseMax, defense, manaMax) });

			
		}

		std::string  guardian("guardian");
		if (personnages.find(guardian) != personnages.end()) {
			std::map<std::string, int>& attributs = personnages[guardian];
				int pvMax = attributs["pvMax"];
				int attackMax = attributs["attackMax"];
				int attack = attributs["attack"];
				int defenseMax = attributs["defenseMax"];
				int defense = attributs["defense"];
				int manaMax = attributs["manaMax"];

				combattants.push_back(new TypeCombattantClass{ "Gardien", PlayerGuardian(idPlayer, namePlayer, pvMax, attackMax, attack, defenseMax, defense, manaMax) });

			
		}
		fichier.close();
		do {
			std::cout << namePlayer << ", choisissez un type de combattant : " << std::endl;
			int index = 1;
			for (const TypeCombattantClass* combattant : combattants) {
				std::cout << index << "." << combattant->name << std::endl;
				index++;
			}

			std::cin >> chosenType;
			index = 1;
			for (const TypeCombattantClass* combattant : combattants) {
				if (chosenType == combattant->name || chosenType == std::to_string(index)) {
					return combattant->type;
				}
				index++;
			}
			std::cout << "Saisie invalide. Reessayez." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("cls");
		} while (true);
	}
	else {
		std::cerr << "Impossible d'ouvrir le fichier " << classFile << std::endl;
	}
}

std::string GameLoop::askAction(std::vector<std::string> actions) {
	std::string chosenAction;

	do {

		std::cout << "Choisissez une action: " << std::endl;
		int index = 1;
		for (const std::string action : actions) {
			std::cout << index << "." << action << std::endl;
			index++;
		}
		std::cin >> chosenAction;
		std::cout << "\n" << std::endl;
		index = 1;
		for (const std::string action : actions) {
			if (chosenAction == action || chosenAction == std::to_string(index)) {
				std::cout << "Vous avez choisi " << action << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				system("cls");
				return action;
			}
			index++;
		}
		std::cout << "\n" << std::endl;

		std::cout << "Saisie invalide. Reessayez." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
	} while (true);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
}


Spell GameLoop::askSpell(std::vector<Spell> spells) {
	std::string chosenSpell;

	do {
		std::cout << "Choisissez un spell: " << std::endl;
		int index = 1;
		for (Spell spell : spells) {
			std::cout << index << "." << spell.getName() << std::endl;
			index++;
		}
		std::cout << "5.Retour (menu action)" << std::endl;
		std::cout << "\n" << std::endl;

		std::cin >> chosenSpell;
		index = 1;
		for (Spell spell : spells) {
			if (chosenSpell == spell.getName() || chosenSpell == std::to_string(index)) {
				return spell;
			}
			index++;
		}

		if (chosenSpell == "Retour" || chosenSpell == "5") break;
		std::cout << "Saisie invalide. Reessayez." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
	} while (true);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	system("cls");
}

void GameLoop::statsPlayer(PlayerAbstract player) {
	player.afficherInfos();
}

void GameLoop::winOrLose(std::string nameWinnerPlayer, std::string nameLoserPlayer) {
	std::cout << nameWinnerPlayer << " a gagne la partie et " << nameLoserPlayer << " a perdu" << std::endl;
}




bool GameLoop::startAgain() {
	std::string response;
	bool stopPlaying = false;
	do {
		std::cout << "Voulez-vous relancer une partie? ";
		std::cin >> response;

		// Verification de la validite de la saisie (par exemple, si la longueur est superieure à 3 caractères)
		if (response == std::string("yes") || response == std::string("Yes") || response == std::string("Y") || response == std::string("y")) {
			std::cout << "Merci d'avoir joue!" << std::endl;
			stopPlaying = true;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else if (response == std::string("no") || response == std::string("No") || response == std::string("N") || response == std::string("n")) {
			std::cout << "C'est partie pour un nouveau tour!" << std::endl;
			break;  // Sort de la boucle lorsque la saisie est valide
		}
		else {
			std::cout << "Saisie invalide. Reessayez." << std::endl;
			// Efface le tampon d'entree pour eviter des boucles infinies si l'utilisateur entre des caractères non valides
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
	} while (true);
	system("cls");
	return stopPlaying;
}

void readFile() {

}

GameLoop::~GameLoop() {}