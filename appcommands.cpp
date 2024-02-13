#include <iostream>
#include <cstring>

void seeAllEntries(){

}
void addFolder(){

}
void deleteEntry(){

}
void deleteFolder(){

}
void enterCommand(){
  std::cout << "What would you like to do? type commands for a list of all commands: ";
  
  std::string command;
  std::cin >> command;

  if(command == "commands"){
    std::cout << "list of all commands: " << std::endl;
    std::cout << "commands" << std::endl;

    enterCommand();
  }
  else{
    std::cout << "The command you tried to use was invalid" << std::endl;

    enterCommand();
  }
}