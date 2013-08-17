#ifndef KNAPSACK_H_
#define KNAPSACK_H_

#include <iosfwd>
#include <string>
#include<vector>
#include "Item.h"

using namespace std ;
class Knapsack
{
      private:
              vector<Item*> inventory ;
              double weight  ;

      public:
		     
		     Knapsack();
			 double knapWeight() ;
			 bool in(string name) ;
             void add(Item* item) ;
			 bool getItem(string name) ;
             void display() ;
			 void remove(string name) ;
			 
};
#endif 
