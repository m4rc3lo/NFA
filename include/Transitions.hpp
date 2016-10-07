#ifndef TRANSITIONS_HPP
#define TRANSITIONS_HPP

#define  TRANSITION std::vector<std::vector<char> >

#include <vector>
#include <string>

class Transitions
{

public:

  Transitions();
  ~Transitions();

  void set_transition(std::vector<char>);
  TRANSITION get_transions();

private:

   TRANSITION transitions;
};
#endif
