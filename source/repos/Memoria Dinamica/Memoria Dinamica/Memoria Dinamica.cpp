// Memoria Dinamica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


void main()
{
	srand(time(NULL));
	char *randomText = NULL;
	int textLength = 100 + (rand() % 1024);
	randomText = (char *)malloc(textLength);        // Reserva textLength bytes de memoria

	for (int i = 0; i < textLength - 1; i++)
	{
		randomText[i] = 'A' + (rand() % ('Z' - 'A'));
	}
	randomText[textLength - 1] = '\0';

	printf(randomText);
	free(randomText);                      // Libera la memoria reservada

	_getch();
}
