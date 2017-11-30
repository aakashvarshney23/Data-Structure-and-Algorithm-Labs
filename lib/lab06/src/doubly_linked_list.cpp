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

        for (int i = 1; i <= inputs; i++) {
            temp1->next = new node(values[i]);
            temp2 = temp1;
            temp1 = temp1->next;
            temp1->prev = temp2;

        }
        tail = temp2;
        tail->next = nullptr;
    }

    // Copy constructor
    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {

        node *temp; // the temp of the new doubly object
        node *before;

        size = original.size; //initializing the size variable

        node *temp2 = original.head;

        head = new node(temp2->data); //initializing the head with the first data element

        temp = head; //temp points to where head is pointing to

        temp2 = temp2->next;

        for (int i = 1; i < size; i++) {
            before = temp;
            temp->next = new node(temp2->data); //seg fault
            temp = temp->next;
            temp->prev = before;

            temp2 = temp2->next;
        }

        tail = temp;
        tail->next = nullptr;
    }

    // Create doubly linked linked list with one input value
    doubly_linked_list::doubly_linked_list(unsigned input) {

        node *temp = new node(input);
        tail = head;
        size = 1;

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
        if (position == 0)
            return head->data;
        else {
            while (i < position) {
                temp = temp->next;
                i++;
            }
            return temp->data;
        }
    }

    // Get a set of values between position_from to position_to
    std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        node *temp = head;
        vector<unsigned> store;
        int i = 0;
        while (i < position_from) {
            temp = temp->next;
            i++;
        }
        while (i <= position_to) {
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
        doubly_linked_list obj1(*this);
        doubly_linked_list obj2(rhs);
        obj1.merge(obj2);
        return obj1;
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
        temp1->next = temp;
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
        --size;
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
            while (temp->next != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        }
        //split_list.print();
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
        } else if (position <= size / 2) {
            node *temp = head;
            for (int i = 0; i <= position; i++) {
                temp = temp->next;
            }
            while (temp->next != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        } else {
            node *temp = tail;
            for (int i = size; i < size - position; i++) {
                temp = temp->prev;
            }
            while (temp->next != nullptr) {
                split_list.append(temp->data);
                temp = temp->next;
            }
        }
        return split_list;
    }

    doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {

        node *temp = head;
        doubly_linked_list *split_list = new doubly_linked_list();
        int i = 0;
        while (i < position_from) {
            temp = temp->next;
            i++;
        }
        while (i < position_to) {
            split_list->append(temp->data);
            temp = temp->next;
            i++;
        }
        return *split_list;
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

        if (temp->next != nullptr)
            temp->next->prev = temp; // n2;
        if (temp->prev != nullptr)
            temp->prev->next = temp; // n2;
        if (temp1->next != nullptr)
            temp1->next->prev = temp1; // n1;
        if (temp1->prev != nullptr)
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

        while (temp->next != nullptr && count1 != position1_to) {
            if (count1 < position1_from + 1) {
                myprev = temp;
                start1 = temp->next;
                ++count1;
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
        node *dest;
        node *newnode;
        node *other = RHS.head;
        if (head) {
            while (head) {
                dest = head;
                head = head->next;
                delete dest;
            }
            tail = nullptr;
            size = 0;
        }
        if (!RHS.head) {
            head = nullptr;
            tail = nullptr;
            size = 0;
        } else {

            size = RHS.size;
            head = new node(other->data);
            tail = head;
            other = other->next;
            while (other) {
                newnode = new node(other->data);
                tail->next = newnode;
                tail = newnode;
                other = other->next;
            }
        }
    }

// Append the rhs to the end of the this list
    doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
        doubly_linked_list obj1(*this);
        doubly_linked_list obj2(RHS);

        obj1.merge(obj2);
        *this = obj1;
        return obj1;
    }

    unsigned doubly_linked_list::get_size() {
        return size;
    }

    bool doubly_linked_list::is_empty() {
        return !size;
    }

    void doubly_linked_list::print() {
        node *temp = head;
        while (temp->next != nullptr) {
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
