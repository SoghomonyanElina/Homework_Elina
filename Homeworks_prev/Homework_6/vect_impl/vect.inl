#include "vect.hpp"
template <typename T>
My_Vector<T>::My_Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

template <typename T> 
My_Vector<T>::My_Vector(const My_Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    std::cout << "Copy ctor" << std::endl;
    m_data = static_cast<T*>(std::malloc(m_capacity * sizeof(T)));
    if(!m_data) {
        throw std::bad_alloc();
    }
    for(size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
    /*Iterator it_1 = begin();
    for(Iterator it_2 = other.begin(); it_2 != other.end(); ++it_2, ++it_1) {
        *it_1 = *it_2;
    }*/
}

template <typename T>
My_Vector<T>::My_Vector(My_Vector&& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    std::cout << "Move ctor" << std::endl;
    m_data = static_cast<T*>(std::malloc(m_capacity * sizeof(T)));
    if(!m_data) {
        throw std::bad_alloc();
    }
    for(size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
    other.m_size = other.m_capacity = 0;
    other.m_data = nullptr;
}

template <typename T> 
My_Vector<T>::~My_Vector() {
    clear();
}

template <typename T>
T& My_Vector<T>::operator[](size_t index) {
    if(index >= m_size) {
        throw std::out_of_range("The index is out of range");
    }
    return m_data[index];
}

template <typename T>
const T& My_Vector<T>::operator[](size_t index) const {
    if(index >= m_size) {
        throw std::out_of_range("The index is out of range");
    }
    return m_data[index];
}

template <typename T>
My_Vector<T>& My_Vector<T>::operator=(const My_Vector& other) {
    std::cout << "Copy assignment operator" << std::endl;
    if(this != &other) {
        clear();
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = static_cast<T*>(std::malloc(m_capacity * sizeof(T)));
        if(!m_data) {
            throw std::bad_alloc();
        }
        for(size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
        /*Iterator it_1 = begin();
        for(Iterator it_2 = other.begin(); it_2 != other.end(); ++it_2, ++it_1) {
            *it_1 = *it_2;
        }*/
    }
    return *this;
}

template<typename T>
My_Vector<T>& My_Vector<T>::operator=(My_Vector&& other) {
    std::cout << "Move assignment operator" << std::endl;
    if(this != &other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;
        other.m_size = other.m_capacity = 0;
        other.m_data = nullptr;
    }
    return *this;
}

template <typename T>
void My_Vector<T>::push_back(const T& value) {
    if(m_capacity <= m_size + 1) {
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        m_data = static_cast<T*>(std::realloc(m_data, m_capacity * sizeof(T)));
        if(!m_data) {
            throw std::bad_alloc();
        }
    }
    m_data[m_size] = value;
    //auto it = end();
    //m_data[it] = value;
    ++m_size;
}

template <typename T>
void My_Vector<T>::pop_back() {
    if(m_size <= 0) {
        throw std::out_of_range("Vector is empty");
    }
    else{
        --m_size;
    }
}

template <typename T>
void My_Vector<T>::push_front(const T& value) {
    size_t position = 0;
    insert(position, value);
}

template <typename T>
void My_Vector<T>::pop_front() {
    if(m_size > 0) {
        size_t position = 0;
        erase(position);
    }
    else {
        throw std::out_of_range("Vector is empty");
    }
}

template <typename T>
void My_Vector<T>::insert(size_t position, const T& value) {
    if(position > m_size) {
        throw std::out_of_range("Position is out of range");
    }
    if(m_capacity <= m_size + 1) {
        m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        m_data = static_cast<T*>(std::realloc(m_data, m_capacity * sizeof(T)));
        if(!m_data) {
            throw std::bad_alloc();
        }
    }
    for(size_t i = m_size; i != position; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[position] = value;
    ++m_size;
}

template <typename T>
void My_Vector<T>::erase(size_t position) {
    if(position >= m_size) {
        throw std::out_of_range("Position is out of range");
    }
    for(size_t i = position; i != m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    --m_size;
}

template <typename T>
void My_Vector<T>::clear() {
    std::free(m_data);
    m_data = nullptr;
    m_size = m_capacity = 0;
}

template <typename T>
size_t My_Vector<T>::size() {
    return m_size;
}

template <typename T>
typename My_Vector<T>::Iterator My_Vector<T>::begin() {
    return Iterator(m_data);
}

template <typename T>
typename My_Vector<T>::Iterator My_Vector<T>::end() {
    return Iterator(m_data + m_size);
}

template <typename T>
T& My_Vector<T>::front() {
    if(empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return m_data[0];
    //return m_data[begin()];
}

template <typename T>
T& My_Vector<T>::back() {
    if(empty()) {
        throw std::out_of_range("Vector is empty");
    }
    return m_data[m_size - 1];
}

template <typename T>
void My_Vector<T>::print() {
    /*for(size_t i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << ' ';
    }*/
    for(auto it = begin(); it != end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
bool My_Vector<T>::empty() {
    if(m_size) {
        return false;
    }
    return true;
}










