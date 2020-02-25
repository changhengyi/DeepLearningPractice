
#include <iostream>

#ifndef DL_VECTOR_BASE_H
#define DL_VECTOR_BASE_H

namespace dl
{

class VectorBase
{
private:
    int element_num;
	double *p;
	void initialize();//初始化矩阵

public:
    VectorBase();
    VectorBase(int);
    VectorBase(int, double);
    virtual ~VectorBase();

    void SetValues(double*);

    VectorBase& operator+=(const VectorBase&);//向量的+=操作
    VectorBase& operator-=(const VectorBase&);//-=
	VectorBase operator*(const VectorBase & m)const;

    double inner(const VectorBase&); //做内积
    VectorBase scalaMul(double scala); //元素逐个乘标量

    void Show(); //打印向量

    int Dim() const { return element_num; }
};

    
}

#endif
