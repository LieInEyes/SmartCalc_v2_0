#ifndef CPP3_SMARTCALC_V2_0_1_VALID_USER_INPUT_H
#define CPP3_SMARTCALC_V2_0_1_VALID_USER_INPUT_H

#include <string>

using std_str = std::string;

const int k_size_original_line = 255;

namespace my_space {
class ValidUserInput {
 public:
  ValidUserInput() = delete;
  explicit ValidUserInput(std_str input);
  ValidUserInput(const ValidUserInput &other) = delete;
  ValidUserInput(ValidUserInput &&other) noexcept = delete;
  ~ValidUserInput() = default;

  ValidUserInput &operator=(const ValidUserInput &other) = delete;
  ValidUserInput &operator=(ValidUserInput &&other) noexcept = delete;

 public:
  std_str Input();

 private:
  void ValidFirstChar();

  void ValidNumberAndX(int &i);
  void ValidAfterX(int &i);

  void ValidNumber(int &i);
  void ValidPoint(int i);
  void ValidExponent(int i);
  void ValidDigit(int &i);
  void ValidNumberPlusMinus(int i);

  void ValidBracket(int &i);
  void ValidAfterBracket(int i);

  void ValidMod(int &i);
  void ValidAfterMod(int i);

  void ValidTrigonometryLogarithmsSqrt(int &i);
  void ValidAfterTrigonometryLogarithmsSqrt(int i);

  void ValidMath(int i);
  void ValidMinus(int i);
  void ValidAftereMinusPosition0(int i);
  void ValidAfterMinusPositionGreater1(int i);
  void ValidAfterPlusDivMulScale(int i);

  void ClearCountVaribleForNumber();

 private:
  const std_str k_original_line_;
  std_str error_;
  int count_bracket_;
  int count_minus_;
  int count_point_;
  int count_e_;
  int count_digit_before_point_;
  int exit_;
};
}  // namespace my_space

#endif  // CPP3_SMARTCALC_V2_0_1_VALID_USER_INPUT_H
