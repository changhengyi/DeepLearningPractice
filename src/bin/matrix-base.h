#include <iostream>

#ifndef DL_MATRIX_BASE_H
#define DL_MATRIX_BASE_H
 
namespace dl
{

class MatrixBase {
private:
	int rows_num, cols_num;
	double **p;
	void initialize();//初始化矩阵
 
public:
	MatrixBase(int, int);
	MatrixBase(int, int, double);//预配分空间
	virtual ~MatrixBase();//析构函数应当是虚函数，除非此类不用做基类
	
	MatrixBase& operator=(const MatrixBase&);//矩阵的复制
	MatrixBase& operator=(double *);//将数组的值传给矩阵
	MatrixBase& operator+=(const MatrixBase&);//矩阵的+=操作
	MatrixBase& operator-=(const MatrixBase&);//-=
	MatrixBase& operator*=(const MatrixBase&);//*=
	MatrixBase operator*(const MatrixBase & m)const;
	
	void Show() const;//矩阵显示
	
	double Point(int i, int j) const;
	int row() const;
	int col() const;

	static MatrixBase T(const MatrixBase & m);//矩阵转置的实现,且不改变矩阵
    
};
}
 
 
#endif