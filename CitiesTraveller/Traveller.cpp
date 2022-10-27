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
	/*
	Citie* nextCitie = nullptr;
	int roadNear = 0;
	int citieNear = 0;
	int minDistance= 1000000;

	for (size_t i = 0; i < currentCitie->roadsLinkTo.size(); i++)
	{
		
		if (currentCitie->roadsLinkTo.at(i)->distance < minDistance)
		{
			for (size_t j = 0; j < currentCitie->roadsLinkTo.at(i)->citiesLinkTo.size(); j++)
			{
				if (invalidCities.size() > 0)
				{
					if (std::find(invalidCities.begin(), invalidCities.end(), currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j)) != std::end(invalidCities))
					{
						continue;
					}
				}
				
				if (!CheckIfAlreadyGo(currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j)))
				{
					nextCitie = currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j);
					//citieNearest = i;
					minDistance = currentCitie->roadsLinkTo.at(i)->distance;

					roadNear = i;
					citieNear = j;
				}
			}
			
			
			
		}
	}
	if (nextCitie == nullptr)
	{
		invalidCities.push_back(currentCitie->roadsLinkTo.at(roadNear)->citiesLinkTo.at(citieNear));
		visitedCities.clear();
		currentCitie = beginCitie;
		FindNearestCitieFromCurrent();
	}*/
	//return currentCitie->roadsLinkTo.at(citieNearest)->citiesLinkTo.at(1);
	Citie* nextCitie = nullptr;
	for (size_t i = 0; i < currentCitie->roadsLinkTo.size(); i++)	//Pour tout les chemins
	{
		for (size_t j = 0; j < currentCitie->roadsLinkTo.at(i)->citiesLinkTo.size(); j++)//Pour toutes les villes liés
		{
			if (!CheckIfAlreadyGo(currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j)))
			{
				nextCitie = currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j);
			}
		}


	}


	return nextCitie;
}

bool Traveller::FutureRoadAreBlocked(std::vector<Road*> roads)
{
	
	return false;
}


void Traveller::GoTo(Road* road)
{
}

void Traveller::MoveToCity(Citie* citie)
{
	currentCitie = citie;
	visitedCities.push_back(citie);
}

bool Traveller::CheckIfAlreadyGo(Citie* citie)
{
	if (std::find(visitedCities.begin(), visitedCities.end(), citie) != std::end(visitedCities))
	{
		return true;

	}
	else
	{
		return false;
	}
}

void Traveller::FindBestWay(std::vector<Citie> allCities)
{
	while (visitedCities.size() != allCities.size())
	{
		MoveToCity(FindNearestCitieFromCurrent());
	}
	std::cout << std::endl;

}

