#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Heap.h"
#include "Task.h"

#pragma region using
using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::vector;
using std::fstream;
using std::stoi;
#pragma endregion

#pragma region GlobalVars
	vector<Task*> Scheduling;
	Heap<Task*>* ToExecute = new Heap<Task*>;
	int mode = 0;
	static int time = -1;
	Task* runningTask = nullptr;
#pragma endregion
#pragma region mainFunctions
bool isTaskRunning()
{
	if(runningTask!=nullptr){return true; }
	return false;
}
bool isTaskScheduled(int timeStep)
{
	for(int i = 0; i < Scheduling.size(); i++)
	{
		if(Scheduling.at(i)->Arrival == timeStep)
		{
			ToExecute->add(Scheduling.at(i));
			Scheduling.pop_back();
		}
	}
	return true;
}
bool isTaskWaiting()
{
	return false;
}
void remove(){}
bool REGES(stringstream* parseStream,string TOKEN)
{
	getline(*parseStream, TOKEN, ' ');
	string name = TOKEN;
	getline(*parseStream, TOKEN, ' ');
	int priority;
	try
	{
		priority = stoi(TOKEN);
	}
	catch(...)
	{
		cout << "Failed to convert priority number to and integer\n";
	}
	getline(*parseStream, TOKEN, ' ');
	int length;
	try
	{
		length = stoi(TOKEN);
	}
	catch(...)
	{
		cout << "Failed to convert length number to and integer\n";
	}
	getline(*parseStream, TOKEN, ' ');
	int arrival;
	try
	{
		arrival = stoi(TOKEN);
	}
	catch(...)
	{
		cout << "Failed to convert arrival number to and integer\n";
	}
	Task* taskptr = new Task(name, priority, length, arrival);
	Scheduling.push_back(taskptr);
	return true;
	
}
string loadFile(string FileToLoad)
{
	string tmp;
	stringstream FileContents;
	fstream File;
	File.open(FileToLoad);
	if(File.is_open())
	{
		cout << "Successfully opened: " << FileToLoad << "\n";
		while(getline(File, tmp, '\n'))
		{
			FileContents << tmp << " ";
		}
		File.close();
	}
	else
	{
		cout << "File ERROR: \"" << FileToLoad << "\" could not be loaded or located\n";
		return FileToLoad;
	}

	return  FileContents.str();
}
void parse(string ToBeParsed)
{
	string TOKEN;
	stringstream parseStream(ToBeParsed);
	while(getline(parseStream, TOKEN, ' '))
	{
		if(!TOKEN.empty())
		{
			if(TOKEN == "exit")
			{
				cout << "GOODBYE!\n";
				system("pause");
				exit(0);
			}
			else if(TOKEN == "load")
			{
				getline(parseStream, TOKEN, ' ');
				loadFile(TOKEN);

			}
			else if(TOKEN == "display")
			{

			}
			else if(TOKEN == "schedule")
			{
				system("cls");
				cout << "You are now in Scheduling mode\n";
				mode = 1;
			}
			else if(TOKEN == "simulate")
			{
				system("cls");
				cout << "You are now in Simulation mode\n";
				mode = 2;
			}
			else if(mode == 1)
			{
				if(TOKEN == "register")
				{
					stringstream* ssptr = &parseStream;
					REGES(ssptr, TOKEN);
					break;
				}
				else if(TOKEN == "remove")
				{

				}
				else if(TOKEN == "clear")
				{

				}
				else
				{
					cout << "\"" << TOKEN << "\"" << " is not a recognized command in this mode\n";
				}
				
			}
			else if(mode==2)
			{
				if(TOKEN == "step")
				{
					getline(parseStream, TOKEN);
					if(TOKEN == "step")
					{
						time++;
						if(isTaskScheduled(time))
						{
							ToExecute->buildHeap();
							if(isTaskRunning())
							{
								
								runningTask = ToExecute->getHeapArray()[0];
							}
							else
							{
								runningTask->Elapsed++;
								
								if(runningTask->length <= 0)
								{
									runningTask = nullptr;
									ToExecute->buildHeap();
								}
							}

						}
						else
						{
							if(isTaskWaiting)
							{

							}
						}
					}
				}
				else if(TOKEN == "reset")
				{

				}
				else if(TOKEN == "run")
				{

				}
				else
				{
					cout << "\"" << TOKEN << "\"" << " is not a recognized command in this mode\n";
				}
			}
			else
			{
				cout << "\"" << TOKEN << "\"" << " is not a recognized command\n";
			}

			
			
		}
	}
}

#pragma endregion
int main()
{
	
	bool isRunning{ true };
	string inputStr;
	while(isRunning)
	{
		cout << ">>";
		getline(cin, inputStr);
		stringstream inputStream(inputStr);
		parse(inputStream.str());
	}
}