// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>

void AbrirFichero(FILE **pFile, const char *nombre)
{
	fopen_s(pFile, nombre, "wt");
}

//void EscribirFichero(FILE **pFile, const char *nombre)
//{
//	fprintf(*pfile, *nombre);
//}

//void CerrarFichero(FILE **pfile)
//{
//	fclose(*pfile);
//	*pfile = NULL;
//}


int main()
{
    
}

