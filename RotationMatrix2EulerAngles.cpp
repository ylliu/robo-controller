#include "RotationMatrix2EulerAngles.h"
#include <iostream>


EulerAngles RotationMatrix2EulerAngles::tr2pry(CMatrix* matrix)
{
	EulerAngles  euler_angles;
	if (matrix->GetCol() != 3 || matrix->GetRow() != 3)
		return euler_angles;

	//double eps = 0.0001;
	//if (IsSingularity(matrix))
	//{
	//	euler_angles.roll = 0.0;
	//	euler_angles.pitch = atan2(matrix->GetElemntByIndex(0, 2), matrix->GetElemntByIndex(2, 2));
	//	euler_angles.yaw = atan2(matrix->GetElemntByIndex(1, 0), matrix->GetElemntByIndex(1, 1));
	//	return euler_angles;
	//}

	euler_angles.roll = atan2(-matrix->GetElemntByIndex(1, 2), matrix->GetElemntByIndex(2, 2));
	double sr = sin(euler_angles.roll);
	double cr = cos(euler_angles.roll);
	euler_angles.pitch = atan2(matrix->GetElemntByIndex(0, 2),
		cr * matrix->GetElemntByIndex(2, 2) - sr * matrix->GetElemntByIndex(1, 2));

	euler_angles.yaw = atan2(-matrix->GetElemntByIndex(0, 1), matrix->GetElemntByIndex(0, 0));
	return euler_angles;
}

bool RotationMatrix2EulerAngles::IsSingularity(CMatrix* matrix)
{
	return matrix->GetElemntByIndex(2, 2) < EPS&&matrix->GetElemntByIndex(1, 2) < EPS;
}

void RotationMatrix2EulerAngles::PrintEulerAngles()
{
}
