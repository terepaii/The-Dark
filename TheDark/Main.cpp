#include "Main.h"

#include <algorithm>



int main(int argc, char argv[]) {
	Main temp;
	temp.play();
	return 0;
}

Main::Main() {
	// create some rooms
    knap = new Knapsack() ;
	createRooms();
	createItems();
	map2 = new Map2() ;
	inLivingRoom = false ;		//These boolean variables act as a checklist of events, once the corresponding event has occurred, they change to true.
	manOnStairs = false ;
	gardenDig = false ;
}

void Main::createRooms() {
	

	// create the rooms
	
    study = new Room("the study","The walls are lined with dusty bookshelves, there is a desk with a computer on it") ;
	playRoom = new Room("the play room","It is scattered with toys,it looks as if it has not been disturbed in a long time.There is a crawl space in the corner of the room");
	hall1 = new Room("the hall","The wallpaper is peeling off the walls, picture frames have fallen to the floor,there are doors to the west and east, the hallway also continues further north") ;
	hall2 = new Room("the hall","There is a door to the north which is slightly ajar, it looks like the kitchen. There is also a door to the east and a stairs the to the west. There is a small door under the stairs with a rusty lock") ;
	kitchen = new Room("the kitchen","There is mould in the sink and cutlery strewn about the floor.There is a door to the east which leads outside") ;
	stairsRoom = new Room("the room under the stairs","It is very confined. There is torn piece of paper, it appears to be unreadable") ;
	livingRoom = new Room("the living room","Facing you is a huge mirror hanging on the wall") ;
	street = new Room("the street","Walking past an eerie manor you hear the sobbing of a little girl, hesitantly you make your way to the door to investigate further") ;
	masterRoom = new Room("the master bedroom","There is a grand bed in the centre of the room, there is also a safe in the corner of the room") ;
	guestRoom = new Room("the guest room","There is nothing of interest in this room") ;
	bathroom = new Room("the bathroom","Ugh, it hasn't been cleaned in a while") ;
	kidsRoom = new Room("the kids' room","It appears to have not been used in a long time") ;
	upHall1 = new Room("the upstairs hall","There are doors to the east and west, the hall continues further south") ;
	upHall2 = new Room("the upstairs hall","There are doors to the east and west") ;
	gardenShed = new Room("the garden shed","It is full of gardening equipment,it is not much use") ;
	backGarden =new Room("the backgarden","A path leads north to a garden shed. There is a patch of disturbed earth near the shed") ;
	attic = new Room("the attic", "On a table in the middle of the room lies a torn piece of paper matching the piece you found earlier. As soon as you put the two together, a voice creeps from behind you...\"Who are you?\"\n\n\nTO BE CONTINUED... \n\n Type \"quit\" to end game." );

	// initialise room exits
	study->setExits(NULL,hall1,NULL,NULL,NULL,NULL) ;
	playRoom->setExits(NULL,NULL,NULL,hall1,NULL,NULL) ;
	hall1->setExits(hall2,playRoom,NULL,study,NULL,NULL) ;
	hall2->setExits(kitchen,livingRoom,hall1,NULL,upHall1,NULL);
	kitchen->setExits(NULL,backGarden,hall2,NULL,NULL,NULL);
	stairsRoom->setExits(NULL,hall2,NULL,NULL,NULL,NULL);
	livingRoom->setExits(NULL,NULL,NULL,hall2,NULL,NULL) ;
	street->setExits(hall1,NULL,NULL,NULL,NULL,NULL) ;
	upHall1->setExits(NULL,guestRoom,upHall2,masterRoom,NULL,hall2) ;
	upHall2->setExits(upHall1,kidsRoom,NULL,bathroom,NULL,NULL) ;
	masterRoom->setExits(NULL,upHall1,NULL,NULL,NULL,NULL) ;
	guestRoom->setExits(NULL,NULL,NULL,upHall1,NULL,NULL) ;
	kidsRoom->setExits(NULL,NULL,NULL,upHall2,NULL,NULL) ;
	bathroom->setExits(NULL,upHall2,NULL,NULL,NULL,NULL) ;
	gardenShed->setExits(NULL,NULL,backGarden,NULL,NULL,NULL) ;
	backGarden->setExits(NULL,NULL,NULL,kitchen,NULL,NULL) ;
	attic->setExits(NULL,NULL,NULL,NULL,NULL,NULL) ;

	currentRoom = street; 
}

