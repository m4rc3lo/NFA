#ifndef LOADNFA_HPP
#define LOADNFA_HPP

//#define states
#include <string>
#include <vector>

class LoadNFA
{

public:

  LoadNFA(char* path);
  ~LoadNFA();

private:

  std::vector<std::string> states;
  std::vector<std::string> alphabet;
  std::string initial;
  std::vector<std::string> accept;
  std::vector<std::string> strings;

};
#endif /*LOADNFA_HPP*/
