#include <gtest/gtest.h>

//#include "controller.h"
#include "../backend/back/model_calculator.h"
#include "../backend/back/modify_input.h"
#include "../backend/back/reverse_polish_notation.h"
#include "../backend/validator/valid_user_input.h"

//// Проверяем класс valid_user_input.
//// Класс принимает строку введеную пользователем, проверяет ее,
//// и если находит ошибку возвращает ее в видет текста записанного в переменную
/// error

// корректный поль-овательский ввод
TEST(valid_user_input_1, correct_input) {
  std::string error = "0";
  std::string user_input_str =
      "ln3--(sinx+cos3*(tan-4)+atan5.4+acos-x+asin1/"
      "ln2.12E+6+(log4^6)-sqrt4*(-4mod3))";
  std::string verification_str = "0";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_2, incorrect_start_bracket) {
  std::string error = "0";
  std::string user_input_str = "2+2)";
  std::string verification_str =
      "Ошибка: некорреткно раставлены скобки (не хватает ОТКРЫВАЮЩЕЙ скобки "
      "минимум одной)";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_3, incorrect_end_bracket) {
  std::string error = "0";
  std::string user_input_str = "(2+2";
  std::string verification_str =
      "Ошибка: некорреткно раставлены скобки (не хватает ЗАКРЫВАЮЩЕЙ скобки "
      "минимум одной)";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_4, incorrect_first_symbol) {
  std::string error = "0";
  std::string user_input_str = "q3+4";
  std::string verification_str = "Ошибка: некорректный ввод (1 символ)";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_5, incorrect_symbol_before_x_first_position) {
  std::string error = "0";
  std::string user_input_str = "36-xq+2*4";
  std::string verification_str =
      "Ошибка: некорректный символ ПОСЛЕ числа или х";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_6, incorrect_count_point_in_number) {
  std::string error = "0";
  std::string user_input_str = "36.23.12";
  std::string verification_str = "Ошибка: в числе больше '.' чем необходимо";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_7, incorrect_order_cannot_be_a_real_number) {
  std::string error = "0";
  std::string user_input_str = "3.12E+34.6";
  std::string verification_str =
      "Ошибка: в экспонициальной форме записи порядок не может быть "
      "вещественным числом";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_8, incorrect_symbol_after_point) {
  std::string error = "0";
  std::string user_input_str = "3.E2+34.6";
  std::string verification_str = "Ошибка: некорректный символ ПОСЛЕ '.'";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_9, incorrect_consecutive_operators) {
  std::string error = "0";
  std::string user_input_str = "3++7";
  std::string verification_str =
      "Ошибка: некорректный символ ПОСЛЕ + / '/' / * / ^";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_10, incorrect_symbol_after_minus) {
  std::string error = "0";
  std::string user_input_str = "3-mod7";
  std::string verification_str = "Ошибка: неккоректный символ после -";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_11, incorrect_symbol_after_trigonometry) {
  std::string error = "0";
  std::string user_input_str = "25/sinmod6";
  std::string verification_str =
      "Ошибка: некорректный символ ПОСЛЕ Trigonometry";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_12, incorrect_input_trigonometry) {
  std::string error = "0";
  std::string user_input_str = "45+san4";
  std::string verification_str = "Ошибка: некорректный ввод (Trigonometry)";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_13, incorrect_symbol_after_mod) {
  std::string error = "0";
  std::string user_input_str = "45modsin6";
  std::string verification_str = "Ошибка: некорректный символ ПОСЛЕ mod";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_14, incorrect_symbol_after_start_bracket) {
  std::string error = "0";
  std::string user_input_str = "45mod(^7)";
  std::string verification_str =
      "Ошибка: некорректный символ ПОСЛЕ открывающей скобкой";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_15, incorrect_symbol_after_end_bracket) {
  std::string error = "0";
  std::string user_input_str = "45mod(2^7)sin25";
  std::string verification_str =
      "Ошибка: некорректный символ ПОСЛЕ закрывающей скобкой";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_16, incorrect_second_symbol) {
  std::string error = "0";
  std::string user_input_str = "4)*35modsin2)";
  std::string verification_str = "Ошибка: некорректный символ ПОСЛЕ mod";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_17, incorrect_symbol_near_count_e) {
  std::string error = "0";
  std::string user_input_str = "2.65EE";
  std::string verification_str =
      "Ошибка: некорректный символ ПОСЛЕ 'E' или до точки больше одной цифры";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_18, incorrect_count_e) {
  std::string error = "0";
  std::string user_input_str = "2.65E-24E";
  std::string verification_str = "Ошибка: в числе больше 'E' чем необходимо";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_19, incorrect_after_minus_position_0) {
  std::string error = "0";
  std::string user_input_str = "-*1+-2*3/4^-2+6*-3";
  std::string verification_str =
      "Ошибка: неккоректный символ после - (начало строки)";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_20, incorrect_after_mod) {
  std::string error = "0";
  std::string user_input_str =
      "cos(6^4)/sqrt(4)+(36+23)mid(3*2)-tan(ln(24)+log(25mod34))";
  std::string verification_str = "Ошибка: некорректный ввод после символа 'm'";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_21, incorrect_number) {
  std::string error = "0";
  std::string user_input_str = "3.45w+2";
  std::string verification_str =
      "Ошибка: в числе присутствуют некорректные символы";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_22, incorrect_number) {
  std::string error = "0";
  std::string user_input_str = "2.65E-/24";
  std::string verification_str =
      "Ошибка: неккоректные символы в числе ПОСЛЕ 'Е+/E-'";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

TEST(valid_user_input_23, incorrect_double_unary_minus) {
  std::string error = "0";
  std::string user_input_str = "sin2+--4";
  std::string verification_str =
      "Ошибка: унарный '-' подряд может быть только 1";

  my_space::ValidUserInput valid_input(user_input_str);
  error = valid_input.Input();

  EXPECT_EQ(error, verification_str);
}

//// Проверяем класс modify_input.
//// Класс принимает строку введеную пользователем и разюивает её на лексемы,
//// при необходимости добавляет выражение в случае унарнорго минуса.
//// Полученые лексемы записывает в переменную типа вектор
/// modify_string_expression

TEST(modify_input_1, modify_input) {
  std::string user_input_str =
      "ln3--(sinx+cos3*(tan-4)+-x^atan5.4+acos-x+asin1/"
      "ln2.12E+6+(log4^6)-sqrt4*(-4mod3))*4";
  std::string x = "2555";
  std::vector<std::string> modify_string_expression;
  std::vector<std::string> verification_str(
      {"ln",    "3",   "-",    "(",       "0", "-",    "(",     "sin", "2555",
       "+",     "cos", "3",    "*",       "(", "tan",  "-4",    ")",   "+",
       "-2555", "^",   "atan", "5.4",     "+", "acos", "-2555", "+",   "asin",
       "1",     "/",   "ln",   "2.12E+6", "+", "(",    "log",   "4",   "^",
       "6",     ")",   "-",    "sqrt",    "4", "*",    "(",     "-4",  "mod",
       "3",     ")",   ")",    ")",       "*", "4"});

  my_space::ModifyInput modify_input(user_input_str, x);
  modify_input.ModifyStringExpression(modify_string_expression);

  EXPECT_EQ(modify_string_expression, verification_str);
}

TEST(modify_input_2, modify_input) {
  std::string user_input_str =
      "ln3--(sinx+cos3*(tan-4)+-x^atan5.4+acos-x+asin1/"
      "ln2.12E+6+(log4^6)-sqrt4*(-4mod3))*4";
  std::string x = "-2555";
  std::vector<std::string> modify_string_expression;
  std::vector<std::string> verification_str(
      {"ln",   "3",   "-",    "(",       "0", "-",    "(",    "sin", "-2555",
       "+",    "cos", "3",    "*",       "(", "tan",  "-4",   ")",   "+",
       "2555", "^",   "atan", "5.4",     "+", "acos", "2555", "+",   "asin",
       "1",    "/",   "ln",   "2.12E+6", "+", "(",    "log",  "4",   "^",
       "6",    ")",   "-",    "sqrt",    "4", "*",    "(",    "-4",  "mod",
       "3",    ")",   ")",    ")",       "*", "4"});

  my_space::ModifyInput modify_input(user_input_str, x);
  modify_input.ModifyStringExpression(modify_string_expression);

  EXPECT_EQ(modify_string_expression, verification_str);
}

TEST(revers_polish_notation_1, revers) {
  std::vector<std::string> ModifyStringExpression(
      {"ln",    "3",   "-",    "(",       "0", "-",    "(",     "sin", "2555",
       "+",     "cos", "3",    "*",       "(", "tan",  "-4",    ")",   "+",
       "-2555", "^",   "atan", "5.4",     "+", "acos", "-2555", "+",   "asin",
       "1",     "/",   "ln",   "2.12E+6", "+", "(",    "log",   "4",   "^",
       "6",     ")",   "-",    "sqrt",    "4", "*",    "(",     "-4",  "mod",
       "3",     ")",   ")",    ")",       "*", "4"});
  std::vector<std::string> verification_str(
      {"3", "ln", "0",     "2555",    "sin",  "3",  "cos", "-4",    "tan",
       "*", "+",  "-2555", "5.4",     "atan", "^",  "+",   "-2555", "acos",
       "+", "1",  "asin",  "2.12E+6", "ln",   "/",  "+",   "4",     "log",
       "6", "^",  "+",     "4",       "sqrt", "-4", "3",   "mod",   "*",
       "-", "-",  "4",     "*",       "-"});

  std::vector<std::string> reverse_expression;
  my_space::ReversePolishNotation reverse_polish_notation(ModifyStringExpression);
  reverse_polish_notation.ReverseFromModifyToReversPolish(reverse_expression);

  EXPECT_EQ(reverse_expression, verification_str);
}

TEST(Model_1, Calculate) {
  std::string user_input_str =
      "2+3-4*5/"
      "(6^2+1.2+3-(2*1.2-4)+sin2)-cos3+4mod5*tan4+sqrt4-atan1-acos1+asin1";
  double result = 0;
  std::string x = "2";
  std::string error = "0";
  my_space::ModelCalculator model(user_input_str, x);
  model.Calculate(result, error);
  double verification_str = 12.9383936774212594326926278546494060464942;

  ASSERT_DOUBLE_EQ(result, verification_str);
}

TEST(Model_2, Calculate) {
  std::string user_input_str = "x/(4-2*2)";
  double result = 0;
  std::string x = "2";
  std::string error = "0";
  my_space::ModelCalculator model(user_input_str, x);
  model.Calculate(result, error);
  double verification_str = 0;

  EXPECT_EQ(error, "Ошибка: деление на 0 запрещено");
}

TEST(Model_3, Calculate) {
  std::string user_input_str = "logx^ln6+-2*-(3+4)";
  double result = 0;
  std::string x = "2";
  std::string error = "0";
  my_space::ModelCalculator model(user_input_str, x);
  model.Calculate(result, error);
  double verification_str = 14.116357430554289000378402013776094507241;

  ASSERT_DOUBLE_EQ(result, verification_str);
}

TEST(Model_4, Calculate) {
  std::string user_input_str =
      "2+3-4*5/"
      "(6^2+1.2+3-(2*1.2-4)+-sin2)--cos3+4mod5*-tan4+-sqrt4--atan1--acos1+-"
      "asin1";
  double result = 0;
  std::string x = "2";
  std::string error = "0";
  my_space::ModelCalculator model(user_input_str, x);
  model.Calculate(result, error);
  double verification_str = -3.8957845290714347071142530181472632595323;

  ASSERT_DOUBLE_EQ(result, verification_str);
}

TEST(Model_5, Calculate) {
  std::string user_input_str = "9/2.5";
  double result = 0;
  std::string x = "2";
  std::string error = "0";
  my_space::ModelCalculator model(user_input_str, x);
  model.Calculate(result, error);
  double verification_str = 3.6;

  ASSERT_DOUBLE_EQ(result, verification_str);
}

// TEST(Controler_1, 1) {
//   std::string user_input_str =
//   "0-(2+3-4*5/(6^2+1.2+3-(2*1.2-4)+-sin2)--cos3+4mod5*-tan4+-sqrt4--atan1--acos1+-asin1)";
//   double result = 0;
//   std::string x = "2";
//   std::string error = "0";
//   my_space::Controller controller(user_input_str, x, "calculator");
//   controller.SwitchModel(result, error);
//   double verification_str = 3.8957845290714347071142530181472632595323;
//   ASSERT_DOUBLE_EQ(result, verification_str);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
