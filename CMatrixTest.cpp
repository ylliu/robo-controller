#include "CppUTest/UtestMacros.h"
#include "CppUTest/TestHarness.h"
#define private public
#include "VirtualBoundary.h"
#include <memory>
#include "CMatrix.h"
#include <iostream>
TEST_GROUP(CMatrixTest)
{
	void setup(){
	}
	void teardown(){
	}
};

TEST(CMatrixTest, CreateAMatrix)
{
	double matrix_data_a[2][3] = { { 1, 3, 4 }, { 2, 1, 5 } };
	CMatrix* matrix_a = new CMatrix();
	CHECK_EQUAL(true, matrix_a->CreateMatrix(matrix_data_a[0], 2, 3));
	//matrix_a->PrintMatrix();
	delete matrix_a;
}
TEST(CMatrixTest, CanGetElemntByIndex)
{
	double matrix_data_a[2][3] = { { 1, 3, 4 }, { 2, 8, 5 } };
	CMatrix* matrix_a = new CMatrix();
	matrix_a->CreateMatrix(matrix_data_a[0], 2, 3);
	CHECK(fabs(5.0-matrix_a->GetElemntByIndex(1, 2))<0.000001);
	//matrix_a->PrintMatrix();
	delete matrix_a;
}

TEST(CMatrixTest, ShouldReturnNegetive9999999WhenDetectOutOfIndex)
{
	double matrix_data_a[2][3] = { { 1, 3, 4 }, { 2, 8, 5 } };
	CMatrix* matrix_a = new CMatrix();
	matrix_a->CreateMatrix(matrix_data_a[0], 2, 3);
	CHECK(fabs(-9999999.0 - matrix_a->GetElemntByIndex(4, 5)) < 0.000001);
	//matrix_a->PrintMatrix();
	delete matrix_a;
}