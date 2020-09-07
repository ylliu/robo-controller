#ifndef ROTATIONMATRIX2EULERANGLES_2020_08_30_H_
#define ROTATIONMATRIX2EULERANGLES_2020_08_30_H_
#include "CMatrix.h"
#include <math.h>
#include <iostream>
#define PI 3.1415926
#define EPS 0.0001

typedef struct EulerAngles_
{
	double roll = 0.0;
	double pitch = 0.0;
	double yaw = 0.0;
	bool IsEqual(EulerAngles_ other)
	{
		double eps = 0.0001;
		return
			(fabs(this->roll - other.roll) < eps&&
			fabs(this->pitch - other.pitch) < eps&&
			fabs(this->yaw - other.yaw) < eps);
	}
	void PrintEulerAngles(){
		std::cout << std::endl;
		std::cout << "roll:" << roll << " pitch:" << pitch << " yaw:" << yaw << std::endl;
	}
}EulerAngles;

class RotationMatrix2EulerAngles
{
public:
	RotationMatrix2EulerAngles()
	{
	}

	~RotationMatrix2EulerAngles()
	{
	}

	EulerAngles tr2pry(CMatrix* matrix);

	bool IsSingularity(CMatrix* matrix);

	void PrintEulerAngles();
protected:

private:

};

#endif


