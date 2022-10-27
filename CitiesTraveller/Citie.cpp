#include "Citie.h"
#include "Road.h"

Citie::Citie()
{
}

Citie::Citie(std::string citieNameP): citieName{citieNameP}
{
}

Citie::~Citie()
{
}

void Citie::ConnectToCitie(Citie* otherCity, float distance)
{
	Road* newRoad = new Road(distance, { this,otherCity });
	roadsLinkTo.push_back(newRoad);
	otherCity->roadsLinkTo.push_back(newRoad);
}
