#include "doubly_linked_list.h"

using namespace std;

// Default constructor
doubly_linked_list::doubly_linked_list() {
    head = tail = nullptr;
    size = 0;

}

// Take in a vector of inputs and construct a doubly linked list from them
doubly_linked_list::doubly_linked_list(std::vector<unsigned> values) {
    int inputs = values.size();
    size = values.size();
    node *temp1;
    head = new node(values[0]);
    temp1 = head;
    node *temp2;
    temp1->prev = nullptr;

    for (int i = 1; i < inputs + 1; i++) {
        temp1->next = new node(values[i]);
        temp2 = temp1;
        temp1 = temp1->next;
        temp1->prev = temp2;

    }
    tail = temp2;
    tail->next = nullptr;
    size++;
}

// Copy constructor
doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
    node *temp = original.head;
    while (temp != nullptr) {
        append(temp->data);
        temp = temp->next;
    }
}

// Create doubly linked linked list with one input value
doubly_linked_list::doubly_linked_list(unsigned input) {
    node *temp;
    temp->data = input;
    temp->prev = nullptr;
    temp->next = nullptr;

}

// Default constructor
doubly_linked_list::~doubly_linked_list() {
    node *temp;
    temp = head;
    while (head != nullptr) {
        temp = head->next;
        delete head;
        head = temp;
        size--;
    }
}

// return the value inside of the node located at position
unsigned doubly_linked_list::get_data(unsigned position) {
    node *temp = head;
    int i = 0;
    while (i < position) {
        temp = temp->next;
        i++;
    }
    cout << temp->data;
}

// Get a set of values between position_from to position_to
std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
    node *temp = head;
    vector<unsigned> store;
    int i = 0;
    if (i < position_from) {
        temp = temp->next;
        i++;
    }
    int a = 0;
    while (i < position_to) {
        store.push_back(temp->data);
        temp = temp->next;
        i++;
    }
    return store;
}

// Add a value to the end of the list
void doubly_linked_list::append(unsigned data) {
    node *newnode;
    node *temp;
    newnode = new node(data);
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
        size++;
    } else {
        temp = new node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        size++;
    }
}

// Merge two lists together in place, placing the input list at the end of this list
void doubly_linked_list::merge(doubly_linked_list rhs) {

}

// Allow for the merging of two lists using the + operator.
doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
//    return ;
}

// Insert a node before the node located at position
void doubly_linked_list::insert_before(unsigned position, unsigned data) {
    node *temp = new node(data);
    node *temp1 = head;
    node *temp2;

    for (int i = 0; i < position - 2; i++) {
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
    temp->next = temp2;
    temp2->prev = temp->next;
    temp1->next = temp;
    temp->prev = temp1;


    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }

}

// Insert a node after the node located at position
void doubly_linked_list::insert_after(unsigned position, unsigned data) {
    node *temp = new node(data);
    node *temp1 = head;
    node *temp2;

    for (int i = 0; i < position - 1; i++) {
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
    temp->next = temp2;
    temp2->prev = temp->next;
    temp1->next = temp;
    temp->prev = temp1;


    for (int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }

}

// Remove the node located at position from the linked list
void doubly_linked_list::remove(unsigned position) {

}

// Split the list with the node being split on being included in the returned list
doubly_linked_list doubly_linked_list::split_before(unsigned position) {
//    return ;
}

// Split the list with the node being split on being included in the retained list
doubly_linked_list doubly_linked_list::split_after(unsigned position) {
//    return ;
}

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {
//    return ;
}

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
void doubly_linked_list::swap(unsigned position1, unsigned position2) {

}

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                  unsigned position2_to) {

}

// Overload operator=
doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {
//    return <#initializer#>;
}

// Append the rhs to the end of the this list
doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
//    return <#initializer#>;
}

unsigned doubly_linked_list::get_size() {
    return size;
}

bool doubly_linked_list::is_empty() {
    return !size;
}

void doubly_linked_list::print() {
    node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
