#pragma once

#include "Citie.h"

class Road
{
public:
	Road();
	Road(float distanceP, std::vector<Citie*> citiesLinkToP);
	~Road();
	float distance;
	std::string roadName;
	std::vector<Citie*> citiesLinkTo;
	//Citie* starCitie;
	//Citie* endCitie;
};

