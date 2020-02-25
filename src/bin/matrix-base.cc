#include "matrix-base.h"

namespace dl
{

using std::endl;
using std::cout;
using std::istream;

const double EPS = 1e-10;

void MatrixBase::initialize() {//初始化矩阵大小
	p = new double*[rows_num];//分配rows_num个指针
	for (int i = 0; i < rows_num; ++i) {
		p[i] = new double[cols_num];//为p[i]进行动态内存分配，大小为cols
	}
}
//声明一个全0矩阵
MatrixBase::MatrixBase(int rows, int cols)
{
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = 0;
		}
	}
}
//声明一个值全部为value的矩阵
MatrixBase::MatrixBase(int rows, int cols, double value)
{
	rows_num = rows;
	cols_num = cols;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = value;
		}
	}
}
 
//析构函数
MatrixBase::~MatrixBase() {
 for (int i = 0; i < rows_num; ++i) {
			delete[] p[i];
		}
		delete[] p;
}
//实现矩阵的复制
MatrixBase& MatrixBase::operator=(const MatrixBase& m)
{
	if (this == &m) {
		return *this;
	}
 
	if (rows_num != m.rows_num || cols_num != m.cols_num) {
		for (int i = 0; i < rows_num; ++i) {
			delete[] p[i];
		}
		delete[] p;
 
		rows_num = m.rows_num;
		cols_num = m.cols_num;
		initialize();
	}
 
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}
	return *this;
}
//将数组的值传递给矩阵(要求矩阵的大小已经被声明过了)
MatrixBase& MatrixBase::operator=(double *a){
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<cols_num;j++){
			p[i][j]= *(a+i*cols_num+j);
		}
	}
	return *this;
}
//+=操作
MatrixBase& MatrixBase::operator+=(const MatrixBase& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;
}
//实现-=
MatrixBase& MatrixBase::operator-=(const MatrixBase& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
}
//实现*=
MatrixBase& MatrixBase::operator*=(const MatrixBase& m)
{
	MatrixBase temp(rows_num, m.cols_num);//若C=AB,则矩阵C的行数等于矩阵A的行数，C的列数等于B的列数。
	for (int i = 0; i < temp.rows_num; i++) {
		for (int j = 0; j < temp.cols_num; j++) {
			for (int k = 0; k < cols_num; k++) {
				temp.p[i][j] += (p[i][k] * m.p[k][j]);
			}
		}
	}
	*this = temp;
	return *this;
}
//实现矩阵的乘法
MatrixBase MatrixBase::operator*(const MatrixBase & m)const{
	MatrixBase ba_M(rows_num,m.cols_num,0.0);
	for(int i=0;i<rows_num;i++){
		for(int j=0;j<m.cols_num;j++){
			for(int k=0;k<cols_num;k++){
				ba_M.p[i][j]+=(p[i][k]*m.p[k][j]);
			}
		}
	}
	return ba_M;
}
 
//矩阵显示
void MatrixBase::Show() const {
	//cout << rows_num <<" "<<cols_num<< endl;//显示矩阵的行数和列数
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//返回矩阵第i行第j列的数
double MatrixBase::Point(int i, int j) const{
	return this->p[i][j];
}

//读取矩阵行列数
int MatrixBase::row() const{
	return rows_num;
}

int MatrixBase::col() const{
	return cols_num;
}

//实现矩阵的转置
MatrixBase MatrixBase::T(const MatrixBase & m)
{	int col_size=m.col();
	int row_size=m.row();
	MatrixBase mt(col_size, row_size);
	for (int i = 0; i <row_size; i++) {
		for (int j = 0; j <col_size; j++) {
			mt.p[j][i] = m.p[i][j];
		}
	}
	return mt;
}

}

