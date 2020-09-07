#include "CppUTest/UtestMacros.h"
#include "CppUTest/TestHarness.h"
#define private public
#include "VirtualBoundary.h"
#include <memory>

TEST_GROUP(BoundaryTest)
{
	void setup(){
		virtual_boundary = std::make_shared<VirtualBoundary>();
	}
	void teardown(){
	}
	std::shared_ptr<VirtualBoundary> virtual_boundary;
};

TEST(BoundaryTest, CanCreateVirtualBoundary)
{
	BoundarySize boundary_size;
	boundary_size.x_min = -10;
	boundary_size.x_max = 10;
	boundary_size.y_min = -10;
	boundary_size.y_max = 10;
	boundary_size.z_min = -10;
	boundary_size.z_max = 10;
	CHECK_EQUAL(true, virtual_boundary->CreateBoundary(boundary_size));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointXValueIsSmallerThanTheXMin)
{
	BoundarySize boundary_size;
	boundary_size.x_min = -10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.x = -11;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointXValueIsBiggerThanTheXMax)
{
	BoundarySize boundary_size;
	boundary_size.x_max = 10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.x = 11;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointYValueIsBiggerThanTheYMax)
{
	BoundarySize boundary_size;
	boundary_size.y_max = 10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.y = 11;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointYValueIsSmallerThanTheYMin)
{
	BoundarySize boundary_size;
	boundary_size.y_min = -10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.y = -11;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointZValueIsSmallerThanTheZMin)
{
	BoundarySize boundary_size;
	boundary_size.z_min = -10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.z = -11;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointZValueIsBiggerThanTheZMax)
{
	BoundarySize boundary_size;
	boundary_size.z_max = 10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.z = 11;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnTrueWhenPointIsInBoundary)
{
	BoundarySize boundary_size;
	boundary_size.x_min = -10;
	boundary_size.x_max = 10;
	boundary_size.y_min = -10;
	boundary_size.y_max = 10;
	boundary_size.z_min = -10;
	boundary_size.z_max = 10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.x = 1;
	point_in_doundary.y = 2;
	point_in_doundary.z = 1;
	CHECK_EQUAL(true, virtual_boundary->InBoundary(point_in_doundary));
}

TEST(BoundaryTest, ShouldReturnFalseWhenPointIsOutOfBoundary)
{
	BoundarySize boundary_size;
	boundary_size.x_min = -10;
	boundary_size.x_max = 10;
	boundary_size.y_min = -10;
	boundary_size.y_max = 10;
	boundary_size.z_min = -10;
	boundary_size.z_max = 10;
	virtual_boundary->CreateBoundary(boundary_size);
	Points3D point_in_doundary;
	point_in_doundary.x = 11;
	point_in_doundary.y = -11;
	point_in_doundary.z = -10;
	CHECK_EQUAL(false, virtual_boundary->InBoundary(point_in_doundary));
}