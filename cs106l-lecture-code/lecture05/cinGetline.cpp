#include <iostream>

void cinGetline() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;                 // 读取一个浮点数到pi，此时输入缓冲区会留下一个换行符\n
  std::getline(std::cin, name);   // ！会直接读取到缓冲区中残留的\n，导致读取到空字符串，实际作用是 "吃掉" 前面留下的换行符
  std::getline(std::cin, name);   // 读取用户输入
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

int main() {
    cinGetline();
    return 0;
}