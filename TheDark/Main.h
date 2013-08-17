#ifndef MAIN_H_
#define MAIN_H_
#include <algorithm>
#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Player.h"
#include "Map2.h"
#include "Item.h"
#include "Lamp.h"
#include "Knapsack.h"
#include "Knife.h"

#include <iostream>
#include <string>

using namespace std;

class Main {
private:
	Parser parser;
	Room *currentRoom ,*street,*study,*playRoom,*hall1,*hall2,*kitchen,*stairsRoom,*livingRoom,*masterRoom,*guestRoom,*bathroom,*kidsRoom,*upHall1,*upHall2,
		*gardenShed,*backGarden ,*attic;
	
	Item *rustyKey,*shedKey,*diary,*aomDisc,*shovel,*stool,*fork ,*soap,*paper ;
	Lamp *lamp ;
	Knife *knife ;
	Player *player;
	Knapsack *knap;
	bool inLivingRoom;
	bool manOnStairs;
	bool gardenDig;
	bool atticEvent;
	void createRooms();
	void createItems();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
	Map2 *map2;

public:
	Main();
	void play();
	string go(string direction);
	
};

#endif 
