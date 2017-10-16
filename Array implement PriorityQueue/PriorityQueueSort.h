//Gushu Qin
#ifndef PRIORITYQUEUESORT_H_
#define PRIORITYQUEUESORT_H_



#include "ArrayQueue.h"
#include "array.h"


namespace ods{
//constructor
template<class T>
class PriorityQueueSort : public ArrayQueue<T>{

	public:
		PriorityQueueSort(): ArrayQueue<T>(){};

		/*
			called the add() from the base class to add the new element at the back of the array.
			if there's only one element at the array, do nothing
			if there's more than one element in the array, test if the element is bigger than its previous one
			if it dose, then do nothing
			else it calls the swap function from array.h class to swap the element with it previous one
			it'll stop until the previous element in the array is smaller than the latter element, at that time, all elements in the array are sortted.
		*/

		bool add(T x){
			ArrayQueue<T>::add(x);

			if(this->n == 1)
				return true;

			int n = this->n;
			n--;
			while(int m = (this->j + n) % this->a.length){

				 if (this->a[m] >= this->a[(this->j + n - 1) % this->a.length])
				 	return true;

				 else{
				  this->a.swap(m, (this->j + n - 1) % this->a.length);
					n--;
				}
			}
			return true;
		}

		/*
		wrapper function, called remove() from base class to do the work.
		*/
		void removeMin(){
			ArrayQueue<T>::remove();
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
