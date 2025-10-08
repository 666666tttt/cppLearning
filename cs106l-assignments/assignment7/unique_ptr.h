#pragma once

#include <cstddef>
#include <utility>

namespace cs106l {

/**
 * @brief A smart pointer that owns an object and deletes it when it goes out of scope.
 * @tparam T The type of the object to manage.
 * @note This class is a simpler version of `std::unique_ptr`.
 */
template <typename T> class unique_ptr {
private:
  /* STUDENT TODO: What data must a unique_ptr keep track of? */
  T* ptr;
public:
  /**
   * @brief Constructs a new `unique_ptr` from the given pointer.
   * @param ptr The pointer to manage.
   * @note You should avoid using this constructor directly and instead use `make_unique()`.
   */
  unique_ptr(T* ptr) {
    /* STUDENT TODO: Implement the constructor */
    this->ptr = ptr;
  }

  /**
   * @brief Constructs a new `unique_ptr` from `nullptr`.
   */
  unique_ptr(std::nullptr_t) {
    /* STUDENT TODO: Implement the nullptr constructor */
    this->ptr = nullptr;
  }

  /**
   * @brief Constructs an empty `unique_ptr`.
   * @note By default, a `unique_ptr` points to `nullptr`.
   */
  unique_ptr() : unique_ptr(nullptr) {}

  /**
   * @brief Dereferences a `unique_ptr` and returns a reference to the object.
   * @return A reference to the object.
   */
  T& operator*() {
    /* STUDENT TODO: Implement the dereference operator */
    return *ptr;
  }

  /**
   * @brief Dereferences a `unique_ptr` and returns a const reference to the object.
   * @return A const reference to the object.
   */
  const T& operator*() const {
    /* STUDENT TODO: Implement the dereference operator (const) */
    return *ptr;
  }

  /**
   * @brief Returns a pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A pointer to the object.
   */
  T* operator->() {
    /* STUDENT TODO: Implement the arrow operator */
    return ptr;
  }

  /**
   * @brief Returns a const pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A const pointer to the object.
   */
  const T* operator->() const {
    /* STUDENT TODO: Implement the arrow operator */
    return ptr;
  }

  /**
   * @brief Returns whether or not the `unique_ptr` is non-null.
   * @note This allows us to use a `unique_ptr` inside an if-statement.
   * @return `true` if the `unique_ptr` is non-null, `false` otherwise.
   */
  operator bool() const {
    /* STUDENT TODO: Implement the boolean conversion operator */
    return ptr != nullptr;
  }

  /** STUDENT TODO: In the space below, do the following:
   * - Implement a destructor
   * - Delete the copy constructor
   * - Delete the copy assignment operator
   * - Implement the move constructor
   * - Implement the move assignment operator
   */
  ~unique_ptr() {
    delete ptr;
  }

  unique_ptr(const unique_ptr& other) = delete;

  unique_ptr& operator=(const unique_ptr& other) = delete;

  /*
  移动构造：
  先把ptr指向other的ptr（首先将当前对象的ptr指向other所管理的资源）;
  再把other的ptr置为空，确保原对象不再拥有资源
  这种设计体现了unique_ptr的 "唯一所有权" 特性
  */ 
  unique_ptr(unique_ptr&& other) {
    ptr = other.ptr;
    other.ptr = nullptr;
  }
  
  /*
  移动赋值：
  先排除自我赋值的情况：
    删除原有资源；将当前对象的ptr指向other所管理的资源；
    把other的ptr置空，确保原对象不再拥有资源
  返回时为什么返回*this而不是this？
  赋值运算符的返回类型是 unique_ptr&（当前对象的引用），
  而 this 是指针类型（unique_ptr*）。返回 *this 才能得到与返回类型匹配的 “对象引用”，
  而返回 this 会导致类型不匹配（指针无法隐式转换为引用）。
  */
  unique_ptr& operator=(unique_ptr&& other) {
    if (this != &other) {
      delete ptr;
      ptr = other.ptr;
      other.ptr = nullptr;
    }
    return *this;
  }
};

// main.cpp会用到！
/**
 * @brief Creates a new unique_ptr for a type with the given arguments.
 * @example auto ptr = make_unique<int>(5);
 * @tparam T The type to create a unique_ptr for.
 * @tparam Args The types of the arguments to pass to the constructor of T.
 * @param args The arguments to pass to the constructor of T.
 */

// 完美转发std::forward()
template <typename T, typename... Args> 
unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}