#include "doubly_linked_list.h"

using namespace std;

namespace lab6 {
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
        cout << temp->data << " ";
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

//Merge two lists together in place, placing the input list at the end of this list
    void doubly_linked_list::merge(doubly_linked_list rhs) {
        //the next of the last node or the node pointed to by tail should have its next point to the head of the input list
        //the prev of the first node of the input list or the node pointed to by the head should have its prev point to the tail of the previous list

        tail->next = rhs.head;
        rhs.head->prev = tail;

        tail = rhs.tail;

        size = size + rhs.size;
    }

// Allow for the merging of two lists using the + operator.
    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        node *temp = rhs.head;
        doubly_linked_list result;
        vector<unsigned> values;
        while (temp != rhs.tail->next) {
            result.append(temp->data);
            temp = temp->next;
        }
        return result;

    }

// Insert a node before the node located at position
    void doubly_linked_list::insert_before(unsigned position, unsigned data) {
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

    }

// Insert a node after the node located at position
    void doubly_linked_list::insert_after(unsigned position, unsigned data) {
        node *temp = new node(data);
        node *temp1 = head;
        node *temp2;

        for (int i = 0; i < position; i++) {
            temp1 = temp1->next;
            temp2 = temp1->next;
        }
        temp->next = temp2;
        temp2->prev = temp->next;
        temp1->next = temp->prev;
        temp->prev = temp1;
    }

// Remove the node located at position from the linked list
    void doubly_linked_list::remove(unsigned position) {
        node *temp = head;
        node *runner_next;
        node *runner_prev;
        int i = 0;
        for (i; i < position; i++) {
            temp = temp->next;

        }

        if (position == 0) {
            temp = head;
            head = head->next;
            delete (temp);
        } else if (position >= 1 && position < size) {
            runner_next = temp->next;
            runner_prev = temp->prev;
            runner_next->prev = runner_prev;
            runner_prev->next = runner_next;
            delete (temp);

        } else if (position == size) {
            temp = tail;
            tail = tail->prev;
            delete (temp);
        }

    }

