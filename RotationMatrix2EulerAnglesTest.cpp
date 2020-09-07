#include "CppUTest/UtestMacros.h"
#include "CppUTest/TestHarness.h"

#include <memory>
#include <math.h>
#include "RotationMatrix2EulerAngles.h"

TEST_GROUP(RotationMatrix2EulerAnglesTest)
{
	void setup(){
	}
	void teardown(){
	}
};

TEST(RotationMatrix2EulerAnglesTest, NewAClass)
{
	RotationMatrix2EulerAngles* tr2rpy = new RotationMatrix2EulerAngles();
	CHECK(true);
	delete tr2rpy;
}

TEST(RotationMatrix2EulerAnglesTest, ShouldReturnNullEulerAnglesWhenInputMatrixIsNotARotationMatrix)
{
	RotationMatrix2EulerAngles* tr2rpy = new RotationMatrix2EulerAngles();
	//double rotation_matrix[2][2] = { { 1.0, 0, 0 }, { 0, 0, -1.0 }/*, { 0, 1.0, 1 }*/ }; //rotx(pi/2)
	double rotation_matrix[2][2] = { { 1.0, 0 }, { 0, -1.0 } };
	CMatrix* matrix = new CMatrix();
	matrix->CreateMatrix(rotation_matrix[0], 2, 2);
	EulerAngles null_euler_angles;
	CHECK(null_euler_angles.IsEqual(tr2rpy->tr2pry(matrix)));
	delete tr2rpy;
	delete matrix;
}

TEST(RotationMatrix2EulerAnglesTest, ReturnRollWhenRotate90DegreesAlongTheXAxis)
{
	RotationMatrix2EulerAngles* tr2rpy = new RotationMatrix2EulerAngles();
	double rotation_matrix[3][3] = { { 1.0, 0, 0 }, { 0, 0, -1.0 }, { 0, 1.0, 0 } }; //rotx(pi/2)
	CMatrix* matrix = new CMatrix();
	matrix->CreateMatrix(rotation_matrix[0], 3, 3);
	EulerAngles expected_euler_angles;
	expected_euler_angles.roll = PI / 2;
	CHECK(expected_euler_angles.IsEqual(tr2rpy->tr2pry(matrix)));
	delete tr2rpy;
	delete matrix;
}

TEST(RotationMatrix2EulerAnglesTest, ReturnPitchWhenRotate90DegreesAlongTheYAxis)
{
	RotationMatrix2EulerAngles* tr2rpy = new RotationMatrix2EulerAngles();
	double rotation_matrix[3][3] = { { 0, 0, 1.0 }, { 0, 1.0, 0 }, { -1.0, 0, 0 } }; //roty(pi/2)
	CMatrix* matrix = new CMatrix();
	matrix->CreateMatrix(rotation_matrix[0], 3, 3);
	EulerAngles expected_euler_angles;
	expected_euler_angles.pitch = PI / 2;
	CHECK(expected_euler_angles.IsEqual(tr2rpy->tr2pry(matrix)));
	delete tr2rpy;
	delete matrix;
}

TEST(RotationMatrix2EulerAnglesTest, ReturnYawWhenRotate90DegreesAlongTheZAxis)
{
	RotationMatrix2EulerAngles* tr2rpy = new RotationMatrix2EulerAngles();
	double rotation_matrix[3][3] = { { 0, -1.0, 0 }, { 1.0, 0, 0 }, { 0, 0, 1 } }; //rotz(pi/2)
	CMatrix* matrix = new CMatrix();
	matrix->CreateMatrix(rotation_matrix[0], 3, 3);
	EulerAngles expected_euler_angles;
	expected_euler_angles.yaw = PI / 2;
	CHECK(expected_euler_angles.IsEqual(tr2rpy->tr2pry(matrix)));
	delete tr2rpy;
	delete matrix;
}

TEST(RotationMatrix2EulerAnglesTest, CanConvertRotationMatrixToEulerAngles)
{
	RotationMatrix2EulerAngles* tr2rpy = new RotationMatrix2EulerAngles();
	double rotation_matrix[3][3] = 
		{ { 0.9363, -0.2896, 0.1987 }, 
		{ 0.3130, 0.9447, -0.0978 }, 
		{ -0.1593, 0.1538, 0.9752 } }; //rotx(0.1)*roty(0.2)*rotz(0.3)
	CMatrix* matrix = new CMatrix();
	matrix->CreateMatrix(rotation_matrix[0], 3, 3);
	EulerAngles expected_euler_angles;
	expected_euler_angles.roll = 0.1;
	expected_euler_angles.pitch = 0.2;
	expected_euler_angles.yaw = 0.3;
	EulerAngles actural_euler_angles = tr2rpy->tr2pry(matrix);
	CHECK(expected_euler_angles.IsEqual(actural_euler_angles));
	delete tr2rpy;
	delete matrix;
}
//singularity situation not test