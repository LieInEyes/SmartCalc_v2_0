#include "modify_input.h"

#include <utility>

namespace my_space {
ModifyInput::ModifyInput(const std_str &original_line, std_str x)
    : k_original_line_(original_line),
      k_x_(std::move(x)),
      temp_input_expression_(original_line),
      flag_minus_(0) {}

//// Класс принимает строку введеную пользователем и разюивает её на лексемы,
//// при необходимости добавляет выражение в случае унарнорго минуса.
//// Полученые лексемы записывает в переменную типа вектор
/// modify_string_expression

//// ОСНОВНАЯ ФУНКЦИЯ МОДИФИКАЦИИ (запускает цикл посимвольно)
void ModifyInput::ModifyStringExpression(
    std_vec_str &modify_string_expression) {
  for (size_t i = 0; i < temp_input_expression_.size(); ++i) {
    if (temp_input_expression_[i] == '(' || temp_input_expression_[i] == ')' ||
        temp_input_expression_[i] == '+' || temp_input_expression_[i] == '*' ||
        temp_input_expression_[i] == '/' || temp_input_expression_[i] == '^') {
      RecordSingleChar(i);
    } else if (temp_input_expression_[i] == '-') {
      RecordMinus(i);
    } else if (temp_input_expression_[i] == 'a') {
      RecordArcTrigonometry(i);
    } else if (temp_input_expression_[i] == 'l' ||
               temp_input_expression_[i] == 's' ||
               temp_input_expression_[i] == 'c' ||
               temp_input_expression_[i] == 't') {
      RecordTrigonometryLogarithm(i);
    } else if (temp_input_expression_[i] == 'm') {
      modify_string_expression_.emplace_back("mod");
      i += 2;
    } else {
      RecordDigitX(i);
    }
  }
  modify_string_expression = modify_string_expression_;
}

//// ОТДЕЛЯЕМ ОДИНОЧНЫЙ СИМВОЛ=ОПЕРАТОР=СКОБКИ
void ModifyInput::RecordSingleChar(const size_t &i) {
  if (temp_input_expression_[i] == '(') {
    modify_string_expression_.emplace_back("(");
  } else if (temp_input_expression_[i] == ')') {
    modify_string_expression_.emplace_back(")");
  } else if (temp_input_expression_[i] == '+') {
    modify_string_expression_.emplace_back("+");
  } else if (temp_input_expression_[i] == '*') {
    modify_string_expression_.emplace_back("*");
  } else if (temp_input_expression_[i] == '/') {
    modify_string_expression_.emplace_back("/");
  } else if (temp_input_expression_[i] == '^') {
    modify_string_expression_.emplace_back("^");
  }
}

//// ЗАПИСЫВАЕМ МИНУС. ЕСЛИ УНАРНЫЙ, ДОБАВЛЯЕМ ВЫРАЖЕНИЕ, ИНАЧЕ ПРОСТО
///ЗАПИСЫВАЕМ ЛЕКСЕМУ -
void ModifyInput::RecordMinus(size_t &i) {
  if (SearchUnaryMinus(i)) {
    if (temp_input_expression_[i + 1] == '(') {
      ModifyInputWhereUnaryMinusBeforeBracket(i);
    } else {
      ++flag_minus_;
    }
  } else {
    modify_string_expression_.emplace_back("-");
  }
}

//// ОТДЕЛЯЕМ ПРОСТОЙ МИНУС ОТ УНАРНОГО
bool ModifyInput::SearchUnaryMinus(const size_t &i) const {
  if (i == 0 || (i > 0 &&
                 (temp_input_expression_[i - 1] == '(' ||
                  temp_input_expression_[i - 1] == '+' ||
                  temp_input_expression_[i - 1] == '-' ||
                  temp_input_expression_[i - 1] == '*' ||
                  temp_input_expression_[i - 1] == '/' ||
                  temp_input_expression_[i - 1] == 'n' ||
                  temp_input_expression_[i - 1] == 's' ||
                  temp_input_expression_[i - 1] == 't' ||
                  temp_input_expression_[i - 1] == 'g' ||
                  temp_input_expression_[i - 1] == '^' ||
                  temp_input_expression_[i - 1] == 'd') &&
                 ((temp_input_expression_[i + 1] >= '0' &&
                   temp_input_expression_[i + 1] <= '9') ||
                  temp_input_expression_[i + 1] == 'x' ||
                  temp_input_expression_[i + 1] == 'a' ||
                  temp_input_expression_[i + 1] == 's' ||
                  temp_input_expression_[i + 1] == 'c' ||
                  temp_input_expression_[i + 1] == 't' ||
                  temp_input_expression_[i + 1] == 'l' ||
                  temp_input_expression_[i + 1] == '('))) {
    return true;
  } else {
    return false;
  }
}

//// ДОБАВЛЯЕМ УСЛОВИЕ ДЛЯ УНАРНОГ МИНУСА ЕСЛИ ОН СТОИТ ПЕРЕД ОТКРВАЮЩЕЙ СКОБКОЙ
void ModifyInput::ModifyInputWhereUnaryMinusBeforeBracket(size_t &i) {
  std_str temp;
  for (size_t j = 0; j < i; ++j) {
    temp += temp_input_expression_[i];
  }
  temp += "(0-";
  int count_bracket = 1;
  size_t j = i + 1;
  temp += temp_input_expression_[j];
  ++j;
  for (; count_bracket; ++j) {
    if (temp_input_expression_[j] == '(') {
      ++count_bracket;
      temp += temp_input_expression_[j];
    } else if (temp_input_expression_[j] == ')') {
      --count_bracket;
      temp += temp_input_expression_[j];
    } else {
      temp += temp_input_expression_[j];
    }
  }
  temp += ')';
  for (; j < temp_input_expression_.size() || temp_input_expression_[j] != '\0';
       ++j) {
    temp += temp_input_expression_[j];
  }
  temp_input_expression_ = temp;
  --i;
}

//// ЗАПИСЫВАЕМ ARC TRIGONOMETRY
void ModifyInput::RecordArcTrigonometry(size_t &i) {
  std_str temp;
  if (flag_minus_) {
    temp = "-";
  }
  if (temp_input_expression_[i + 1] == 's') {
    modify_string_expression_.emplace_back(temp + "asin");
  } else if (temp_input_expression_[i + 1] == 'c') {
    modify_string_expression_.emplace_back(temp + "acos");
  } else if (temp_input_expression_[i + 1] == 't') {
    modify_string_expression_.emplace_back(temp + "atan");
  }
  i += 3;
  if (flag_minus_) {
    --flag_minus_;
  }
}

//// ЗАПИСЫВАЕМ TRIGONOMETRY, LOGARYTHM, SQRT
void ModifyInput::RecordTrigonometryLogarithm(size_t &i) {
  std_str temp;
  if (flag_minus_) {
    temp = "-";
  }
  if (temp_input_expression_[i] == 'c') {
    modify_string_expression_.emplace_back(temp + "cos");
    i += 2;
  } else if (temp_input_expression_[i] == 't') {
    modify_string_expression_.emplace_back(temp + "tan");
    i += 2;
  } else if (temp_input_expression_[i] == 'l' &&
             temp_input_expression_[i + 1] == 'n') {
    modify_string_expression_.emplace_back(temp + "ln");
    ++i;
  } else if (temp_input_expression_[i] == 'l' &&
             temp_input_expression_[i + 1] == 'o') {
    modify_string_expression_.emplace_back(temp + "log");
    i += 2;
  } else if (temp_input_expression_[i] == 's' &&
             temp_input_expression_[i + 1] == 'i') {
    modify_string_expression_.emplace_back(temp + "sin");
    i += 2;
  } else if (temp_input_expression_[i] == 's' &&
             temp_input_expression_[i + 1] == 'q') {
    modify_string_expression_.emplace_back(temp + "sqrt");
    i += 3;
  }
  if (flag_minus_) {
    --flag_minus_;
  }
}

//// ЗАПИСЫВАЕМ ЧИСЛО, ЕСЛИ Х, ТО СРАЗУ ПОДКИДЫВАЕМ ЗНАЧЕНИЕ
void ModifyInput::RecordDigitX(size_t &i) {
  if (temp_input_expression_[i] == 'x') {
    RecordX();
  } else {
    RecordDigit(i);
  }
  if (flag_minus_) {
    --flag_minus_;
  }
}
void ModifyInput::RecordX() {
  if (flag_minus_ && k_x_[0] == '-') {
    std_str temp = k_x_;
    temp.erase(0, 1);
    modify_string_expression_.emplace_back(temp);
  } else if (flag_minus_ && k_x_[0] != '-') {
    std_str temp = "-" + k_x_;
    modify_string_expression_.emplace_back(temp);
  } else
    modify_string_expression_.emplace_back(k_x_);
}

void ModifyInput::RecordDigit(size_t &i) {
  std_str temp;
  int exit = 0;
  int count_e = 0;
  for (; i < temp_input_expression_.size() && !exit; ++i) {
    if (temp_input_expression_[i] >= '0' && temp_input_expression_[i] <= '9' &&
        !count_e) {
      temp += temp_input_expression_[i];
    } else if (temp_input_expression_[i] >= '0' &&
               temp_input_expression_[i] <= '9' && count_e) {
      if (!(temp_input_expression_[i + 1] >= '0' &&
            temp_input_expression_[i + 1] <= '9')) {
        temp += temp_input_expression_[i];
        ++exit;
      }
    } else if (temp_input_expression_[i] == '.') {
      temp += temp_input_expression_[i];
    } else if (temp_input_expression_[i] == 'E') {
      temp += temp_input_expression_[i];
      ++count_e;
    } else if ((temp_input_expression_[i] == '+' ||
                temp_input_expression_[i] == '-') &&
               count_e) {
      temp += temp_input_expression_[i];
    } else {
      ++exit;
      --i;
    }
  }
  if (flag_minus_) {
    modify_string_expression_.emplace_back("-" + temp);
  } else {
    modify_string_expression_.emplace_back(temp);
  }
  --i;
}
}  // namespace my_space
