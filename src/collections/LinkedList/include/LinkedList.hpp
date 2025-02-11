#pragma once

#include <cstddef>
#include <stdexcept>

#include "../../Sequence/include/Sequence.hpp"

#define LINKEDLIST_EMPTY "LinkedListSmart is empty\n"
#define LINKEDLIST_OUT_OF_RANGE "Index out of range\n"
#define LINKEDLIST_SUBSEQ_ERR "Invalid subsequence indices\n"

template <typename T>
class LinkedList : public Sequence<T> {
   private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node() : next(nullptr), prev(nullptr) {}
        Node(T value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}
    };
    Node head;
    size_t size;
    Node* FindNode(size_t index) {
        if (index > size) {
            throw std::out_of_range(LINKEDLIST_OUT_OF_RANGE);
        }
        Node* current = &head;
        for (size_t i = 0; i <= index; ++i) {
            current = current->next;
        }
        return current;
    }
    const Node* FindNode(size_t index) const {
        if (index > size) {
            throw std::out_of_range(LINKEDLIST_OUT_OF_RANGE);
        }
        const Node* current = &head;
        for (size_t i = 0; i <= index; ++i) {
            current = current->next;
        }
        return current;
    }
    void Clear() {
        while (head.next != &head) {
            RemoveAt(0);
        }
    }

   public:
    LinkedList() : head(T(), &head, &head), size(0) {}
    ~LinkedList() {
        while (head.next != &head) {
            RemoveAt(0);
        }
    }
    LinkedList& operator=(const LinkedList& other) {
        Clear();
        for (size_t i = 0; i < other.size; ++i) {
            Append(other.Get(i));
        }
        size = other.size;
        return *this;
    }
    T& GetFirst() override {
        if (head.next) {
            return head.next->value;
        }
        throw std::out_of_range(LINKEDLIST_EMPTY);
    }
    const T& GetFirst() const override {
        if (head.next) {
            return head.next->value;
        }
        throw std::out_of_range(LINKEDLIST_EMPTY);
    }
    T& GetLast() override {
        if (head.prev) {
            return head.prev->value;
        }
        throw std::out_of_range(LINKEDLIST_EMPTY);
    }
    const T& GetLast() const override {
        if (head.prev) {
            return head.prev->value;
        }
        throw std::out_of_range(LINKEDLIST_EMPTY);
    }
    T& Get(size_t index) override { return FindNode(index)->value; }
    const T& Get(size_t index) const override { return FindNode(index)->value; }
    size_t GetLength() const override { return size; }
    void Append(const T& value) override {
        auto prev = head.prev;
        prev->next = new Node(value, &head, prev);
        head.prev = prev->next;
        ++size;
    }
    void Prepend(const T& value) override {
        auto next = head.next;
        next->prev = new Node(value, next, &head);
        head.next = next->prev;
        ++size;
    }
    void InsertAt(const T& value, size_t index) override {
        auto node = FindNode(index);
        auto next = node->next;
        node->next = new Node(value, next, node);
        next->prev = node->next;
        ++size;
    }
    void RemoveAt(size_t index) override {
        auto node = FindNode(index);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --size;
    }
};