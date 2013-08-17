#include <iostream>
#include "knapsack.h"

using std::cout ;
using std::endl ;


 
Knapsack::Knapsack()
{
	this->weight = 0;
}      

double Knapsack::knapWeight()
{
	return weight ;
}

bool Knapsack::in(string name)
{
	bool exists = false ;
	for(unsigned int i = 0; i < inventory.size() ; i++)
	{
		if(inventory[i]->getDesc() == name)
		{
			exists = true ;
		}
	}
	return exists ;
}

void Knapsack::remove(string name)
{
	for(unsigned int j = 0 ; j < inventory.size() ; j++)
	{
		if(name == inventory[j]->getDesc())
		{
			this->weight -=inventory[j]->getWeight() ;
			inventory.erase(inventory.begin()+j) ;
		}
	}
    
}

bool Knapsack::getItem(string name)
{
	bool in = false ;
	for(unsigned int i = 0; i < inventory.size() ; i++)
	{
		if(inventory[i]->getDesc() == name)
		{
			in = true;
		}
	}
	return in ;
}

void Knapsack::add(Item* item)
{
	if((item->getWeight() + knapWeight()) <= 10)
	{
		 inventory.push_back(item) ;
		 weight += item->getWeight() ;
	}else{
		 cout << "The knapsack is too heavy, you need to drop an item before you can pick that up." << endl ;
	}
}

void Knapsack::display()
{
    if(inventory.size() == 0)
    {
        cout << "You have nothing in your inventory" << endl ;
    }    
    else 
    {
	    cout << "Item" <<"         Weight" << endl ;
        for(unsigned int i = 0 ; i < inventory.size() ; i++)
         {
             cout << i+1 << "." << inventory[i]->getDesc() << "         "<<inventory[i]->getWeight() << endl ;
         }

	} 
}  

