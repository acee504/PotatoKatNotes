#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <list>
#include "entryeditor.cpp"
void closeApp(){}
int checkEntry(std::string i){
  std::ifstream file(i);
  if(!file.is_open()){
    return 1;
  } else{return 0;}
}
void addToEntry(std::string add, std::string inn){
  //allow the user to select and add to an entry
  const char path[] = "C:\\PKN\\";
  add = path+i+".txt";
  if(checkEntry(editEntry)==1){std::cout<<"The entry you tried to edit does not exist"<<std::endl;} 
  else if(checkEntry(add)==0){
    std::fstream f;
    f.open(i, std::ios::app);
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
void deleteEntry(std::string del){
  //complete location of file with path
  std::string fileLocStr;
  fileLocStr.append("C:\\PKN\\"+del+".txt");
  //create dos command to delete file
  std::string delFileCmd = "del /s /q " + fileLocStr;
  std::cout << "delFileCmd: " << delFileCmd << std::endl;
  //this executes the command
  int delFileStatus = system(delFileCmd.c_str());
  //prettier format
  std::cout << std::endl;
}
void readEntry(std::string inn){
  const char path[] = "C:\\PKN\\";
  std::string i = path+inn+".txt";
  std::ifstream f(path+inn+".txt");
  if(checkEntry(i)==1){std::cout<<"The entry you tried openning does not exist!"<<std::endl<<std::endl;}
  else if(checkEntry(i)==0){
    if (f.is_open())
      std::cout << f.rdbuf();
    std::cout<<std::endl;
  }
}
void enterCommand(std::string command){
  std::transform(command.begin(), command.end(), command.begin(),
    [](unsigned char c){ return std::tolower(c); });
  //filter userinput
  else if(command == "stop"){closeApp();}
  else if(command == "new"){addEntry();enterCommand();}
  else if(command == "delete" || command=="del"){deleteEntry();enterCommand();}
  else if(command == "open"){readEntry();enterCommand();}
  else if(command == "add"){addToEntry();enterCommand();}
  else if(command == "see"){seeAllEntries();enterCommand();}
  else{std::cout<<"The command you tried to use was invalid"<<std::endl;enterCommand();}
}

//rewrite code to work with visuals