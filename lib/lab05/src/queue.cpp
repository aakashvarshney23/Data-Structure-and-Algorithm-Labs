#include "../inc/queue.h"
#include <iostream>
namespace lab5 {
    queue::queue() :head(nullptr),tail(nullptr),size(0){}

    queue::queue(std::string &data) {
        head=tail=new node(data);
        size=1;
    }

    queue::queue(const queue &original) {
        if (original.head!= nullptr) {
            node *original_tmp = original.head;
            node *tmp = head = new node(original_tmp->data);
            size = original.size;

            original_tmp = original_tmp->next;
            while (original_tmp != nullptr) {
                tmp->next = new node(original_tmp->data);
                tmp = tmp->next;
                tail=tmp;
                original_tmp = original_tmp->next;
            }
        } else{
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
    }

    queue::~queue() {
        while(head != nullptr)
            dequeue();
    }

    queue &queue::operator=(const queue &RHS) {
        if(this != &RHS)
        {
            if (head!= nullptr)
                delete this;
            if (RHS.head!= nullptr) {

                node *RHS_tmp = RHS.head;
                node *tmp = head = new node(RHS_tmp->data);
                size=RHS.size;
                RHS_tmp = RHS_tmp->next;
                while (RHS_tmp != nullptr) {
                    tmp->next=new node(RHS_tmp->data);
                    tmp=tmp->next;
                    tail=tmp;
                    RHS_tmp = RHS_tmp->next;
                }
            }
        }
        return *this;
    }

    bool queue::isEmpty() const {
        return size==0;
    }

    unsigned queue::queueSize() const {
        return size;
    }

    std::string queue::top() const {
        return head->data;
    }

    void queue::enqueue(std::string &data) {
        node* temp = new node(data);
        if(tail!= nullptr)
            tail->next = temp;
        tail = temp;
        if(head== nullptr){
            head = tail;
        }
        ++size;
    }

    void queue::dequeue() {
        if(head==tail){
            tail= nullptr;
            delete head;
            head = nullptr;
        }
        else
        {
            node* temp=head->next;
            delete head;
            head=temp;
        }
        --size;
    }
}