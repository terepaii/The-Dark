#include "Lamp.h"
#include <iostream>



Lamp::Lamp(string desc,double weight,bool pick,bool move) : Item(desc,weight,pick,move)
{
	
}
void Lamp::toggle()
{
	on = true;
}

bool Lamp::isOn()
{
	return on ;
}