#ifndef LOADNFA_HPP
#define LOADNFA_HPP

//#define states
#include <string>
#include <vector>
#include <fstream>

#include "Transitions.hpp"

class LoadNFA
{

public:

  LoadNFA(char* path);
  ~LoadNFA();

  void print();

private:

  void load();
  void split();

  void states_alphabet();
  void production();
  void initial_acceppt();
  void string();

  int index;


  std::ifstream stream_file;

  std::vector<std::string> loads;

  std::vector<std::string> states;
  std::vector<std::string> alphabet;
  std::string initial;
  std::vector<std::string> accept;
  std::vector<std::string> strings;

};
#endif /*LOADNFA_HPP*/
