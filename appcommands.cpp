#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>

#include "entryeditor.cpp"

void addFolder(){

}
void deleteEntry(){
  //make this next
}
void deleteFolder(){

}
void closeApp(){

}
void listCommands(){
  std::cout << "list of all commands: " << std::endl;
  std::cout << "1. commands" << std::endl;
  std::cout << "2. stop" << std::endl;
  std::cout << "3. new" << std::endl;
  std::cout << "4. delete" << std::endl;
}
void enterCommand(){
  std::cout << "What would you like to do? type commands for a list of all commands: ";
  
  std::string command;
  std::cin >> command;

  //Makes the string input lower case
  std::transform(command.begin(), command.end(), command.begin(),
    [](unsigned char c){ return std::tolower(c); });

  if(command == "commands"){
    listCommands();
    enterCommand();
  }
  else if(command == "stop"){
    closeApp();
  }
  else if(command == "new"){
    addEntry();
    enterCommand();
  }
  else if(command == "delete"){
    deleteEntry();
    enterCommand();
  }
  else{
    std::cout << "The command you tried to use was invalid" << std::endl;

    enterCommand();
  }
}