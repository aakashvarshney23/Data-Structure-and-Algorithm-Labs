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
        tail = head = temp;
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
        if (position > size) {
            return tail->data;
        }

        for (int i = 0; i < position; i++) {
            if (temp->next == nullptr) {
                std::cout << "That location does not exist!!" << std::endl;
                return 0;
            }

            temp = temp->next;
        }
        return temp->data;
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
        node *newnode;
        node *list;
        doubly_linked_list answer = *this;
        //variable used for holding the linked list

        //ptr pts to the first node of the given list
        list = rhs.head;
        //check to make sure the list is not empty and add list if there is something
        while (list != nullptr) {
            answer.append(list->data);
            list = list->next;
        }
        return answer;
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

        node *temp1 = head;
        unsigned count = 0;
        if (position2 < position1) {
            unsigned value = 0;
            value = position2;
            position2 = position1;
            position1 = value;
        }
        if (position2 == position1) {
            throw "Error: Node can't be swapped with itself.";
        }
        if (position2 > size || position1 > size) {
            throw "Error: One or both of the positions are outside the linked list.";
        }
        swap_set(position1, position1, position2, position2);
    }

    // Swap two sets of cards. The sets are inclusive. USE POINTERS!
    void doubly_linked_list::swap_set(unsigned position1_from, unsigned position1_to, unsigned position2_from,
                                      unsigned position2_to) {
        node *temp1 = head;
        unsigned count = 0;
        if (position1_from > position1_to || position2_from > position2_to) {
            if (position1_from > position1_to && position2_from > position2_to) {
                unsigned value1;
                value1 = position1_from;
                position1_from = position1_to;
                position1_to = value1;
                unsigned value2;
                value2 = position2_from;
                position2_from = position2_to;
                position2_to = value2;
            }
            if (position1_from > position1_to) {
                unsigned value1;
                value1 = position1_from;
                position1_from = position1_to;
                position1_to = value1;
            }
            if (position2_from > position2_to) {
                unsigned value2;
                value2 = position2_from;
                position2_from = position2_to;
                position2_to = value2;
            }
        }
        if (size < position1_from || size < position1_to || size < position2_from || size < position2_to) {
            throw "Position doesn't exist";
        }
        if (position1_from > position2_from || position1_to > position2_from || position1_from > position2_to ||
            position1_to > position2_to) {
            if (position2_to < position1_from) {
                unsigned value1, value2;
                value1 = position2_from;
                value2 = position2_to;
                position2_from = position1_from;
                position2_to = position1_to;
                position1_from = value1;
                position1_to = value2;
            } else if (position2_to < position1_to && position2_from < position1_from) {
                unsigned value;
                value = position2_from;
                position2_to = position1_to;
                position2_from = position2_to;
                position1_to = position1_from;
                position1_from = value;
            } else if (position2_from < position1_from) {
                unsigned value;
                value = position2_from;
                position2_from = position1_to;
                position1_to = position1_from;
                position1_from = value;
            } else
            {
                unsigned value;
                value = position2_from;
                position2_from = position1_to;
                position1_to = value;
            }
        }
        while (count != position1_from) {
            temp1 = temp1->next;
            count++;
        }
        node *saver_from1 = temp1;
        while (count != position1_to) {
            temp1 = temp1->next;
            count++;
        }
        node *saver_to1 = temp1;
        node *temp2 = temp1;
        while (count != position2_from) {
            temp2 = temp2->next;
            count++;
        }
        node *saver_from2 = temp2;
        while (count != position2_to) {
            temp2 = temp2->next;
            count++;
        }
        node *saver_to2 = temp2;
        if (saver_to1->next == saver_from2 &&
            saver_from2->prev == saver_to1)
        {
            node *temp1_prev = saver_to1->prev;
            node *temp2_next = saver_to2->next;
            if (saver_from1->prev != nullptr) {
                temp1_prev->next = saver_from2;
            }
            if (saver_to2->next != nullptr) {
                temp2_next->prev = saver_to1;
            }
            saver_from2->prev = temp1_prev;
            saver_to1->next = temp2_next;
            saver_from1->prev = saver_to2;
            saver_to2->next = saver_from1;
        } else if (saver_to1->next !=
                   saver_from2->prev)
        {
            node *temp1_prev = saver_from1->prev;
            node *temp1_next = saver_to1->next;
            node *temp2_prev = saver_from2->prev;
            node *temp2_next = saver_to2->next;
            temp2_prev->next = saver_from1;
            if (saver_from1->prev != nullptr) {
                temp1_prev->next = saver_from2;
            }
            temp1_next->prev = saver_to2;
            saver_to1->next = temp2_next;
            saver_from1->prev = temp2_prev;
            if (saver_to2->next != nullptr) {
                temp2_next->prev = saver_from1;
            }
            saver_to2->next = temp1_next;
            saver_from2->prev = temp1_prev;
        } else
        {
            node *temp1_prev = saver_from1->prev;
            node *temp_middle = saver_to1->next;
            node *temp2_next = saver_to2->next;
            temp_middle->next = saver_from1;
            temp_middle->prev = saver_to2;
            if (temp1_prev != nullptr) {
                temp1_prev->next = saver_from2;
            }
            if (temp2_next != nullptr) {
                temp2_next->prev = saver_to1;
            }
            saver_to1->next = temp2_next;
            saver_from1->prev = temp_middle;
            saver_to2->next = temp_middle;
            saver_from2->prev = temp1_prev;
        }
        if (saver_from2->prev == nullptr) {
            head = saver_from2;
        }
        if (saver_to1->next == nullptr) {
            tail = saver_to1;
        }
    }

// Overload operator=
    doubly_linked_list &doubly_linked_list::operator=(const doubly_linked_list &RHS) {
        node *look;
        node *newnode;
        node *temp = RHS.head;
        if (head) {
            while (head) {
                look = head;
                head = head->next;
                delete look;
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
            head = new node(temp->data);
            tail = head;
            temp = temp->next;
            while (temp) {
                newnode = new node(temp->data);
                tail->next = newnode;
                tail = newnode;
                temp = temp->next;
            }
        }
    }

// Append the rhs to the end of the this list
    doubly_linked_list &doubly_linked_list::operator+=(const doubly_linked_list &RHS) {
        doubly_linked_list obj1 = *this + RHS;
        *this = obj1;
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

    void doubly_linked_list::swap_data(unsigned position1, unsigned position2){
        node *temp1 = head;
        node *temp2 = head;
        node *prev1=nullptr;
        node *next1=nullptr;
        node *prev2=nullptr;
        node *next2=nullptr;

        for(int i=0; i<position1; i++) {
            if (temp1->next != nullptr) {
                prev1 = temp1;
                temp1 = temp1->next;
            }
        }
        next1 = temp1->next;

        for(int i=0; i<position2; i++){
            if(temp2->next != nullptr){
                prev2 = temp2;
                temp2 = temp2->next;
            }
        }
        next2 = temp2->next;

        int temp;
        temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
    }
    void doubly_linked_list::setter(int location, int value){
        node* temp= head;
        int temploc=0;

        while(temp!= nullptr && temploc++ != location){
            temp = temp->next;
        }

        temp->data = value;
    }
}
