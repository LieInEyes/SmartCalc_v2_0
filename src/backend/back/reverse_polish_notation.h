#ifndef CPP3_SMARTCALC_V2_0_1_REVERSE_POLISH_NOTATION_H
#define CPP3_SMARTCALC_V2_0_1_REVERSE_POLISH_NOTATION_H

#include <stack>
#include <string>
#include <vector>

using std_str = std::string;
using std_vec_str = std::vector<std::string>;
using std_stk_str = std::stack<std::string>;

namespace my_space {
class ReversePolishNotation {
 public:
  ReversePolishNotation() = delete;
  explicit ReversePolishNotation(std_vec_str input_expression);
  ReversePolishNotation(const ReversePolishNotation &other) = delete;
  ReversePolishNotation(ReversePolishNotation &&other) noexcept = delete;
  ~ReversePolishNotation() = default;

  ReversePolishNotation &operator=(const ReversePolishNotation &other) = delete;
  ReversePolishNotation &operator=(ReversePolishNotation &&other) noexcept =
      delete;

 public:
  void ReverseFromModifyToReversPolish(std_vec_str &output_reverse_expression);

 private:
  static int SearchPriority(const std_str &str);
  void PushOutOperatorOfStack(int priority);
  void ChoosingPriorityOfMinus(size_t &i);
  void ChoosingPriorityOfPlus();
  void ChoosingPriorityOfMultDiv(size_t &i);
  void ChoosingPriorityOfModScaleSqrt(size_t &i);
  void ChoosingPriorityOfTrigonometryLogorithm(size_t &i);
  void DisclosureBracketEnd();

 private:
  const std_vec_str input_expression_;
  std_vec_str reverse_expression_;
  std_stk_str postfix_operator_;
};
}  // namespace my_space

#endif  // CPP3_SMARTCALC_V2_0_1_REVERSE_POLISH_NOTATION_H
