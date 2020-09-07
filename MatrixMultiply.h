#ifndef MATRIXMULTIPLY_2020_08_29_H_
#define MATRIXMULTIPLY_2020_08_29_H_
#include "CMatrix.h"
class MatrixMultiply
{
public:
	MatrixMultiply()
	{
	}

	~MatrixMultiply()
	{
	}
	CMatrix* Trmul(CMatrix* matrix_a, CMatrix* matrix_b);

	bool LetfMatrixColNotEqualRightMatrixRow(CMatrix* matrix_a, CMatrix* matrix_b);

	CMatrix* DoMatrixMul(CMatrix* matrix_a, CMatrix* matrix_b);

public:

protected:

private:

};

#endif


