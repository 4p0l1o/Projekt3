#include "SetTime.hpp"

std::string getTimeString();
std::string getCurrentTime();

int main()
{
  std::cout << compareTime(getTimeString(), getCurrentTime());
  return 0;
}
