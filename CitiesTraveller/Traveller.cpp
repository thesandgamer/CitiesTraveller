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

	//Test for shortest past : Block beaucause d'ont check too on the future path
	/*
	int c = 0;//Current road
	float minDistance = 100000;

	
	for (size_t i = 0; i < currentCitie->roadsLinkTo.size(); i++)	//Pour tout les chemins
	{
		for (size_t j = 0; j < currentCitie->roadsLinkTo.at(i)->citiesLinkTo.size(); j++)//Pour toutes les villes liés à la route
		{
			Citie* citieToCheck = currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j);
			if (citieToCheck == beginCitie)//Check si le prochain est le même que celui du début
			{
				if (visitedCities.size() == allCitiesToVisit->size() - 1)//Check si on check pour la dernière ville
				{
					if (!CheckIfAlreadyGo(citieToCheck))
					{
						if (currentCitie->roadsLinkTo.at(i)->distance < minDistance)//Si la route à une plus petite distance
						{
							c = i;
							minDistance = currentCitie->roadsLinkTo.at(i)->distance;
						}

					}

				}

			}
			else if (!CheckIfAlreadyGo(citieToCheck))
			{
				if (currentCitie->roadsLinkTo.at(i)->distance < minDistance)//Si la route à une plus petite distance
				{
					c = i;
					minDistance = currentCitie->roadsLinkTo.at(i)->distance;
				}

			}

			
		}
		
	}
	Citie* nextCitie = nullptr;
	
	for (size_t j = 0; j < currentCitie->roadsLinkTo.at(c)->citiesLinkTo.size(); j++)//Pour toutes les villes liés à la route
	{
		Citie* citieToCheck = currentCitie->roadsLinkTo.at(c)->citiesLinkTo.at(j);
		if (citieToCheck == beginCitie)//Check si le prochain est le même que celui du début
		{
			if (visitedCities.size() == allCitiesToVisit->size() - 1)//Check si on check pour la dernière ville
			{
				if (!CheckIfAlreadyGo(citieToCheck))
				{
					nextCitie = citieToCheck;
					break;

				}

			}

		}
		else if (!CheckIfAlreadyGo(citieToCheck))
		{
			nextCitie = citieToCheck;
			break;

		}


	}


	return nextCitie;*/ 

	
	Citie* nextCitie = nullptr;
	for (size_t i = 0; i < currentCitie->roadsLinkTo.size(); i++)	//Pour tout les chemins
	{
		for (size_t j = 0; j < currentCitie->roadsLinkTo.at(i)->citiesLinkTo.size(); j++)//Pour toutes les villes liés
		{
			if (currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j) == beginCitie)//Check si le prochain est le même que celui du début
			{
				if (visitedCities.size() == allCitiesToVisit->size() - 1)//Check si on check pour la dernière ville
				{
					if (!CheckIfAlreadyGo(currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j)))
					{
						nextCitie = currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j);
						break;

					}
		
				}
					
			}	
			else if (!CheckIfAlreadyGo(currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j)))
			{
				nextCitie = currentCitie->roadsLinkTo.at(i)->citiesLinkTo.at(j);
				break;

			}
			

		}


	}
	return nextCitie;
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

void Traveller::FindBestWay(std::vector<Citie>* allCities)
{
	allCitiesToVisit = allCities;
	while (visitedCities.size() != allCities->size())	//Tant qu'il n'a pas visité toutes les villes
	{
		MoveToCity(FindNearestCitieFromCurrent());
	}	
	std::cout << " Path find: ";
	std::cout << "Start of path: " << beginCitie->citieName << std::endl;
	for (size_t i = 0; i < visitedCities.size(); i++)
	{
		std::cout << "Citie: " << visitedCities.at(i)->citieName<<" | ";
	}
	std::cout << std::endl;

}

