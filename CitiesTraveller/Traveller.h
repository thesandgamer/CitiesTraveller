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
	void CheckIfAlreadyGo(Citie* citie);

	
	
};

