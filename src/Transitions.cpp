#include "Transitions.hpp"


Transitions::Transitions()
{
  this->transitions = TRANSITION ();
}

Transitions::~Transitions()
{
  ;
}

void Transitions::set_transition(std::vector<char> t)
{
  this->transitions.push_back(t);
}

TRANSITION Transitions::get_transions()
{
  return this->transitions;
}
