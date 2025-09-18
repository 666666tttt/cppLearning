#include <format>
#include "class.h"
// 构造函数定义
// book::book(int id_, std::string name_, std::string author_, std::string publisher_, std::string ISBN_) {
//     this->id = id_;
//     this->name = name_;
//     this->author = author_;
//     this->publisher = publisher_;
//     this->ISBN = ISBN_;
// }
// 与前面等效：成员初始化列表定义（传统初始化，有窄化转换问题）
// book::book(int id_, std::string name_, std::string author_, std::string publisher_, std::string ISBN_)
//     : id(id_), name(name_), author(author_), publisher(publisher_), ISBN(ISBN_) {}

// 与前面等效：成员初始化列表定义（统一初始化，无窄化转换问题）
book::book(int id_, std::string name_, std::string author_, std::string publisher_, std::string ISBN_)
    : id{id_}, name{name_}, author{author_}, publisher{publisher_}, ISBN{ISBN_} {}


// const成员函数定义
std::string book::book_information() const {
    return std::format("id:{}\nname:{}\nauthor:{}\npublisher:{}\nISBN{}", id, name, author, publisher, ISBN);
}

int book::get_id() const {
    return this->id;
}

std::string book::get_name() const {
    return this->name;
}

std::string book::get_author() const {
    return this->author;
}

std::string book::get_publisher() const {
    return this->publisher;
}

std::string book::get_ISBN() const {
    return this->ISBN;
}



void book::set_name(const std::string &name_) {
    this->name = name_;
}

void book::set_author(const std::string &author_) {
    this->author = author_;
}

void book::set_ISBN(const std::string &ISBN_) {
    this->ISBN = ISBN_;
}

std::string book::get_book_information() const {
    return book_information();
}