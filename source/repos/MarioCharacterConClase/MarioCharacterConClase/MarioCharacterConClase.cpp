// EjemplosUF04.cpp: define el punto de entrada de la aplicación de consola.
//
#include "pch.h"
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "MarioCharacter.h"


MarioCharacter marioCharacter;

int main()
{
	srand((unsigned int)time(NULL));

	MarioCharacter::PrintAllRoles();
	marioCharacter.PrintAllNames();

	marioCharacter.Init();
	marioCharacter.PrintData();

	_getch();

	return 0;
}

