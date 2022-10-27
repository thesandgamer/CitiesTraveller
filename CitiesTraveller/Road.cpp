#include "Road.h"

Road::Road()
{
}

Road::Road(float distanceP, std::vector<Citie*> citiesLinkToP): 
	distance{distanceP},citiesLinkTo{citiesLinkToP}
{
	roadName = rand();
}

Road::~Road()
{
}
