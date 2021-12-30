#include "Process.h"
#include<iostream>
using namespace std;

Process::Process()
{
	id = 0;
	processes = 0;
}
Process::Process(int id, int processes)
{
	setID(id);
	setProcesses(processes);
}
void Process::setID(int id)
{
	this->id = id;
}
void Process::setProcesses(int processes)
{
	if (processes >= 0)
	{
		this->processes = processes;
	}
	else
	{
		this->processes = 0;
	}
}
int Process::getID()
{
	return id;
}
int Process::getProcesses()
{
	return processes;
}
Process::~Process()
{

}