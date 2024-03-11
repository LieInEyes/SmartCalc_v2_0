#include "valid_user_input.h"

namespace my_space {
ValidUserInput::ValidUserInput(std_str input)
    : k_original_line_(std::move(input)),
      error_("0"),
      count_bracket_(0),
      count_minus_(0),
      count_point_(0),
      count_e_(0),
      count_digit_before_point_(0),
      exit_(0) {}

//// Класс принимает строку введеную пользователем, проверяет ее,
//// и если находит ошибку возвращает ее в виет текста записанного в переменную
/// error_

//// ОСНОВНАЯ ФУНКЦИЯ ВАЛИДАЦИИ (запускает цикл посимвольно)
std_str ValidUserInput::Input() {
  ValidFirstChar();
  for (int i = 0;
       error_ == "0" && i < k_size_original_line && k_original_line_[i] != '\0';
       ++i) {
    if ((k_original_line_[i] >= '0' && k_original_line_[i] <= '9') ||
        k_original_line_[i] == 'x') {
      ValidNumberAndX(i);
    } else if (k_original_line_[i] == '(' || k_original_line_[i] == ')') {
      ValidBracket(i);
    } else if (k_original_line_[i] == 'm') {
      ValidMod(i);
    } else if (k_original_line_[i] == 'a' || k_original_line_[i] == 'c' ||
               k_original_line_[i] == 't' || k_original_line_[i] == 's' ||
               k_original_line_[i] == 'l') {
      ValidTrigonometryLogarithmsSqrt(i);
    } else if (k_original_line_[i] == '+' || k_original_line_[i] == '-' ||
               k_original_line_[i] == '*' || k_original_line_[i] == '/' ||
               k_original_line_[i] == '^') {
      ValidMath(i);
    }
    if (error_ != "0") {
      return error_;
    }
  }

  if (count_bracket_ > 0) {
    error_ =
        "Ошибка: некорреткно раставлены скобки (не хватает ЗАКРЫВАЮЩЕЙ скобки "
        "минимум одной)";
  } else if (count_bracket_ < 0) {
    error_ =
        "Ошибка: некорреткно раставлены скобки (не хватает ОТКРЫВАЮЩЕЙ скобки "
        "минимум одной)";
  }
  return error_;
}

//// ******************** ПРОВЕРКА 0 СИМВОЛА ********************
void ValidUserInput::ValidFirstChar() {
  if (k_original_line_.size() != 0) {
    if (!((k_original_line_[0] >= '0' && k_original_line_[0] <= '9') ||
          k_original_line_[0] == '(' || k_original_line_[0] == 's' ||
          k_original_line_[0] == 'c' || k_original_line_[0] == 't' ||
          k_original_line_[0] == '-' || k_original_line_[0] == 'a' ||
          k_original_line_[0] == 'x' || k_original_line_[0] == 'l')) {
      error_ = "Ошибка: некорректный ввод (1 символ)";
    }
  } else {
    error_ = "Ошибка: выражение не введено";
  }
}

//// ******************** ПОИСК: ЧИСЛО / Х ********************
void ValidUserInput::ValidNumberAndX(int &i) {
  if (k_original_line_[i] == 'x') {
    ValidAfterX(i);
  } else {
    ValidNumber(i);
  }
  count_minus_ = 0;
}

//// ****************** ПРОВЕРЯЕМ ЧТО ПОСЛЕ ЧИСЛА ИЛИ Х ********************
void ValidUserInput::ValidAfterX(int &i) {
  if (!(k_original_line_[i + 1] == '+' || k_original_line_[i + 1] == '-' ||
        k_original_line_[i + 1] == '*' || k_original_line_[i + 1] == '/' ||
        k_original_line_[i + 1] == '^' || k_original_line_[i + 1] == 'm' ||
        k_original_line_[i + 1] == ')' || k_original_line_[i + 1] == '\0')) {
    error_ = "Ошибка: некорректный символ ПОСЛЕ числа или х";
  }
}

//// ******************** ПРОВЕРЯЕМ ЧИСЛО ********************
void ValidUserInput::ValidNumber(int &i) {
  ClearCountVaribleForNumber();
  for (; !exit_ && error_ == "0" && i < k_size_original_line &&
         k_original_line_[i] != '\0';
       ++i) {
    if (k_original_line_[i] >= '0' && k_original_line_[i] <= '9' && !count_e_) {
      ValidDigit(i);
      if (!count_point_) {
        ++count_digit_before_point_;
      }
    } else if (k_original_line_[i] >= '0' && k_original_line_[i] <= '9' &&
               count_e_) {
      if (k_original_line_[i + 1] == '.') {
        error_ =
            "Ошибка: в экспонициальной форме записи порядок не может быть "
            "вещественным числом";
      }
      if (k_original_line_[i + 1] == 'E') {
        error_ = "Ошибка: в числе больше 'E' чем необходимо";
      }
      if (!(k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9')) {
        ++exit_;
      }
    } else if (k_original_line_[i] == '.') {
      ValidPoint(i);
    } else if (k_original_line_[i] == 'E') {
      ValidExponent(i);
    } else if (k_original_line_[i] == '+' || k_original_line_[i] == '-') {
      ValidNumberPlusMinus(i);
    }
  }
  if (error_ == "0") {
    --i;
    ValidAfterX(i);
  }
}

//// ******************** ПРОВЕРЯЕМ ЧИСЛО ********************
void ValidUserInput::ValidPoint(int i) {
  ++count_point_;
  if (count_point_ > 1 && !count_e_) {
    error_ = "Ошибка: в числе больше '.' чем необходимо";
  } else {
    if (!(k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9')) {
      error_ = "Ошибка: некорректный символ ПОСЛЕ '.'";
    }
  }
}

// Проверяем что после Е
void ValidUserInput::ValidExponent(int i) {
  ++count_e_;
  if (!((k_original_line_[i + 1] == '-' || k_original_line_[i + 1] == '+') &&
        count_point_ == 1 && count_digit_before_point_ == 1)) {
    error_ =
        "Ошибка: некорректный символ ПОСЛЕ 'E' или до точки больше одной цифры";
  }
}

// Проверяем что пссле числа
void ValidUserInput::ValidDigit(int &i) {
  if (k_original_line_[i + 1] == '+' || k_original_line_[i + 1] == '-' ||
      k_original_line_[i + 1] == '*' || k_original_line_[i + 1] == '/' ||
      k_original_line_[i + 1] == '^' || k_original_line_[i + 1] == 'm' ||
      k_original_line_[i + 1] == ')' || k_original_line_[i + 1] == '\0') {
    ++exit_;
  } else if (!((k_original_line_[i + 1] >= '0' &&
                k_original_line_[i + 1] <= '9') ||
               k_original_line_[i + 1] == '.' ||
               k_original_line_[i + 1] == 'E')) {
    error_ = "Ошибка: в числе присутствуют некорректные символы";
  }
}

// проверяем что после +/- если это экспонициальная форма записи
void ValidUserInput::ValidNumberPlusMinus(int i) {
  if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') &&
        count_e_)) {
    error_ = "Ошибка: неккоректные символы в числе ПОСЛЕ 'Е+/E-'";
  }
}

//// ******************** ПРОВЕРЯЕМ И СЧИТАЕМ СКОБКИ ********************
void ValidUserInput::ValidBracket(int &i) {
  count_minus_ = 0;
  ValidAfterBracket(i);
  if (error_ == "0") {
    if (k_original_line_[i] == '(') {
      ++count_bracket_;
    } else if (k_original_line_[i] == ')') {
      --count_bracket_;
    }
  }
}

// ******************** ПРОВЕРЯЕМ ЧТО ПОСЛЕ СКОБОК ********************
void ValidUserInput::ValidAfterBracket(int i) {
  if (k_original_line_[i] == '(') {
    if (k_original_line_[i + 1] == '-') {
      ++count_minus_;
    }
    if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') ||
          k_original_line_[i + 1] == '-' || k_original_line_[i + 1] == '(' ||
          k_original_line_[i + 1] == 's' || k_original_line_[i + 1] == 'c' ||
          k_original_line_[i + 1] == 't' || k_original_line_[i + 1] == 'a' ||
          k_original_line_[i + 1] == 'l' || k_original_line_[i + 1] == 'x')) {
      error_ = "Ошибка: некорректный символ ПОСЛЕ открывающей скобкой";
    }
  } else {
    if (!(k_original_line_[i + 1] == '+' || k_original_line_[i + 1] == '-' ||
          k_original_line_[i + 1] == '*' || k_original_line_[i + 1] == '/' ||
          k_original_line_[i + 1] == ')' || k_original_line_[i + 1] == 'm' ||
          k_original_line_[i + 1] == '^' || k_original_line_[i + 1] == '\0'))
      error_ = "Ошибка: некорректный символ ПОСЛЕ закрывающей скобкой";
  }
}

