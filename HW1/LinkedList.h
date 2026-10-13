#pragma once
#include<iostream>

#include "Node.h"


template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override { Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    //New from here lower

    void addAnywhere(int position,T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Error: Position outside list" << std::endl;
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }

        Node<T>* previous = head_;

        for (int i = 0; i < position - 1; ++i) {
            previous = previous->next;
        }

        Node<T>* fresh = new Node<T>(value);
        fresh->next = previous->next;
        previous->next = fresh;
        ++size_;

    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Error:Position out of bounds." << std::endl;
            return;
        }
        Node<T>* current = head_;
        if (position == 0) {
            deleteFront();
            return;
        }
        for (int i = 0; i < position-1; ++i) {
            current = current->next;
        }
        Node<T>* doomed = current->next;
        current->next = current->next->next;
        delete doomed->data;
        delete doomed;
        size_--;
    }

    void reverse() override {
        if (head_ == nullptr) {
            std::cout << "Error: LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* previous_node = nullptr;
        Node<T>* current_node = head_;
        Node<T>* next_node = head_->next;

        if (current_node == nullptr) {
            std::cout << "Error: LinkedList is empty" << std::endl;
            return;
        }
        if (next_node == nullptr) {
            std::cout << "Error: Cant Reverse 1 element" << std::endl;
            return;
        }
        while (next_node != nullptr) {
            next_node = current_node->next;
            current_node->next = previous_node;
            previous_node = current_node;
            current_node = next_node;
        }
        head_ = previous_node;
        return;
    }


    void concat(List<T>* other) override {
        LinkedList<T>* other_linked_list =
            dynamic_cast<LinkedList<T>*>(other);

        if (other_linked_list != nullptr) {
            // FIX: Prevent concatenating the list with itself.
            if (other_linked_list == this) {
                return;
            }

            if (other_linked_list->size_ == 0) {
                std::cout << "LinkedList to concat is empty." << std::endl;
                return;
            }

            if (head_ == nullptr) {
                head_ = other_linked_list->head_;
            }
            else {
                Node<T>* current = head_;

                while (current->next != nullptr) {
                    current = current->next;
                }

                current->next = other_linked_list->head_;
            }

            size_ += other_linked_list->size_;

            // Transfer ownership to this list.
            other_linked_list->head_ = nullptr;
            other_linked_list->size_ = 0;
        }
        else {
            std::cout << "LinkedList not found. Cant Concat" << std::endl;
            return;
        }

    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
    int size_;
};