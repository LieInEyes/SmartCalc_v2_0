#include "view.h"

#include "ui_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::View),
      result_(0),
      error_("0"),
      input_x_str_("0") {
  ui->setupUi(this);

  connect(ui->number_0, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_1, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_2, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_3, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_4, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_5, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_6, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_7, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_8, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->number_9, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_bracket_f, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_bracket_r, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_plus, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_minus, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_mult, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_division, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_scale, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_sqrt, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_cos, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_sin, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_tan, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_acos, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_asin, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_atan, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_ln, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_log, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_mod, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_point, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_x, SIGNAL(clicked()), this, SLOT(ClickedButton()));
  connect(ui->button_E, SIGNAL(clicked()), this, SLOT(ClickedButton()));
}

View::~View() { delete ui; }

void View::ClickedButton() {
  auto *button = (QPushButton *)sender();
  if (ui->user_input->text() == "0")
    ui->user_input->setText("0" + button->text());
  else
    ui->user_input->setText(ui->user_input->text() + button->text());
}

void View::on_button_AC_clicked() { ui->user_input->setText(""); }

void View::on_button_back_space_clicked() {
  QString str = ui->user_input->text();
  str.resize(str.size() - 1);
  ui->user_input->setText(str);
}

void View::on_button_result_clicked() {
  error_ = "0";
  input_x_str_ = "0";
  result_ = 0.0;
  setlocale(LC_NUMERIC, "C");
  original_input_str_ = ui->user_input->text().toStdString();
  if (ui->user_input->text().contains('x')) {
    RandomX RandomXWindow;
    RandomXWindow.setModal(true);
    RandomXWindow.exec();
    input_x_str_ = RandomXWindow.on_button_ok_clicked();
  }
  my_space::Controller controller(original_input_str_, input_x_str_, "calculator");
  controller.SwitchModel(result_, error_);
  if (error_ == "0") {
    ui->user_input->setText(QString::number(result_, 'g', 15));
  } else {
    QMessageBox::warning(this, "Ошибка", QString::fromStdString(error_));
  }
}

void View::on_button_graph_clicked() {
  error_ = "0";
  input_x_str_ = "0";
  result_ = 0.0;
  original_input_str_ = ui->user_input->text().toStdString();
  if (ui->user_input->text().contains('x')) {
    my_space::Controller controller(original_input_str_, input_x_str_, "graph");
    controller.SwitchModel(result_, error_);
    if (error_ != "0") {
      QMessageBox::warning(this, "Ошибка", QString::fromStdString(error_));
    }
  } else {
    QMessageBox::warning(this, "Ошибка",
                         "Отсутствует переменная 'coordinate_x_'");
  }
}

void View::on_button_credit_clicked() {
  CreditCalc creditWindow;
  creditWindow.setModal(true);
  creditWindow.exec();
}

void View::on_button_deposit_clicked() {
  DepositCalc depositWindow;
  depositWindow.setModal(true);
  depositWindow.exec();
}
