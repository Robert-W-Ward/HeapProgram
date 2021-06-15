#pragma once
#include <string>
struct Task
{
	std::string name;
	int Priority;
	int length;
	int Arrival;
	int Elapsed;

	Task():name(""),Priority(0),length(0),Arrival(-1),Elapsed(0){}
	Task(std::string name,int P,int L, int A):name(name),Priority(P),length(L),Arrival(A),Elapsed(0){}
};

