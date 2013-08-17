#include "CommandWords.h"

vector<string> CommandWords::validCommands;

/**
 * Constructor - initialise the command words.
 */
CommandWords::CommandWords() {
	if (validCommands.empty()) {
		validCommands.push_back("go");
		validCommands.push_back("quit");
		validCommands.push_back("help");
		validCommands.push_back("use");
		validCommands.push_back("take");
		validCommands.push_back("read");
		validCommands.push_back("input") ;
		validCommands.push_back("drop");
		validCommands.push_back("crawl");
		validCommands.push_back("toggle");
		validCommands.push_back("map");
		validCommands.push_back("run");
		validCommands.push_back("turn");
		validCommands.push_back("totalmap");
		validCommands.push_back("play");
		validCommands.push_back("drop");
		validCommands.push_back("take");
		validCommands.push_back("open");
		validCommands.push_back("look");
		validCommands.push_back("finish");
		validCommands.push_back("knapsack");
	}
}

/**
 * Check whether a given String is a valid command word. 
 * Return true if it is, false if it isn't.
 **/
bool CommandWords::isCommand(string aString) {
	for (unsigned int i = 0; i < validCommands.size(); i++)
	{
		if (validCommands[i].compare(aString) == 0)
			return true;
	}
	// if we get here, the string was not found in the commands
	return false;
}

/*
 * Print all valid commands to System.out.
 */
void CommandWords::showAll() {
	//Loops through validCommands and prints each to the screen.
	for (unsigned int i = 0; i < validCommands.size(); i++)
	{
		cout << validCommands[i]<< "  ";
	}
	cout << endl;
}
