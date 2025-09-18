
#include <iostream>

void cinGetlineBug() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  std::cin >> name;   // 仅仅是吃掉了之前的换行符
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

int main() {
    cinGetlineBug();
    return 0;
}