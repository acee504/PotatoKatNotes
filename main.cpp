#include <iostream>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include "appcommands.cpp"
char msg[] = "A folder has been created to store data; it is called PKN and is located in the C drive.";
int main(){
  const char* dir = "C:\\PKN";
  struct stat sb;
  if(stat(dir, &sb) == 0){
    enterCommand();
  } else{std::system("mkdir C:\\PKN"); std::cout<<msg<<std::endl; enterCommand();}
  return 0;
}