//// ******************** ПРОВЕРЯЕМ MOD ********************
void ValidUserInput::ValidMod(int &i) {
  if (k_original_line_[i + 1] == 'o' && k_original_line_[i + 2] == 'd') {
    i += 2;
    ValidAfterMod(i);
  } else {
    error_ = "Ошибка: некорректный ввод после символа 'm'";
  }
}

// ******************** ПРОВЕРЯЕМ ЧТО ПОСЛЕ MOD ********************
void ValidUserInput::ValidAfterMod(int i) {
  if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') ||
        k_original_line_[i + 1] == 'x' || k_original_line_[i + 1] == '-' ||
        k_original_line_[i + 1] == '+' || k_original_line_[i + 1] == '(')) {
    error_ = "Ошибка: некорректный символ ПОСЛЕ mod";
  }
}

//// ******************** ПОИСК И ПРОВЕРКА: COS / SIN / TAN / ACOS / ASIN / ATAN
//// LOG / LN / SQRT ********************
void ValidUserInput::ValidTrigonometryLogarithmsSqrt(int &i) {
  if ((k_original_line_[i] == 'a' && k_original_line_[i + 1] == 'c' &&
       k_original_line_[i + 2] == 'o' && k_original_line_[i + 3] == 's') ||
      (k_original_line_[i] == 'a' && k_original_line_[i + 1] == 's' &&
       k_original_line_[i + 2] == 'i' && k_original_line_[i + 3] == 'n') ||
      (k_original_line_[i] == 'a' && k_original_line_[i + 1] == 't' &&
       k_original_line_[i + 2] == 'a' && k_original_line_[i + 3] == 'n') ||
      (k_original_line_[i] == 's' && k_original_line_[i + 1] == 'q' &&
       k_original_line_[i + 2] == 'r' && k_original_line_[i + 3] == 't')) {
    i += 3;
  } else if ((k_original_line_[i] == 'c' && k_original_line_[i + 1] == 'o' &&
              k_original_line_[i + 2] == 's') ||
             (k_original_line_[i] == 's' && k_original_line_[i + 1] == 'i' &&
              k_original_line_[i + 2] == 'n') ||
             (k_original_line_[i] == 't' && k_original_line_[i + 1] == 'a' &&
              k_original_line_[i + 2] == 'n') ||
             (k_original_line_[i] == 'l' && k_original_line_[i + 1] == 'o' &&
              k_original_line_[i + 2] == 'g')) {
    i += 2;
  } else if ((k_original_line_[i] == 'l' && k_original_line_[i + 1] == 'n')) {
    i += 1;
  } else {
    error_ = "Ошибка: некорректный ввод (Trigonometry)";
  }
  if (error_ == "0") {
    ValidAfterTrigonometryLogarithmsSqrt(i);
  }
  count_minus_ = 0;
}

