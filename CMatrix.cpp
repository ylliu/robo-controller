#include "CMatrix.h"
#include <math.h>
#include <iostream>

CMatrix::~CMatrix()
{
	delete[] data_ptr_;
}


bool CMatrix::CreateMatrix(double* matrix_data, int row, int col)
{
	row_ = row;
	col_ = col;
	size_ = row_*col_;
	if (size_ > 0)
	{
		data_ptr_ = new double[size_];
		for (int i = 0; i < size_; i++)
		{
			data_ptr_[i] = matrix_data[i];
		}
		return true;
	}
	else{
		data_ptr_ = nullptr;
		return false;
	}
}

bool CMatrix::IsEqual(const CMatrix* other)
{
	if (this->row_ != other->row_)
		return false;
	if (this->col_ != other->col_)
		return false;
	for (int i = 0; i < row_*col_; i++)
	{
		if (fabs(this->data_ptr_[i] - (other->data_ptr_[i]))>0.000001)
			return false;
	}
	return true;
}

void CMatrix::PrintMatrix()
{
	std::cout << std::endl;
	for (int i = 0; i < row_; i++)
	{
		for (int j = 0; j < col_; j++)
		{
			std::cout << data_ptr_[i*col_ + j] << " ";
		}
		std::cout << std::endl;
	}
}

double CMatrix::GetElemntByIndex(int row, int col)
{
	if (row>row_ || col > col_)
		return -9999999.0;
	return	data_ptr_[row*col_ + col];
}

