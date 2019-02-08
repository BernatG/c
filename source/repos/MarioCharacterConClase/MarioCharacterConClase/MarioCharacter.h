#pragma once
class MarioCharacter
{
public:
	MarioCharacter();

	void Init();
	void PrintData();

	static void PrintAllRoles();
	static void PrintAllNames();

private:
	char name[64];
	int lives;
	int coins;

	static char roles[][128];
	static char names[][128];
};