// ***************** ПРОВЕРКА ЧТО ПОСЛЕ: COS / SIN / TAN / ACOS / ASIN / ATAN /
// LOG / LN / SQRT *****************
void ValidUserInput::ValidAfterTrigonometryLogarithmsSqrt(int i) {
  if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') ||
        k_original_line_[i + 1] == 'x' || k_original_line_[i + 1] == '(' ||
        k_original_line_[i + 1] == '-' || k_original_line_[i + 1] == 'a' ||
        k_original_line_[i + 1] == 'c' || k_original_line_[i + 1] == 's' ||
        k_original_line_[i + 1] == 't' || k_original_line_[i + 1] == 'l')) {
    error_ = "Ошибка: некорректный символ ПОСЛЕ Trigonometry";
  }
}

//// ******************** ПОИСК: + / - / '/' / * / ^ ********************
void ValidUserInput::ValidMath(int i) {
  if (k_original_line_[i] == '-') {
    ValidMinus(i);
  } else {
    ValidAfterPlusDivMulScale(i);
  }
}

//// ******************** ПРОВЕРКА: - ********************
void ValidUserInput::ValidMinus(int i) {
  if (i == 0) {
    ValidAftereMinusPosition0(i);
    ++count_minus_;
  } else if (i > 0) {
    if (k_original_line_[i - 1] == '-' || k_original_line_[i - 1] == '+' ||
        k_original_line_[i - 1] == '*' || k_original_line_[i - 1] == '/') {
      ++count_minus_;
    }
    ValidAfterMinusPositionGreater1(i);
  }
  if (count_minus_ > 1) {
    error_ = "Ошибка: унарный '-' подряд может быть только 1";
  }
}

