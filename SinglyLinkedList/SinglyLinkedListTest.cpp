#include <assert.h>
#include <iostream>
#include "SinglyLinkedList.h"
// write your test first
//1 download
//2 compile
//3 write a test
//4 complie
//5 implement method
//6 compile
//7 run
void test_constructor() {
    SinglyLinkedList<int> lst = {100, 200, 300, 400, 500};
    assert(*lst.at(0) == 100);
    assert(*lst.at(1) == 200);//anything is wrong, assert will stop and tell you where is wrong
    assert(*lst.at(2) == 300);
    assert(*lst.at(3) == 400);
    assert(*lst.at(4) == 500);
    assert(lst.size() == 5);
}

void test_remove() {
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    lst1.remove(2);
    assert(*lst1.at(0) == 100);
    assert(*lst1.at(1) == 200);
    assert(*lst1.at(2) == 400);
    assert(*lst1.at(3) == 500);
    assert(lst1.size() == 4);

    SinglyLinkedList<int> lst2 = {100, 200, 300, 400, 500};
    lst2.remove(0);
    assert(*lst2.at(0) == 200);
    assert(*lst2.at(1) == 300);
    assert(*lst2.at(2) == 400);
    assert(*lst2.at(3) == 500);
    assert(lst2.size() == 4);

    SinglyLinkedList<int> lst3 = {100, 200, 300, 400, 500};
    lst3.remove(4);
    assert(*lst3.at(0) == 100);
    assert(*lst3.at(1) == 200);
    assert(*lst3.at(2) == 300);
    assert(*lst3.at(3) == 400);
    assert(lst3.size() == 4);

}

void test_insert() {
    // TODO
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    lst1.insert(3, 600);
    assert(*lst1.at(0) == 100);
    assert(*lst1.at(1) == 200);//anything is wrong, assert will stop and tell you where is wrong
    assert(*lst1.at(2) == 300);
    assert(*lst1.at(3) == 600);
    assert(*lst1.at(4) == 400);
    assert(*lst1.at(5) == 500);
    assert(lst1.size() == 6);

    SinglyLinkedList<int> lst2 = {100, 200, 300, 400, 500};
    lst2.insert(0, 600);
    assert(*lst2.at(0) == 600);
    assert(*lst2.at(1) == 100);//anything is wrong, assert will stop and tell you where is wrong
    assert(*lst2.at(2) == 200);
    assert(*lst2.at(3) == 300);
    assert(*lst2.at(4) == 400);
    assert(*lst2.at(5) == 500);
    assert(lst2.size() == 6);

    SinglyLinkedList<int> lst3 = {100, 200, 300, 400, 500};
    lst3.insert(5, 600);
    assert(*lst3.at(0) == 100);
    assert(*lst3.at(1) == 200);//anything is wrong, assert will stop and tell you where is wrong
    assert(*lst3.at(2) == 300);
    assert(*lst3.at(3) == 400);
    assert(*lst3.at(4) == 500);
    assert(*lst3.at(5) == 600);
    assert(lst3.size() == 6);

    SinglyLinkedList<int> lst4 = {};
    lst4.insert(0, 600);
    assert(*lst4.at(0) == 600);



}

void test_push_back() {
    // TODO
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    lst1.push_back(600);
    assert(*lst1.at(0) == 100);
    assert(*lst1.at(1) == 200);
    assert(*lst1.at(2) == 300);
    assert(*lst1.at(3) == 400);
    assert(*lst1.at(4) == 500);
    assert(*lst1.at(5) == 600);
    assert(lst1.size() == 6);

    SinglyLinkedList<int> lst2 = {};
    lst2.push_back(600);
    assert(*lst2.at(0) == 600);
    assert(lst2.size() == 1);
}

void test_push_front() {
    // TODO
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    lst1.push_front(600);
    assert(*lst1.at(0) == 600);
    assert(*lst1.at(1) == 100);
    assert(*lst1.at(2) == 200);
    assert(*lst1.at(3) == 300);
    assert(*lst1.at(4) == 400);
    assert(*lst1.at(5) == 500);
    assert(lst1.size() == 6);

    SinglyLinkedList<int> lst2 = {};
    lst2.push_front(600);
    assert(*lst2.at(0) == 600);
    assert(lst2.size() == 1);
}

void test_append() {
    // TODO
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    SinglyLinkedList<int> list = {600, 700, 800, 900};
    lst1.append(list);
    assert(*lst1.at(0) == 100);
    assert(*lst1.at(1) == 200);
    assert(*lst1.at(2) == 300);
    assert(*lst1.at(3) == 400);
    assert(*lst1.at(4) == 500);
    assert(*lst1.at(5) == 600);
    assert(*lst1.at(6) == 700);
    assert(*lst1.at(7) == 800);
    assert(*lst1.at(8) == 900);
    assert(lst1.size() == 9);

    SinglyLinkedList<int> lst2 = {};
    SinglyLinkedList<int> list1 = {600, 700, 800, 900};
    lst2.append(list1);
    assert(*lst2.at(0) == 600);
    assert(*lst2.at(1) == 700);
    assert(*lst2.at(2) == 800);
    assert(*lst2.at(3) == 900);
    assert(lst2.size() == 4);

    SinglyLinkedList<int> lst3 = {100, 200, 300, 400, 500};
    SinglyLinkedList<int> list2 = {};
    lst3.append(list2);
    assert(*lst3.at(0) == 100);
    assert(*lst3.at(1) == 200);
    assert(*lst3.at(2) == 300);
    assert(*lst3.at(3) == 400);
    assert(*lst3.at(4) == 500);
    assert(lst3.size() == 5);
}

void test_sum() {
    SinglyLinkedList<int> lst1 = {100, 200, 300, 400, 500};
    assert(sum(lst1)==1500);

    SinglyLinkedList<int> lst2 ={};
    assert(sum(lst2)== 0);
}

int main() {
    test_constructor();
    test_remove();
    test_insert();
    test_push_back();
    test_push_front();
    test_append();
    test_sum();
}
