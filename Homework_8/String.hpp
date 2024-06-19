#pragma once
#include <cstring>
#include <iostream>
#include <stdexcept>

class String {
  private:
    static const size_t size_of_SSO = 22;
    static const size_t max_size = 31; //5 bit
    union {
      char buffer[size_of_SSO + 1]; //including flags
      struct {
        char* data;
        size_t size;
        size_t capacity;
        size_t* ref_count; //for COW
      } heap;
    } storage;
    void init_from_cstr(const char* str);
    bool is_SSO() const;
    void set_SSO_size(size_t len);
    size_t get_SSO_size() const;
    void set_heap_flag();
    void COW();
    void release_heap();
   public: 
    String(); //default
    String(const char*);
    String(const String& other);
    String(String&& other);
    ~String();
    char& operator[](size_t index);
    String& operator=(const String& other);
    String& operator=(String&& other);
    size_t length() const;
    void append(const char* str);
    void clear();
    bool is_empty() const;
    void print() const;
    void memalloc() const;
};
#include "String.inl"