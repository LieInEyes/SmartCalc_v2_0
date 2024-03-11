#ifndef CPP3_SMARTCALC_V2_0_1_MODIFY_INPUT_H
#define CPP3_SMARTCALC_V2_0_1_MODIFY_INPUT_H

#include <string>
#include <vector>

using std_str = std::string;
using std_vec_str = std::vector<std::string>;

namespace my_space {
class ModifyInput {
 public:
  ModifyInput() = delete;
  ModifyInput(const std_str &original_line, std_str x);
  ModifyInput(const ModifyInput &other) = delete;
  ModifyInput(ModifyInput &&other) noexcept = delete;
  ~ModifyInput() = default;

  ModifyInput &operator=(const ModifyInput &other) = delete;
  ModifyInput &operator=(ModifyInput &&other) noexcept = delete;

 public:
  void ModifyStringExpression(std_vec_str &output_modify_expression);

 private:
  void RecordSingleChar(const size_t &i);
  void RecordMinus(size_t &i);
  bool SearchUnaryMinus(const size_t &i) const;
  void ModifyInputWhereUnaryMinusBeforeBracket(size_t &i);
  void RecordArcTrigonometry(size_t &i);
  void RecordTrigonometryLogarithm(size_t &i);
  void RecordDigitX(size_t &i);
  void RecordX();
  void RecordDigit(size_t &i);

 private:
  const std_str k_original_line_;
  const std_str k_x_;
  std_vec_str modify_string_expression_;
  std_str temp_input_expression_;
  int flag_minus_;
};
}  // namespace my_space

#endif  // CPP3_SMARTCALC_V2_0_1_MODIFY_INPUT_H
