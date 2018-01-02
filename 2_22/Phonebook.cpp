#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Phonebook.h"
int main()
{
  Phonebook<std::vector> pb;//vectorでもlistでもいける
  pb.add("police", "110");
  pb.add("fire", "119");
  pb.add("weather", "117");
  pb.print(std::cout);
  return 0;
}
