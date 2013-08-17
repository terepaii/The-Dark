#include "Knife.h"
#include <iostream>



Knife::Knife(string desc,double weight,bool pick,bool move) : Item(desc,weight,pick,move)
{
	
}
void Knife::swing()
{
	cout<<"Whhoooooosssh!"<<endl ;
}
