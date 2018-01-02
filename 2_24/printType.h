#include <iostream>
#include <typeinfo>

void printType()
{
  std::cout << std::endl;
}

//再帰っぽい感じで消化していく
template <class Thead, class... Tbody>
void printType(Thead head, Tbody... body)
{
  std::cout << '(' << typeid(Thead).name() << ')' << head;
  if(sizeof...(body) > 0) std::cout << ',';
  printType(body...);
}
