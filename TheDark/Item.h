#ifndef ITEM_H_
#define ITEM_H_

#include <string> 
#include <iostream>
using std::string ;

class Item
{
      private:
              bool pick ;
              bool move ;
              double weight ;
              string desc ;
              
      public:
             Item (string desc,double weight,bool pick,bool move) ;
             bool isPickable() ;
             bool isMoveable() ;
			 void setDesc() ;
             string getDesc() ;
			 void setWeight() ;
             double getWeight() ;
};
#endif
