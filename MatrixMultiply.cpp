#include "MatrixMultiply.h"
#include <iostream>

CMatrix* MatrixMultiply::Trmul(CMatrix* matrix_a, CMatrix* matrix_b)
{
	if (LetfMatrixColNotEqualRightMatrixRow(matrix_a, matrix_b))
	{
		return nullptr;
	}
	return DoMatrixMul(matrix_a, matrix_b);
}

bool MatrixMultiply::LetfMatrixColNotEqualRightMatrixRow(CMatrix* matrix_a, CMatrix* matrix_b)
{
	return matrix_a->GetCol() != matrix_b->GetRow();
}

CMatrix* MatrixMultiply::DoMatrixMul(CMatrix* matrix_a, CMatrix* matrix_b)
{
	CMatrix *matrix = new CMatrix();
	double *c;
	double *a = matrix_a->GetDataPtr();
	double *b = matrix_b->GetDataPtr();

	int m, n, k;
	m = matrix_a->GetRow();
	n = matrix_a->GetCol();
	k = matrix_b->GetCol();
	
	c = new double[m*k];
	int i, j, l, u;
	for (i = 0; i <= m - 1; i++)
	for (j = 0; j <= k - 1; j++)
	{
		u = i*k + j; c[u] = 0.0;
		for (l = 0; l <= n - 1; l++)
			c[u] = c[u] + a[i*n + l] * b[l*k + j];
	}
	matrix->CreateMatrix(c, m, k);
	delete[] c;
	return matrix;
}
