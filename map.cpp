

#include "map.h"
#include <stack>


using namespace std;

void Map::unvisitAll() {
	for (int c = 0; c < MAX_CITIES; c++)
		visited[c] = false;
}

void Map::markVisited(City c){
	if (c < numCities)
		visited[c] = true;
}
Map::Map() : numCities(0)
{
	for (int index = 0; index < MAX_CITIES; index++)
	{
		cities[index] = "";
		visited[index] = false;
		map[index] = nullptr;
	}
}

City Map::getNextCity(City origin)
{
	City dest = UNKNOWN_CITY;
	Node<City>* cityPtr = map[origin];
	while (cityPtr != nullptr && visited[cityPtr->getItem()])
		cityPtr = cityPtr->getNext();
	if (cityPtr != nullptr)
	{
		dest = cityPtr->getItem();
		markVisited(dest);
	}
	return dest;
}

bool Map::isPath(City Origin, City Destination)
{
	bool success;
	stack<int> _stack;
	unvisitAll();

	_stack.push(Origin);
	markVisited(Origin);

	City topCity = _stack.top();
	while (!_stack.empty() && (topCity != Destination)) {
		City nextCity = getNextCity(topCity);

		if (nextCity == UNKNOWN_CITY)
			_stack.pop();
		else {
			_stack.push(nextCity);
			markVisited(nextCity);
		}

		if (!_stack.empty())
			topCity = _stack.top();
	}

	return !_stack.empty();
}

bool Map::isVisited(City city)
{
	return visited[city];
}

City Map::getIndex(string cityName)
{
	City city = 0;
	while (city < numCities && cities[city] != cityName)
		city++;
	if (city >= numCities)
		city = UNKNOWN_CITY;
	return city;
}
void Map::insertAdjacent(City origin, City dest)
{
	Node<City>* cityPtr = new Node<City>(dest, map[origin]);
	map[origin] = cityPtr;
}

void Map::readMap(string cityFile, string flightFile){
	ifstream cInput(cityFile);
	ifstream fInput(flightFile);
	string city1, city2;
	getline(cInput, city1);
	while (!cInput.eof()) {
		cout << "City Found: " << city1 << endl;
		cities[numCities++] = city1;
		getline(cInput, city1);
	}
	cInput.close();
	getline(fInput, city1, ',');
	
	while (!fInput.eof()) {
		ws(fInput);
		getline(fInput, city2);
		insertAdjacent(convert(city1), convert(city2));
		getline(fInput, city1, ',');
	}
	fInput.close();
}

void Map::flights(string RequestFile)
{
	ifstream flightsInput(RequestFile);

	string FlightOrigin, FlightDestination;

	cout << endl;

	while (!flightsInput.eof()) {
		getline(flightsInput, FlightOrigin, ',');
		ws(flightsInput);
		getline(flightsInput, FlightDestination);
		cout << "BEGIN FLIGHTPLAN" << endl;
		cout << "City Origin: " << FlightOrigin << endl;
		cout << "City Destination: " << FlightDestination << endl << endl;

		cout << "Flying from " << FlightOrigin << " to " << FlightDestination << "." << endl << endl;

		if (isPath(convert(FlightOrigin), convert(FlightDestination)))
			cout << "HPAir flies from " << FlightOrigin << " to " << FlightDestination << "." << endl << endl;
		else
			cout << "HPAir does not fly from " << FlightOrigin << " to " << FlightDestination << "." << endl << endl;
		ifstream R("cities.txt");

		(R.is_open());
		cout << "Hpair Covers these cities\n" << R.rdbuf() << "\n\n";
		cout << "Thank you for flying." << endl << endl;
	}
	flightsInput.close();
}

int Map::convert(string InputCity) {
	int _city1 = -1;
	for (string sCity : cities) {
		_city1++;
		if (sCity == InputCity) {
			break;
		}
	}
	return _city1;
}