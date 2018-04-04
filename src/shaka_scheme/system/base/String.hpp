#ifndef SHAKA_ASCII_STRING_H
#define SHAKA_ASCII_STRING_H

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "shaka_scheme/system/exceptions/IndexOutOfBoundsException.hpp"

namespace shaka {

class String {
public:
  String() {}

  // Construction from a std::string with iterators
  String(std::string str) :
      str(str) {}

  // make new string with length "size"
  String(std::size_t size) :
      str(size, ' ') {}

  // Create string with size "size" and initialize with character "b""
  String(std::size_t size, char b) :
      str(size, b) {}

  //Makes a copy of a string
  String(const String& c) :
      str(c.str) {}

  String(String&& c) :
      str(std::move(c.str)) {}

  // Copy and swap operator= assignment
  String& operator=(String rhs) {
    this->str = rhs.str;
    return *this;
  }

  // Copy assignment with substring.
  String(String& c, std::size_t index) :
      str(c.str.substr(index, std::string::npos)) {
  }

  // Makes a string out of part of another string
  String(String& c, std::size_t index, std::size_t length) :
      str(c.str.substr(index, length)) {}

  // return length of a_string
  std::size_t length() const {
    return str.size();
  }

  // takes the index, and returns the value of the index
  char ref(std::size_t index) const {
    if(index > str.size()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    return str[index];
  }

  // Set the internal string as another's shaka::String's substring
  void substring(const String& other, std::size_t start, std::size_t end) {
    if(start > other.length() || end > other.length()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    this->str = other.str.substr(start, end-start);
  }

  void set(std::size_t index, char a) {
    if(index > str.size()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    this->str.at(index) = a;
  }

  void append(const String& other) {
    this->str += other.str;
  }

  void copy(const String& other) {
    this->str = other.str;
  }

  void copy(const String& other, std::size_t start) {
    if(start > other.length()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    this->str = other.str.substr(start, std::string::npos);
  }

  void copy(const String& other, std::size_t start, std::size_t end) {
    if(start > other.length() || end > other.length()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    this->str = other.str.substr(start, end);
  }

  void fill(char fill) {
    for (char& c : this->str) {
      c = fill;
    }
  }

  void fill(char fill, std::size_t start) {
    if(start > str.size()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    for (std::size_t i = start; i < this->str.size(); ++i) {
      this->str.at(i) = fill;
    }
  }

  void fill(char fill, std::size_t start, std::size_t end) {
    if(start > str.size() || end > str.size()) {
      throw IndexOutOfBoundsException(666,"Index out of bounds: +");
    }
    for (std::size_t i = start; i < end; ++i) {
      this->str.at(i) = fill;
    }
  }

  void upcase() {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) ->
        unsigned char { return std::toupper(c); });
  }

  void downcase() {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) ->
        unsigned char { return std::tolower(c); });
  }

  friend bool operator==(const String& s1, const String& s2) {
    return s1.str.compare(s2.str) == 0;
  }

  friend bool operator!=(const String& s1, const String& s2) {
    return s1.str.compare(s2.str) != 0;
  }

  //  return !(s1 == s2);

  friend bool operator<(const String& s1, const String& s2) {
    return s1.str.compare(s2.str) < 0;
  }
  friend bool operator>(const String& s1, const String& s2) {
    return s1.str.compare(s2.str) > 0;
  }
  friend bool operator<=(const String& s1, const String& s2) {
    return s1.str.compare(s2.str) <= 0;
  }
  friend bool operator>=(const String& s1, const String& s2) {
    return s1.str.compare(s2.str) >= 0;
  }

  char& operator[](std::size_t);

  const std::string get_string() const {
    return this->str;
  }

  friend std::ostream& operator<<(std::ostream& lhs, const shaka::String& rhs);

private:
  std::string str;
};

} // namespace shaka
#endif // SHAKA_ASCII_STRING_H
