#include <string>
class book {
    private:
        // 私有成员变量
        int id;
        std::string name;
        std::string author;
        std::string publisher;
        std::string ISBN;

        // 私有常量成员函数声明
        std::string book_information() const;
    
    public:
        // 带参数的构造函数声明
        book(int id_, std::string name_, std::string author_, std::string publisher_, std::string ISBN_);
        // 默认构造函数声明
        book() = default;

        // 公有常量成员函数声明
        int get_id() const;
        std::string get_name() const;
        std::string get_author() const;
        std::string get_publisher() const;
        std::string get_ISBN() const;
        std::string get_book_information() const;

        // 公有成员函数声明
        // void set_id(const int &id_);
        void set_name(const std::string &name_);
        void set_author(const std::string &author_);
        // void set_publisher(const std::string &publisher_);
        void set_ISBN(const std::string &ISBN_);
};