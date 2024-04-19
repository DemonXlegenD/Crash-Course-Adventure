// PROJECT 1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <iomanip>

#include "PlayerAbstract.h"
#include "GameLoop.h"
#include "GameConfig.h"
#include "Team.h"
#include "Object.h"
#include "./Utils/Loading.h"

// Fonction pour afficher un cadre de longueur donnée avec "|"
void afficherCadreCote(int hauteur) {
	for (int i = 0; i < hauteur; i++) {
		std::cout << "|" << std::setw(78) << "|" << std::endl;
	}
}

// Fonction pour afficher un cadre de longueur donnée avec "-"
void afficherCadreHautBas(int longueur) {
	for (int i = 0; i < longueur; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}

// Fonction pour afficher les statistiques du joueur
void afficherStatsJoueur(int pv, int attaque, int defense, int playerNbr) {
	if (playerNbr == 1) {
		std::cout << "| PV: " << std::left << std::setw(73) << pv << "|" << std::endl;
		std::cout << "| Attaque: " << std::left << std::setw(68) << attaque << "|" << std::endl;
		std::cout << "| Defense: " << std::left << std::setw(68) << defense << "|" << std::endl;
	}
	else {
		std::cout << "|" << std::right << std::setw(75) << "PV: " << pv << "| " << std::endl;
		std::cout << "|" << std::right << std::setw(76) << "Attaque: "<< attaque << "| " << std::endl;
		std::cout << "|" << std::right << std::setw(75) << "Defense: "<< defense << "| " << std::endl;
	}
}

// Fonction pour afficher les actions disponibles
void afficherActions(const std::string& actions) {
	afficherCadreCote(2);
	std::cout << "| Actions disponibles :               |" << std::endl;
	std::cout << "|" << std::left << std::setw(78) << actions << "|" << std::endl;
	afficherCadreCote(2);
}

// Fonction pour afficher les logs de combat
void afficherLogsDeCombat(const std::string& logs) {
	afficherCadreCote(2);
	std::cout << "| Logs de combat :                   |" << std::endl;
	std::cout << "|" << std::left << std::setw(78) << logs << "|" << std::endl;
	afficherCadreCote(2);
}

int main()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); // Change la couleur du texte en rouge vif

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int consoleWidth;

	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
		consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	}
	else {
		consoleWidth = 80; // Valeur par défaut si la récupération de la largeur échoue
	}

	// Texte à afficher
	std::string studio = "The Lab & Co!\n";
	std::string title = "Crash Course Adventure!\n";;

	// Calculer la position de début pour centrer le texte
	int startPosStudio = (consoleWidth - studio.length()) / 2;
	int startPosTitle = (consoleWidth - title.length()) / 2;

	// Afficher le texte centré
	for (int i = 0; i < startPosStudio; i++) {
		std::cout << " ";
	}
	std::cout << studio << std::endl;
	for (int i = 0; i < startPosTitle; i++) {
		std::cout << " ";
	}
	std::cout << title << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); // Rétablir la couleur par défaut

	std::this_thread::sleep_for(std::chrono::seconds(1));
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Change la couleur du texte en vert vif
	std::string texteIntro = "Ce jeu est un crash test et donc n'est pas totalement termine...";
	int delai = 100; // Délai en millisecondes (100 ms = 0,1 seconde)

	for (char c : texteIntro) {
		std::cout << c;
		Sleep(delai);
	}

	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	loading(3);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); // Change la couleur du texte en bleu vif

	int numberPlayer = GameLoop::askNumberPlayer();
	int numberTeams = 2;
	std::vector<PlayerAbstract> players;
	
	std::vector<Team> teams;
	for (int i = 0; i < numberTeams; i++) {
		loading(3);
		std::string name(GameLoop::askNameTeam("Team " + std::to_string(i + 1)));
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::vector<PlayerAbstract> playersTeam;

		for (int j = 0; j < numberPlayer / 2; j++) {
			std::string name(GameLoop::askName("Joueur " + std::to_string((j + 1) * (i + 1))));
			std::this_thread::sleep_for(std::chrono::seconds(1));
			PlayerAbstract player(GameLoop::askType("Joueur " + std::to_string((j + 1) * (i + 1)), name));
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system("cls");
			playersTeam.push_back(player);
			players.push_back(player);

			playersTeam[j].afficherInfos();
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		teams.push_back(Team(name, playersTeam));
	}

	system("cls");
	loading(3);


	GameConfig config(teams[0], teams[1], players);

	std::vector<std::string> actions;
	actions.push_back(std::string("spell"));
	actions.push_back(std::string("surrend"));
	actions.push_back(std::string("inventaire"));

	std::vector<Object> inventory;

	players[0].addSpellToList();
	players[1].addSpellToList();

	std::string winner;
	std::string loser;

	do {
		do {
			std::cout << "Combattez\n" << std::endl;

			do {
				std::cout << "Au tour du " << players[0].getId() << " : " << players[0].getName() << ".\n" << std::endl;


				std::cout << "Choisir une action a faire" << std::endl;
				std::string action(GameLoop::askAction(actions));
				if (action == actions[0]) {
					Spell spell(GameLoop::askSpell(players[0].getSpellList()));
					if (spell.getType() == "offensive") {
						players[1].getDamage(spell.getDamage());
						break;
					}
					else if (spell.getType() == "defensive") {
						players[0].setActualDefense(players[0].getActualDefense() + spell.getDamage());
						break;
					}
					else if (spell.getType() == "buff") {
						players[0].setActualAttack(players[0].getActualAttack() + spell.getDamage());
						break;
					}
					else if (spell.getType() == "ultimate") {
						players[1].getDamage(2 * spell.getDamage());
						break;
					}
					else {
						std::cout << "Retour au menu actions" << std::endl;
					}
				}
				else if (action == std::string("surrend")) {
					players[0].setActualPv(0);
					break;
				}
				else if (action == actions[2]) {
					std::cout << "invenaire vide, retour au menu" << std::endl;
				}
				system("cls");
			} while (true);
			players[0].afficherInfos();
			players[1].afficherInfos();
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
			if (players[0].getActualPv() <= 0 || players[1].getActualPv() <= 0) {
				break;
			}

			do {
				std::cout << "Au tour du " << players[1].getId() << " : " << players[1].getName() << ".\n" << std::endl;

				std::cout << "Choisir une action a faire" << std::endl;
				std::cout << std::endl;
				std::string action(GameLoop::askAction(actions));
				if (action == actions[0]) {
	
					Spell spell(GameLoop::askSpell(players[1].getSpellList()));
					if (spell.getType() == "offensive") {
						players[0].getDamage(spell.getDamage());
						break;
					}
					else if (spell.getType() == "defensive") {
						players[1].setActualDefense(players[1].getActualDefense() + spell.getDamage());
						break;
					}
					else if (spell.getType() == "buff") {
						players[1].setActualAttack(players[1].getActualAttack() + spell.getDamage());
						break;
					}
					else if (spell.getType() == "ultimate") {
						players[0].getDamage(2 * spell.getDamage());
						break;
					}
					else {
						std::cout << "Retour au menu actions" << std::endl;
					}
				}
				else if (action == actions[1]) {
					players[1].setActualPv(0);
					break;
				}
				else if (action == actions[2]) {
					std::cout << "invenaire vide, retour au menu" << std::endl;
				}
				system("cls");
			} while (true);
			players[0].afficherInfos();
			players[1].afficherInfos();
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		} while (players[0].getActualPv() > 0 && players[1].getActualPv() > 0);
		if (players[0].getActualPv() < 0) {
			winner = players[1].getName();
			loser = players[0].getName();
		}
		else {
			winner = players[0].getName();
			loser = players[1].getName();
		}
		GameLoop::winOrLose(loser, winner);
	} while (GameLoop::startAgain());
	return 0;
}
