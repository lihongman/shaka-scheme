#include "shaka_scheme/system/base/String.hpp"
#include "shaka_scheme/system/exceptions/IndexOutOfBoundsException.hpp"

namespace shaka {

std::ostream& operator<<(std::ostream& lhs, const shaka::String& rhs) {
  for (auto it : rhs.get_string()) {
    lhs << it;
  }
  return lhs;
}

char& String::operator[](std::size_t index) {
  if(index > str.size()) {
    throw IndexOutOfBoundsException(666,"Index out of bounds: +");
  }
  return str[index];
}

} // namespace shaka
