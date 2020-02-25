
#include <tuple>
#include <vector>

#include "perceptron/perceptron.h"
#include "utils/dl-utils.h"
// #include "perceptron-test.h"

namespace dl
{

//基于and真值表构建训练数据
 tuple<vector<VectorBase>, double *> GetTrainingDataSet()
 {
     double values[4][2] = {{1, 1}, {0, 0}, {1, 0}, {0, 1}};
//     vector<double *> values(4);
//     values(0) = {1, 1};
//     VectorBase *input_vecs = new VectorBase[4];
     vector<VectorBase> input_vecs(4);
     int value_num = getArrayLenth(values);
     for (int i = 0; i < value_num; i++)
     {
         double *value = values[i];
         VectorBase input_vec = VectorBase(2);
         input_vec.SetValues(value);
         input_vecs[i] = input_vec;
     }

     double labels[4] = {1, 0, 0, 0};

     return make_tuple(input_vecs, labels);
 }

//使用and真值表训练感知器 
 Perceptron TrainAndPerception()
 {
     ReluActivator relu = ReluActivator();
     Perceptron p = Perceptron();
     p.Init(2);
     tuple<vector<VectorBase>, double *> sample = GetTrainingDataSet();
     vector<VectorBase> input_vecs = get<0>(sample);
    //  double *labels = get<1>(sample);
    double labels[4] = {1, 0, 0, 0};
     cout << "lab:" << labels[0] << endl;
     p.Train(input_vecs, labels, 10, 0.1, relu);

     return p;
 }

}

int main(int argc, char *argv[])
{
  try
  {
    using namespace dl;
    using namespace std;
    Perceptron and_p = TrainAndPerception();

    and_p.Show();

    //测试
    double d1[] = {1, 1};
    VectorBase vec1 = VectorBase(2);
    vec1.SetValues(d1);

      double d2[] = {0, 0};
      VectorBase vec2 = VectorBase(2);
      vec2.SetValues(d2);

      double d3[] = {1, 0};
      VectorBase vec3 = VectorBase(2);
      vec3.SetValues(d3);

      double d4[] = {0, 1};
      VectorBase vec4 = VectorBase(2);
      vec4.SetValues(d4);

      ReluActivator relue = ReluActivator();

    cout << "1 and 1 = " << and_p.Predict(vec1, &relue) << endl;
      cout << "0 and 0 = " << and_p.Predict(vec2, &relue) << endl;
      cout << "1 and 0 = " << and_p.Predict(vec3, &relue) << endl;
      cout << "0 and 1 = " << and_p.Predict(vec4, &relue) << endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
    return -1;
  }

    return 0;
}

