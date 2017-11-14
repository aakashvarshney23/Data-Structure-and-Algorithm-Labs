#include <iostream>
#include "../inc/stack.h"

namespace lab5 {
    stack::stack():head(nullptr), size(0) {}

    stack::stack(std::string &data) {
        head = new node(data);
        size =1;
    }

    stack::stack(const stack &original) {
        if (original.head!= nullptr) {
            node *original_tmp = original.head;
            node *tmp = head = new node(original_tmp->data);
            size=original.size;

            original_tmp = original_tmp->next;
            while (original_tmp != nullptr) {
                tmp->next = new node(original_tmp->data);
                tmp = tmp->next;
                original_tmp = original_tmp->next;
            }
        }else {
            head = nullptr;
            size = 0;
        }
    }

    stack::~stack() {
        while(head != nullptr)
            pop();
    }

    stack &stack::operator=(const stack &RHS) {

        if(this != &RHS)
        {
            if (head!= nullptr)
                delete this;
            if (RHS.head!= nullptr) {
                node *RHS_tmp = RHS.head;
                node *tmp = head = new node(RHS_tmp->data);
                size = RHS.size;
                RHS_tmp = RHS_tmp->next;
                while (RHS_tmp != nullptr) {
                    tmp->next=new node(RHS_tmp->data);
                    tmp=tmp->next;
                    RHS_tmp = RHS_tmp->next;
                }
            }
        }
        return *this;
    }

    bool stack::isEmpty() const {
        return size==0;
    }

    unsigned stack::stackSize() const {
        return size;
    }

    std::string stack::top() const {
        return head->data;
    }

    void stack::push(std::string &data) {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
        ++size;
    }

    void stack::pop() {
        if(head!= nullptr) {
            node *temp = head;
            head = head->next;
            delete temp;
            --size;
        }
        else {
            std::cout << "ERROR: list is empty" << std::endl;
        }
    }
}