#include "Bus.h"
#include "olc6502.h"

Bus::Bus()
{
	// flush the toilet
	for (auto& i : ram) i = 0x00;
}