#include "reverse_polish_notation.h"

namespace my_space {
ReversePolishNotation::ReversePolishNotation(std_vec_str input_expression)
    : input_expression_(std::move(input_expression)) {}

void ReversePolishNotation::ReverseFromModifyToReversPolish(
    std_vec_str &reverse_expression) {
  for (size_t i = 0; i < input_expression_.size(); ++i) {
    if (input_expression_[i][0] >= '0' && input_expression_[i][0] <= '9') {
      reverse_expression_.emplace_back(input_expression_[i]);
    } else if (input_expression_[i][0] == '+') {
      ChoosingPriorityOfPlus();
    } else if (input_expression_[i][0] == '-') {
      ChoosingPriorityOfMinus(i);
    } else if (input_expression_[i][0] == '*' ||
               input_expression_[i][0] == '/') {
      ChoosingPriorityOfMultDiv(i);
    } else if (input_expression_[i][0] == '^' ||
               input_expression_[i][0] == 'm' ||
               (input_expression_[i][0] == 's' &&
                input_expression_[i][1] == 'q')) {
      ChoosingPriorityOfModScaleSqrt(i);
    } else if (input_expression_[i][0] == '(') {
      postfix_operator_.emplace("(");
    } else if (input_expression_[i][0] == ')') {
      DisclosureBracketEnd();
    } else {
      ChoosingPriorityOfTrigonometryLogorithm(i);
    }
  }
  for (; !postfix_operator_.empty(); postfix_operator_.pop()) {
    reverse_expression_.emplace_back(postfix_operator_.top());
  }
  reverse_expression = reverse_expression_;
}

int ReversePolishNotation::SearchPriority(const std_str &str) {
  if (str == "+" || str == "-") {
    return 1;
  } else if (str == "*" || str == "/") {
    return 2;
  } else if (str == "^" || str == "mod" || str == "sqrt") {
    return 3;
  } else if (str != "(") {
    return 4;
  }
  return 0;
}

void ReversePolishNotation::PushOutOperatorOfStack(int priority) {
  for (; !postfix_operator_.empty() &&
         SearchPriority(postfix_operator_.top()) >= priority;
       postfix_operator_.pop()) {
    reverse_expression_.emplace_back(postfix_operator_.top());
  }
}

void ReversePolishNotation::ChoosingPriorityOfMinus(size_t &i) {
  if (input_expression_[i].size() == 1) {
    if (!postfix_operator_.empty()) {
      PushOutOperatorOfStack(1);
    }
    postfix_operator_.emplace("-");
  } else {
    postfix_operator_.emplace(input_expression_[i]);
  }
}

void ReversePolishNotation::ChoosingPriorityOfPlus() {
  if (!postfix_operator_.empty()) {
    PushOutOperatorOfStack(1);
  }
  postfix_operator_.emplace("+");
}

void ReversePolishNotation::ChoosingPriorityOfMultDiv(size_t &i) {
  if (!postfix_operator_.empty()) {
    PushOutOperatorOfStack(2);
  }
  if (input_expression_[i][0] == '*') {
    postfix_operator_.emplace("*");
  } else {
    postfix_operator_.emplace("/");
  }
}

void ReversePolishNotation::ChoosingPriorityOfModScaleSqrt(size_t &i) {
  if (!postfix_operator_.empty()) {
    PushOutOperatorOfStack(3);
  }
  if (input_expression_[i][0] == '^') {
    postfix_operator_.emplace("^");
  } else if (input_expression_[i][0] == 'm') {
    postfix_operator_.emplace("mod");
  } else {
    postfix_operator_.emplace("sqrt");
  }
}

void ReversePolishNotation::ChoosingPriorityOfTrigonometryLogorithm(size_t &i) {
  if (!postfix_operator_.empty()) {
    PushOutOperatorOfStack(4);
  }
  if (input_expression_[i][0] == 's') {
    postfix_operator_.emplace("sin");
  } else if (input_expression_[i][0] == 'c') {
    postfix_operator_.emplace("cos");
  } else if (input_expression_[i][0] == 't') {
    postfix_operator_.emplace("tan");
  } else if (input_expression_[i][0] == 'a' && input_expression_[i][1] == 's') {
    postfix_operator_.emplace("asin");
  } else if (input_expression_[i][0] == 'a' && input_expression_[i][1] == 'c') {
    postfix_operator_.emplace("acos");
  } else if (input_expression_[i][0] == 'a' && input_expression_[i][1] == 't') {
    postfix_operator_.emplace("atan");
  } else if (input_expression_[i][0] == 'l' && input_expression_[i][1] == 'n') {
    postfix_operator_.emplace("ln");
  } else if (input_expression_[i][0] == 'l' && input_expression_[i][1] == 'o') {
    postfix_operator_.emplace("log");
  }
}

void ReversePolishNotation::DisclosureBracketEnd() {
  for (; postfix_operator_.top() != "("; postfix_operator_.pop()) {
    reverse_expression_.emplace_back(postfix_operator_.top());
  }
  postfix_operator_.pop();
}
}  // namespace my_space
