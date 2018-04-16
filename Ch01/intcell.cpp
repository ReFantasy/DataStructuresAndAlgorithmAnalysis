#include "intcell.h"

IntCell::IntCell(int initialValue /*= 0*/)
	:_storedValue(initialValue)
{

}

int IntCell::Read() const
{
	return _storedValue;
}

void IntCell::Write(int X)
{
	_storedValue = X;
}
