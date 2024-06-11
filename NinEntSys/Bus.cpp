#include "Bus.h"
#include "olc6502.h"

Bus::Bus()
{
	// flush the toilet
	for (auto& i : ram) i = 0x00;
}

Bus::~Bus()
{
}

void Bus::write(uint16_t addr, uint8_t data)
{
	// RAM Range Guard
	if (addr >= 0x0000 && addr <= 0xFFFF)
		ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr, bool bReadOnly)
{
}