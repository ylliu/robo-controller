#include "VirtualBoundary.h"

bool VirtualBoundary::InBoundary(Points3D point_in_doundary)
{
	if (point_in_doundary.x < boundary_size_.x_min)
		return false;
	if (point_in_doundary.x > boundary_size_.x_max)
		return false;
	if (point_in_doundary.y > boundary_size_.y_max)
		return false;
	if (point_in_doundary.y < boundary_size_.y_min)
		return false;
	if (point_in_doundary.z < boundary_size_.z_min)
		return false;
	if (point_in_doundary.z > boundary_size_.z_max)
		return false;
	return true;
}

bool VirtualBoundary::CreateBoundary(BoundarySize boundary_size)
{
	boundary_size_ = boundary_size;
	return true;
}

