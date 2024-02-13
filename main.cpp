#include <iostream>
#include <cstring>
#include "appcommands.cpp"

void addEntry(std::string entry){
  std::cout << "Entry has been added. " << entry << std::endl;
}
int main(){
  std::cout << "code has started running. " << std::endl;
  enterCommand();
  
  return 0;
}