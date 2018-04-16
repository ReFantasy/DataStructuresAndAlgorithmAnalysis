#ifndef __INTCELL_H__
#define __INTCELL_H__

class IntCell
{
public:
	explicit IntCell(int initialValue = 0);

	int Read()const;

	void Write(int X);

private:
	int _storedValue;

};
#endif
