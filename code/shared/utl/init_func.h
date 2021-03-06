#pragma once

/*
    Copyright 2018 Brick

    Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software
    and associated documentation files (the "Software"), to deal in the Software
   without restriction,
    including without limitation the rights to use, copy, modify, merge,
   publish, distribute,
    sublicense, and/or sell copies of the Software, and to permit persons to
   whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
   all copies or
    substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING
    BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
   PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
   LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
   OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

#include <cstdint>

namespace utl {
class init_function {
public:
  using callback_t = void (*)();

private:
  init_function *next_{nullptr};
  callback_t callback_{nullptr};

  init_function(init_function *&parent, callback_t callback) noexcept;

public:
  init_function(callback_t callback) noexcept;
  init_function(init_function &parent, callback_t callback) noexcept;

  init_function(const init_function &) = delete;
  init_function(init_function &&) = delete;

  static init_function *&ROOT() noexcept;

  static std::size_t init();
};

inline init_function::init_function(init_function *&parent,
                                    callback_t callback) noexcept
    : next_(parent),
      callback_(callback) {
  parent = this;
}

inline init_function::init_function(callback_t callback) noexcept
    : init_function(ROOT(), callback) {}

inline init_function::init_function(init_function &parent,
                                    callback_t callback) noexcept
    : init_function(parent.next_, callback) {}

inline init_function *&init_function::ROOT() noexcept {
  static init_function *root{nullptr};

  return root;
}

inline std::size_t init_function::init() {
  std::size_t total = 0;

  for (init_function *i = ROOT(); i;) {
    if (i->callback_) {
      i->callback_();
      i->callback_ = nullptr;

      ++total;
    }

    init_function *j = i->next_;
    i->next_ = nullptr;
    i = j;
  }

  ROOT() = nullptr;

  return total;
}
} // namespace mem