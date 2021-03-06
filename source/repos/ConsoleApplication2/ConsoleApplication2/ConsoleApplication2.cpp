

#include "pch.h"
#include <iostream>

const int maxNumKeysInSequence = 10;
struct WarriorAttack
{
	char attackName[64];
	char keySequence[maxNumKeysInSequence];
	int damage;
};

const int maxWarriorAttacks = 3;
struct DBZBudokaiTenkaichiWarrior
{
	char name[64];
	WarriorAttack warriorAttacks[maxWarriorAttacks];
};

DBZBudokaiTenkaichiWarrior warriors[] =
{
	// Elemento 0: Son Gokuh
	{
		"Son Gokuh",
		{
			{ "KameHameHa",{ 'S', 'D', 'P' }, 100 },
			{ "KaiouKen",{ 'A', 'D', 'P' }, 50 },
			{ "Kienzan",{ 'W', 'A', 'S', 'D', 'P' }, 150 },
		}
	},
	// Elemento 1: Son Gohan
	{
		"Son Gohan",
		{
			{ "KameHameHa",{ 'S', 'D', 'P' }, 100 },
			{ "Masenkou",{ 'A', 'D', 'P' }, 50 },
			{ "Kakusandan",{ 'W', 'A', 'S', 'D', 'P' }, 150 },
		}
	},
};



void Ejercicio21()
{
	// Declara e inicializa un puntero al nombre del guerrero en 
// el elemento 0 - Son Gokuh

	char *nombreGuerro = warriors[0].name;

		// Declara e inicializa un puntero a la segunda tecla necesaria 
	// para usar el Masenkou de Son Gohan

	char *masenkuGohan = &warriors[1].warriorAttacks[1].keySequence[1];

		// Declara e inicializa un puntero al daño del Kakusandan de
	// Son Gohan

	int *dañoKakusandan = &warriors[1].warriorAttacks[2].damage;

		// Declara el puntero al quinto caracter nombre del 
	// ataque KameHameHa de Son Gohan
	char *quintoCaracterKameHameHa = &warriors[1].warriorAttacks[0].attackName[4];

		// Declara el puntero al caracter final (el '/0') del
	// nombre del ataque Kaiouken de Son Gokuh
	char *ataqueKaioukenDeSonGokuh = &warriors[0].warriorAttacks[1].attackName[8];

}


int main()
{
    std::cout << "Hello World!\n"; 
}

