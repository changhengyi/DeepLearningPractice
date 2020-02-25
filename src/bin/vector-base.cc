
#include "vector-base.h"
#include "utils/dl-utils.h"

namespace dl
{

using std::endl;
using std::cout;

void VectorBase::initialize() {//初始化矩阵大小
	p = new double[element_num];//分配rows_num个指针
}

VectorBase::VectorBase()
{
//    cout << "empty" << endl;
}

//声明一个全0向量
VectorBase::VectorBase(int elements)
{
	element_num = elements;
	initialize();
	for (int i = 0; i < element_num; i++) {
		p[i] = 0;
	}
}

//声明一个值全部为value的向量
VectorBase::VectorBase(int elements, double value)
{
	element_num = elements;
	initialize();
	for (int i = 0; i < element_num; i++) {
		p[i] = value;
	}
}

//析构函数
VectorBase::~VectorBase() {
//	delete[] p;
}

//设置值
void VectorBase::SetValues(double* values)
{
    for (int i = 0; i < element_num; i++) {
        p[i] = values[i];
    }
}

//+=操作
VectorBase& VectorBase::operator+=(const VectorBase& m)
{
	for (int i = 0; i < element_num; i++) {
		p[i] += m.p[i];
	}
	return *this;
}

//实现-=
VectorBase& VectorBase::operator-=(const VectorBase& m)
{
	for (int i = 0; i < element_num; i++) {
		p[i] -= m.p[i];
	}
	return *this;
}

//实现乘法
VectorBase VectorBase::operator*(const VectorBase & m)const{
	VectorBase ba_M(element_num, 0);
	for (int i = 0; i < element_num; i++) {
		ba_M.p[i] += (p[i] * m.p[i]);
	}
	return ba_M;
}

/**
 * 做内积
*/
double VectorBase::inner(const VectorBase& m)
{
    VectorBase ba_M = *this * m;

    double sum = 0;
    for (int i = 0; i < element_num; i++) {
		sum += ba_M.p[i];
	}

    return sum;
}

/**
 * 元素逐个乘标量
*/
VectorBase VectorBase::scalaMul(double scala)
{
    VectorBase ba_M(element_num, 0);
	for(int i = 0;i < element_num; i++) {
		ba_M.p[i] += (p[i] * scala);
	}
	return ba_M;
}

/**
 * 打印向量
*/
void VectorBase::Show()
{
    for (int i = 0; i < element_num; i++) {
			cout << p[i] << " ";
	}
	cout << endl;
}

}
