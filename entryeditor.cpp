#include <iostream>
#include <string>
#include <fstream>

void addEntry(){
  std::string filename;
  std::cout << "Name the entry: "; std::getline(std::cin, filename); 
  std::getline(std::cin, filename); 
  //add an if statment that checks for if there already exists a entry with the same name and if so reject it
  std::ofstream outfile (filename + ".txt");
  
  std::string input;
  std::cout << "Enter the contents: "; std::getline(std::cin, input); 
  outfile << input << std::endl;
  std::cout << std::endl;

  outfile.close();
}
void editEntry(){

}