//Gushu Qin
#ifndef PRIORITYQUEUESEARCH_H_
#define PRIORITYQUEUESEARCH_H_



#include "ArrayQueue.h"
#include "array.h"


namespace ods{
//PriorityQueueSearch is derived from ArrayQueue class
template<class T>
class PriorityQueueSearch : public ArrayQueue<T>{


	public:
		//constructor
		PriorityQueueSearch(): ArrayQueue<T>(){};

		//wrapper function, called the base class add() function to do the work
		bool add(T x){
			ArrayQueue<T>::add(x);
      return true;
		}

		/*
		if there's only one element at the array, call remove() from the base class to remove that element.
		otherwise it compares two elements and swap them if the latter element is smaller than the previous one.
		it start from the last element at the array and gradually move to the first one.
		int the end, the element at the first position of the array is the smallest.
		Then it calls remove() from the base class and remove the first element in the array.
		*/
		void removeMin(){

      if(this->n == 1)
				ArrayQueue<T>::remove();
      else {
        int n = this->n;
				n--;
			while(n > 0){
				 if (this->a[(this->j + n) % this->a.length] <= this->a[(this->j + n - 1) % this->a.length]){
				 	this->a.swap((this->j + n) % this->a.length, (this->j + n - 1) % this->a.length);

				}
      n--;
			}
			ArrayQueue<T>::remove();
    	}
	}


	/*
	print all element in array;
	This is just for testing and debuging.
	*/
	void print(){
		for(int i = 0; i < this->n; i++)
			std::cout << this->a[(this->j + i)%this->a.length] << " ";

		}


};
}

#endif
