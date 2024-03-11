#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATOR_H
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATOR_H

#include <cmath>
#include <stack>
#include <vector>

#include "modify_input.h"
#include "reverse_polish_notation.h"

namespace my_space {

using std_str = std::string;
using std_vec_str = std::vector<std::string>;
using std_stk_dbl = std::stack<double>;

class ModelCalculator {
 public:
  ModelCalculator() = delete;
  ModelCalculator(std_str input, std_str x);
  ModelCalculator(const ModelCalculator &other) = delete;
  ModelCalculator(ModelCalculator &&other) noexcept = delete;
  ~ModelCalculator() = default;

  ModelCalculator &operator=(const ModelCalculator &other) = delete;
  ModelCalculator &operator=(ModelCalculator &&other) noexcept = delete;

 public:
  void Calculate(double &result, std_str &error);

 private:
  void CalculationMinusOperation(size_t &i);
  void CalculationSimpleMathOperation(size_t &i, std_str &error);
  void CalculationArcLogOperation(size_t &i);
  void CalculationSinSqrtOperation(size_t &i);
  void CalculationCosTanModOperation(size_t &i);

 private:
  const std_str k_original_line_;
  const std_str k_x_;
  std_vec_str modify_string_expression_;
  std_vec_str reverse_expression_;
  std_stk_dbl postfix_result_;
  int flag_minus_;
};
}  // namespace my_space

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_CALCULATOR_H
