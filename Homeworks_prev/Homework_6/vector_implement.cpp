#include <iostream>
#include <stdexcept>
template <typename T>
class My_Vector { 
    private:
      T* data;
      size_t size;
      size_t capacity;
    public:
      My_Vector();
      My_Vector(const My_Vector& other); //Copy constructor
      My_Vector(My_Vector&& other); //Move constructor
      ~My_Vector();
      T& operator[](size_t index);
      My_Vector& operator=(const My_Vector& other);
      My_Vector& operator=(My_Vector&& other);
      void push_back(const T& value);
      void pop_back();
      void push_front(const T& value);
      void pop_front();
      void insert(size_t position, const T& value);
      void erase(size_t position);
      void clear();
      size_t get_size() const;
      void print();
};

template <typename T> 
My_Vector<T>::My_Vector() : data(nullptr), size(0), capacity(0) {}

template<typename T>
My_Vector<T>::~My_Vector() {
    delete[] data;
}

template <typename T>
My_Vector<T>::My_Vector(const My_Vector& other) : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
    std::cout << "Copy_ctor" << std::endl;
    for(size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
My_Vector<T>::My_Vector(My_Vector&& other) : data(other.data), size(other.size), capacity(other.capacity) {
    std::cout << "Move_ctor" << std::endl;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

template <typename T>
T& My_Vector<T>::operator[](size_t index) {
    if(index < size) {
        return data[index];
    }
    throw std::out_of_range("Index is out of range");
}

template <typename T>
My_Vector<T>& My_Vector<T>::operator=(const My_Vector& other) {
    std::cout << "Copy assignment op" << std::endl;
    if(this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[other.capacity];
        for(size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
My_Vector<T>& My_Vector<T>::operator=(My_Vector&& other) {
    std::cout <<"Move assignment op" << std::endl;
    if(this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;
        return *this;
    }
    return *this;
}

template <typename T>
void My_Vector<T>::push_back(const T& value) {
    if(size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* tmp = new T[capacity];
        for(size_t i = 0; i < size; ++i) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }
    data[size] = value;
    ++size;
}

template <typename T>
void My_Vector<T>::push_front(const T& value) {
    if(size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* tmp = new T[capacity];
        tmp[0] = value;
        for(size_t i = 0; i < size; ++i) {
            tmp[i + 1] = data[i];
        }
        delete[] data;
        data = tmp;
    }
    else {
        for(size_t i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = value;
    }
    ++size;
}

template <typename T>
void My_Vector<T>::pop_back() {
    if(size <= 0) {
        throw std::out_of_range("Vector is empty");
    }
    /*else {
        --size;
    }*/
    /*else {
        data[size - 1].~T();
    }*/
    else {
        T* tmp = new T[capacity];
        for(size_t i = 0; i < size - 1; ++i) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
        --size;
    }
}

template <typename T>
void My_Vector<T>::pop_front() {
    if(size <= 0) {
        throw std::out_of_range("Vector is empty");
    }
    else {
        for(size_t i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        --size;
    }
}

template <typename T>
void My_Vector<T>::insert(size_t position, const T& value) {
    if(position > size) {
        throw std::out_of_range("Position is out of range");
    }
    if(size >= capacity) {
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* tmp = new T[capacity];
        for(size_t i = 0; i < position; ++i) {
            tmp[i] = data[i];
        }
        tmp[position] = value;
        for(size_t i = position + 1; i < size + 1; ++i) {
            tmp[i] = data[i - 1];
        }
        delete[] data;
        data = tmp;
    }
    else {
        for(size_t i = size; i > position; --i) {
            data[i] = data[i - 1];
        }
        data[position] = value;
    }
    ++size;
}

template <typename T>
void My_Vector<T>::erase(size_t position) {
    if(position >= size) {
        throw std::out_of_range("Position is out of range");
    }
    for(size_t i = position; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template <typename T>
void My_Vector<T>::clear() {
    size = 0;
}

template <typename T>
size_t My_Vector<T>::get_size() const{
    return size;
}

template <typename T>
void My_Vector<T>::print() {
    for(size_t i = 0; i < size; ++i) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    My_Vector<int> vec;
    //My_Vector<int> vec_;
    for(int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }
    //vec.print();

    //vec_ = vec; //operator=, copy assignment op;
    //My_Vector<int> vec_ = vec; //Copy constructor
    //vec_ = My_Vector<int>();
    //vec_ = My_Vector<int>(); //Move assignment op 
    //vec_.push_back(2);
    //vec.push_back(7);
    //vec.pop_back();
    //vec.insert(3,5);
    //vec.push_front(4);
    //vec.pop_front();
    //vec.erase(1);
    //vec.clear();
    //std::cout << vec[4] << std::endl; //operator[]
    //vec_.print();
    //vec_.print();
    //std::cout << vec.get_size() << std::endl;
}