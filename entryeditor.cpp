#include <iostream>
#include <string>
#include <fstream>

void addEntry(){
  std::string filename;
  std::cout << "Name the entry: "; std::getline(std::cin, filename); 
  std::getline(std::cin, filename); 
  std::ofstream outfile (filename + ".txt");
  
  std::string input;
  std::cout << "Enter the contents: "; std::getline(std::cin, input); 
  outfile << input << std::endl;

  outfile.close();
}