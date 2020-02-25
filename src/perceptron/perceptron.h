#include "activator/activator.h"
#include "bin/vector-base.h"

#include <string>
#include <vector>

#ifndef DL_PERCEPTRON_H
#define DL_PERCEPTRON_H

namespace dl
{

using namespace std;

class Perceptron
{
protected:
    
//    Activator activator_;
    VectorBase *weights_;
    double bias_;

public:
    Perceptron(/* args */);
    ~Perceptron();

    void Init(int input_num);
    void Show();
    double Predict(VectorBase input_vec, Activator *activator);

    void Train(vector<VectorBase> input_vecs, double *labels, int iteration, double rate, Activator &activator);
    void OneIteration(vector<VectorBase> input_vecs, double *labels, double rate, Activator *activator);
    void UpdateWeights(VectorBase input_vec, double output, double label, double rate);
};
    
}

#endif
