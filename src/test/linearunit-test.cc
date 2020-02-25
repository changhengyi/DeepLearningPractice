//
//  linearunit-test.c
//  deeplearning
//
//  Created by 邱威 on 2020/1/19.
//  Copyright © 2020 qiuwei. All rights reserved.
//

#include <tuple>
#include <vector>

#include "bin/vector-base.h"
#include "utils/dl-utils.h"
#include "linearunit/linear-unit.h"

namespace dl
{

// 生成训练数据
tuple<vector<VectorBase>, double *> lu_GetTrainingDataSet()
{
    double values[5][1] = {{5}, {3}, {8}, {1.4}, {10.1}};

    vector<VectorBase> input_vecs(5);
    int value_num = getArrayLenth(values);
    for (int i = 0; i < value_num; i++)
    {
        double *value = values[i];
        VectorBase input_vec = VectorBase(1);
        input_vec.SetValues(value);
        input_vecs[i] = input_vec;
    }

    double labels[5] = {5500, 2300, 7600, 1800, 11400};

    return make_tuple(input_vecs, labels);
}

// 训练线性单元
LinearUnit TrainLinearUnit()
{
    LinearUnit lu = LinearUnit();
    lu.Init(1);

    tuple<vector<VectorBase>, double *> sample = lu_GetTrainingDataSet();
    vector<VectorBase> input_vecs = get<0>(sample);
    //     double *labels = get<1>(sample);
    double labels[5] = {5500, 2300, 7600, 1800, 11400};
//    cout << "lab:" << labels[0] << endl;
    LinearActivator la = LinearActivator();
    lu.Train(input_vecs, labels, 10, 0.01, la);

    return lu;
}

}

int main(int argc, char *argv[])
{
    try
    {
      using namespace dl;
      using namespace std;
      LinearUnit lu = TrainLinearUnit();

      lu.Show();

      //测试
      double d1[] = {3.4};
      VectorBase vec1 = VectorBase(1);
      vec1.SetValues(d1);

        double d2[] = {15};
        VectorBase vec2 = VectorBase(1);
        vec2.SetValues(d2);

        double d3[] = {1.5};
        VectorBase vec3 = VectorBase(1);
        vec3.SetValues(d3);

        double d4[] = {6.3};
        VectorBase vec4 = VectorBase(1);
        vec4.SetValues(d4);

        LinearActivator la = LinearActivator();

        cout << "Work 3.4 years, monthly salary = " << lu.Predict(vec1, &la) << endl;
        cout << "Work 15 years, monthly salary = " << lu.Predict(vec2, &la) << endl;
        cout << "Work 1.5 years, monthly salary = " << lu.Predict(vec3, &la) << endl;
        cout << "Work 6.3 years, monthly salary = " << lu.Predict(vec4, &la) << endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what();
      return -1;
    }

    return 0;
}


