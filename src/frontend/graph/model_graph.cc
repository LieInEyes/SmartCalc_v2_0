#include "model_graph.h"

ModelGraph::ModelGraph(QWidget *parent, std::string k_original_line,
                       std::string k_x)
    : QDialog(parent),
      ui(new Ui::Graph),
      k_original_line_(std::move(k_original_line)),
      error_("0"),
      x_min_dbl_(0.0),
      x_max_dbl_(0.0),
      y_min_dbl_(0.0),
      y_max_dbl_(0.0),
      step_(0.0),
      value_variable_(0.0),
      result_(0.0),
      k_x_(std::move(k_x)) {
  ui->setupUi(this);
}

ModelGraph::~ModelGraph() { delete ui; }

void ModelGraph::on_buttonOk_clicked() {
  error_ = "0";
  ValidInputParametr();

  if (error_ == "0") {
    ui->widget->xAxis->setRange(x_min_dbl_, x_max_dbl_);
    ui->widget->yAxis->setRange(y_min_dbl_, y_max_dbl_);

    step_ = (x_max_dbl_ - x_min_dbl_) / k_iter_;
    value_variable_ = x_min_dbl_;
    for (int count = 0; count < k_iter_; value_variable_ += step_, ++count) {
      coordinate_x_.push_back(value_variable_);
      my_space::ModelCalculator calculator(k_original_line_,
                                      std::to_string(value_variable_));
      calculator.Calculate(result_, error_);
      if (error_ == "0") {
        coordinate_y_.push_back(result_);
      } else {
        QMessageBox::warning(this, "Ошибка", QString::fromStdString(error_));
        close();
        break;
      }
    }
    if (error_ == "0") {
      ui->widget->addGraph();
      ui->widget->graph(0)->setLineStyle(QCPGraph::lsLine);
      ui->widget->graph(0)->setScatterStyle(
          QCPScatterStyle(QCPScatterStyle::ssDisc, 2));
      ui->widget->graph(0)->addData(coordinate_x_, coordinate_y_);
      ui->widget->replot();
    }
  } else {
    QMessageBox::warning(this, "Ошибка", QString::fromStdString(error_));
  }
}

void ModelGraph::ValidInputParametr() {
  ValidInputNumber(ui->x_min->text(), "X min");
  if (error_ == "0") {
    ValidInputNumber(ui->x_max->text(), "X max");
    if (error_ == "0") {
      ValidInputNumber(ui->y_min->text(), "Y min");
      if (error_ == "0") {
        ValidInputNumber(ui->y_max->text(), "Y max");
        if (error_ == "0") {
          x_min_dbl_ = ui->x_min->text().toDouble();
          x_max_dbl_ = ui->x_max->text().toDouble();
          y_min_dbl_ = ui->y_min->text().toDouble();
          y_max_dbl_ = ui->y_max->text().toDouble();
        }
      }
    }
  }
}

void ModelGraph::ValidInputNumber(const QString &number_str,
                                  const std::string &parametr) {
  if (number_str.size() != 0) {
    int count_point = 0;
    int i = 0;
    if ((number_str[i] >= '0' && number_str[i] <= '9') ||
        number_str[i] == '-') {
      ++i;
      for (; i < number_str.size(); ++i) {
        if (!((number_str[i] >= '0' && number_str[i] <= '9') ||
              number_str[i] == '.')) {
          error_ = "Ошибка: " + parametr + " должно быть вещественное числом";
          break;
        } else {
          if (number_str[i] == '.') {
            ++count_point;
            if (count_point > 1) {
              error_ = "Ошибка: " + parametr +
                       " - в числе присутствует больше одной '.'";
              break;
            }
            if (i + 1 == number_str.size()) {
              error_ =
                  "Ошибка: " + parametr + " - число не может заканчиваться '.'";
              break;
            }
          }
        }
      }
    } else {
      error_ = "Ошибка: " + parametr +
               " - 1ый символ, должно быть вещественное число";
    }
  } else {
    error_ = "Ошибка: не заполнен параметр " + parametr;
  }
}
