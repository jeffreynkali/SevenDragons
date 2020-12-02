#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "Table.h"
#include "Deck.h"
#include "AnimalCardFactory.h"
#include "Player.h"
#include "Hand.h"


int main(){
	Table table;
	AnimalCardFactory* factory = AnimalCardFactory::getFactory();
	Deck<std::shared_ptr<AnimalCard>> deck = factory->getDeck();
	int nbPlayers;
	char answer;
	int cardNumber, row, col;
	int extraCards; 
	bool isLegal{ true };
	std::string name[5];

	//we create a vector with the objective annimals and randommize it
	//so that the player numbers associated with these positions do not always have
	//same animal
	std::vector<std::string> animals{"bear", "deer", "hare", "moose", "wolf"};
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(animals.begin(), animals.end(), g);

	//srand(time(NULL));
	std::cout << "Souhaitez vous continuer a partir d'une partie sauvegardee (O/N) :" << std::endl;
	std::cin >> answer;

	if (answer == 'O' || answer == 'o'){
		//load from file
		try{
			std::ifstream inputFile("gameParameters.txt");
			std::string line;
			std::string dummyLine;
			int i = 0;
			inputFile >> nbPlayers;

			std::getline(inputFile, dummyLine);
			while (std::getline(inputFile, line) && i < nbPlayers){
				std::istringstream iss(line);
				iss >> name[i] >> animals[i];
				i++;
			}
			table.read(inputFile);
		}
		catch (std::exception ex){
			std::cout << "Une exception a ete lancee : "<<ex.what()<<std::endl;
		}
	}
	else{
		do{
			std::cout << "Veuillez saisir le nombre de joueurs qui participeront a la partie(2-5) :" << std::endl;
			std::cin >> nbPlayers;
		} while (nbPlayers < 2 || nbPlayers > 5);
		

		for (int i = 0; i < nbPlayers; i++){
			std::cout << "Veuillez saisir le nom du joueur # " << i + 1 << ":" << std::endl;
			std::cin >> name[i];
		}
	}
	
	std::shared_ptr<Player> p1(new Player(name[0], animals[0]));
	table.addPlayer(p1);
	std::shared_ptr<Player> p2(new Player(name[1], animals[1]));
	table.addPlayer(p2);

	if (nbPlayers == 2){
		for (int k = 0; k < 3; k++) {
			p1->getHand()->operator+=(deck.draw());
			p2->getHand()->operator+=(deck.draw());
		}
	}
	if (nbPlayers == 3){
		std::shared_ptr<Player> p3(new Player(name[2], animals[2]));
		table.addPlayer(p3);
		for (int k = 0; k < 3; k++) {
			p1->getHand()->operator+=(deck.draw());
			p2->getHand()->operator+=(deck.draw());
			p3->getHand()->operator+=(deck.draw());
		}
	}
	if (nbPlayers == 4){
		std::shared_ptr<Player> p3(new Player(name[2], animals[2]));
		table.addPlayer(p3);
		std::shared_ptr<Player> p4(new Player(name[3], animals[3]));
		table.addPlayer(p4);
		for (int k = 0; k < 3; k++) {
			p1->getHand()->operator+=(deck.draw());
			p2->getHand()->operator+=(deck.draw());
			p3->getHand()->operator+=(deck.draw());
			p4->getHand()->operator+=(deck.draw());
		}
	}
	if (nbPlayers == 5){
		std::shared_ptr<Player> p3(new Player(name[2], animals[2]));
		table.addPlayer(p3);
		std::shared_ptr<Player> p4(new Player(name[3], animals[3]));
		table.addPlayer(p4);
		std::shared_ptr<Player> p5(new Player(name[4], animals[4]));
		table.addPlayer(p5);
		for (int k = 0; k < 3; k++) {
			p1->getHand()->operator+=(deck.draw());
			p2->getHand()->operator+=(deck.draw());
			p3->getHand()->operator+=(deck.draw());
			p4->getHand()->operator+=(deck.draw());
			p5->getHand()->operator+=(deck.draw());
		}


	}



	bool win{ false };
	while (!win){
		
		std::cout << "Voulez vous mettre le jeu en pause(O/N) ? " << std::endl;
		std::cin >> answer;
		if (answer == 'O' || answer == 'o'){
			try{
				std::ofstream outputFile;
				outputFile.open("gameParameters.txt", std::ofstream::trunc);
				outputFile << nbPlayers << std::endl;
				for (int i = 0; i < nbPlayers; i++){
					outputFile << table.getPlayers().at(i)->getName() << " " << table.getPlayers().at(i)->getSecretAnimal() << std::endl;
				}
				table.write(outputFile);
			}
			catch (std::exception ex){
				std::cout << "une exception a ete lancee : " << ex.what() << std::endl;
			}
			break;
		}

			for (int i = 0; i < nbPlayers; i++){
				table.print();
				table.getPlayers().at(i)->getHand()->operator+=(deck.draw());
				table.getPlayers().at(i)->print();
				std::cout << std::endl<< "Veuillez selectionner le numero d'une carte de votre main a jouer:(l'index debute a 0)" << std::endl;
				std::cin >> cardNumber;

				//If the card played is an action card
				if ((table.getPlayers().at(i)->getHand()->operator[](cardNumber))->getAnimalChar(0) == 'B'
					||
					(table.getPlayers().at(i)->getHand()->operator[](cardNumber))->getAnimalChar(0) == 'D'
					||
					(table.getPlayers().at(i)->getHand()->operator[](cardNumber))->getAnimalChar(0) == 'H'
					||
					(table.getPlayers().at(i)->getHand()->operator[](cardNumber))->getAnimalChar(0) == 'M'
					||
					(table.getPlayers().at(i)->getHand()->operator[](cardNumber))->getAnimalChar(0) == 'W')
				{
					switch ((table.getPlayers().at(i)->getHand()->operator[](cardNumber))->getAnimalChar(0))
					{
					case 'B':{
						std::shared_ptr<AnimalCard> a;
						std::shared_ptr<BearAction> b;
						a = table.getPlayers().at(i)->getHand()->operator[](cardNumber);
						b = std::dynamic_pointer_cast<BearAction>(a);
						//print out the lsit of players with therir numbers
						std::cout << std::endl;
						for (int k = 0; k < nbPlayers; k++){
							std::cout << "joueur #" << k << " :" << name[k] << std::endl;
						}
						QueryResult q = b->query();
						b->perform(table, table.getPlayers().at(i).get(), q);
						//after using the actionCard we remove it from the player's hand
						table.getPlayers().at(q.getReply1())->getHand()->operator-=(a);
						break;
					}
						

					case 'D':{
						std::shared_ptr<AnimalCard> a;
						std::shared_ptr<DeerAction> d;
						a = table.getPlayers().at(i)->getHand()->operator[](cardNumber);
						d = std::dynamic_pointer_cast<DeerAction>(a);
						//print out the lsit of players with therir numbers
						std::cout << std::endl;
						for (int k = 0; k < nbPlayers; k++){
							std::cout << "joueur #" << k << " :"<<name[k] << std::endl;
						}
						d->perform(table, table.getPlayers().at(i).get(), d->query());
						//after using the actionCard we remove it from the player's hand
						table.getPlayers().at(i)->getHand()->operator-=(a);
						break;
					}
						

					case 'H':{
						std::shared_ptr<AnimalCard> a;
						std::shared_ptr<HareAction> h;
						a = table.getPlayers().at(i)->getHand()->operator[](cardNumber);
						h = std::dynamic_pointer_cast<HareAction>(a);
						do{
							isLegal = true;
							try{
								h->perform(table, table.getPlayers().at(i).get(), h->query());
							}
							catch (MyException ex){
								ex.print();
								isLegal = false;
							}
						} while (!isLegal);
						//after using the actionCard we remove it from the player's hand
						table.getPlayers().at(i)->getHand()->operator-=(a);
						break; 
					}
						

					case 'M':{
						std::shared_ptr<AnimalCard> a;
						std::shared_ptr<MooseAction> m;
						a = table.getPlayers().at(i)->getHand()->operator[](cardNumber);
						m = std::dynamic_pointer_cast<MooseAction>(a);
						m->perform(table, table.getPlayers().at(i).get(), m->query());
						//after using the actionCard we remove it from the player's hand
						table.getPlayers().at(i)->getHand()->operator-=(a);
						break;
					}
						

					case 'W':{
						std::shared_ptr<AnimalCard> a;
						std::shared_ptr<WolfAction> w;
						a = table.getPlayers().at(i)->getHand()->operator[](cardNumber);
						w = std::dynamic_pointer_cast<WolfAction>(a);
						do{
							isLegal = true;
							try{
								w->perform(table, table.getPlayers().at(i).get(), w->query());
							}
							catch (MyException ex){
								ex.print();
								isLegal = false;
							}
						} while (!isLegal);
						//after using the actionCard we remove it from the player's hand
						table.getPlayers().at(i)->getHand()->operator-=(a);
						break;
					}
						
					}
						
				}
				else{
					do{
						std::cout << std::endl<<"Voulez vous passer votre tour(O/N) ? :" << std::endl;
						std::cin >> answer;
						if (answer == 'O' || answer == 'o')break;
						isLegal = true;
						try{
							std::cout << std::endl<<"a quelle ligne souhaitez vous jouer la carte(row#):" << std::endl;
							std::cin >> row ;
							std::cout << std::endl << "a quelle colonne souhaitez vous jouer la carte(col#):" << std::endl;
							std::cin >> col;
							extraCards = table.addAt((table.getPlayers().at(i)->getHand()->operator[](cardNumber)), row, col);
							//we remove the card from the player's hand
							table.getPlayers().at(i)->getHand()->operator-=((table.getPlayers().at(i)->getHand()->operator[](cardNumber)));
							for (int c = 0; c < extraCards; c++)table.getPlayers().at(i)->getHand()->operator+=(deck.draw());
						}
						catch (MyException ex){
							//if an exception is caught it's because the placement was illegal
							//because within this snippet of code the only method throwing a myException Error
							//is table.addAt()
							ex.print();
							isLegal = false;
						}
						
					} while (!isLegal);
					
				}
			
				//let's verify if one player has won
				if (table.win(animals[0]) || table.win(animals[1]) || table.win(animals[2]) || table.win(animals[3]) || table.win(animals[4]))break;
			
		}
	}

	//now let's find which player won
	for (int i = 0; i < nbPlayers; i++){
		if (table.win(table.getPlayers().at(i)->getSecretAnimal())){
			std::cout << std::endl << "le joueur #" << i << ", " << name[i] << " d'animal secret :" << table.getPlayers().at(i)->getSecretAnimal() << " a gagne la partie" << std::endl;
			win = true;
			break;
		}
	}
	
	system("pause");
	return 0;
}
