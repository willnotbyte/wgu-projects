#pragma once
#include <string> 

//Create degree program options
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//Make the enum an accessible string variable.
static const std::string degreeProgramStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"};