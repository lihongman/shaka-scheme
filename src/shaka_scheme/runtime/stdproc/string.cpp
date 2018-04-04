//
// Created by Herman on 3/7/2018.
//

#include "shaka_scheme/runtime/stdproc/string.hpp"

#include "shaka_scheme/system/base/String.hpp"
#include "shaka_scheme/system/base/Character.hpp"
#include "shaka_scheme/system/base/Integer.hpp"

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

Args make_string(Args args) {
  //Checks if too many arguments
  if (args.size() > 2) {
    throw InvalidInputException(1, "make_string: Too many arguments: +");
  }
  //Checks if correct type
  if (args[0]->get_type() != shaka::Integer) {
    throw InvalidInputException(1, "make_string: Argument contains "
        "non-integer");
  }

  Args result;
  int length = args[0]->get<shaka::Integer>();

  if (args.size() == 2) {
    if(args[0]->get_type() != shaka::Character) {
      throw InvalidInputException(1, "make_string: Argument contains "
          "non-character");
    }
    char character = args[0]->get<shaka::Character>();
    result.push_back(create_node(shaka::String(length,character)));
    return result;
  }
  result.push_back(create_node(shaka::String(length)));
  return result;
}

Args 

} // namespace impl
} // namespace stdproc
} // namespace shaka
