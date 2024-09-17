#include "String.hpp"

void String::init_from_cstr(const char* str) {
  size_t len = std::strlen(str);
  if(len <= size_of_SSO) {
    std::memcpy(storage.buffer, str, len + 1);
    set_SSO_size(len);
  }
  else {
    storage.heap.size = len;
    storage.heap.capacity = len + 1;
    storage.heap.data = new char(storage.heap.capacity);
    std::memcpy(storage.heap.data, str, len + 1);
    storage.heap.ref_count = new size_t(1);
    set_heap_flag();
  }
}

bool String::is_SSO() const {
  return (storage.buffer[size_of_SSO] & 0x80) == 0; //check the highest bit of last byte(check with 10000000)
}

void String::set_SSO_size(size_t len) {
  storage.buffer[size_of_SSO] = static_cast<char>(len & 0x1F); //save size of SSO in last 5 bytes(00011111)
}

size_t String::get_SSO_size() const {
  return static_cast<size_t>(storage.buffer[size_of_SSO] & 0x1F);
}

void String::set_heap_flag() {
  storage.buffer[size_of_SSO] |= 0x80;
}

void String::COW() {
  if(!is_SSO() && *(storage.heap.ref_count) > 1) {
    --(*(storage.heap.ref_count));
    char* new_data = new char[storage.heap.size + 1];
    std::memcpy(new_data, storage.heap.data, storage.heap.size + 1);
    storage.heap.data = new_data;
    storage.heap.ref_count = new size_t(1);
  }
}

void String:: release_heap() {
  if(!is_SSO() && --(*(storage.heap.ref_count)) == 0) {
    delete[] storage.heap.data;
    delete storage.heap.ref_count;
  }
}

String::String() {
  storage.buffer[0] = '\0';
  set_SSO_size(0);
}

String::String(const char* str) {
  init_from_cstr(str);
}

String::String(const String& other) {
  if(other.is_SSO()) {
    std::memcpy(storage.buffer, other.storage.buffer, size_of_SSO + 1);
  }
  else {
    storage.heap.size = other.storage.heap.size;
    storage.heap.capacity = other.storage.heap.capacity;
    storage.heap.data = other.storage.heap.data;
    storage.heap.ref_count = other.storage.heap.ref_count;
    ++(*(storage.heap.ref_count));
  }
}

String::String(String&& other) {
  if(other.is_SSO()) {
    std::memcpy(storage.buffer, other.storage.buffer, size_of_SSO + 1);
  }
  else {
    storage.heap.size = other.storage.heap.size;
    storage.heap.capacity = other.storage.heap.capacity;
    storage.heap.data = other.storage.heap.data;
    storage.heap.ref_count = other.storage.heap.ref_count;
    other.storage.heap.size = 0;
    other.storage.heap.capacity = 0;
    other.storage.heap.data = nullptr;
    other.storage.heap.ref_count = nullptr;
  }
}

String::~String() {
  clear();
}

String& String::operator=(const String& other) {
  if(this != &other) {
    release_heap();
    if(other.is_SSO()) {
      memcpy(storage.buffer, other.storage.buffer, size_of_SSO + 1);
    }
    else {
      storage.heap.size = other.storage.heap.size;
      storage.heap.capacity = other.storage.heap.capacity;
      storage.heap.data = other.storage.heap.data;
      storage.heap.ref_count = other.storage.heap.ref_count;
      ++(*(storage.heap.ref_count));
    }
  }
  return *this;
}

String& String::operator=(String&& other) {
  if(this != &other) {
    release_heap();
    if(other.is_SSO()) {
      memcpy(storage.buffer, other.storage.buffer, size_of_SSO + 1);
    }
    else {
      storage.heap.size = other.storage.heap.size;
      storage.heap.capacity = other.storage.heap.capacity;
      storage.heap.data = other.storage.heap.data;
      storage.heap.ref_count = other.storage.heap.ref_count;
      other.storage.heap.size = 0;
      other.storage.heap.capacity = 0;
      other.storage.heap.data = nullptr;
      other.storage.heap.ref_count = nullptr;
    }
  }
  return *this;
}

char& String::operator[](size_t index) {
  if(index >= length()) {
    throw std::out_of_range("The index is out of range");
  }
  return is_SSO() ? storage.buffer[index] : storage.heap.data[index];
}

void String::append(const char* str) {
  size_t len = std::strlen(str);
  if(is_SSO()) {
    size_t current_size = get_SSO_size(); 
    if(current_size + len <= size_of_SSO) {
      std::memcpy(storage.buffer + current_size, str, len + 1);
      set_SSO_size(current_size + len);
    }
    else {
      size_t new_size = current_size + len;
      char* new_data = new char[new_size + 1];
      std::memcpy(new_data, storage.buffer, current_size);
      std::memcpy(new_data + current_size, str, len + 1);
      storage.heap.data = new_data;
      storage.heap.capacity = new_size + 1;
      storage.heap.size = new_size;
      storage.heap.ref_count = new size_t(1);
      set_heap_flag();
    }
  }
  else {
    COW();
    if(storage.heap.size + len >= storage.heap.capacity) {
      storage.heap.capacity = (storage.heap.size + len) * 2;
      char* new_data = new char[storage.heap.capacity];
      std::memcpy(new_data, storage.heap.data, storage.heap.size);
      delete[] storage.heap.data;
      storage.heap.data = new_data;
    }
    std::memcpy(storage.heap.data + storage.heap.size, str, len + 1);
    storage.heap.size +=len;
  }
}

size_t String::length() const {
  return is_SSO() ? get_SSO_size() : storage.heap.size;
}

void String::clear() {
  release_heap();
  storage.buffer[0] = '\0';
  set_SSO_size(0);
}

bool String::is_empty() const {
  return length() == 0;
}

void String::memalloc() const {
  if(is_SSO()) {
    std::cout << "Memory allocated from stack" << std::endl;
  }
  else {
    std::cout << "Memory allocated from heap" << std::endl;
  }
}

void String::print() const {
  if(is_SSO()) {
    for(size_t i = 0; i < get_SSO_size(); ++i) {
      std::cout << storage.buffer[i];
    }
  }
  else {
    for(size_t i = 0; i < storage.heap.size; ++i) {
      std::cout << storage.heap.data[i];
    }
  }
  std::cout << std::endl;
}







 
