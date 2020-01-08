//
// Created by Robert Wallis on 1/7/20.
//

#include <vector>
#include "gtest/gtest.h"

class Implicit {
 private:
  std::vector<int> *_list; // pointer to demonstrate implicit copies

 public:
  explicit Implicit(std::vector<int> &list) :
      _list(&list) {
  }

  void remove(int i) {
    _list->erase(_list->begin() + i);
  }

  int get(int i) {
    return (*_list)[i];
  }
};

TEST(Cpp, ImplicitCopy) {
  std::vector<int> l{1, 2, 3};
  auto a = Implicit(l);
  auto b = a;
  b.remove(1);
  EXPECT_EQ(3, b.get(1));
  EXPECT_EQ(3, a.get(1)); // not 2, because we deleted 2 from "a" due to the deep copy
}

class Copyable {
 private:
  std::vector<int> *_list; // pointer to demonstrate implicit copies

 public:
  explicit Copyable(std::vector<int> &list) :
      _list(&list) {
  }

  Copyable(const Copyable &src) :
      _list(new std::vector<int>(*src._list)) {
  }

  void remove(int i) {
    _list->erase(_list->begin() + i);
  }

  int get(int i) {
    return (*_list)[i];
  }
};

TEST(Cpp, CopyConstructor) {
  std::vector<int> l{1, 2, 3};
  auto a = Copyable(l);
  auto b = a;
  b.remove(1);
  EXPECT_EQ(3, b.get(1));
  EXPECT_EQ(2, a.get(1)); // used copy constructor, didn't affect a

  b = a; // oops no assignment constructor
  b.remove(1);
  EXPECT_EQ(3, b.get(1));
  EXPECT_EQ(3, a.get(1)); // used shallow assignment instead of copy constructor
}

class CompleteCopyable {
 private:
  std::vector<int> *_list; // pointer to demonstrate implicit copies

 public:
  explicit CompleteCopyable(std::vector<int> &list) :
      _list(&list) {
  }

  CompleteCopyable(const CompleteCopyable &src) :
      _list(new std::vector<int>(*src._list)) {
  }

  CompleteCopyable &operator=(const CompleteCopyable &src) {
    if (this == &src) {
      return *this;
    }
    delete _list;
    _list = new std::vector<int>(*src._list);
    return *this;
  }

  void remove(int i) {
    _list->erase(_list->begin() + i);
  }

  int get(int i) {
    return (*_list)[i];
  }
};

TEST(Cpp, CopyConstructorFull) {
  std::vector<int> l{1, 2, 3};
  auto a = CompleteCopyable(l);
  auto b = a;
  b.remove(1);
  EXPECT_EQ(3, b.get(1));
  EXPECT_EQ(2, a.get(1)); // used copy constructor, didn't affect "a"

  b = a; // OK! used assignment constructor
  b.remove(1);
  EXPECT_EQ(3, b.get(1));
  EXPECT_EQ(2, a.get(1)); // All Good! Didn't affect "a"
}