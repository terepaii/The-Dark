#ifndef LAMP_H_
#define LAMP_H_

#include "Item.h"
#include <string>

using namespace std ;

class Lamp: public Item
{
private:
	bool on ;

public:
    
	Lamp(string desc,double weight,bool pick,bool move);
	void toggle() ;
	bool isOn() ;
};
#endif
