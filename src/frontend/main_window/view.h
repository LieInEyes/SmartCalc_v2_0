#ifndef CPP3_SMARTCALC_V2_0_1_SRC_VIEW_H
#define CPP3_SMARTCALC_V2_0_1_SRC_VIEW_H

#include <QMainWindow>
#include <QMessageBox>

#include "controller/controller.h"
#include "frontend/credit_calculator/creditcalc.h"
#include "frontend/deposit_calculator/depositcalc.h"
#include "frontend/window_input_x/randomx.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

  using std_str = std::string;

 public:
  explicit View(QWidget *parent = nullptr);
  View(const View &other) = delete;
  View(View &&other) noexcept = delete;
  ~View() override;

  View &operator=(const View &other) = delete;
  View &operator=(View &&other) noexcept = delete;

 private slots:
  void ClickedButton();
  void on_button_AC_clicked();
  void on_button_back_space_clicked();
  void on_button_result_clicked();
  void on_button_graph_clicked();
  static void on_button_credit_clicked();
  static void on_button_deposit_clicked();

 private:
  Ui::View *ui;

  std_str original_input_str_;
  std_str error_;
  std_str input_x_str_;

  double result_;
};

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_VIEW_H
