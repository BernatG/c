#include "pch.h"
#include <string.h>
#include <stdio.h>
//#include "Common.h"

const int maxRegisters = 1024;

// Definición de la estructura
class Teacher
{
private:
	bool exists = false;
	char completeName[128];
	int age;
	char sexAppeal;
	char cookingSkills;
	char sadisticBehaviour;
	char curriculum[512];
public:
	bool Init(
		bool _exists,
		const char *_completeName,
		int _age,
		char _sexAppeal,
		char _cookingSkills,
		char _sadisticBehaviour,
		char *_curriculum
	);
};

bool Teacher::Init(
	bool _exists,
	const char *_completeName,
	int _age,
	char _sexAppeal,
	char _cookingSkills,
	char _sadisticBehaviour,
	char *_curriculum
)
{
	bool paramsAreCorrect =
		(strlen(_completeName) < 128) &&
		(_age >= 0) && (_age <= 2999) &&
		(_sexAppeal >= 0) && (_sexAppeal <= 10) &&
		(_cookingSkills >= 0) && (_cookingSkills <= 10) &&
		(_sadisticBehaviour >= 0) && (_sadisticBehaviour <= 10) &&
		(strlen(_curriculum) < 512);
	if (paramsAreCorrect)
	{
		strcpy_s(completeName, _completeName);
		age = _age;
		sexAppeal = _sexAppeal;
		cookingSkills = _cookingSkills;
		sadisticBehaviour = _sadisticBehaviour;
		strcpy_s(curriculum, _curriculum);
	}
	else
	{
		false,
			strcpy_s(completeName, "DoesNotExistOrIndexIsOutOfRange");
			age = 0;
			sexAppeal = 0;
			cookingSkills = 0;
			sadisticBehaviour = 0;
			strcpy_s(curriculum, "");
	}
}

// Una sola tabla en lugar de
// un montón de ellas
Teacher teacherTable[maxRegisters];




bool TableWriteRegister_Struct(int index, Teacher *teacherData);
bool TableReadRegister_Struct(int index, Teacher *teacherData);

void StructsArraysExample_Write();
void StructsArraysExample_Read();


void StructsArraysExample()
{
	StructsArraysExample_Write();
	StructsArraysExample_Read();
}

void StructsArraysExample_Write()
{
	Teacher Bernat;
	bool esCorrecto = Bernat.Init(
		true, 
		"Bernat Grifol Belio", 
		18,
		38634,
		25875325,
		258,
		"De to");

	// Podemos agregar elementos a la tabla
	// manualmente...
	strcpy_s(teacherTable[0].completeName, "Enrique Sainz");
	teacherTable[0].exists = true;
	teacherTable[0].age = 40;
	teacherTable[0].sexAppeal = 10;
	teacherTable[0].cookingSkills = 10;
	teacherTable[0].sadisticBehaviour = 15;
	strcpy_s(teacherTable[0].curriculum, "Hace juegos y tal.");

	// Pero utilizar las funciones es mucho
	// más elegante, legible y mantenible;
	// Además, es más seguro ya que en la 
	// función de escribir sólo aceptamos
	// datos que sean correctos

	// Este primer intento no funciona, porque
	// hemos pasado un 15 en sadisticBehaviour,
	// y la función sólo nos permite hasta 10
	Teacher teacher =
	{
		false,
		"Enrique Sainz",
		40,
		10,
		10,
		15,
		"Hace juegos y tal."
	};

	if (TableWriteRegister_Struct(0, &teacher))
	{
		printf("Registro Enrique Sainz escrito con éxito.\n");
	}
	else
	{
		printf("Fallo escribiendo registro Enrique Sainz.\n");
	}

	// Este intento sí que funciona
	teacher.sadisticBehaviour = 10;

	if (TableWriteRegister_Struct(0, &teacher))
	{
		printf("Registro Enrique Sainz escrito con éxito.\n");
	}
	else
	{
		printf("Fallo escribiendo registro Enrique Sainz.\n");
	}
}

void StructsArraysExample_Read()
{
	// Mira que fácilmente declaro
	// los datos del profesor
	Teacher teacher;

	// Puedo leer directamente de la tabla
	// si voy con un poco de cuidado
	if (teacherTable[10].exists)
	{
		// Esto nunca ocurre porque 
		// teacherTable[10] no está 
		// inicializado
		teacher = teacherTable[10];
	}

	if (teacherTable[0].exists)
	{
		// Esto si que ocurre!
		teacher = teacherTable[0];
	}


	// Lo cierto es que, con tan poco código
	// que mantener, no hace ni falta utilizar
	// una función para acceder a la tabla,
	// pero ¡hey! Siempre nos puede venir bien
	// para hacer comprobaciones previas
	if (TableReadRegister_Struct(0, &teacher))
	{
		printf("Registro 0 leido con éxito.\n");
	}
	else
	{
		printf("Registro 0 no se ha podido leer.\n");
	}

}


bool TableWriteRegister_Struct(int index, Teacher *teacher)
{
	// Esta función devuelve cierto si se 
	// ha escrito correctamente el registro;
	// sólo escribimos el registro si los
	// datos a escribir están dentro de
	// las longitudes y rangos correctos

	bool paramsAreCorrect = false;

	if ((index >= 0) && (index < maxRegisters))
	{
		paramsAreCorrect =
			(strlen(teacher->completeName) < 128) &&
			(teacher->age >= 0) && (teacher->age <= 2999) &&
			(teacher->sexAppeal >= 0) && (teacher->sexAppeal <= 10) &&
			(teacher->cookingSkills >= 0) && (teacher->cookingSkills <= 10) &&
			(teacher->sadisticBehaviour >= 0) && (teacher->sadisticBehaviour <= 10) &&
			(strlen(teacher->curriculum) < 512);

		if (paramsAreCorrect)
		{
			teacherTable[index] = *teacher;
			teacherTable[index].exists = true;
		}
	}

	return paramsAreCorrect;
}

Teacher failedToReadTeacher =
{
	false,
	"DoesNotExistOrIndexIsOutOfRange",
	0,
	0,
	0,
	0,
	""
};

bool TableReadRegister_Struct(int index, Teacher *teacher)
{
	bool registerExists = false;

	if (
		(index >= 0) &&
		(index < maxRegisters) &&
		teacherTable[index].exists
		)
	{
		// Si el indice es correcto y el 
		// registro existe, entonces devolvemos
		// los datos de dicho registro
		*teacher = teacherTable[index];
		registerExists = true;
	}
	else
	{
		// Si el indice no es correcto o el
		// registro no existe, entonces devolvemos
		// unos valores por defecto
		*teacher = failedToReadTeacher;
		registerExists = false;
	}

	return registerExists;
}

