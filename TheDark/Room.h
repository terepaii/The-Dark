#ifndef ROOM_H_
#define ROOM_H_

#include "Item.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

class Room {
private:
	vector<Item*> items ;
	string desc;
	string longDesc ;
	map<string, Room*> exits;
	bool beenHere ;

public:
	
	Room(string description,string longDesc);
	void setExits(Room *north, Room *east, Room *south, Room *west,Room *up,Room *down);
	void addItem(Item* item); 
    void remove(string name) ;
	void display() ;
	bool getItem(string name) ;
	string description();
	Room* nextRoom(string direction);
	void iBeenHere() ;
	bool wasIhere() ;
	string exitString();
	string longDescription() ;
};

#endif /*ROOM_H_*/
