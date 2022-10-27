#include <iostream>

#include "Traveller.h"

int main()
{
	Traveller traveller {};

	std::vector<Citie> cities;
	cities.push_back({ "A" });
	cities.push_back({ "B" });
	cities.push_back({ "C" });
	cities.push_back({ "D" });
	cities.push_back({ "E" });

	//Les connections se font dans les deux sens
	cities.at(0).ConnectToCitie(&cities.at(1), 2);	//Connection A-B
	cities.at(0).ConnectToCitie(&cities.at(2),2);	//Connection A-C

	cities.at(1).ConnectToCitie(&cities.at(2), 3);	//Connection B-C
	cities.at(1).ConnectToCitie(&cities.at(3), 3);	//Connection B-D

	cities.at(2).ConnectToCitie(&cities.at(4), 3);	//Connection C-E
	cities.at(3).ConnectToCitie(&cities.at(4), 3);	//Connection D-E

	cities.at(1).ConnectToCitie(&cities.at(4), 1);	//Connection B-E
	cities.at(2).ConnectToCitie(&cities.at(3), 1);	//Connection C-D

	traveller.StartAtCitie(&cities.at(0));
	traveller.MoveToCity(traveller.FindNearestCitieFromCurrent());
	
}
