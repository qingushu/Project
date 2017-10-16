//Gushu Qin
#ifndef SHOPPER_H_
#define SHOPPER_H_

#include "PriorityQueueSort.h"
#include "PriorityQueueSearch.h"
#include <cstdlib>

/*
  Shopper class to create Shopper object
*/
class Shopper{

  long int loyalty;
  int cartSize;
  int priority;


public:
  //default constructor
  Shopper() : loyalty(0), cartSize(0), priority(0) {}
  //constructor that takes priority
  Shopper(int n) : loyalty(rand()), cartSize(rand()){
    priority = n;
  }
  //copy constructor just in case;
  Shopper(const Shopper& sp) : loyalty(sp.loyalty), cartSize(sp.cartSize), priority(sp.priority){}

  /*
  overload <
  */
  bool operator <(const Shopper& s) {
         if(priority < s.priority) {
            return true;
         }
         return false;
      }

  /*
  overload >
  */
  bool operator >(const Shopper& s) {
          if(priority > s.priority) {
            return true;
          }
          return false;
      }

      friend bool operator<=(const Shopper& lhs, const Shopper& rhs);
      friend bool operator>=(const Shopper& lhs, const Shopper& rhs);

};
/*
  overload <=
*/
bool operator<=(const Shopper& lhs, const Shopper& rhs){
  if(lhs.priority <= rhs.priority) {
     return true;
  }
  return false;
 }

 /*
  overload >=
 */
bool operator>=(const Shopper& lhs, const Shopper& rhs){
  if(lhs.priority >= rhs.priority) {
   return true;
}
return false;
}



#endif