// Split the list with the node being split on being included in the returned list
    doubly_linked_list doubly_linked_list::split_before(unsigned position) {

        doubly_linked_list split_list;
        if (position == 0) {
            node *temp = head;
            while (temp != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        } else if (position < size / 2) {
            node *temp = head;
            for (int i = 0; i < position; i++) {
                temp = temp->next;
            }
            while (temp != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        } else {
            node *temp = tail;
            for (int i = 0; i < size - position - 1; i++) {
                temp = temp->prev;
            }
            while (temp != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        }
        split_list.print();
        return split_list;
    }

// Split the list with the node being split on being included in the retained list
    doubly_linked_list doubly_linked_list::split_after(unsigned position) {
        doubly_linked_list split_list;
        if (position == 0) {
            node *temp = head;
            temp = head->next;
            while (temp != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        } else if (position < size / 2) {
            node *temp = head;
            for (int i = 0; i <= position; i++) {
                temp = temp->next;
            }
            while (temp != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        } else {
            node *temp = tail;
            for (int i = size; i >= position + 3; i--) {
                temp = temp->prev;
            }
            while (temp != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        }
        split_list.print();
        return split_list;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {
        //case 1: both from and to exist somewhere within the linked list
        //case 2: both from and to exist at the ends of the linked list
        //case 3: to exists before from
        //case 4: to and from are at the same position

        node *temp = head;
        node *temp1 = head;
        node *temp2 = head;
        doubly_linked_list obj;


        if (position_to - position_from + 1 == size || position_from == position_to) {
            std::cout << "Cannot split list within this range." << std::endl;
        }

        if (position_from < position_to) {
            //split before position
            for (int i = 0; i < position_from; i++) {
                temp1 = temp; //refers to the node right before position from
                temp = temp->next;
            }

            temp->prev->next = nullptr; //temp1->next=nullptr
            temp->prev = nullptr;

            doubly_linked_list obj(temp->data);
            temp = temp->next;

            for (int i = position_from + 1; i < position_to; i++) {
                obj.append(temp->data);
                temp = temp->next;
            }
            obj.append(temp->data);

            temp2 = temp->next; //temp2 refers to the node after position_to
            //obj.append(temp->data);
            temp->next->prev = nullptr; //temp2->prev=nullptr
            temp->next = nullptr;

            //merging the ends of the list
            obj.tail = temp2;

            temp1->next = temp2;
            temp2->prev = temp1;

            obj.size = (position_to - position_from) + 1;
            size = size - obj.size;

            return obj;
        } else {//'from' to tail and then head to 'to' and then
            for (int i = 0; i < position_from; i++) {
                temp1 = temp1->next;
            }

            doubly_linked_list obj(temp->data);
            temp = temp->next;

            while (temp1 != nullptr) {
                obj.append(temp1->data);
                temp1 = temp1->next;
            }

            for (int i = 0; i <= position_to; i++) {
                obj.append(temp2->data);
                temp2 = temp2->next;
            }

            obj.size = position_to + (size - position_from) + 2;
            size = size - obj.size;

            return obj;
        }
    }

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
    void doubly_linked_list::swap(unsigned position1, unsigned position2) {
        node *temp = head;
        node *temp1 = head;
        node *n1;
        for (int i = 0; i < position1; i++) {
            temp = temp->next;
        }
        for (int j = 0; j < position2; j++) {
            temp1 = temp1->next;
        }
        n1->next = temp->next;
        n1->prev = temp->prev;

        temp->prev = temp1->prev;
        temp->next = temp1->next;

        temp1->prev = n1->prev;
        temp1->next = n1->next;

        if (temp->next != 0)
            temp->next->prev = temp; // n2;
        if (temp->prev != 0)
            temp->prev->next = temp; // n2;
        if (temp1->next != 0)
            temp1->next->prev = temp1; // n1;
        if (temp1->prev != 0)
            temp1->prev->next = temp1; // n1;
    }

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
    void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                      unsigned position2_to) {
        node *temp = head;
        node *mynext, *myprev, *start1, *end1, *mynext2, *myprev2, *start2, *end2;
        int count1, count2;
        count1 = 0;
        count2 = 0;

        while (temp->next != nullptr && count1++ != position1_to) {
            if (count1 < position1_from + 1) {
                myprev = temp;
                start1 = temp->next;
            }
            temp = temp->next;
        }
        end1 = temp;
        mynext = end1->next;

        temp = head;

        while (temp->next != nullptr && count2++ != position2_to) {
            if (count2 < position2_from + 1) {
                myprev2 = temp;
                start2 = temp->next;
            }
            temp = temp->next;
        }
        end2 = temp;
        mynext2 = end2->next;

        end1->next = mynext2;
        start1->prev = myprev2;
        end2->next = mynext;
        start2->prev = myprev;

        myprev->next = start2;
        mynext->prev = end2;
        myprev2->next = start1;
        mynext2->prev = end1;
    }

// Overload operator=
    doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {


        int minsize = size;
        int maxsize = RHS.size;
        char choice = 'b';

        node *temp = head;
        node *temp1 = RHS.head;

        if (size > RHS.size) {
            minsize = RHS.size;
            maxsize = size;
            choice = 'a';
        }

        for (int i = 0; i < minsize; i++) {
            temp->data = temp1->data;
            temp = temp->next;
            temp1 = temp1->next;
        }
        if (choice == 'a') {
            for (int j = minsize; j < maxsize; j++) {
                remove(j);
            }
        } else if (choice == 'b') {
            for (int j = minsize; j < maxsize; j++) {
                append(temp1->data);
                temp1 = temp1->next;
            }
        }

        size = RHS.size;

        return *this;

    }

// Append the rhs to the end of the this list
    doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {

        node *temp = RHS.head;

        while (temp->next != nullptr) {
            append(temp->data);
            temp = temp->next;
        }
        append(temp->data);

        return *this;

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
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) const {
        node *iterL = head, *iterR = rhs.head;
        while (iterL != nullptr && iterR != nullptr) {
            if (iterL->data != iterR->data)
                return false;
            iterL = iterL->next;
            iterR = iterR->next;
        }
        return iterL == nullptr && iterR == nullptr;
    }

    std::string doubly_linked_list::to_string() {
        if (!head) return "";
        else {
            std::string output = "";
            output += std::to_string(head->data);
            node *to_return = head->next;
            while (to_return) {
                output += ", ";
                output += std::to_string(to_return->data);
                to_return = to_return->next;
            }
            return output;
        }
    }


}
