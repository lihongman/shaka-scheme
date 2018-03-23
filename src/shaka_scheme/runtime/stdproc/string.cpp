//
// Created by Herman on 3/7/2018.
//

#include "shaka_scheme/runtime/stdproc/string.hpp"

#include "shaka_scheme/system/base/String.hpp"
#include "shaka_scheme/system/base/Character.hpp"

namespace shaka {
namespace stdproc {
namespace impl {

Args isString(Args args) {
  if (args.size() > 1) {
    throw InvalidInputException(1, "not: Too many arguments: +");
  }
  Args result;

  if (args[0]->get_type() == shaka::String) {
    result.push_back(create_node(shaka::Boolean(true)));
  } else {
    result.push_back(create_node(shaka::Boolean(false)));
  }
  return result;
}

//TODO: Complete once Character class is done.
Args make_string(Args args) {

}

Args 

} // namespace impl
} // namespace stdproc
} // namespace shaka
