#include<iostream>
#include<assert.h>
#include<string>

#include"heap.h"

using namespace std;


void test_constructor() {
  try{
    int arr[] = {1, 30, 9, 2, 7, 22, 3, 99, 100};
    Heap *tmp = new Heap(arr, 9);
    assert(tmp->at(0) == 100);
    assert(tmp->at(1) == 99);
    assert(tmp->at(2) == 22);
    assert(tmp->at(3) == 30);
    assert(tmp->at(4) == 7);
    assert(tmp->at(5) == 9);
    assert(tmp->at(6) == 3);
    assert(tmp->at(7) == 1);
    assert(tmp->at(8) == 2);

    int arr1[] = {};
    Heap *tmp1 = new Heap(arr1, 0);
  } catch (string message){
    cout << message << endl;
    exit(1);
  }
}

void test_queue() {
    int arr[] = {1, 30, 9, 2, 7, 22, 3, 99, 100};
    Heap *tmp = new Heap(arr, 9);
    tmp->queue(101);
    assert(tmp->at(0) == 101);
    assert(tmp->at(1) == 100);
    assert(tmp->at(2) == 22);
    assert(tmp->at(3) == 30);
    assert(tmp->at(4) == 99);
    assert(tmp->at(5) == 9);
    assert(tmp->at(6) == 3);
    assert(tmp->at(7) == 1);
    assert(tmp->at(8) == 2);
    assert(tmp->at(9) == 7);

    int arr1[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    Heap *tmp1 = new Heap(arr1, 10);
    tmp1->queue(-11);
    assert(tmp1->at(0) == -1);
    assert(tmp1->at(1) == -2);
    assert(tmp1->at(2) == -3);
    assert(tmp1->at(3) == -4);
    assert(tmp1->at(4) == -5);
    assert(tmp1->at(5) == -6);
    assert(tmp1->at(6) == -7);
    assert(tmp1->at(7) == -8);
    assert(tmp1->at(8) == -9);
    assert(tmp1->at(9) == -10);
    assert(tmp1->at(10) == -11);


    int arr2[] = {};
    Heap *tmp2 = new Heap(arr2, 0);
    for(int i = 1; i <= 5; i++)
      tmp2->queue(10*i);

    assert(tmp2->at(0) == 50);
    assert(tmp2->at(1) == 40);
    assert(tmp2->at(2) == 20);
    assert(tmp2->at(3) == 10);
    assert(tmp2->at(4) == 30);


}

void test_dequeue() {

  try{
    int arr[] = {1, 30, 9, 2, 7, 22, 3, 99, 100};
    Heap *tmp = new Heap(arr, 9);
    assert(tmp->dequeue() == 100);
    assert(tmp->dequeue() == 99);
    assert(tmp->dequeue() == 30);
    assert(tmp->dequeue() == 22);
    assert(tmp->dequeue() == 9);
    assert(tmp->dequeue() == 7);
    assert(tmp->dequeue() == 3);
    assert(tmp->dequeue() == 2);
    assert(tmp->dequeue() == 1);

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Heap *tmp1 = new Heap(arr1, 10);
    assert(tmp1->dequeue() == 10);
    assert(tmp1->dequeue() == 9);
    assert(tmp1->dequeue() == 8);
    assert(tmp1->dequeue() == 7);
    assert(tmp1->dequeue() == 6);
    assert(tmp1->dequeue() == 5);
    assert(tmp1->dequeue() == 4);
    assert(tmp1->dequeue() == 3);
    assert(tmp1->dequeue() == 2);
    assert(tmp1->dequeue() == 1);

    int arr2[] = {1};
    Heap *tmp2 = new Heap(arr2, 1);
    for(int i = 1; i <= 5; i++)
      tmp2->queue(10*i);
    for(int i = 1; i <=5; i++)
      assert(tmp2->dequeue() == 10*(5-i+1));
      assert(tmp2->dequeue() == 1);
      tmp2->dequeue();

    } catch (string message){
      cout << "test --- dequeue empty array" << endl << "EXCEPTION ----" << message << endl;
      exit(1);
    }
}

   int main() {
       test_constructor();
       test_queue();
       test_dequeue();
       return 0;
   }
