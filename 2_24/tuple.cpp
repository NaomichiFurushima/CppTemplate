
#include "tuple.h"
#include "printType.h"

int main()
{
  tuple<char, int, const char*> t;
  get<0>(t) = 'T';
  get<1>(t) = 4;
  get<2>(t) = "two";
  printType(get<0>(t), get<1>(t), get<2>(t)); 
}
