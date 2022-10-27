#pragma once
#include <vector>
#include <iostream>
#include "Citie.h"

class Traveller
{
public:
	Citie* currentCitie;
	Citie* beginCitie;
	std::vector<Citie*> visitedCities;

	void StartAtCitie(Citie* citie);

	Citie* FindNearestCitieFromCurrent();

	void GoTo(Road* road);
	void MoveToCity(Citie* citie);
	bool CheckIfAlreadyGo(Citie* citie);

	void FindBestWay(std::vector<Citie> allCities);

	std::vector<Citie*> invalidCities;

	bool FutureRoadAreBlocked(std::vector<Road*> roads);
	
};

