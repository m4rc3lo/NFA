#include "LoadNFA.hpp"

#include <iostream>
#include <sstream>
#include <assert.h>
//#define NDEBUG
//#include <fstream>
//#include <stdlib.h>

LoadNFA::LoadNFA(char* path)
{
  this->stream_file.open(path, std::ios::in);

  if (!stream_file.is_open())
  {
    std::cout << "Failed to load file" << std::endl;
    exit(EXIT_FAILURE);
  }

  this->loads = std::vector<std::string> ();
  this->load();

  this->states_alphabet();


}

LoadNFA::~LoadNFA()
{
  if (this->stream_file.is_open())
    this->stream_file.close();
}

void LoadNFA::load()
{
  //std::ifstream stream_file;
  std::string line = "";

  int num_ = 0;

  while(stream_file.good())
  {
    std::getline(this->stream_file, line);
    this->loads.push_back(line);
    //num_ = atoi (line.c_str());
  }

}

void LoadNFA::split()
{
  std::cout << "haha!";
}

void LoadNFA::print()
{
  std::cout << std::endl;
  for (int i = 0 ; i < this->loads.size() ; i++)
    std::cout << this->loads.at(i) << std::endl;
}

void LoadNFA::states_alphabet()
{
  int size = 0;
  int interate = 1;
  std::string states_(this->loads.at(3));
  std::string alphabet_(this->loads.at(4));

  #ifndef NDEBUG
  std::cout << "states_: " << states_ << std::endl;
  std::cout << "alphabet_: " << alphabet_<< std::endl;
  #endif


  assert (states_.at(0) == '{' );//&& states_.at(states_.size()-1)=='}');
  assert (alphabet_.at(0) =='{');// && alphabet_.at(alphabet_.size()-1)=='}');

  size = (int)states.size();
  this->states = std::vector<std::string>();
  std::string str_ = "";

  while(interate < (size-1))
  {
    if ( !(states_.at(interate) == ',') )
    {
      char at = states_.at(interate);
      str_ += at; //states.at(interate);
      this->states.push_back(str_);
      str_ = "";

    }
    interate++;
  }

  interate = 1;
  size = (int)alphabet.size();
  this->alphabet = std::vector<std::string>();
  str_ = "";

  while(interate < (size-1))
  {
    if (!states_.at(interate) == ',')
    {
      char at =  states_.at(interate);
      str_ += at;
      this->alphabet.push_back(str_);
      str_ = "";
    }
    interate++;
  }

  #ifndef NDEBUG
  {
    std::string temp_01 = "";
    std::string temp_02 = "";

    for(int i = 0 ; this->states.size() ; i++)
      temp_01 += this->states.at(i);

    for(int i = 0 ; this->alphabet.size() ; i++)
      temp_02 += this->alphabet.at(i);

    std::cout << "\n\tStates: " << temp_01 << std::endl;
    std::cout << "\n\tStates: " << temp_01 << std::endl;

  }
  #endif
}

void production()
{
  std::vectot<std::string> temp_;
  //int index = 6

  while (this->loads.at(6))


}
void initial_acceppt()
{

}
void string()
{

}
