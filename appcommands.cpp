#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include "entryeditor.cpp"
void closeApp(){
}
void deleteEntry(){
  //complete location of file with path
  std::string fileLocStr;
  std::string i;
  std::cout << "What entry would you like to delete: "; std::cin >> i; std::cout << std::endl;
  fileLocStr.append("C:\\PKN\\"+i+".txt");
  //create dos command to delete file
  std::string delFileCmd = "del /s /q " + fileLocStr;
  std::cout << "delFileCmd: " << delFileCmd << std::endl;

  //this executes the command
  int delFileStatus = system(delFileCmd.c_str());
  //prettier format
  std::cout << std::endl;
}
int checkEntry(std::string i){
  std::ifstream file(i);
  if(!file.is_open()){
    return 1;
  } else{return 0;}
}
void readEntry(){
  const char path[] = "C:\\PKN\\";
  std::string inn;
  std::cout << "What file would you like to open: "; std::cin >> inn; std::cout<<std::endl;
  std::string i = path+inn+".txt";
  std::ifstream f(path+inn+".txt");
  if(checkEntry(i)==1){std::cout<<"The file you tried openning does not exist!"<<std::endl<<std::endl;}
  else if(checkEntry(i)==0){
    //opens file
    if (f.is_open())
      std::cout << f.rdbuf();
    std::cout<<std::endl;
  }
}
void listCommands(){
  std::cout << "list of all commands: " << std::endl;
  std::cout << "1. commands" << std::endl;
  std::cout << "2. stop" << std::endl;
  std::cout << "3. new" << std::endl;
  std::cout << "4. delete" << std::endl;
  std::cout << "5. open" << std::endl;
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
  else if(command == "open"){
    readEntry();
    enterCommand();
  }
  else{
    std::cout << "The command you tried to use was invalid" << std::endl;
    enterCommand();
  }
}