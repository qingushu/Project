#include<iostream>
#include<string>

class Heap{
  private:

    int capacity;
    int size;
    int *arr;

  public:
    Heap(int *data, size_t size1){
      capacity = 20;
      size = size1;
      arr = new int [capacity];

        for(int i = 0; i < size; i++)
          arr[i] = data[i];



      buildHeap();
}


  void buildHeap()
  {
    for (int k = size/2; k >= 0; k--)
      shiftDown(k);
  }

  void shiftDown(int k)
  {
    int tmp = arr[k];
    int leftC = 2*k+1, rightC = 2*k+2;
    int swapTo;
    bool hasBiggerLeftC = leftC < size && arr[leftC] > arr[k];
    bool hasBiggerRightC = rightC < size && arr[rightC] > arr[k];

    if (hasBiggerLeftC || hasBiggerRightC){
        if(arr[rightC] > arr[leftC]){
          swapTo = rightC;
          swap(k, rightC);
        }
        else {
          swapTo = leftC;
          swap(k, leftC);
        }
        shiftDown(swapTo);
    }

}


  void swap(int pos1, int pos2){
    int tmp;
    tmp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = tmp;
}

void print(){
  for(int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}


  int dequeue(){
    if(size == 0) throw std::string("no element in array, can't dequeue");
    int hold = arr[0];
    arr[0] = arr[size-1];
    size--;
    int i = 0;
    shiftDown(i);
    return hold;
  }

  void queue(int i) {
    if(size == capacity) doubleCapacity();
    int item = size;
    size++;
    int parent = (item-1)/2;
    arr[item] = i;
    int up = arr[item];

    while (item != 0 && !(arr[parent] > up)) {
      arr[item] = arr[parent];
      item = parent;
      parent = (item-1)/2;
    }
    arr[item] = up;
  }

  void doubleCapacity(){
    capacity *= 2;
    int *temp = new int [capacity];
    for(int i = 0; i < size; i++)
      temp[i] = arr[i];
    delete [] arr;
    arr = temp;
  }

  int at(int i){
    if(size == 0) throw std::string ("no element in this array");
   return arr[i];
 }


};
