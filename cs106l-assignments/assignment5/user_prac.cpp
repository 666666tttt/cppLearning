#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
// <<运算符重载实现
// 返回std::ostream&类型的os，支持链式调用
std::ostream& operator<<(std::ostream& os, const User& user) {
  os << "User(name=" << user.get_name() << ", friends=[";
  std::string* friends = user._friends; // 因为声明为友元函数，所以才能访问私有成员
  size_t size = user.size();
  for (size_t i = 0; i < size; ++i) {
    if (i + 1 < size) {
      os << friends[i] << ", ";
    } else {
      os << friends[i];
    }
  }
  os << "])";
  return os;
}

// 析构函数实现
/*
delete:	仅调用单个 std::string的析构函数，释放单个对象的内存
delete[]:调用数组中每个 std::string的析构函数，然后释放整个内存块

用delete[]而不是delete的原因：
_friends是一个new std::string[_capacity]的数组，
而delete只能析构_friends的第一个元素，会造成内存泄露。
如果_friends只是单个对象，则可以用delete。
*/
User::~User() {
  delete[] _friends;  
}

// 拷贝构造函数实现：统一初始化
User::User(const User& user) : _name(user._name),
                              _size(user._size),
                              _capacity(user._capacity),
                              _friends(new std::string[user._capacity])
{
  for (size_t i = 0; i < _size; ++i) {
    _friends[i] = user._friends[i];
  }
}

// 拷贝赋值函数实现
/*
自赋值检查：
如果不检查，当对象自我赋值时（如a = a），可能导致资源被错误释放后无法正确访问。

具体来说，如果没有自赋值检查，会发生以下问题：
1、首先执行delete[] _friends释放当前对象的动态内存
2、接下来试图从源对象（其实是同一个对象）拷贝_friends数据
3、但此时源对象的_friends已经被释放（变成野指针），访问它会导致未定义行为（可能是程序崩溃、数据损坏等）

释放_friends中的内存
delete[] _friends 释放当前对象中动态分配的_friends数组内存，防止内存泄漏。

return *this
return *this 支持连续赋值操作（如a = b = c）
*/
User& User::operator=(const User& user) {
  if (this == &user) {
    return *this;
  }

  delete[] _friends;

  _name = user._name;
  _size = user._size;
  _capacity = user._capacity;
  _friends = new std::string[user._capacity];
  for (size_t i = 0; i < _size; ++i) {
    _friends[i] = user._friends[i];
  }

  return *this;
}

// 运算符+=重载实现
/*
1、当前对象（this 指向的对象）调用 add_friend 方法，将参数对象的名字添加为自己的好友。
2、参数对象调用 add_friend 方法，将当前对象的名字添加为自己的好友。
一个是指针，一个是引用，所以一个用->访问成员，一个用.访问成员
*/
User& User::operator+=(User& other) {
  this->add_friend(other.get_name());
  other.add_friend(this->get_name());
  return *this;
}

// 运算符<重载实现
bool User::operator<(const User& other) const {
  return this->get_name() < other.get_name();
}