
#include "perceptron.h"
#include "utils/dl-utils.h"

namespace dl
{

Perceptron::Perceptron()
{

}

Perceptron::~Perceptron()
{
    delete weights_;
}

void Perceptron::Init(int input_num)
{
//    activator_ = activator;
    bias_ = 0;
    weights_ = new VectorBase(input_num);
}

/**
 * 打印权重和偏置量
*/
void Perceptron::Show()
{
    weights_->Show();
    cout << "bias:\t" << bias_ << endl;
}

/**
 * 输入向量，输出感知器的计算结果
*/
double Perceptron::Predict(VectorBase input_vec, Activator *activator)
{
    double value = weights_->inner(input_vec) + bias_;
    return activator->Backward(value);
}

/**
 * 输入训练数据：一组向量与每个向量对应的label，以及训练轮数，学习率
*/
void Perceptron::Train(vector<VectorBase> input_vecs, double *labels, int iteration, double rate, Activator &activator)
{
    for (int i = 0; i <iteration; i++)
    {
        OneIteration(input_vecs, labels, rate, &activator);
    }
}

/**
 * 一次迭代，把所有的训练数据过一遍
*/
void Perceptron::OneIteration(vector<VectorBase> input_vecs, double *labels, double rate, Activator *activator)
{
    for (int i = 0; i < input_vecs.size(); i++) {
        VectorBase input_vec = input_vecs[i];
        double label = labels[i];
        double output = Predict(input_vec, activator);

        UpdateWeights(input_vec, output, label, rate);
    }
}

/**
 * 按感知器规则更新权重
*/
void Perceptron::UpdateWeights(VectorBase input_vec, double output, double label, double rate)
{
    double delta = label - output;
    VectorBase scalaVec = input_vec.scalaMul(rate * delta);
    *weights_ += scalaVec;

    //更新
    bias_ += rate * delta;
    weights_->Show();

    cout  << "bias:" << bias_ << endl;
}

}
