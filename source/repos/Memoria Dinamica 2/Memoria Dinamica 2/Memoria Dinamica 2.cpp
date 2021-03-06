// Memoria Dinamica 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <time.h>

struct Fighter
{
	char name[64];
	int attack;
	int defense;
	float criticalProbability;

};

void main()
{
	// Supongamos que necesitamos
	// memoria para 17 luchadores
	Fighter *fighters = (Fighter *)malloc(17 * sizeof(Fighter));

	strcpy_s(fighters[0].name, "Ryu");
	strcpy_s(fighters[1].name, "Ken");
	strcpy_s(fighters[2].name, "Dhalsim");
	strcpy_s(fighters[3].name, "BlankaNieves");
	strcpy_s(fighters[4].name, "Balrog");
	// Etc.

	free(fighters);
}
