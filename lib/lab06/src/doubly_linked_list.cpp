#include "doubly_linked_list.h"
/*
 * You will be writing all of the code for each of these functions.
 * Remember, this is a doubly linked list, not an array. You need to
 * be using pointers, and not overwriting your values like you would
 * in an array.
 *
 * If you need to write auxiliary functions, you are more than welcome
 * to, but you can't change the signature of any of the functions we
 * have written.
 *
 * Information on doubly linked lists can be found at
 * https://en.wikipedia.org/wiki/Doubly_linked_list
 *
 * Hints: - Keep track of size. If you add or delete something, you
 *          need to change size.
 *        - This isn't an array, so moving things around is actually
 *          a lot easier. Just change the pointers to the objects.
 *        - Keep track of your edge cases; empty, 1 item, and 2 items
 *        - Some of these functions are basically the same thing,
 *          with the index shifted or return ignored. Don't rewrite
 *          code, just call the function with the 'correct' inputs.
 *        - Test your doubly linked list by itself before testing it
 *          in the deck class. It will make it easier to find any bugs
 *        - Use your debugger. It is your best friend for finding
 *          issues!
 *        - Don't forget to ask for help on Slack!
 *
 * We will be making changes throughout the week to the deck.cpp as
 * well as adding testing into the project. Make sure to pull and
 * merge frequently.
 */

