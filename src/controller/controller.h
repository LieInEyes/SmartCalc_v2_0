#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_H

#include <string>

#include "backend/back/model_calculator.h"
#include "frontend/graph/model_graph.h"
#include "backend/validator/valid_user_input.h"

namespace my_space {
class Controller {
  using std_str = std::string;

 public:
  Controller() = delete;
  Controller(std_str input, std_str x, std_str type_model);
  Controller(const Controller &other) = delete;
  Controller(Controller &&other) noexcept = delete;
  ~Controller() = default;

  Controller &operator=(const Controller &other) = delete;
  Controller &operator=(Controller &&other) noexcept = delete;

 public:
  void SwitchModel(double &result, std_str &error) const;
  void TransitForCalculator(double &result, std_str &error) const;
  void TransitForGraph(double &result, std_str &error) const;

 private:
  const std_str k_original_line_;
  const std_str k_x_;
  const std_str k_type_model_;
};
}  // namespace my_space

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_H
