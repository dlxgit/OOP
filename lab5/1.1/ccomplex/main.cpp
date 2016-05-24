#include "Ccomplex.h"

int main()
{
	CComplex a = CComplex(2,1);
	CComplex b = CComplex(7, 4);
	CComplex c = a + b;
	std::cout << c.Re() << "+" << c.Im() << std::endl;
	return 0;
}