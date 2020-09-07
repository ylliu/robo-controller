#include "CppUTest/UtestMacros.h"
#include "CppUTest/TestHarness.h"

#include <memory>
#include <math.h>
#define private public
#include "CMatrix.h"
#include "MatrixMultiply.h"

TEST_GROUP(MatrixMultiplyTest)
{
	void setup(){
		matrix_a = new CMatrix();
		matrix_b = new CMatrix();
		matrix_multiply = new MatrixMultiply();
	}
	void teardown(){
		delete matrix_a;
		delete matrix_b;
		delete matrix_multiply;
	}
	CMatrix* matrix_a;
	CMatrix* matrix_b;
	MatrixMultiply* matrix_multiply;
};

TEST(MatrixMultiplyTest, ShouldReturnNullptrWhenLeftMatrixColNotEqualRightMaxtrixRow)
{
	
	double matrix_data_a[2][3] = { { 1, 3, 4 }, { 2, 1, 5 } };
	double matrix_data_b[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

	matrix_a->CreateMatrix(matrix_data_a[0], 2, 3);
	matrix_b->CreateMatrix(matrix_data_a[0], 2, 3);

	CMatrix* actual_matrix = matrix_multiply->Trmul(matrix_a, matrix_b);
	CHECK(nullptr== actual_matrix);
	delete actual_matrix;
}

TEST(MatrixMultiplyTest, ShouldReturnResultMatrix)
{
	double matrix_data_a[2][3] = { { 1, 3, 4 }, { 2, 1, 5 } };
	double matrix_data_b[3][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

	matrix_a->CreateMatrix(matrix_data_a[0], 2, 3);
	matrix_b->CreateMatrix(matrix_data_b[0], 3, 2);
	double matrix_data_expect[2][2] = { { 30, 38 }, { 30, 38 } };
	CMatrix* expect_matrix = new CMatrix();
	expect_matrix->CreateMatrix(matrix_data_expect[0], 2, 2);
	
	CMatrix* actual_matrix = matrix_multiply->Trmul(matrix_a, matrix_b);
	CHECK_EQUAL(true,expect_matrix->IsEqual(actual_matrix));
	delete expect_matrix;
	delete actual_matrix;
}
