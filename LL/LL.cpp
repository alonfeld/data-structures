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
        std::cout << "LL::add: added sole node [" << newNode << "] with data " << data << " to list." << std::endl;   
    } else {
        std::cout << "LL::add: adding node [" << newNode << "] with data " << data << " to end of list after [" << this->last << "]." << std::endl; 
        this->last->next = newNode;
        this->last = newNode;
    }
    this->size++;
}

void LL::addFirst(int data) {
    LlNode* newNode;
    newNode = new LlNode();

    std::cout << "LL::add: adding node [" << newNode << "] with data " << data << " to start of list before [" << this->head << "]." << std::endl; 
    
    newNode->data = data;
    newNode->next = this->head;
    this->head = newNode;
    this->size++;
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
        std::cout << "LL::addInPlace: location " << location << " is larger than list size " << this->size << "." << std::endl;
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

        newNode = new LlNode();
        newNode->data = data;
        newNode->next = tmp->next;
        tmp->next = newNode;
        this->size++;

        std::cout << "LL::addInPlace: added node [addr  data  location  prevAddr]: [" << newNode << "  " << data << "  " << i << "  " << tmp << "]." << std::endl;
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

        std::cout << "LL::removeFirst: removing single node [" << this->head << "  " << data << "]." << std::endl;

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

    std::cout << "LL::removeLast: removing node [" << this->last << "  " << data <<  "]. prev [" << tmp << "]" << std::endl;

    delete this->last;
    tmp->next = nullptr;
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

        std::cout << "LL::removeFirst: removing single node [" << this->head << "  " << data << "]." << std::endl;

        delete this->head;
        this->head = nullptr;
        this->last = nullptr;
        this->size = 0;
        return data;
    }        

    int data = this->head->data;
    LlNode* tmp = this->head->next;

    std::cout << "LL::removeFirst: removing node [" << this->head << "  " << data <<  "]. next [" << tmp << "]" << std::endl;

    delete this->head;
    this->head = tmp;
    this->size--;

    return data;
}

void LL::deleteList() {
    std::cout << "LL::deleteList: deleting list." << std::endl;
    LlNode* itr { this->head };
    LlNode* tmp;
    while(itr != nullptr) {
        std::cout << itr << " " << itr->data << std::endl;
        tmp = itr;
        itr = itr->next;
        delete tmp;        
    }
    this->head = nullptr;
    this->last = nullptr;
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
        std::cout << tmp << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;

    tmp = this->head;
    while(tmp != nullptr) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }    

    std::cout << std::endl;
    std::cout << "LL::printList: Head: " << this->head->data << std::endl;
    std::cout << "LL::printList: Last: " << this->last->data << std::endl;
}
