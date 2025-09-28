/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */
  friend std::ostream& operator<< (std::ostream& os, const User& user);   // 友元运算符<<重载函数声明（非成员重载）
  ~User();                                      // 析构函数声明
  User(const User& user);                       // 拷贝构造函数声明
  User& operator=(const User& user);            // 拷贝赋值函数声明
  User(User&& user) = delete;                   // 禁用移动构造函数
  User& operator=(User&& user) = delete;        // 禁用移动赋值函数
  User& operator+= (User& other);               // 运算符+=重载函数声明（成员重载）
  bool operator< (const User& other) const;     // 运算符<重载函数声明（成员重载）

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};