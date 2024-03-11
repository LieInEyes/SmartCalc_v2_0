#include "controller.h"

namespace my_space {
Controller::Controller(std_str input, std_str x, std_str type_model)
    : k_original_line_(std::move(input)),
      k_x_(std::move(x)),
      k_type_model_(std::move(type_model)) {}

void Controller::SwitchModel(double &result, std_str &error) const {
  ValidUserInput valid_input(k_original_line_);
  error = valid_input.Input();
  if (error == "0") {
    if (k_type_model_ == "calculator") {
      TransitForCalculator(result, error);
    } else if (k_type_model_ == "graph") {
      TransitForGraph(result, error);
    }
  }
}

void Controller::TransitForCalculator(double &result, std_str &error) const {
  my_space::ModelCalculator calculator(k_original_line_, k_x_);
  calculator.Calculate(result, error);
}

void Controller::TransitForGraph(double &result, std_str &error) const {
  ModelGraph graph(nullptr, k_original_line_, k_x_);
  graph.setModal(true);
  graph.exec();
}
}  // namespace my_space
