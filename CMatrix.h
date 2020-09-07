#pragma once

class CMatrix
{
public:
	CMatrix()
	{
	}

	~CMatrix();

	bool CreateMatrix(double* matrix_data, int row, int col);
	int GetRow(){ return row_; }
	int GetCol(){ return col_; }
	double* GetDataPtr(){ return data_ptr_; }
	bool IsEqual(const CMatrix* other);
	void PrintMatrix();
	double GetElemntByIndex(int row, int col);
protected:
private:
	//CMatrix&  CMatrix::operator=(const CMatrix& rhs);

private:
	double*	data_ptr_;
	int	row_;
	int	col_;
	int size_;

};