namespace lab6 {
// Default constructor
    doubly_linked_list::doubly_linked_list() {
        head = tail = nullptr;
        size = 0;
    }

// Take in a vector of inputs and construct a doubly linked list from them
    doubly_linked_list::doubly_linked_list(std::vector<unsigned> values) {
        head = tail = new node(values[0]);
        size = values.size();

        for (int i = 1; i < size; ++i) {
            tail->next = new node(values[i]);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

// Copy constructor
    doubly_linked_list::doubly_linked_list(const doubly_linked_list &original) {
        size = original.size;
        head = tail = new node(original.head->data);
        for (node *temp = original.head->next; temp != nullptr; temp = temp->next) {
            tail->next = new node(temp->data);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

// Create doubly linked linked list with one input value
    doubly_linked_list::doubly_linked_list(unsigned input) {
        head = tail = new node(input);
        size = 1;
    }

// Default constructor
    doubly_linked_list::~doubly_linked_list() {
        while (head != nullptr)
            remove(0);
    }

// return the value inside of the node located at position
    unsigned doubly_linked_list::get_data(unsigned position) {
        if (size <= position)
            throw "Invalid Position";
        node *temp_position = head;
        for (int i = 0; i < position; ++i) {
            temp_position = temp_position->next;
        }
        return temp_position->data;
    }

// Get a set of values between position_from to position_to
    std::vector<unsigned> doubly_linked_list::get_set(unsigned position_from, unsigned position_to) {
        if (!is_valid(position_from) || !is_valid(position_to) || position_from >= position_to)
            throw "Invalid location";
        int list_length = position_to - position_from + 1;
        std::vector<unsigned> number_list(list_length, 0);
        node *position_pointer = head;

        for (unsigned i = 0; i <= position_to; ++i) {
            if (i >= position_from) {
                number_list[i - position_from] = position_pointer->data;
            }
            position_pointer = position_pointer->next;
        }
        return number_list;
    }

// Add a value to the end of the list
    void doubly_linked_list::append(unsigned data) {
        insert_before(size, data);
    }

// Merge two lists together in place, placing the input list at the end of this list
    void doubly_linked_list::merge(doubly_linked_list rhs) {
        node *rhs_iterator = rhs.head;
        while (rhs_iterator != nullptr) {
            append(rhs_iterator->data);
            rhs_iterator = rhs_iterator->next;
        }
    }

// Allow for the merging of two lists using the + operator.
    doubly_linked_list doubly_linked_list::operator+(const doubly_linked_list &rhs) const {
        doubly_linked_list result(*this);
        result.merge(doubly_linked_list(rhs));

        return result;
    }

// Insert a node before the node located at position
    void doubly_linked_list::insert_before(unsigned position, unsigned data) {
        if (!is_valid(position) && position != size)
            throw "Invalid Position";
        if (position == 0) {
            if(size == 0){
                head = tail = new node(data);
            }else {
                head->prev = new node(data);
                head->prev->next = head;
                head = head->prev;
            }
        } else if (position == size) {
            tail->next = new node(data);
            tail->next->prev = tail;
            tail = tail->next;
        } else {
            node *temp = head;
            for (int i = 0; i < position; ++i) {
                temp = temp->next;
            }
            temp->prev->next = new node(data);
            temp->prev->next->prev = temp->prev;
            temp->prev = temp->prev->next;
            temp->prev->next = temp;
        }
        ++size;
    }

// Insert a node after the node located at position
    void doubly_linked_list::insert_after(unsigned position, unsigned data) {
        if (!is_valid(position))
            throw "Invalid Position";
        insert_before(position + 1, data);
    }

// Remove the node located at position from the linked list
    void doubly_linked_list::remove(unsigned position) {
        if (!is_valid(position))
            throw "Invalid Position";
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else if (position == 0) {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        } else if (position == size - 1) {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        } else {
            node *temp = head;
            for (int i = 0; i < position; ++i) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        --size;
    }

// Split the list with the node being split on being included in the returned list
    doubly_linked_list doubly_linked_list::split_before(unsigned position) {
        if (!is_valid(position) && position != size)
            throw "Invalid Position";
        doubly_linked_list split_list;
        if (position == size) {//return empty list, no change to original list
            return split_list;
        } else if (position == 0)//new list gets whole list, original list becomes empty
        {
            split_list.head = head;
            head = nullptr;
            split_list.tail = tail;
            tail = nullptr;
            split_list.size = size;
            size = 0;
            return split_list;
        } else {
            node *position_pointer = head;
            for (int i = 0; i < position - 1; ++i) {
                position_pointer = position_pointer->next;
            }
            split_list.head = position_pointer->next;
            split_list.tail = tail;
            split_list.head->prev = nullptr;
            position_pointer->next = nullptr;
            tail = position_pointer;
            split_list.size = size - position;
            size = position;
        }
        return split_list;
    }

// Split the list with the node being split on being included in the retained list
    doubly_linked_list doubly_linked_list::split_after(unsigned position) {
        if (!is_valid(position))
            throw "Invalid Position";
        return split_before(position + 1);
    }

// Create two lists, one starting at position_from and ending with position_to and return that list
// Merge the beginning of the original list with the end of the original list and retain it
    doubly_linked_list doubly_linked_list::split_set(unsigned position_from, unsigned position_to) {
        if (!is_valid(position_from) || !is_valid(position_to) || position_from > position_to)
            throw "invalid positions";
        doubly_linked_list split_list(split_before(position_from));
        merge(split_list.split_after(position_to - position_from));
        return split_list;
    }

// Swap two nodes in the list. USE POINTERS. Do not just swap the values!
    void doubly_linked_list::swap(unsigned position1, unsigned position2) {
        swap_set(position1, position1, position2, position2);
    }

// Swap two sets of cards. The sets are inclusive. USE POINTERS!
    void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                      unsigned position2_to) {
        if (!is_valid(position1_from) || !is_valid(position1_to) || !is_valid(position2_from) ||
            !is_valid(position2_to))
            throw "Invalid Position";
        if (position1_from > position1_to || position2_from > position2_to)
            throw "Invalid Position";
        if (position1_to >= position2_from && position1_to <= position2_to)
            throw "Invalid Position: Sets Cannot intersect";
        if (position1_from >= position2_from && position1_from <= position2_to)
            throw "Invalid Position: Sets Cannot intersect";

        if (position1_from > position2_from) {
            unsigned tmp = position1_from;
            position1_from = position2_from;
            position2_from = tmp;
            tmp = position1_to;
            position1_to = position2_to;
            position2_to = tmp;
        }

        doubly_linked_list swap_list1(split_before(position1_from));
        doubly_linked_list sublist1(swap_list1.split_after(position1_to - position1_from));
        doubly_linked_list swap_list2(sublist1.split_before(position2_from - position1_to - 1));
        doubly_linked_list sublist2(swap_list2.split_after(position2_to - position2_from));

        merge(swap_list2);
        merge(sublist1);
        merge(swap_list1);
        merge(sublist2);

    }

// Overload operator=
    doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {
        while (head != nullptr)
            remove(0);
        size = RHS.size;
        head = tail = new node(RHS.head->data);
        for (node *temp = RHS.head->next; temp != nullptr; temp = temp->next) {
            tail->next = new node(temp->data);
            tail->next->prev = tail;
            tail = tail->next;
        }
        return *this;
    }

// Append the rhs to the end of the this list
    doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
        *this = *this + RHS;
        return *this;
    }

    unsigned doubly_linked_list::get_size() {
        return size;
    }

    bool doubly_linked_list::is_empty() {
        return !size;
    }

    bool doubly_linked_list::is_valid(unsigned position) {
        return (position >= 0 && position < size);
    }

    bool doubly_linked_list::operator==(const doubly_linked_list &rhs) const {
        node * iterL=head, * iterR = rhs.head;
        while(iterL!= nullptr && iterR!= nullptr){
            if (iterL->data != iterR->data)
                return false;
            iterL = iterL->next;
            iterR = iterR->next;
        }
        return iterL == nullptr && iterR == nullptr;
    }

    std::string doubly_linked_list::to_string() {
        if(!head) return "";
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