#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <list>
#include "entryeditor.cpp"
void closeApp(){
}
int checkEntry(std::string i){
  std::ifstream file(i);
  if(!file.is_open()){
    return 1;
  } else{return 0;}
}
void addToEntry(){
  //allow the user to select and add to an entry
  const char path[] = "C:\\PKN\\";
  std::string i;
  std::cout << "What entry would you like to add to: "; std::cin >> i;
  i = path+i+".txt";
  if(checkEntry(i)==1){std::cout<<"The entry you tried to edit does not exist"<<std::endl;} 
  else if(checkEntry(i)==0){
    std::fstream f;
    f.open(i, std::ios::app);
    std::string inn;
    std::cout<<"What would you like to add: "<<std::endl;
    std::getline(std::cin, inn);std::getline(std::cin, inn);
    f<<inn<<std::endl;
    f.close();
    std::cout<<std::endl;
  }
}
void seeAllEntries(){
  const char path[] = "C:\\PKN\\";
  std::string command("dir /a-d ");
  command.append(path);
  const char* final_command = command.c_str();
  system(final_command);
  std::cout<<std::endl;
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
void readEntry(){
  const char path[] = "C:\\PKN\\";
  std::string inn;
  std::cout << "What file would you like to open: "; std::cin >> inn; std::cout<<std::endl;
  std::string i = path+inn+".txt";
  std::ifstream f(path+inn+".txt");
  if(checkEntry(i)==1){std::cout<<"The entry you tried openning does not exist!"<<std::endl<<std::endl;}
  else if(checkEntry(i)==0){
    if (f.is_open())
      std::cout << f.rdbuf();
    std::cout<<std::endl;
  }
}
void listCommands(){
  std::cout<<std::endl;
  std::list<std::string> commands = {"help", "stop", "new", "delete or del", "open", "add", "see"};
  for (auto v : commands)
    std::cout <<"-" + v << "\n";
  std::cout<<std::endl;
}
void enterCommand(){
  std::cout << "What would you like to do? type help for a list of all commands: ";
  std::string command;
  std::cin >> command;
  //Makes the string input lower case
  std::transform(command.begin(), command.end(), command.begin(),
    [](unsigned char c){ return std::tolower(c); });
  //filter userinput
  if(command == "help"){listCommands();enterCommand();}
  else if(command == "stop"){closeApp();}
  else if(command == "new"){addEntry();enterCommand();}
  else if(command == "delete" || command=="del"){deleteEntry();enterCommand();}
  else if(command == "open"){readEntry();enterCommand();}
  else if(command == "add"){addToEntry();enterCommand();}
  else if(command == "see"){seeAllEntries();enterCommand();}
  else{std::cout<<"The command you tried to use was invalid"<<std::endl;enterCommand();}
}