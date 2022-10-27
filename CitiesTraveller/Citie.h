#pragma once
#include <vector>
#include <string>
#include <iostream>

class Road;

class Citie
{
public:
	Citie();
	Citie(std::string citieNameP);
	~Citie();
	std::vector<Road*> roadsLinkTo;
	std::string citieName;

	void ConnectToCitie(Citie* otherCity, float distance);
};