// ******************** ПРОВЕРКА ЧТО ПОСЛЕ - НА ПОЗИЦИИ 0 ********************
void ValidUserInput::ValidAftereMinusPosition0(int i) {
  if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') ||
        k_original_line_[i + 1] == '(' || k_original_line_[i + 1] == 'a' ||
        k_original_line_[i + 1] == 's' || k_original_line_[i + 1] == 'c' ||
        k_original_line_[i + 1] == 't' || k_original_line_[i + 1] == 'l' ||
        k_original_line_[i + 1] == 'x')) {
    error_ = "Ошибка: неккоректный символ после - (начало строки)";
  }
}

// ******************** ПРОВЕРКА ЧТО ПОСЛЕ - НА ПОЗИЦИИ БОЛЬШЕ 0
// ********************
void ValidUserInput::ValidAfterMinusPositionGreater1(int i) {
  if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') ||
        k_original_line_[i + 1] == '-' || k_original_line_[i + 1] == '(' ||
        k_original_line_[i + 1] == 'a' || k_original_line_[i + 1] == 's' ||
        k_original_line_[i + 1] == 'c' || k_original_line_[i + 1] == 't' ||
        k_original_line_[i + 1] == 'l' || k_original_line_[i + 1] == 'x')) {
    error_ = "Ошибка: неккоректный символ после -";
    ++count_minus_;
  }
}

// ******************** ПРОВЕРКА ЧТО ПОСЛЕ: + / * ^ ********************
void ValidUserInput::ValidAfterPlusDivMulScale(int i) {
  if (!((k_original_line_[i + 1] >= '0' && k_original_line_[i + 1] <= '9') ||
        k_original_line_[i + 1] == 'x' || k_original_line_[i + 1] == '(' ||
        k_original_line_[i + 1] == 's' || k_original_line_[i + 1] == 'c' ||
        k_original_line_[i + 1] == 't' || k_original_line_[i + 1] == 'a' ||
        k_original_line_[i + 1] == 'l' || k_original_line_[i + 1] == '-')) {
    error_ = "Ошибка: некорректный символ ПОСЛЕ + / '/' / * / ^";
  }
}
void ValidUserInput::ClearCountVaribleForNumber() {
  count_point_ = 0;
  count_e_ = 0;
  count_digit_before_point_ = 0;
  exit_ = 0;
}
}  // namespace my_space
