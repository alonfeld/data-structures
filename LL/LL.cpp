#include <iostream>
#include "LL.hpp"

// Basic CTOR
LL::LL() {
    this->head = nullptr;
    this->last = nullptr;
    this->size = 0;
}

void LL::add(int data) {
    LlNode* newNode;
    newNode = new LlNode();
    newNode->data = data;
    if(this->head == nullptr) {
        this->head = newNode;
        this->last = newNode;    
    } else {
        this->last->next = newNode;
        this->last = newNode;
    }
    this->size++;
    std::cout << "LL::add: added data " << data << " to end of list." << std::endl; 
}

void LL::addFirst(int data) {
    LlNode* newNode;
    newNode = new LlNode();
    newNode->data = data;
    newNode->next = this->head;
    this->head = newNode;
    this->size++;
    std::cout << "LL::add: added data " << data << " to start of list." << std::endl; 
}

void LL::addInPlace(int data, unsigned int location) {
    LlNode* newNode;
    LlNode* tmp;
    
    if( this->head == nullptr ) {
        std::cout << "LL::addInPlace: List is empty." << std::endl;
        return; // TODO: throw exception
    }

    if( location == 0 ) {
        std::cout << "LL::addInPlace: location 0 is not supported." << std::endl;
        return; // TODO: throw exception
    }

        if( location > this->size+1 ) {
        std::cout << "LL::addInPlace: location is larger than list size." << std::endl;
        return; // TODO: throw exception
    }

    if( location == 1 ) {
        addFirst(data);        
    } else if( location == this->size+1 ) {
        add(data);
    } else {
        tmp = this->head;
        int i=1;
        for(;i<location-1;i++) {
            if( tmp->next != nullptr ) {
                tmp = tmp->next;
            } else {
                std::cout << "LL::addInPlace: exception - list is broken." << std::endl;
                return; // TODO: throw exception
            }
        }

        std::cout << "LL::addInPlace: adding data " << data << " to location " << i << "." << std::endl;

        newNode = new LlNode();
        newNode->data = data;
        newNode->next = tmp->next;
        tmp->next = newNode;
        this->size++;
    }
}

int LL::removeLast() {
    LlNode* tmp;

    if(this->head == nullptr ) {
        std::cout << "LL::removeLast: exception - empty list." << std::endl;
        //TODO: throw exception
        return -1;
    }

    if(this->head == this->last) {
        int data = this->head->data;
        delete this->head;
        this->head = nullptr;
        this->last = nullptr;
        this->size = 0;
        return data;
    }

    tmp = this->head;
    while(tmp->next != this->last) {
        tmp = tmp->next;
    }

    int data = this->last->data;
    delete this->last;
    this->last = tmp;
    this->size--;

    return data;
}

int LL::removeFirst() {
    if(this->head == nullptr ) {
        std::cout << "LL::removeFirst: exception - empty list." << std::endl;
        //TODO: throw exception
        return -1;
    }

    if(this->head == this->last) {
        int data = this->head->data;
        delete this->head;
        this->head = nullptr;
        this->last = nullptr;
        this->size = 0;
        return data;
    }        

    int data = this->head->data;
    LlNode* tmp = this->head->next;
    delete this->head;
    this->head = tmp;
    this->size--;

    return data;
}

void LL::printList() {
    if(this->head == nullptr ) {
        std::cout << "LL::printList: List is empty" << std::endl;
        if(this->last != nullptr) {
            std::cout << "LL::printList: Exception List is empty but last iss not null!" << std::endl;    
        }
        return;
    }
    std::cout << "LL::printList: List size: " << this->size << std::endl;

    LlNode* tmp { this->head };
    while(tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
    std::cout << "LL::printList: Head: " << this->head->data << std::endl;
    std::cout << "LL::printList: Last: " << this->last->data << std::endl;
}
