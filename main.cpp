#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include <catboost/libs/model_interface/c_api.h>

int main() {
  auto modelHandle = ModelCalcerCreate();
  if (!LoadFullModelFromFile(modelHandle, "model.cbm")) {
    printf("LoadFullModelFromFile error message: %s\n", GetErrorString());
  }

  if (!SetPredictionType(modelHandle, APT_PROBABILITY)) {
    printf("SetPredictionType error message: %s\n", GetErrorString());
  }

  float fs[2] = {1.1f, 2.2f};
  double result[1];
  if (!CalcModelPredictionSingle(modelHandle, fs, 2, nullptr, 0, result, 1)) {
    printf("CalcModelPredictionSingle error message: %s\n", GetErrorString());
  }

  printf("result: %f", result[0]);

  //   auto floats = std::vector<float>{1.1f, 2.2f};

  //   auto d = floats.data();
  //   auto p = d->data();
  //   const float **p1 = &p;

  // static const float data[1][2] = {{1.0f, 2.0f}};

  // const float *ptrs[2];
  // for (int i = 0; i < 2; ++i) {
  //   ptrs[i] = data[i];
  // }

  // const float **cppStylePtr = ptrs;

  // auto floats = std::vector<float>{1.1f, 2.2f};
  // const float *p = floats.data();
  // auto p2 = &p;
  // //   auto p1 = floats.data();
  // //   const float ** p2 = &floats[0].;

  // auto strings = std::vector<const char *>{"hello"};

  // auto p3 = strings.data();
  // const char ***p4 = &p3;
  //   auto p4 = &p3;
  //   auto p5 = &p4;

  auto val = GetShapValues(modelHandle);
  // std::cout << "val: " << val;

  // auto m = ModelCalcerCreate();

  return 0;
}