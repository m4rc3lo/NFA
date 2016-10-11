#include <iostream>

#include "LoadNFA.hpp"

int main (int argc, char **argv)
{
    std::cout << "it's alive" << std::endl;

    LoadNFA load_nfa (argv[1]);
    load_nfa.print();

    exit(EXIT_SUCCESS);
}
