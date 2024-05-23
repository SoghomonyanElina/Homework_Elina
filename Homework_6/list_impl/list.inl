#include "list.hpp" 

template<typename T>
List<T>::List(const List& other) : head(nullptr), tail(nullptr), m_size(0) {
    for (Node<T>* current = other.head; current != nullptr; current = current->m_next) {
        push_back(current->m_data);
    }
}

template<typename T>
List<T>::List(List&& other) : head(other.head), tail(other.tail), m_size(other.m_size) {
    other.head = nullptr;
    other.tail = nullptr;
    other.m_size = 0;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other) {
        clear();
        for (Node<T>* current = other.head; current != nullptr; current = current->m_next) {
            push_back(current->m_data);
        }
    }
    return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& other) {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        m_size = other.m_size;
        other.head = nullptr;
        other.tail = nullptr;
        other.m_size = 0;
    }
    return *this;
}

template<typename T>
T& List<T>::front() {
    if (head == nullptr) throw std::out_of_range("List is empty");
    return head->m_data;
}

template<typename T>
T& List<T>::back() {
    if (tail == nullptr) throw std::out_of_range("List is empty");
    return tail->m_data;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    if (current) current = current->m_next;
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    if (current) current = current->m_prev;
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

template<typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template<typename T>
T& List<T>::Iterator::operator*() {
    return current->m_data;
}

template<typename T>
typename List<T>::Iterator List<T>::begin() {
    return Iterator(head);
}

template<typename T>
typename List<T>::Iterator List<T>::end() {
    return Iterator(nullptr);
}

template<typename T>
void List<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (tail) {
        tail->m_next = newNode;
        newNode->m_prev = tail;
        tail = newNode;
    } else {
        head = tail = newNode;
    }
    ++m_size;
}

template<typename T>
void List<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (head) {
        head->m_prev = newNode;
        newNode->m_next = head;
        head = newNode;
    } else {
        head = tail = newNode;
    }
    ++m_size;
}

template<typename T>
void List<T>::pop_back() {
    if (!tail) throw std::out_of_range("List is empty");
    Node<T>* temp = tail;
    if (tail->m_prev) {
        tail = tail->m_prev;
        tail->m_next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete temp;
    --m_size;
}

template<typename T>
void List<T>::pop_front() {
    if (!head) throw std::out_of_range("List is empty");
    Node<T>* temp = head;
    if (head->m_next) {
        head = head->m_next;
        head->m_prev = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete temp;
    --m_size;
}

template<typename T>
void List<T>::insert(size_t position, const T& value) {
    if (position > m_size) throw std::out_of_range("Position out of range");
    if (position == 0) {
        push_front(value);
        return;
    }
    if (position == m_size) {
        push_back(value);
        return;
    }
    Node<T>* newNode = new Node<T>(value);
    Node<T>* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->m_next;
    }
    newNode->m_next = current;
    newNode->m_prev = current->m_prev;
    current->m_prev->m_next = newNode;
    current->m_prev = newNode;
    ++m_size;
}

template<typename T>
void List<T>::erase(size_t position) {
    if (position >= m_size) throw std::out_of_range("Position out of range");
    if (position == 0) {
        pop_front();
        return;
    }
    if (position == m_size - 1) {
        pop_back();
        return;
    }
    Node<T>* current = head;
    for (size_t i = 0; i < position; ++i) {
        current = current->m_next;
    }
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    delete current;
    --m_size;
}

template<typename T>
void List<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->m_next;
        delete temp;
    }
    head = tail = nullptr;
    m_size = 0;
}

template<typename T>
size_t List<T>::size() const {
    return m_size;
}

template<typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

