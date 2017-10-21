#include "../inc/node.h"
#include <iostream>

namespace lab4 {
    // Take in value and create a node
    node::node(int input)
    {
        data= input;
        next = nullptr;
    }
    // Takes in an array of values and creates the appropriate nodes
    node::node(int values[], int length)
    {
        this->data=values[0];
        node*tmp=this;
        for(int i=1; i < length; i++){
            tmp ->next=new node(values[i]);
            tmp = tmp->next;
        }
    }

    // Default destructor
    node::~node(){}

    // Add a value to the end node
    void node::append(int input)
    {
        node * tmp=this;
        while(tmp->next != nullptr)
            tmp = tmp->next;
        tmp->next=new node(input);
    }

    // Add an array of values to the end as separate nodes
    void node::append(int inputs[], int length)
    {
        node * tmp=this;
        while(tmp->next != nullptr)
            tmp = tmp->next;
        for(int i=0; i < length; i++){
            tmp ->next=new node(inputs[i]);
            tmp = tmp->next;
        }
    }

    // Insert a new node after the given location
    node* node::insert(int location, int value)
    {

        node * tmp_base= this;
        node * tmp_break= nullptr;
        for(int i=0; i< location; ++i){
            if(tmp_base->next== nullptr)
            {
                std::cout << "Error: invalid location";
                throw 1;
            }
            tmp_base=tmp_base->next;
        }
        if(tmp_base->next== nullptr)
            tmp_base->next=new node(value);
        else
        {
            tmp_break=tmp_base->next;
            tmp_base->next=new node(value);
            tmp_base->next->next=tmp_break;
        }
        return this;
    }

    // Remove a node and link the next node to the previous node
    node* node::remove(int location)
    {
        if(location==0)//needed to update head
        {
            node * tmp = this->next;
            delete this;
            return tmp;
        }
        node * tmp_base= this;
        node * tmp_break= nullptr;
        for(int i=0; i< location-1; ++i){
            if(tmp_base->next== nullptr)
            {
                std::cout << "Error: invalid location";
                throw 2;
            }
            tmp_base=tmp_base->next;
        }
        if(tmp_base->next == nullptr)
        {
            throw 2;
        }
        else if(tmp_base->next->next != nullptr) {
            tmp_break = tmp_base->next->next;
            delete tmp_base->next;
            tmp_base ->next = tmp_break;
        }
        else
        {
            delete tmp_base->next;
        }
        return this; // Must return head pointer location
    }

    // Print all nodes
    void node::print()
    {
        node * tmp = this;
        while (tmp != nullptr){
            std::cout << tmp ->data << "->" ;
            tmp = tmp->next;
        }
        std::cout << "null" << std::endl;
    }

    //Print the middle node
    void node::print_middle()
    {
        node * slow=this,*fast=this;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        std::cout << slow->data << std::endl;
        // HINT: Use a runner to traverse through the linked list at two different rates, 1 node per step
        //       and two nodes per step. When the faster one reaches the end, the slow one should be
        //       pointing to the middle
    }

    // Get the value of a given node
    int node::get_value(int location)
    {
        node * tmp_base=this;
        for(int i=0; i< location; ++i){
            if(tmp_base->next== nullptr)
            {
                std::cout << "Error: invalid location";
                throw 1;
            }
            tmp_base=tmp_base->next;
        }
        return tmp_base->data;
    }

    // Overwrite the value of a given node
    void node::set_data(int location, int value)
    {
        node * tmp_base=this;
        for(int i=0; i< location; ++i){
            if(tmp_base->next== nullptr)
            {
                std::cout << "Error: invalid location";
                throw 1;
            }
            tmp_base=tmp_base->next;
        }
        tmp_base->data=value;
    }
}