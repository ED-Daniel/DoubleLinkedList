//
// Created by MSI GS66 Stealth on 11.03.2022.
//

#ifndef DOUBLELINKEDLIST_LINKEDLIST_H
#define DOUBLELINKEDLIST_LINKEDLIST_H

#include <iostream>

template<typename ListNode>
class ListIterator {
public:
    using NodeValueType = typename ListNode::ValueType;
    using ValueType = ListNode;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    using difference_type = ListNode;
    using iterator_category = std::forward_iterator_tag;

    ListIterator(PointerType ptr) : current(ptr) {}

    ListIterator& operator++() {
        current = current->next;
        return (*this);
    }

    ListIterator operator++(int) {
        ListIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    ListIterator& operator--() {
        current = current->previous;
        return (*this);
    }

    ListIterator operator--(int) {
        ListIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[] (int index) {
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

    PointerType operator->() {
        return current;
    }

    NodeValueType& operator*() {
        return current->data;
    };

    bool operator==(const ListIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const ListIterator& other) const {
        return current != other.current;
    }


private:
    PointerType current;
};

template<typename ListNode>
class RandomAccessIterator {
public:
    template<typename T>
    friend struct std::iterator_traits;
    using node_type = typename ListNode::ValueType;
    using node_reference = node_type&;
    using value_type = ListNode;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = std::random_access_iterator_tag;

    explicit RandomAccessIterator(pointer ptr) : current(ptr) {}

    RandomAccessIterator& operator++() {
        current = current->next;
        return (*this);
    }

    RandomAccessIterator operator++(int) {
        RandomAccessIterator iterator = *this;
        current = current->next;
        return iterator;
    }

    RandomAccessIterator& operator--() {
        current = current->previous;
        return (*this);
    }

    RandomAccessIterator operator--(int) {
        RandomAccessIterator iterator = *this;
        current = current->previous;
        return iterator;
    }

    friend RandomAccessIterator& operator+= (RandomAccessIterator& lhs, difference_type rhs)
    {
        difference_type m = rhs;
        if (m >= 0) while (m--) ++lhs;
        else while (m++) --lhs;
        return lhs;
    }

    friend RandomAccessIterator operator+ (RandomAccessIterator lhs, difference_type rhs) {
        RandomAccessIterator temp = lhs;
        return temp += rhs;
    }

    friend RandomAccessIterator operator+ (difference_type lhs, RandomAccessIterator rhs) {
        RandomAccessIterator temp = rhs;
        return temp += lhs;
    }

    friend RandomAccessIterator& operator-= (RandomAccessIterator& lhs, difference_type rhs)
    {
        return lhs += -rhs;
    }

    friend RandomAccessIterator operator- (RandomAccessIterator i, difference_type rhs) {
        RandomAccessIterator temp = i;
        return temp -= rhs;
    }

    friend difference_type operator- (RandomAccessIterator& a, RandomAccessIterator& b) {
        difference_type n = 0;

        pointer tempA = a.current;
        pointer tempB = b.current;

        while (a.current != b.current && b.current != nullptr) {
            n++;
            b.current = b.current->next;
        }
        if (b.current == nullptr) {
            n = 0;

            a.current = tempA;
            b.current = tempB;

            while (a.current != b.current) {
                n--;
                a.current = a.current->next;
            }
        }

        a.current = tempA;
        b.current = tempB;
        return n;
    }

    reference operator[] (int index) {
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }

    pointer operator->() {
        return current;
    }

    node_type& operator*() {
        return current->data;
    };

    bool operator==(const RandomAccessIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const RandomAccessIterator& other) const {
        return current != other.current;
    }

    friend bool operator< (RandomAccessIterator& a, RandomAccessIterator& b)
    {
        return b - a > 0;
    }

    friend bool operator> (RandomAccessIterator& a, RandomAccessIterator& b)
    {
        return b < a;
    }

    friend bool operator>= (RandomAccessIterator& a, RandomAccessIterator& b)
    {
        return !(a < b);
    }

    friend bool operator<= (RandomAccessIterator& a, RandomAccessIterator& b)
    {
        return !(a > b);
    }

private:
    pointer current;
};

template<typename ListNode>
class ReversedListIterator {
public:
    using NodeValueType = typename ListNode::ValueType;
    using ValueType = ListNode;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    ReversedListIterator(PointerType ptr) : current(ptr) {}

    ReversedListIterator& operator++() {
        current = current->previous;
        return (*this);
    }

    ReversedListIterator operator++(int) {
        ReversedListIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReversedListIterator& operator--() {
        current = current->next;
        return (*this);
    }

    ReversedListIterator operator--(int) {
        ReversedListIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    ReferenceType operator[] (int index) {
        for (int i = 0; i < index; ++i) {
            current = current->previous;
        }
        return current;
    }

    PointerType operator->() {
        return current;
    }

    NodeValueType& operator*() {
        return current->data;
    };

    bool operator==(const ReversedListIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const ReversedListIterator& other) const {
        return current != other.current;
    }


private:
    PointerType current;
};

template<typename T>
class ListNode;

template<typename T>
std::ostream & operator<< (std::ostream & out, const ListNode<T> & list_node) {
    out << list_node.data;
    return out;
}

template<typename T>
class ListNode {
private:
    friend std::ostream & operator<< <T>(std::ostream & out, const ListNode<T> & list_node);
public:
    using ValueType = T;

    ListNode(T value, ListNode<T> * previous = nullptr, ListNode<T> * next = nullptr) :
            data(value),
            previous(previous),
            next(next) {}

    T data;
    ListNode<T> * previous;
    ListNode<T> * next;
};

template<typename T>
class LinkedList;

template<typename T>
std::ostream & operator<< (std::ostream & out, const LinkedList<T> & dll) {
    ListNode<T> * current = dll.head;
    while (current != nullptr) {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}

template<typename T>
class LinkedList {
private:
    friend std::ostream & operator<< <T>(std::ostream & out, const LinkedList<T> & dll);
public:
    using Iterator = ListIterator<ListNode<T>>;
    using ReversedIterator = ReversedListIterator<ListNode<T>>;
    using RandomAccessIterator = RandomAccessIterator<ListNode<T>>;

    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        clear();
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        ListNode<T> * current = head;
        while (current != nullptr) current = current->next;
        return Iterator(current);
    }

    ReversedIterator r_begin() {
        ListNode<T> * current = head;
        while (current->next != nullptr) current = current->next;
        return ReversedIterator(current);
    }

    ReversedIterator r_end() {
        return ReversedIterator(head->previous);
    }

    RandomAccessIterator ra_begin() {
        return RandomAccessIterator(head);
    }

    RandomAccessIterator ra_end() {
        ListNode<T> * current = head;
        while (current != nullptr) current = current->next;
        return RandomAccessIterator (current);
    }

    size_t size() {
        size_t count = 0;
        ListNode<T> * current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void push_back(T value) {
        if (head == nullptr) head = new ListNode<T>(value);
        else {
            ListNode<T> * current = head;
            while (current->next != nullptr) current = current->next;
            auto * temp = new ListNode<T>(value, current);
            current->next = temp;
        }
    }

    void push_front(T value) {
        auto * temp = new ListNode<T>(value, nullptr, head);
        temp->next->previous = temp;
        head = temp;
    }

    void pop_back() {
        if (head == nullptr) throw std::out_of_range("Tried to pop from empty list");
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            ListNode<T> * current = head;
            while (current->next != nullptr) current = current->next;
            current->previous->next = nullptr;
            delete current;
        }
    }

    void pop_front() {
        if (head == nullptr) throw std::out_of_range("Tried to pop from empty list");
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            auto * temp = head->next;
            delete head;
            temp->previous = nullptr;
            head = temp;
        }
    }

    void insert(T value, size_t position) {
        if (position == 0) push_front(value);
        else {
            ListNode<T> *current = head;
            for (size_t i = 0; i < position; ++i) {
                current = current->next;
            }
            auto *temp = new ListNode<T>(value, current->previous, current);
            current->previous->next = temp;
            current->previous = temp;
        }
    }

    void erase(size_t start, size_t end) {
        size_t listSize = size();
        if (start < 0) start = 0;
        if (end > listSize) end = listSize;
        if (start == 0 && end == listSize) {
            clear();
            return;
        }

        ListNode<T> * current = head;
        for (size_t i = 0; i < start; ++i) {
            current = current->next;
        }

        ListNode<T> * prev = current->previous;

        for (size_t i = start; i < end; ++i) {
            ListNode<T> * temp = current->next;
            delete current;
            current = temp;
        }

        if (prev == nullptr) {
            head = current;
            current->previous = nullptr;
        }
        else if (current == nullptr) {
            prev->next = nullptr;
        }
        else {
            prev->next = current;
            current->previous = prev;
        }
    }

    void assign(T value, size_t start, size_t end) {
        size_t listSize = size();
        if (start < 0) start = 0;
        if (end > listSize) end = listSize;

        ListNode<T> * current = head;
        for (size_t i = 0; i < start; ++i) {
            current = current->next;
        }

        for (size_t i = start; i < end; ++i) {
            current->data = value;
            current = current->next;
        }
    }

    void swap(size_t position1, size_t position2) {
        size_t listSize = size();
        if (position1 < 0 || position2 < 0 || position1 > listSize || position2 > listSize)
            throw std::out_of_range("List index was out of range");

        ListNode<T> * current1 = head;
        for (size_t i = 0; i < position1; ++i) {
            current1 = current1->next;
        }
        ListNode<T> * current2 = head;
        for (size_t i = 0; i < position2; ++i) {
            current2 = current2->next;
        }

        T temp = current1->data;
        current1->data = current2->data;
        current2->data = temp;
    }

    void resize(size_t new_size, T value) {
        size_t listSize = size();
        if (new_size < listSize) erase(listSize - new_size, listSize);
        else {
            if (head == nullptr) head = new ListNode<T>(value);
            else {
                ListNode<T> *current = head;
                while (current->next != nullptr) current = current->next;
                for (size_t i = 0; i < new_size - listSize; ++i) {
                    auto *temp = new ListNode<T>(value, current);
                    current->next = temp;
                    current = current->next;
                }
            }
        }
    }

    T get_front() {
        if (head == nullptr) throw std::out_of_range("The list was empty");
        return head->data;
    }

    T get_back() {
        if (head == nullptr) throw std::out_of_range("The list was empty");
        ListNode<T> * current = head;
        while (current->next != nullptr) current = current->next;
        return current->data;
    }

    bool empty() { return head == nullptr; }

    void clear() {
        ListNode<T> * current = head;
        while (current != nullptr) {
            ListNode<T> * temp = current->next;
            delete current;
            current = temp;
        }
        head = nullptr;
    }

    void reverse() {
        size_t listSize = size();
        for (size_t i = 0; i < listSize / 2; ++i) {
            swap(i, listSize - i - 1);
        }
    }

    LinkedList<T>& operator=(const LinkedList<T> & other){
        auto cpy = other;
        std::swap(*this, cpy);
        return *this;
    }

private:
    ListNode<T> * head;
};

#endif //DOUBLELINKEDLIST_LINKEDLIST_H
