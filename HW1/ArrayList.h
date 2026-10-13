#pragma once
#include <iostream>
#include "List.h"

template <typename T>
class ArrayList : public List<T> {
public:
    ArrayList() : size_(0) {}

    void addFront(T* value) override {
        if (size_ >= CAPACITY) {
            std::cout << "Error: ArrayList is full." << std::endl;
            return;
        }

        for (int i = size_; i > 0; --i) {
            data_[i] = data_[i - 1];
        }

        data_[0] = value;
        ++size_;
    }

    void deleteFront() override {
        if (size_ == 0) {
            std::cout << "Error: ArrayList is empty." << std::endl;
            return;
        }

        delete data_[0];

        for (int i = 0; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        --size_;
        data_[size_] = nullptr; // FIX: Clear unused slot.
    }

    bool search(T* value) const override {
        for (int i = 0; i < size_; ++i) {
            if (*data_[i] == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) {
            std::cout << *data_[i] << ",";
        }
        std::cout << std::endl;
    }

    //New from here lower

    void addAnywhere(int position, T* value) override {
        if (position > size_ || position < 0) {
            std::cout << "Invalid Array Position" << std::endl;
            return;
        }

        // FIX: Check capacity before shifting.
        if (size_ >= CAPACITY) {
            std::cout << "Error: ArrayList is full." << std::endl;
            return;
        }

        for (int i = size_; i > position; --i) {
            data_[i] = data_[i - 1];
        }

        // FIX: Insert at the requested position, not index 0.
        data_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        // FIX: position == size_ is also invalid.
        if (position >= size_ || position < 0) {
            std::cout << "Error: Invalid Array Position" << std::endl;
            return;
        }

        // FIX: Delete the removed element before overwriting its pointer.
        delete data_[position];

        for (int i = position; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }

        --size_;
        data_[size_] = nullptr; // FIX: Clear the unused last slot.
    }

    void reverse() override {
        T* temp;
        int j = size_ - 1;
        int i = 0;

        while (i < j) {
            temp = data_[i];
            data_[i] = data_[j];
            data_[j] = temp;
            j--;
            i++;
        }
    }

    void concat(List<T>* other) override {
        ArrayList<T>* other_array_list =
            dynamic_cast<ArrayList<T>*>(other);

        if (other_array_list != nullptr) {
            // FIX: Prevent concatenating the list with itself.
            if (other_array_list == this) {
                return;
            }

            if (other_array_list->size_ == 0) {
                std::cout << "Error: Cannot concat empty list" << std::endl;
                return;
            }

            if (size_ + other_array_list->size_ > CAPACITY) {
                std::cout << "Error: Cannot concat, not enough CAPACiTY ." << std::endl;
                return;
            }

            for (int i = 0; i < other_array_list->size_; ++i) {
                // FIX: Append at the next available destination index.
                data_[size_] = other_array_list->data_[i];

                // Transfer ownership to this list.
                other_array_list->data_[i] = nullptr;
                size_++;
            }

            other_array_list->size_ = 0;
        }
        else {
            std::cout << "Error: ArrayList not found" << std::endl;
            return;
        }
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete data_[i];
        }
    }

private:
    static const int CAPACITY = 20;
    T* data_[CAPACITY];
    int size_;
};
