#pragma once

class Bus;

class olc6502
{
public:
	olc6502();
	~olc6502();

	void ConnectBus(Bus* n) { bus = n; }

public:
	enum FLAGS6502
	{
		C = (1 << 0), // Carry
		Z = (1 << 1), // Zero
		I = (1 << 2), // Disable Interrupts
		D = (1 << 3), // Decimal
		B = (1 << 4), // Break
		U = (1 << 5), // Unused
		V = (1 << 6), // Overflow
		N = (1 << 7), // Negative
	};

	uint8_t a = 0x00; //Accumilate
	uint8_t x = 0x00; // X
	uint8_t y = 0x00; // Y
	uint8_t stkp = 0x00; //Stack Point
	uint8_t pc = 0x0000; // program counter
	uint8_t stats = 0x00; //status

	// Modes
	uint8_t IMP(); uint8_t IMM();
	uint8_t ZP0(); uint8_t ZPX();
	uint8_t ZPY(); uint8_t REL();
	uint8_t ABS(); uint8_t ABX();
	uint8_t ABY(); uint8_t IND();
	uint8_t IZX(); uint8_t IZY();

private:
	Bus* bus = nullptr;
	uint8_t read(uint16_t a);
	void write(uint16_t a, uint8_t d);

	uint8_t GetFlag(FLAGS6502 f);
	void SetFlag(FLAGS6502 f, bool v); // J00l B00l YET AGAIN!!
};

