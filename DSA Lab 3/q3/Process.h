#pragma once
class Process
{
public:
	Process();
	Process(int, int);
	void setID(int);
	void setProcesses(int);
	int getID();
	int getProcesses();
	~Process();
private:
	int id, processes;
};

