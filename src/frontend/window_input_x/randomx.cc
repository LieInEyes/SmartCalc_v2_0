#include "randomx.h"

#include "ui_randomx.h"

RandomX::RandomX(QWidget *parent)
    : QDialog(parent), ui(new Ui::RandomX), error_("0") {
  ui->setupUi(this);
}

RandomX::~RandomX() { delete ui; }

std::string RandomX::on_button_ok_clicked() {
  error_ = "0";
  QString x_str = ui->stringX->text();
  ValidInputX(x_str);
  if (error_ == "0") {
    close();
  } else {
    QMessageBox::warning(this, "Ошибка", error_);
  }
  return x_str.toStdString();
}

void RandomX::ValidInputX(const QString &x_str) {
  int count_point = 0;
  int i = 0;
  if ((x_str[i] >= '0' && x_str[i] <= '9') || x_str[i] == '-') {
    ++i;
    for (; i < x_str.size(); ++i) {
      if (!((x_str[i] >= '0' && x_str[i] <= '9') || x_str[i] == '.')) {
        error_ = "Ошибка: должно быть вещественное число";
        break;
      } else {
        if (x_str[i] == '.') {
          ++count_point;
          if (count_point > 1) {
            error_ = "Ошибка: в числе присутствует больше одной '.'";
            break;
          }
          if (i + 1 == x_str.size()) {
            error_ = "Ошибка: число не может заканчиваться '.'";
            break;
          }
        }
      }
    }
  } else {
    error_ = "Ошибка: 1ый символ, должно быть вещественное число";
  }
}
