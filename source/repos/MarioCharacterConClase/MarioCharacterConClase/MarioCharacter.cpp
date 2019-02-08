#include "pch.h"
#include "MarioCharacter.h"
#include <stdlib.h>
#include <stdio.h>

char MarioCharacter::roles[][128] =
{
	"Plumber",
	"Princess",
	"Fungus",
	"Lizard",
	"King",
};

char MarioCharacter::names[][128] =
{
	"Mario",
	"Luigi",
	"Peach",
	"Daisy",
	"Toad",
	"Bowser",
	"Wario",
	"Waluigi",
	"Yoshi",
};

MarioCharacter::MarioCharacter()
{
	// Nada, de momento
}

void MarioCharacter::Init()
{
	int numberOfRoles = sizeof(roles) / sizeof(roles[0]);
	int numberOfNames = sizeof(names) / sizeof(names[0]);

	int randRole = rand() % numberOfRoles;
	int randNames = rand() % numberOfNames;
	sprintf_s(name, "%s %s", roles[randRole], names[randNames]);

	coins = rand() % 100;
	lives = rand() % 20;
}

void MarioCharacter::PrintData()
{
	printf("%s - Coins: %d - Lives: %d\n", name, coins, lives);
}

void MarioCharacter::PrintAllRoles()
{
	int numberOfRoles = sizeof(roles) / sizeof(roles[0]);

	printf("Possible roles:\n");
	for (int i = 0; i < numberOfRoles; i++)
	{
		printf("%s\n", roles[i]);
	}

	printf("\n");
}

void MarioCharacter::PrintAllNames()
{
	int numberOfNames = sizeof(names) / sizeof(names[0]);

	printf("Possible names:\n");
	for (int i = 0; i < numberOfNames; i++)
	{
		printf("%s\n", names[i]);
	}

	printf("\n");
}

