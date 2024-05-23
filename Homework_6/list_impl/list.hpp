#pragma once
#include <stdexcept>
#include <cstddef>

template <typename T>
class Node {
    public:
        T m_data;
        Node* m_prev;
        Node* m_next;
        Node(const T& data) : m_data(data), m_prev(nullptr), m_next(nullptr) {}
};

template<typename T>
class List {
    private:
      Node<T>* head;
      Node<T>* tail;
      size_t m_size;
    public:
      List() : head(nullptr), tail(nullptr), m_size(0) {}
      List(const List& other);
      List(List&& other);
      ~List();
      List& operator=(const List& other);
      List& operator=(List&& other);
      T& front();
      T& back();
      void push_back(const T& value);
      void push_front(const T& value);
      void pop_back();
      void pop_front();
      void push_back();
      void insert(size_t position, const T& value);
      void erase(size_t position);
      void clear();
      size_t size() const;
      bool empty() const;

      class Iterator {
        private:
          Node<T>* current;
        public:
          Iterator(Node<T>* node) : current(node) {}
          Iterator& operator++();
          Iterator& operator++(int);
          Iterator& operator--();
          Iterator& operator--(int);
          bool operator==(const Iterator& other) const;
          bool operator!=(const Iterator& other) const;
          T& operator*();
    };
    Iterator begin();
    Iterator end();
};
#include "list.inl"