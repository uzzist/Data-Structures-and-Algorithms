#include<iostream>
using namespace std;

void Dijkstra(int[][9], int);
int MinVertex(int[], bool[], int);

int main()
{
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	int start;
	cout << "Enter starting node: ";
	cin >> start;
	Dijkstra(graph, start);
	return 0;
}
void Dijkstra(int graph[][9], int start)
{
	int distance[9];
	for (int i = 0; i < 9; i++)
	{
		distance[i] = INT_MAX;
	}
	distance[start] = 0;
	bool visited[9];
	for (int i = 0; i < 9; i++)
	{
		visited[i] = false;
	}
	for (int index = 0; index < 9 - 1; index++)
	{
		int minVertex = MinVertex(distance, visited, 9);
		visited[minVertex] = true;
		for (int j = 0; j < 9; j++)
		{
			if (graph[minVertex][j] != 0 && !visited[j])
			{
				int d = distance[minVertex] + graph[minVertex][j];
				if (d < distance[j])
				{
					distance[j] = d;
				}
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		cout << i << " " << distance[i] << endl;
	}
}
int MinVertex(int distance[], bool visited[], int v)
{
	int min = -1;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i] && (min == -1 || distance[i] < distance[min]))
		{
			min = i;
		}
	}
	return min;
}