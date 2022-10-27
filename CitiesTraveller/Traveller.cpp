#include "Traveller.h"
#include "Road.h"
#include "Citie.h"

void Traveller::StartAtCitie(Citie* citie)
{
	beginCitie = citie;
	currentCitie = beginCitie;
}

Citie* Traveller::FindNearestCitieFromCurrent()
{
	
	int citieNearest = 0;
	int minDistance= 1000000;
	for (size_t i = 0; i < beginCitie->roadsLinkTo.size(); i++)
	{
		if (beginCitie->roadsLinkTo.at(i)->distance < minDistance)
		{
			citieNearest = i;
			minDistance = beginCitie->roadsLinkTo.at(i)->distance;
		}
	}
	return beginCitie->roadsLinkTo.at(citieNearest)->citiesLinkTo.at(1);
}

void Traveller::GoTo(Road* road)
{
}

void Traveller::MoveToCity(Citie* citie)
{
	currentCitie = citie;
}

void Traveller::CheckIfAlreadyGo(Citie* citie)
{
}
