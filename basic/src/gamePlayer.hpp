#pragma once

class GamePalyer
{
public:
	const int* getNumTurnsAddress()
	{
		const int* p = &NumTurns;
		return p;
	}
private:
	static const int NumTurns = 5;
	int scores[NumTurns];
};