//
// eXcellent Multi-platform emulator type 8 - 'XM8'
// based on ePC-8801MA
//
// Author : Takeda.Toshiya (ePC-8801MA)
// Author : Tanaka.Yasushi (XM8)
//
// [ file i/o ]
//

#ifdef SDL

#include "os.h"
#include "common.h"
#include "fileio.h"

//
// FILEIO()
// constructor
//
FILEIO::FILEIO()
{
	fp = NULL;
	readonly = false;
}

//
// ~FILEIO()
// destructor
//
FILEIO::~FILEIO()
{
	Fclose();
}

//
// IsProtected()
// get read-only flag
//
bool FILEIO::IsProtected(_TCHAR *filename)
{
	if (IsOpened() == false) {
		SDL_assert(false);
		return false;
	}

	return readonly;
}

//
// Fopen()
// open file
//
bool FILEIO::Fopen(_TCHAR *filename, int mode)
{
	SDL_RWops *ops;

	Fclose();

	// initialize
	ops = NULL;
	readonly = false;

	switch (mode) {
	// read binary
	case FILEIO_READ_BINARY:
		ops = SDL_RWFromFile(filename, "r+b");
		if (ops != NULL) {
			fp = ops;
			return true;
		}

		readonly = true;

		ops = SDL_RWFromFile(filename, "rb");
		if (ops != NULL) {
			fp = ops;
			return true;
		}
		break;

	// write binary
	case FILEIO_WRITE_BINARY:
		ops = SDL_RWFromFile(filename, "wb");
		if (ops != NULL) {
			fp = ops;
			return true;
		}
		break;

	// create new binary
	case FILEIO_READ_WRITE_NEW_BINARY:
		ops = SDL_RWFromFile(filename, "w+b");
		if (ops != NULL) {
			fp = ops;
			return true;
		}
		break;

	// default
	default:
		SDL_assert(false);
		break;
	}

	return false;
}

//
// Fclose()
// close file
//
void FILEIO::Fclose()
{
	if (fp != NULL) {
		SDL_RWclose((SDL_RWops*)fp);
		fp = NULL;
	}
}

//
// IsOpened()
// check file is opened or not
//
bool FILEIO::IsOpened()
{
	if (fp == NULL) {
		return false;
	}

	return true;
}

//
// FgetBool()
// read one bool
//
bool FILEIO::FgetBool()
{
	bool b;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return false;
	}

	s = SDL_RWread((SDL_RWops*)fp, &b, sizeof(b), 1);
	if (s != 1) {
		SDL_assert(false);
		return false;
	}

	return b;
}

//
// FputBool()
// write one bool
//
void FILEIO::FputBool(bool b)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &b, sizeof(b), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetUint8()
// read one uint8
//
uint8 FILEIO::FgetUint8()
{
	uint8 val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputUint8()
// write one uint8
//
void FILEIO::FputUint8(uint8 val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetUint16()
// read one uint16
//
uint16 FILEIO::FgetUint16()
{
	uint16 val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputUint16()
// write one uint16
//
void FILEIO::FputUint16(uint16 val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetUint32()
// read one uint32
//
uint32 FILEIO::FgetUint32()
{
	uint32 val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputUint32()
// write one uint32
//
void FILEIO::FputUint32(uint32 val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetUint64()
// read one uint64
//
uint64 FILEIO::FgetUint64()
{
	uint64 val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputUint64()
// write one uint64
//
void FILEIO::FputUint64(uint64 val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetDouble()
// read one double
//
double FILEIO::FgetDouble()
{
	double val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputDouble()
// write one double
//
void FILEIO::FputDouble(double val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetInt8()
// read one int8
//
int8 FILEIO::FgetInt8()
{
	int8 val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputInt8()
// write one int8
//
void FILEIO::FputInt8(int8 val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetInt32()
// read one int32
//
int32 FILEIO::FgetInt32()
{
	int32 val;
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return 0;
	}

	return val;
}

//
// FputInt32()
// write one int32
//
void FILEIO::FputInt32(int32 val)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		SDL_assert(false);
		return;
	}
}

//
// FgetUint32_LE()
// read one uint32 in little endian format
//
uint32 FILEIO::FgetUint32_LE()
{
	uint32 val;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	val = SDL_ReadLE32((SDL_RWops*)fp);

	return val;
}

//
// Fgetc()
// read one character
//
int FILEIO::Fgetc()
{
	uint8 val;
	size_t s;

	if (IsOpened() == false) {
		return EOF;
	}

	s = SDL_RWread((SDL_RWops*)fp, &val, sizeof(val), 1);
	if (s != 1) {
		return EOF;
	}

	return (int)val;
}

//
// Fread()
// read from byte stream
//
uint32 FILEIO::Fread(void* buffer, uint32 size, uint32 count)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWread((SDL_RWops*)fp, buffer, (size_t)size, (size_t)count);

	return (uint32)s;
}

//
// Fwrite()
// write into byte strem
//
uint32 FILEIO::Fwrite(void* buffer, uint32 size, uint32 count)
{
	size_t s;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	s = SDL_RWwrite((SDL_RWops*)fp, buffer, (size_t)size, (size_t)count);

	return (uint32)s;
}

//
// Fseek()
// seek any position
//
uint32 FILEIO::Fseek(long offset, int origin)
{
	Sint64 current;

	current = 0;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0xffffffff;
	}

	switch (origin) {
	// from current
	case FILEIO_SEEK_CUR:
		current = SDL_RWseek((SDL_RWops*)fp, (Sint64)offset, RW_SEEK_CUR);
		if (current >= 0) {
			return 0;
		}
		break;

	// from bottom
	case FILEIO_SEEK_END:
		current = SDL_RWseek((SDL_RWops*)fp, (Sint64)offset, RW_SEEK_END);
		if (current >= 0) {
			return 0;
		}
		break;

	// from top
	case FILEIO_SEEK_SET:
		current = SDL_RWseek((SDL_RWops*)fp, (Sint64)offset, RW_SEEK_SET);
		if (current >= 0) {
			return 0;
		}
		break;

	// default
	default:
		SDL_assert(false);
		break;
	}

	// error
	return 0xffffffff;
}

//
// Ftell()
// get current position
//
uint32 FILEIO::Ftell()
{
	Sint64 current;

	if (IsOpened() == false) {
		SDL_assert(false);
		return 0;
	}

	current = SDL_RWtell((SDL_RWops*)fp);

	return (uint32)current;
}

//
// Remove
// delete file
//
void FILEIO::Remove(_TCHAR *filename)
{
	// d88 disk image does not require this method
	// because only DISK::teledisk_to_d88() calls FILEIO::Remove()
	SDL_assert(false);
}

#endif // SDL
