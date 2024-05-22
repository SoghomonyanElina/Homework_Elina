#include <iostream>
#include <cstdlib>
#include <stdexcept>

#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class My_Vector {
    private:
       T* m_data;
       size_t m_size;
       size_t m_capacity;
    public:
       class Iterator {
        private:
          T* m_iter;
        public:
          Iterator(T* ptr) : m_iter(ptr) {}

          T& operator*() {
            return *m_iter;
          }

          Iterator& operator++() {
            ++m_iter;
            return *this;
          }

          Iterator& operator++(int) {
            //Iterator tmp = *this;
            m_iter++;
            return *this;
            //return tmp; 
          }

          Iterator& operator--() {
            --m_iter;
            return *this;
          }
          
          bool operator==(const Iterator& other) {
            return m_iter == other.m_iter;
          }

          bool operator!=(const Iterator& other) {
            return m_iter != other.m_iter;
          }
        };

        My_Vector();
        My_Vector(const My_Vector& other); //Copy constructor
        My_Vector(My_Vector&& other); //Move constructor
        ~My_Vector();
        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        My_Vector& operator=(const My_Vector& other);
        My_Vector& operator=(My_Vector&& other);
        T& front();
        T& back();
        void push_back(const T& value);
        void pop_back();
        void push_front(const T& value);
        void pop_front();
        void insert(size_t position, const T& value);
        void erase(size_t position);
        void clear();
        size_t size();
        bool empty();
        Iterator begin();
        Iterator end();
        void print();
};
#include "vect.inl"
#endif //VECTOR_HPP