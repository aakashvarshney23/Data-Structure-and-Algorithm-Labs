#include "node.h"
#include <iostream>

namespace lab4 {
    node::node() {
        next = nullptr;
        data = 0;
    }

    // Take in value and create a node
    node::node(int input) {
        data = input;
        next = nullptr;
    }

    // Takes in an array of values and creates the appropriate nodes
    node::node(int values[], int length) {
        node *temp;
        temp = this;
        temp->data = values[0];
        for (int i = 1; i < length; i++) {
            temp->next = new node(values[i]);
            temp = temp->next;
        }
    }

    // Default destructor
    node::~node() {
        // Hint: You don't want to just delete the current node. You need to keep track of what is next
    }

    // Add a value to the end node
    void node::append(int input) {
        node *temp = this;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new node(input);

    }

    // Add an array of values to the end as separate nodes
    void node::append(int inputs[], int length) {
        node *temp = this;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        for (int i = 0; i < length; i++) {
            temp->next = new node(inputs, length);
            temp->next = new node(inputs[i]);
            temp = temp->next;
        }

    }

    // Insert a new node after the given location
    node *node::insert(int location, int value) {
        // Must return head pointer location
        node *temp;
        temp = this;

        node *temp1 = new node(value);

        for (int i = 1; i <= location; i++)
            temp = temp->next;

        temp1->next = temp->next;
        temp->next = temp1;
        return this;
    }

    // Remove a node and link the next node to the previous node
    node *node::remove(int location) {
        // Must return head pointer location
        node *temp;
        temp = this;
        if (location == 0) {
            temp = temp->next;
            return temp;
        } else if (location != 0) {
            for (int i = 1; i < location; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            return this;
        }
    }

// Print all nodes
    void node::print() {
        node *temp;
        temp = this;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        if (temp == nullptr)
            std::cout << "null";

    }

//Print the middle node
    void node::print_middle() {
        node *runner;
        node *temp = this;
        int count = 0;
        runner = this;
        while (runner != nullptr) {
            count++;
            runner = runner->next;
        }
        if (count % 2 == 1) {
            int print_loc = count / 2;
            for (int i = 0; i < print_loc; i++)
                temp = temp->next;

        } else if (count % 2 == 0) {
            int print_loc = count / 2 - 1;
            for (int i = 0; i < print_loc; i++)
                temp = temp->next;

        }
        std::cout << temp->data;
    }

// Get the value of a given node
    int node::get_value(int location) {
        node *temp = this;
        int i = 0;
        while (i < location) {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

// Overwrite the value of a given node
    void node::set_data(int location, int value) {
        node *temp;
        temp = this;
        for (int i = 0; i < location; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }
}