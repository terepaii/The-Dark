#include "Item.h"

             
 Item::Item(string desc,double weight,bool pick,bool move)
 {
    this->pick = pick ;
    this->move = move ;
    this->desc = desc ;
    this->weight = weight ;
 }
 bool Item::isPickable()
 {
    return pick ;
 }
 bool Item::isMoveable()
 {
    return move ;
 }
 string Item::getDesc()
 {
    return desc ;
 }  
  double Item::getWeight()
 {
    return weight ;
 }  

      
