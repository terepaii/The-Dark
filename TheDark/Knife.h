#ifndef KNIFE_H_
#define KNIFE_H_

#include "Item.h"

#include <iostream>
#include <string>

using namespace std ;

class Knife: public Item
{
private:
	bool on ;

public:
    
	Knife(string desc,double weight,bool pick,bool move);
	void swing() ;
};
#endif
