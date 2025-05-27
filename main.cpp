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

  auto val = GetShapValues(modelHandle);

  return 0;
}