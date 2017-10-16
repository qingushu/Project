//Gushu Qin
#include <iostream>
#include "utils.h"
#include "ArrayQueue.h"
#include "PriorityQueueSearch.h"
#include "PriorityQueueSort.h"
#include <random>
#include <chrono>
#include "Shopper.h"





using namespace std;
using namespace ods;
//namespace ods {
int main(){
	int arr[5000];
	PriorityQueueSort <int> *psort = new PriorityQueueSort<int>();
	PriorityQueueSearch <int> *psearch = new PriorityQueueSearch<int>();

	PriorityQueueSort <Shopper> *shopper_sort = new PriorityQueueSort<Shopper>();
	PriorityQueueSearch <Shopper> *shopper_search = new PriorityQueueSearch<Shopper>();



	for(int i = 0; i < 5000; i++){
// produces random #s between 0 and 1
		std::default_random_engine generator(i);
// converts those to equally-likely ints between 1 and 10
		std::uniform_int_distribution<int> distribution(1,10);
		int temp = distribution(generator);
		arr[i] = temp;

}

	auto start = chrono::steady_clock::now();
 // code to time here
 	for(int i = 0; i < 5000; i++)
 		psort->add(arr[i]);
 	auto end = chrono::steady_clock::now();
 	auto diff = end - start;
 	cout << "priority queue sort add ints: " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;



 	start = chrono::steady_clock::now();
  // code to time here
  for(int i = 0; i < 5000; i++)
  	psearch->add(arr[i]);
  end = chrono::steady_clock::now();
  diff = end - start;
  cout << "priority queue search add ints: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;



	 start = chrono::steady_clock::now();
	 // code to time here
	 for(int i = 0; i < 5000; i++)
	 	psort->removeMin();
	 end = chrono::steady_clock::now();
	 diff = end - start;
	 cout << "priority queue sort remove ints: " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;

	 start = chrono::steady_clock::now();
 	 // code to time here
 	 for(int i = 0; i < 5000; i++)
 	 	psearch->removeMin();
 	 end = chrono::steady_clock::now();
 	 diff = end - start;
 	 cout << "priority queue search remove ints: " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;


	 start = chrono::steady_clock::now();
	  // code to time here
	  for(int i = 0; i < 5000; i++)
	  	shopper_sort->add(arr[i]);
	  end = chrono::steady_clock::now();
	  diff = end - start;
	  cout << "priority queue sort add shoppers:  " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;

		start = chrono::steady_clock::now();
 	  // code to time here
 	  for(int i = 0; i < 5000; i++)
 	  	shopper_search->add(arr[i]);
 	  end = chrono::steady_clock::now();
 	  diff = end - start;
 	  cout << "priority queue search add shoppers: "<<chrono::duration <double, milli> (diff).count() << " ms" << endl;


		start = chrono::steady_clock::now();
		 // code to time here
		 for(int i = 0; i < 5000; i++)
		 	shopper_sort->removeMin();
		 end = chrono::steady_clock::now();
		 diff = end - start;
		 cout << "priority queue sort remove shoppers: " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;

		 start = chrono::steady_clock::now();
 		 // code to time here
 		 for(int i = 0; i < 5000; i++)
 		 	shopper_search->removeMin();
 		 end = chrono::steady_clock::now();
 		 diff = end - start;
 		 cout << "priority queue search remove shoppers: " <<chrono::duration <double, milli> (diff).count() << " ms" << endl;


//
} /* namespace ods */
