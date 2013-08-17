
#include "Room.h"
/**
 * Create a room described "description". Initially, it has no exits.
 * "description" is something like "a kitchen" or "an open court yard".
 */



Room::Room(string desc,string longDesc) {
	this->desc = desc;
	this->longDesc = longDesc;
	
}

/**
 * Define the exits of this room.  Every direction either leads to
 * another room or is null (no exit there).
 */
void Room::setExits(Room *north, Room *east, Room *south, Room *west,Room *up,Room *down) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
	if (up != NULL)
		exits["up"] = up;
	if (down != NULL)
		exits["down"] = down;
}

/**
 * Return the description of the room (the one that was defined in the
 * constructor).
 */
string Room::description() 
{
	if(beenHere == true)
	{
		return "\n\nYou are in " + desc + ".\n"+ exitString() ;
	}else{
		return "\n\nYou are in " + desc + ".\n"+ longDesc + ".\n"+exitString() ;
	}
}

string Room::longDescription()
{
	return longDesc;
}
/**
 * Return a string describing the room's exits, for example
 * "Exits: north west ".
 */
string Room::exitString() {
	string returnString = "\nExits:";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += " " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

void Room::iBeenHere()
{
	beenHere = true ;
}

bool Room::wasIhere()
{
	return beenHere;
}

/**
 * Return the room that is reached if we go from this room in direction
 * "direction". If there is no room in that direction, return null.
 */
Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item* item)
{
	items.push_back(item) ;
}


void Room::remove(string name)
{
	for(unsigned int j = 0 ; j < items.size() ; j++)
	{
		if(name == items[j]->getDesc())
		{
			items.erase(items.begin()+j) ;
			break;
		}
		if(j == items.size())
		{
			cout << "\nThat item isn't in this room.\n" ;
		}
	}
}

void Room::display()
{
	for(unsigned int i = 0 ; i < items.size() ; i++)
	{
		cout << "There is a " <<items[i]->getDesc() << " on the floor" << endl ;
	}
}

bool Room::getItem(string desc)
{
	bool in = false;
	for(unsigned int i = 0; i < items.size() ; i++)
	{
		if(items[i]->getDesc().compare(desc) == 0)
		{
			in = true ;
		}
	}
	
	return in ;
}