void Main::createItems() {
	//creates items
	rustyKey = new Item("rusty-key" , 0.5,true,false) ;
	shedKey = new Item("shed-key", 0.5,true,false) ;
	shovel = new Item("shovel" , 4,true,false) ;
	soap = new Item("soap" , 0.5,true,false) ;
	diary = new Item("diary" , 1,true,false) ;
	stool = new Item("stool" , 3,true,false) ;
	knife = new Knife("knife" , 1,true,false) ;
	fork = new Item("fork" , 1,true,false) ;
	aomDisc = new Item("aom-disc",1,true,false) ;
	lamp = new Lamp("lamp" ,2,true,false) ;
	paper = new Item("paper",0.5,true,true);
	
	//add items to rooms
	study->addItem(aomDisc) ;
	study->addItem(diary) ;	
	playRoom->addItem(shovel) ;
	kitchen->addItem(fork) ;
	kitchen->addItem(knife) ;	
	gardenShed->addItem(lamp) ;
	bathroom->addItem(soap) ;
	kidsRoom->addItem(stool) ;
	stairsRoom->addItem(paper) ;
	
}



void Main::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the Main game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << "Thank you for playing. Good bye." << endl;
}

/**
 * Print out the opening message for the player.
 */
void Main::printWelcome() {
	cout << endl;
	cout << "//////////////////////////////////////////////////////////"<< endl;
	cout << "//  ####### #  #  ####     ###    #####  #####   #   #  //"<< endl;
	cout << "//     #    #  #  #        #  #   #   #  #   #   #  #   //"<< endl;
	cout << "//     #    ####  ###      #   #  #####  ####    ###    //"<< endl;
	cout << "//     #    #  #  #        #  #   #   #  #   #   #  #   //"<< endl;
	cout << "//     #    #  #  ####     ###    #   #  #    #  #   #  //"<< endl;
	cout << "//////////////////////////////////////////////////////////"<< endl;
	cout << "Type \"help\" for help." << endl;
	cout << endl;
	cout << currentRoom->description() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the Main game, true is returned, otherwise false is
 * returned.
 */
bool Main::processCommand(Command command) {
	
	if (command.isUnknown()) {
		cout << "Huh?"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("help") == 0)
		printHelp();
	else if (commandWord.compare("go") == 0)
		goRoom(command);
	else if (commandWord.compare("crawl") == 0 && currentRoom == playRoom) //if you type "crawl" and you are in the play room it will enter the if.
	{
		if (!command.hasSecondWord())
		{
			if(knap->getItem("lamp") == true )  //if you have a lamp in knapsack
			{
				if(lamp->isOn() == true) //if lamps is on
				{
					cout << "You crawl into the crawlspace. You find a rusty key! You crawl back out." << endl ;
					knap->add(rustyKey) ;
				}else{//if lamp isn't on
					cout << "You can't see anything, you crawl back out. Maybe you should turn on your lamp.(toggle)" << endl ;
				}
			}else{
				cout << "You can't see anything, you crawl back out." << endl ;
			}
		}
			
	}
	else if (commandWord.compare("toggle") == 0 && currentRoom == playRoom)//checks room
	{
		if (!command.hasSecondWord())//if there is no second word
		{
			if(knap->getItem("lamp") == true )//if lamp is in inventory
			{
				lamp->toggle() ;// turns on the lamp
			}
		}else if(command.getSecondWord().compare("lamp") == 0){//if the second word is "lamp"
			lamp->toggle() ;//turns on lamp
		}else{
			cout << "Computer says no." << endl ;//if second word is something other than lamp
		}
		
	}
	else if (commandWord.compare("read") == 0)
	{
		if (!command.hasSecondWord())
			cout << "Read what?"<< endl;//if there is no second work in command
		else if(command.getSecondWord().compare("diary") == 0){
		
			if(knap->getItem("diary") == true)//if second word is "diary" and you have a diary
			{
				map2->mbook() ;//prints out damo's beautiful ascii diary
			}
		}else if(command.getSecondWord().compare("paper") == 0){//if second work is paper
			if(knap->getItem("paper") == true)//if you have the piece of paper
			{
				cout << "It's torn in half, it's unreadable" << endl ; 
			}
		}else{
			cout << "No." << endl ;//if second word is something else
		}
	}
	else if (commandWord.compare("input") == 0 && currentRoom == masterRoom)//for inputting code into safe
	{
		if (!command.hasSecondWord())
			cout << "Input what?"<< endl;
		else if(command.getSecondWord().compare("joanna") == 0 )// if second word of command is the code for the safe
		{
			cout << "The safe pops open. There is a lever in the safe, you pull it...You hear a noise out in the hallway!" << endl ;
			atticEvent = true ; //the attic event has no occured
			upHall1->setExits(NULL,guestRoom,upHall2,masterRoom,attic,hall2) ; //adds a new exit to the hall to go up to the attic
		}else{
			cout << "WRONG!" << endl ;//if the code is wrong
		}
	}
	else if (commandWord.compare("open") == 0)
	{
		if (!command.hasSecondWord())
			cout << "Open what?"<< endl;
		else if(command.hasSecondWord())
		{
			if(command.getSecondWord().compare("door") == 0)
			{
				if(currentRoom == hall2)//if you are in the hall2(where the door is under the stairs)
				{
					if(knap->getItem("rusty-key") == true)//if you have the key
					{
						cout << "With some effort, you manage to turn the rusty key in the door and it opens." << endl;
						currentRoom = stairsRoom ; 
						cout << currentRoom->description() << endl ;
						hall2->setExits(kitchen,livingRoom,stairsRoom,hall1,NULL,NULL) ;//adds new exit from hall
					}else{
						cout << "The door is locked, it looks rusty.If you had a key you could open it." << endl;
					}
				}else if(currentRoom == backGarden){//same as before but for the shed door
					if(knap->getItem("shed-key") == true)
					{
						cout << "You wipe the decaying flesh off the key and unlock the shed door." << endl;
						backGarden->setExits(gardenShed,NULL,NULL,kitchen,NULL,NULL) ;
					}else{
						cout << "It's locked! You need a key." <<endl;
					}
				}
			}else if(command.getSecondWord().compare("safe") == 0){//if you try open the safe
				cout << "You need to input the code." << endl ;
			}
		}
	}
	else if (commandWord.compare("knapsack") == 0)
	{
		if(command.hasSecondWord())
		{
			cout << "Computer says no." << endl ;//if there's a second word
		}else{
			knap->display() ;//if there isn't a second word, it displays contents of knapsack
		}
			
	}
	else if (commandWord.compare("use") == 0)
	{
		if(!command.hasSecondWord())
		{
			cout << "Use what?" << endl ;
		}else if(command.getSecondWord().compare("shovel") == 0 && currentRoom == backGarden&& knap->getItem("shovel") == true && gardenDig == false ){//if you have the shovel and you are in the back garden and the event hasn't already happened
			cout << "You use the shovel to dig up the disturbed patch of earth, you expose the remains of a decomposing corpse,It appears to be the remains of a little girl." <<
					"After searching the remains you find a key.\n" ;
			knap->add(shedKey) ;//adds key to knap sack
			gardenDig = true ;//event is ticked off
		}
	}
	else if (commandWord.compare("take") == 0)
	{

		if(!command.hasSecondWord())
		{
			cout << "Take what?" << endl ; //if theres no second word.
		
		}else if(command.getSecondWord().compare("shovel") == 0 && currentRoom->getItem("shovel") == true ){//the rest of the if/else checks if the second word is the same as an item name, and if that item is in the current room
				knap->add(shovel) ;//adds item to knapsack
				currentRoom->remove("shovel") ;//removes from rooms ArrayList<Item>
				
				
			}else if(command.getSecondWord().compare("aom-disc") == 0  && currentRoom->getItem("aom-disc") == true){//the rest are the same as above but for each item
				knap->add(aomDisc) ;
				cout << "Oh, Age of Mythology! My favourite game! " << endl ;
				currentRoom->remove("aom-disc") ;
				
				
			}else if(command.getSecondWord().compare("soap") == 0 && currentRoom->getItem("soap") == true){
				knap->add(soap) ;
				currentRoom->remove("soap") ;
				
				
			}else if(command.getSecondWord().compare("stool") == 0 && currentRoom->getItem("stool") == true){
				knap->add(stool) ;
				currentRoom->remove("stool") ;
				
				
			}else if(command.getSecondWord().compare("fork") == 0 && currentRoom->getItem("fork") == true){
				knap->add(fork) ;
				currentRoom->remove("fork") ;
				
				
			}else if(command.getSecondWord().compare("knife") == 0 && currentRoom->getItem("knife") == true){
				knap->add(knife) ;
				currentRoom->remove("knife") ;
				
				
			}else if(command.getSecondWord().compare("lamp") == 0 && currentRoom->getItem("lamp") == true){
				knap->add(lamp) ;
				currentRoom->remove("lamp") ;
				
				
			}else if(command.getSecondWord().compare("diary") == 0 && currentRoom->getItem("diary") == true){
				knap->add(diary) ;
				currentRoom->remove("diary") ;
				
				
			}else if(command.getSecondWord().compare("paper") == 0 && currentRoom->getItem("paper") == true){
				knap->add(paper) ;
				currentRoom->remove("paper") ;
				
			}else{
				cout << "Huh?" << endl ;//if that item is not in the room/doesnt exist
			}
	}
	else if (commandWord.compare("drop") == 0)//same as take ^^ but does the opposite
	{
		if(!command.hasSecondWord())
		{
			cout << "Drop what?" << endl ;
		}else if(command.getSecondWord().compare("shovel") == 0 ){
				currentRoom->addItem(shovel) ;//adds item to current room's arraylist
				knap->remove("shovel") ;//removes it from knapsack
				currentRoom ->display();//displays whats in the room now
				knap->display() ;//displays your knapsack, for some reason, don't know why I did this
			}else if(command.getSecondWord().compare("paper") == 0 ){
				currentRoom->addItem(paper) ;
				knap->remove("paper") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("aom-disc") == 0 ){
				currentRoom->addItem(aomDisc) ;
				knap->remove("aom-disc") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("soap") == 0 ){
				currentRoom->addItem(soap) ;
				knap->remove("soap") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("stool") == 0 ){
				currentRoom->addItem(stool) ;
				knap->remove("stool") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("fork") == 0 ){
				knap->add(fork) ;
				currentRoom->remove("fork") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("knife") == 0 ){
				currentRoom->addItem(knife) ;
				knap->remove("knife") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("lamp") == 0 ){
				currentRoom->addItem(lamp) ;
				knap->remove("lamp") ;
				currentRoom ->display();
				knap->display() ;
			}else if(command.getSecondWord().compare("diary") == 0 ){
				currentRoom->addItem(diary) ;
				knap->remove("diary") ;
				currentRoom ->display();
				knap->display() ;
			}else{
				cout << "Huh?" << endl ;
			}
	}
	else if (commandWord.compare("look") == 0)
	{
		if(!command.hasSecondWord())
		{
			cout << "Look where?" << endl ;
		}else{

			if(command.getSecondWord().compare("around") == 0)//if you "look around" 
			{
					cout <<"\n\n"<< currentRoom->longDescription() << ".\n" << endl ;//prints rooms long description
					cout << currentRoom->exitString()  << endl ;//prints exits from room
					currentRoom->display() ;//shows what items are in the room
			}else{
				cout << "Huh?" << endl ;
			}
		}
	}
	else if (commandWord.compare("finish") == 0 )
	{
		if(!command.hasSecondWord())
		{
			cout << "Say whaaat?" << endl ;
		}else{

			if(command.getSecondWord().compare("him") == 0 && currentRoom == upHall1 && manOnStairs == false)//our lovely easter egg, you know what happens here
			{																								//if just checks if the event hasnt already happened and if you are in the right room
				if(currentRoom == upHall1)
				{
					cout << "                        .:.-+++++//:-`                      " <<endl;
					cout << "                  `-/- odddyddddddddddhs+:.                 " <<endl;
					cout << "              `/. +sss:./osdoodddddddddddddho-              " <<endl;
					cout << "            :shhy+:.              `-hdddddddddy/`           " <<endl;
					cout << "          :ys:`                     ..-/yhhhhhhhh+`         " <<endl;
					cout << "        .sy.                 -/+/`      `shhhhhhhhh:        " <<endl;
					cout << "       .++`                    `.::`   -syhhhhhhhhhho`      " <<endl;
					cout << "      +y.                               .+ooyhhhhhhhhs`     " <<endl;
					cout << "     oy/                      :osys+:`    `.`.::-:syyys`    " <<endl;
					cout << "    +y+            ..         `.:+syyy+`  --.     -syyyo    " <<endl;
					cout << "   .yy-             :.    .:osso/-`-+yyy+-`       +yyyyy-   " <<endl;
					cout << "   /ys`            `syssssyyyyssyss+.`:+ssso` `-`.sysyss+   " <<endl;
					cout << "   oss`            `sssssssssssssssss+.  .-: --`/osssssss`  " <<endl;
					cout << "   sss              -ssssssssssssssssss+//:-.-/:`osssssss.  " <<endl;
					cout << "  `ss/               `-/+ooossooooo+++++oossssso -sssso:/.  " <<endl;
					cout << "   +:  .                                  `.:+oo- :oooo:`   " <<endl;
					cout << "   :+/+o/                                     ./o` `---.:   " <<endl;
					cout << "   `ooooo/`                                     .+-`-:::.   " <<endl;
					cout << "    :ooooo+`                                     `/+/:/:    " <<endl;
					cout << "     /+++++-             MORTAL KOMBAT            `+++/     " <<endl;
					cout << "     `/++++-  -.                                   /+/      " <<endl;
					cout << "       -/-:. -++` `                                /-       " <<endl;
					cout << "        `::-:+++-.+///:.                          `.        " <<endl;
					cout << "          `://///////////                                   " <<endl;
					cout << "             `-:://///::.                                   " <<endl;//yum
					manOnStairs = true ;
				}
			}
		}

	}
	else if (commandWord.compare("run") == 0)
	{
		if (!command.hasSecondWord())
		{
			if(currentRoom == upHall1 && manOnStairs == false)//this is for the event on the stairs when you can run or turn around
			{
				cout << "You run as fast as you can and burst through the door nearest you and shut it behind you.You press your ear against the door and you can hear footsteps running down the hall." << endl ;
				currentRoom = guestRoom ;//you run into the guest room
				cout << currentRoom->description()  << endl;//prints room desc
				manOnStairs = true ;//event is ticked off
				
			}else{
				cout << "You don't need to run right now!" << endl ;//this prints if you try run at any other point in the game
			}
		}
	}
	else if (commandWord.compare("turn") == 0)//again for stairs event, if you opt to turn around
	{
		if (!command.hasSecondWord())//it can be called by just saying "turn"
		{
			if(currentRoom == upHall1 && manOnStairs == false)
			{
				cout << "You quickly turn around, there is nobody there. The footsteps have stopped. " << endl ;
				manOnStairs = true ;
			}
		}else if( command.getSecondWord().compare("around") == 0){//or "turn around"
			
			if(currentRoom == upHall1 && manOnStairs == false)
			{
				cout << "You quickly turn around, there is nobody there. The footsteps have stopped. " << endl ;
				manOnStairs = true ;
			}
		}
	}
	else if (commandWord.compare("map") == 0)
	{
		if (!command.hasSecondWord())
		{
			
			if(currentRoom == hall1)//if you call "map" it just checks what room you are in and prints the corresponding map
			{
				map2->mhall1() ;
			}else if(currentRoom == hall2){
				map2->mhall2() ;
			}else if(currentRoom == study){
				map2->mstudy() ;
			}else if(currentRoom == playRoom){
				map2->mplayRoom() ;
			}else if(currentRoom == stairsRoom){
				map2->mstairsRoom() ;
			}else if(currentRoom == livingRoom){
				map2->mlivingRoom() ;
			}else if(currentRoom == kitchen){
				map2->mkitchen() ;
			}else if(currentRoom == backGarden){
				map2->mbackGarden() ;
			}else if(currentRoom == gardenShed){
				map2->mshed() ;
			}else if(currentRoom == upHall1){
				map2->mupHall1() ;
			}else if(currentRoom == upHall2){
				map2->mupHall2() ;
			}else if(currentRoom == guestRoom){
				map2->mguestRoom() ;
			}else if(currentRoom == masterRoom){
				map2->mmasterRoom() ;
			}else if(currentRoom == kidsRoom){
				map2->mkidsRoom() ;
			}else if(currentRoom == bathroom){
				map2->mbathroom() ;
			}
		}else{
			cout << "You what?" << endl;
		}
	}
	else if (commandWord.compare("totalmap") == 0)//prints the overall map
	{
		if (!command.hasSecondWord())
		{
			map2->mtotalMap() ;
		}else{
			cout << "Huh?" << endl;
		}
	}
	

	
	else if (commandWord.compare("play") == 0)
	{
		if(!command.hasSecondWord())
		{
			cout << "Play What?" << endl ;
		}else{

			if(command.getSecondWord().compare("disc") == 0 || command.getSecondWord().compare("game") == 0 || command.getSecondWord().compare("aom") == 0)//if you say "play disc" etc..
			{
				if(currentRoom == study)//if you're in the study
				{
					cout << "The disc is scratched, too bad..." << endl  ;
				}else{
					cout << "There is no computer here." << endl ;
				}
			}
		}
	}
	
	else if (commandWord.compare("quit") == 0)//quits game
	{
		if (command.hasSecondWord())
			cout << "Quit what?"<< endl;
		else
			return true; // signal that we want to quit
	}
	return false;
}


void Main::printHelp() {
	cout << "It's not that hard is it?"<< endl;
	cout << endl;
	cout << "Your command words are:"<< endl;
	parser.showCommands();
}


void Main::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		// if there is no second word, we don't know where to go...
		cout << "Go where?"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "You walk into a wall,ouch!"<< endl;
	
	else if (nextRoom == livingRoom)//this is for the mirror event
	{
		currentRoom = nextRoom;
		cout << currentRoom->description() <<endl;
		if(inLivingRoom == false)//if event hasnt happened already
		{
			cout << "Suddenly, in the mirror you see a figure crossing the doorway behind you,you turn to find nobody there." << endl;
			inLivingRoom = true ;//ticks off event
		}
		 
		currentRoom->iBeenHere() ;//this changes a boolean in the room class to say we've been here, so next time we go into the room it will only print a shirt description
		
	}else if(nextRoom == upHall1 && manOnStairs == false){//same as above for stairs event
		
		currentRoom = nextRoom;
		cout << currentRoom->description() <<endl;
		cout << "You hear footsteps following you up the stairs. Do you want to run or turn around?" << endl ;
		currentRoom->iBeenHere() ;
	
	}else if(nextRoom == upHall1 && atticEvent == true){//same as above for attic event
		
		cout << "A ladder to the attic has appeared!" << endl ;
		atticEvent = false ;
		upHall1->setExits(NULL,guestRoom,upHall2,masterRoom,attic,hall2) ;
	
	}else {
		currentRoom = nextRoom;
		cout << currentRoom->description() <<endl;
		currentRoom->iBeenHere() ;
		currentRoom->display() ;
	}
}

/** 
 * Try to go to one direction. If there is an exit, enter the new
 * room, otherwise print an error message.
 */
string Main::go(string direction) {
	//Make the direction lowercase
	transform(direction.begin(), direction.end(), direction.begin(),:: tolower);

	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("There is no door!");

	else{
		currentRoom = nextRoom;
		return currentRoom->description();
	}
}
