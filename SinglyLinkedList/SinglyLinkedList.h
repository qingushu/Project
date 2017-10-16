#include <stddef.h>
#include <initializer_list>

template <class T>
class SinglyLinkedList {

    // Nested class representing the nodes in the list.
    class SinglyLinkedListNode {
    public:
        // The value stored in this node.
        T value;

        // The next node in the sequence.
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(T value) :
            value(value), next(nullptr) {}

        SinglyLinkedListNode(T value, SinglyLinkedListNode *next) :
            value(value), next(next) {}

        // Return the size (length) of the linked list.
        std::size_t size();
    };

    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

public:
    // Constructs a new SinglyLinkedList from an initializer_list of type T[].
    // This is mostly for convenience, especially when testing.
    SinglyLinkedList(std::initializer_list<T> items) : head(nullptr), tail(nullptr) {
        if (items.size() == 0) {
            return;
        }
        // initializer_lists were designed to be used iteratively,
        // so thats what we do.
        // Can you think of how to write this recursively?
        auto it = items.begin();
        while (it != items.end()) {
            this->push_back(*it++);
        }
    }

    // Return a pointer to the value at the given index.
    // If the index is larger than the size of the list,
    // return a nullptr.
    //
    // ASIDE: We will cover exceptions later.
    T* at(std::size_t i);

    // Pushes a new node onto the back of the list.
    void push_back(T value);

    // Pushes a new node onto the front of the list.
    void push_front(T value);

    // Return the size (length) of the linked list.
    std::size_t size();

    // Remove the specified node from the list.
    void remove(std::size_t i);

    // Insert the value at the index.
    void insert(std::size_t i, T value);

    // Append the given list to this one.
    void append(SinglyLinkedList<T> list);

};

template <class T>
T* SinglyLinkedList<T>::at(std::size_t i) {
    // TODO
    if (size() < i + 1){
        return nullptr;
    }
    SinglyLinkedListNode *current = head;
    while(i--){
        current = current ->next;
    }
    return &current->value;
}

template <class T>
void SinglyLinkedList<T>::push_back(T value) {
    // TODO
    // Make sure that this is a O(1) operation!
    if (head == nullptr){
        head = new SinglyLinkedListNode(value);
        tail = head;
    } else {
          tail->next = new SinglyLinkedListNode(value);
          tail = tail->next;
    }
}

template <class T>
void SinglyLinkedList<T>::push_front(T value) {
    // TODO
    // Make sure that this is a O(1) operation!
        head = new SinglyLinkedListNode(value, head);
        if (tail == nullptr)
            tail = head;

}

template <class T>
void SinglyLinkedList<T>::remove(std::size_t i) {
    // TODO
    // Don't forget to not only unlink the node, but to delete the memory.
    SinglyLinkedListNode  *temp;
    if ( head != nullptr && i == 0 ){
        temp = head;
        head = head->next;
        delete temp;
    } else {
        int k = 1;
        SinglyLinkedListNode *p = head;
        while(p!=nullptr && k < i){
            p = p->next;
            k++;
        }
        if (p !=nullptr && p->next != nullptr ){
            temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }
}

template <class T>
void SinglyLinkedList<T>::insert(std::size_t i, T value) {
    // TODO
    // Don't forget to not only unlink the node, but to delete the memory.
    SinglyLinkedListNode *temp;
    if(head == nullptr && i ==0){
        push_back(value);
    } else if (head != nullptr && i == 0){
        temp = head;
        head = new SinglyLinkedListNode(value);
        head->next = temp;
        delete temp;
    } else {
        SinglyLinkedListNode *p = head;
        int k = 1;
        while(p!=nullptr && k < i){
            p = p->next;
            k++;
      }
        temp = p->next;
        p->next = new SinglyLinkedListNode(value);
        p->next->next = temp;
        delete temp;

    }

}

template <class T>
void SinglyLinkedList<T>::append(SinglyLinkedList<T> list) {
    // TODO
    if(this->head == nullptr)
        this->head = list.head;
    else{
        SinglyLinkedListNode *p = this->head;
        while(p->next != nullptr)
            p = p->next;
            p->next = list.head;
      }
}

template <class T>
std::size_t SinglyLinkedList<T>::size() {
    // I did this one for you.  I am such a nice guy!
    if (this->head == nullptr) {
        return 0;
    } else {
        return this->head->size();
    }
}

template <class T>
std::size_t SinglyLinkedList<T>::SinglyLinkedListNode::size() {
    // Seriously, I am the best.

    if (this == nullptr) {
        return 0;
    } else if (this->next == nullptr) {
        return 1;
    } else {
        return 1 + this->next->size();
    }
}

// Takes a reference to a list of integers as an argument,
// and returns the sum of the items in the list.

long sum(SinglyLinkedList<int> list) { //const will make this function stop because "at" is not a member function of "const", when "sum" call "at", compiler will know that "at"
    // TODO(loop)                       //is not a member function of const, so compiler will not permit any non-const function access a const parameter to make sure this function
    //int sum=0;                          //will not change const parameter.
    //if (list.size() == 0)
        //return 0;
  //  else{
        //for(size_t i = 0; i < list.size(); i++)
          //  sum += *list.at(i);
    //}
    //return sum;
    if(*list->size()==0)
      return 0;
      cout << sum(list);
    return list.at(list.size()-1)+ sum(list.at(list.size()-1));

    }
