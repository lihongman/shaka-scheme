//
// Created by Herman on 3/7/2018.
//

#ifndef SHAKA_SCHEME_STDPROC_STRING_HPP
#define SHAKA_SCHEME_STDPROC_STRING_HPP

#include "shaka_scheme/system/base/Data.hpp"
#include "shaka_scheme/system/exceptions/InvalidInputException.hpp"

namespace shaka {
namespace stdproc {

using Args = std::deque<NodePtr>;
using Callable = std::function<std::deque<NodePtr>(std::deque<NodePtr>)>;

namespace impl {

Args isString(Args); //string?

Args make_string(Args); //make-string (2 implementations)

Args charsToString(Args); //string

Args string_length(Args); //string-length

Args string_ref(Args); //string-ref

Args string_set(Args); //string-set!

Args are_strings(Args); //string=?

//Args allStringsEqual(Args); //string-ci=?

Args stringLessThan(Args); //string<?

Args stringGreaterThan(Args); //string>?

Args stringLessThanEq(Args); //string<=?

Args stringGreaterThanEq(Args); //string>=?

Args substring(Args); //substring

Args string_append(Args); //string-append

Args stringtolist(Args); //string->list (3 implementations)

Args listtostring(Args); //list->string

Args string_copy(Args); //string-copy (3 implementations)

Args string_copyEx(Args); //string-copy! (3 implementations)

Args string_fill(Args); //string-fill! (3 implementations)

} //namespace impl

Callable isString = impl::isString;
Callable make_string = impl::make_string;
Callable charsToString = impl::charsToString;
Callable string_length = impl::string_length;
Callable string_ref = impl::string_ref;
Callable string_set = impl::string_set;
Callable are_strings = impl::are_strings;
Callable stringLessThan = impl::stringLessThan;
Callable stringGreaterThan = impl::stringGreaterThan;
Callable stringLessThanEq = impl::stringLessThanEq;
Callable stringGreaterThanEq = impl::stringGreaterThanEq;
Callable substring = impl::substring;
Callable string_appaned = impl::string_append;
Callable stringtolist = impl::stringtolist;
Callable listtostring = impl::listtostring;
Callable string_copy = impl::string_copy;
Callable string_copyEx = impl::string_copyEx;
Callable string_fill = impl::string_fill;


} //namespace stdproc
} //namespace shaka

#endif //SHAKA_SCHEME_STDPROC_STRING_HPP
