#include "model_calculator.h"

namespace my_space {
ModelCalculator::ModelCalculator(std_str input, std_str x)
    : k_original_line_(std::move(input)), k_x_(std::move(x)), flag_minus_(0) {}

void ModelCalculator::Calculate(double &result, std_str &error) {
  ModifyInput modify_input(k_original_line_, k_x_);
  modify_input.ModifyStringExpression(modify_string_expression_);

  ReversePolishNotation reverse_polish_notation(modify_string_expression_);
  reverse_polish_notation.ReverseFromModifyToReversPolish(reverse_expression_);

  for (size_t i = 0; i < reverse_expression_.size(); ++i) {
    if (reverse_expression_[i][0] >= '0' && reverse_expression_[i][0] <= '9') {
      postfix_result_.emplace(stod(reverse_expression_[i], nullptr));
    } else if (reverse_expression_[i][0] == '-') {
      CalculationMinusOperation(i);
    } else if (reverse_expression_[i][0] == '+' ||
               reverse_expression_[i][0] == '*' ||
               reverse_expression_[i][0] == '/' ||
               reverse_expression_[i][0] == '^') {
      CalculationSimpleMathOperation(i, error);
    } else if (reverse_expression_[i][0] == 'a' ||
               reverse_expression_[i][0] == 'l') {
      CalculationArcLogOperation(i);
    } else if (reverse_expression_[i][0] == 's') {
      CalculationSinSqrtOperation(i);
    } else if (reverse_expression_[i][0] == 'c' ||
               reverse_expression_[i][0] == 't' ||
               reverse_expression_[i][0] == 'm') {
      CalculationCosTanModOperation(i);
    }
  }
  if (error == "0") {
    result = postfix_result_.top();
  }
}

void ModelCalculator::CalculationMinusOperation(size_t &i) {
  if (reverse_expression_[i].size() == 1) {
    double temp_right = postfix_result_.top();
    postfix_result_.pop();
    double temp_left = postfix_result_.top();
    postfix_result_.pop();
    postfix_result_.emplace(temp_left - temp_right);
  } else {
    if (reverse_expression_[i][1] >= '0' && reverse_expression_[i][1] <= '9') {
      postfix_result_.emplace(stod(reverse_expression_[i], nullptr));
    } else {
      ++flag_minus_;
      reverse_expression_[i].erase(0, 1);
      --i;
    }
  }
}

void ModelCalculator::CalculationSimpleMathOperation(size_t &i,
                                                     std_str &error) {
  double temp_right = postfix_result_.top();
  postfix_result_.pop();
  double temp_left = postfix_result_.top();
  postfix_result_.pop();
  if (reverse_expression_[i][0] == '+') {
    postfix_result_.emplace(temp_left + temp_right);
  } else if (reverse_expression_[i][0] == '*') {
    postfix_result_.emplace(temp_left * temp_right);
  } else if (reverse_expression_[i][0] == '/') {
    if (temp_right == 0) {
      error = "Ошибка: деление на 0 запрещено";
    } else {
      postfix_result_.emplace(temp_left / temp_right);
    }
  } else {
    postfix_result_.emplace(pow(temp_left, temp_right));
  }
}

void ModelCalculator::CalculationArcLogOperation(size_t &i) {
  double temp_right;
  temp_right = postfix_result_.top();
  postfix_result_.pop();
  double temp_result = 0.0;
  if (reverse_expression_[i][1] == 's') {
    temp_result = asin(temp_right);
  } else if (reverse_expression_[i][1] == 'c') {
    temp_result = acos(temp_right);
  } else if (reverse_expression_[i][1] == 't') {
    temp_result = atan(temp_right);
  } else if (reverse_expression_[i][1] == 'o') {
    temp_result = log10(temp_right);
  } else if (reverse_expression_[i][1] == 'n') {
    temp_result = log(temp_right);
  }
  if (flag_minus_) {
    postfix_result_.emplace(temp_result * -1);
    --flag_minus_;
  } else {
    postfix_result_.emplace(temp_result);
  }
}

void ModelCalculator::CalculationSinSqrtOperation(size_t &i) {
  double temp_right = postfix_result_.top();
  postfix_result_.pop();
  double temp_result = 0.0;
  if (reverse_expression_[i][1] == 'i') {
    temp_result = sin(temp_right);
  } else if (reverse_expression_[i][1] == 'q') {
    temp_result = sqrt(temp_right);
  }
  if (flag_minus_) {
    postfix_result_.emplace(temp_result * -1);
    --flag_minus_;
  } else {
    postfix_result_.emplace(temp_result);
  }
}

void ModelCalculator::CalculationCosTanModOperation(size_t &i) {
  double temp_right = postfix_result_.top();
  postfix_result_.pop();
  double temp_result = 0.0;
  if (reverse_expression_[i][0] == 'c') {
    temp_result = cos(temp_right);
  } else if (reverse_expression_[i][0] == 't') {
    temp_result = tan(temp_right);
  } else if (reverse_expression_[i][0] == 'm') {
    double temp_left = postfix_result_.top();
    postfix_result_.pop();
    temp_result = fmod(temp_left, temp_right);
  }
  if (flag_minus_) {
    postfix_result_.emplace(temp_result * -1);
    --flag_minus_;
  } else {
    postfix_result_.emplace(temp_result);
  }
}
}  // namespace my_space
