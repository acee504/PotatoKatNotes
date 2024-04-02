#include <iostream>
#include <string>
#include <fstream>

//validates if there is or isnt a file with the same name
int validateEntry(std::string i){
  const char path[] = "/PKN/";
  std::ifstream file(path+i+".txt");
  if(file.is_open()){
    return 1;
  } else{return 0;}
}
void addEntry(std::string filename, std::string input){
  const char path[] = "/PKN/";
  if(validateEntry(filename) == 0){
    std::ofstream outfile (path+filename+".txt");
    outfile << input << std::endl;
    std::cout << std::endl;   
    outfile.close();
  } else if(validateEntry(filename)==1){std::cout << std::endl << "A file with that name already exists!" << std::endl << std::endl;}
}
void editEntry(){
  //make this for the visual program
}
