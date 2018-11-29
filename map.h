
#include <string>
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

typedef int City;
const int MAX_CITIES = 30;
const int UNKNOWN_CITY = -1;

class Map
{
private:
	int numCities;
	void unvisitAll();
	void markVisited(City);
	City getNextCity(City);
	int convert(string);
	bool isPath(City, City);
	bool isVisited(City);
	City getIndex(string);
	void insertAdjacent(City, City);

	string cities[MAX_CITIES];
	bool visited[MAX_CITIES];
	Node<City>* map[MAX_CITIES];
	
	void splitCities(string, string&, string&);
	
public:
	Map();
	void readMap(string, string);
	void flights(string);
};
