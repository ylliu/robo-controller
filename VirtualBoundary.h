#ifndef VIRTUAL_BOUNDARY_2020_08_29_H_
#define VIRTUAL_BOUNDARY_2020_08_29_H_

typedef struct BoundarySize_
{
	double x_min = -9999;
	double x_max = 9999;
	double y_min = -9999;
	double y_max = 9999;
	double z_min = -9999;
	double z_max = 9999;
}BoundarySize;

typedef struct Points3D_
{
	double x = 0;
	double y = 0;
	double z = 0;
}Points3D;
class VirtualBoundary{
public:
	VirtualBoundary(){}
	~VirtualBoundary(){}
public:
	bool CreateBoundary(BoundarySize boundary_size);
	bool InBoundary(Points3D point_in_doundary);
private:
	BoundarySize boundary_size_;
};
#endif