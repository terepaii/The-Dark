#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
using namespace std;

class Player 
{
	private:
		string desc ;
		short health ;
		int steps ;

	public:
		Player();
		Player(string desc);
		short getHealth() ;
		int getSteps() ;
		void setSteps() ;
		bool hasKey() ;
};
#endif