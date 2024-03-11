#include "creditcalc.h"

#include "ui_creditcalc.h"

CreditCalc::CreditCalc(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::CreditCalc),
      error_("0"),
      sum_credit_dbl_(0),
      credit_term_dbl_(0),
      percent_rate_dbl_(0),
      payment_dbl_(0),
      accrued_percentages_dbl_(0),
      total_amount_dbl_(0) {
  ui->setupUi(this);
  ui->radio_button->setChecked(true);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_button_clear_clicked() {
  resize(600, 380);
  ui->sum_credit->setText("0.0");
  ui->credit_term->setText("0");
  ui->percent_rate->setText("0.0");
  ui->percent_accrued->setText("0.0");
  ui->total_sum->setText("0.0");
  ui->payment->setText("0.0");
}

void CreditCalc::on_button_calculate_clicked() {
  sum_credit_dbl_ = 0;
  percent_rate_dbl_ = 0;
  credit_term_dbl_ = 0;

  payment_dbl_ = 0;
  accrued_percentages_dbl_ = 0;
  total_amount_dbl_ = 0;

  error_ = "0";

  ValidInput();
  if (error_ == "0") {
    resize(1600, 380);
    if (ui->radio_button->isChecked()) {
      ResultAnnuity();
      AnnuityWriteTable();
    } else {
      DifferentiatedWriteTable();
    }
  } else {
    QMessageBox::warning(this, "Ошибка", error_);
  }
}

void CreditCalc::ValidInput() {
  ValidInputCreditTerm();
  if (error_ == "0") {
    sum_credit_dbl_ = ValidInputNumber("сумма кредита", ui->sum_credit->text());
    if (error_ == "0") {
      percent_rate_dbl_ =
          ValidInputNumber("процентная ставка", ui->percent_rate->text());
    }
  }
}

double CreditCalc::ValidInputNumber(const QString &name_parameter,
                                    const QString &parameter) {
  int count_point = 0;
  int i = 0;
  double result = 0;
  if (parameter[i] >= '0' && parameter[i] <= '9') {
    ++i;
    for (; i < parameter.size(); ++i) {
      if (!((parameter[i] >= '0' && parameter[i] <= '9') ||
            parameter[i] == '.')) {
        error_ = "Ошибка: некорректно введена " + name_parameter +
                 " (должно быть положительное вещественное число)";
        break;
      } else {
        if (parameter[i] == '.') {
          ++count_point;
          if (count_point > 1) {
            error_ = "Ошибка: некорректно введена " + name_parameter +
                     " (в числе присутствует больше одной '.')";
            break;
          }
          if (i + 1 == parameter.size()) {
            error_ = "Ошибка: некорректно введена " + name_parameter +
                     " (число не может заканчиваться '.')";
            break;
          }
        }
      }
    }
  } else {
    error_ = "Ошибка: некорректно введена " + name_parameter +
             " (1ый символ, должно быть положительное вещественное число)";
  }
  if (error_ == "0") {
    result = parameter.toDouble();
    if (result < 0.01) {
      error_ = "Ошибка: некорректно введена " + name_parameter +
               " (должна быть больше 0.01)";
    }
  }
  return result;
}

void CreditCalc::ValidInputCreditTerm() {
  QString credit_term_str = ui->credit_term->text();
  for (int i = 0; i < credit_term_str.size(); ++i) {
    if (!(credit_term_str[i] >= '0' && credit_term_str[i] <= '9')) {
      error_ =
          "Ошибка: некорректно введён период (должно быть положительное целое "
          "число)";
      break;
    }
  }
  if (error_ == "0") {
    credit_term_dbl_ = credit_term_str.toInt();
    if (credit_term_dbl_ < 1) {
      error_ = "Ошибка: заданный период не может быть меньше 1 месяца";
    }
  }
}

void CreditCalc::ResultAnnuity() {
  double monthRate = percent_rate_dbl_ / 12 / 100;
  double coefficient = (monthRate * pow((1 + monthRate), credit_term_dbl_)) /
                       ((pow((1 + monthRate), credit_term_dbl_)) - 1);

  payment_dbl_ = sum_credit_dbl_ * coefficient;
  ui->payment->setText(QString::number(payment_dbl_, 'f', 2));

  total_amount_dbl_ = payment_dbl_ * credit_term_dbl_;
  ui->total_sum->setText(QString::number(total_amount_dbl_, 'f', 2));

  accrued_percentages_dbl_ = total_amount_dbl_ - sum_credit_dbl_;
  ui->percent_accrued->setText(
      QString::number(accrued_percentages_dbl_, 'f', 2));
}

void CreditCalc::AnnuityWriteTable() {
  int row = 0;
  double balance_owed = sum_credit_dbl_, sum_percent_pay = 0.0,
         sum_main_debt = 0.0;
  while (balance_owed > payment_dbl_) {
    sum_percent_pay = balance_owed * (percent_rate_dbl_ / 12 / 100);
    sum_main_debt = payment_dbl_ - sum_percent_pay;
    balance_owed -= sum_main_debt;
    RecordTable(row, sum_main_debt, sum_percent_pay, balance_owed);
    row++;
  }
  if (row != 0) {
    sum_percent_pay = balance_owed * (percent_rate_dbl_ / 12 / 100);
    sum_main_debt = balance_owed;
    payment_dbl_ = balance_owed + sum_percent_pay;
    balance_owed -= sum_main_debt;
    RecordTable(row, sum_main_debt, sum_percent_pay, balance_owed);
  }
}

void CreditCalc::DifferentiatedWriteTable() {
  int row = 0;
  double balance_owed = sum_credit_dbl_, sum_percent_pay = 0;
  double month_rate = percent_rate_dbl_ / 12 / 100;
  double sum_main_debt = sum_credit_dbl_ / credit_term_dbl_;

  while (balance_owed > payment_dbl_) {
    payment_dbl_ =
        sum_main_debt + (sum_credit_dbl_ - sum_main_debt * row) * month_rate;
    if (row == 0) {
      ui->payment->setText("от " + QString::number(payment_dbl_, 'f', 2) + " ");
    }
    sum_percent_pay = payment_dbl_ - sum_main_debt;
    accrued_percentages_dbl_ += sum_percent_pay;
    balance_owed -= sum_main_debt;
    RecordTable(row, sum_main_debt, sum_percent_pay, balance_owed);
    row++;
  }

  if (row != 0) {
    sum_percent_pay = balance_owed * (percent_rate_dbl_ / 12 / 100);
    accrued_percentages_dbl_ += sum_percent_pay;
    sum_main_debt = balance_owed;
    payment_dbl_ = balance_owed + sum_percent_pay;
    balance_owed -= sum_main_debt;
    RecordTable(row, sum_main_debt, sum_percent_pay, balance_owed);
  }

  total_amount_dbl_ = sum_credit_dbl_ + accrued_percentages_dbl_;

  ui->payment->setText(ui->payment->text() + "до " +
                       QString::number(payment_dbl_, 'f', 2));
  ui->percent_accrued->setText(
      QString::number(accrued_percentages_dbl_, 'f', 2));
  ui->total_sum->setText(QString::number(total_amount_dbl_, 'f', 2));
}

void CreditCalc::RecordTable(int row, double sum_main_debt,
                             double sum_percent_pay, double balance_owed) {
  ui->tableWidget->setColumnCount(4);
  ui->tableWidget->setRowCount(credit_term_dbl_);
  ui->tableWidget->setHorizontalHeaderLabels(
      QStringList() << "Сумма платежа, руб."
                    << "Платеж по основному долгу, руб."
                    << "Платеж по процентам, руб."
                    << "Остаток долга, руб.");
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);

  auto *itemPayMent = new QTableWidgetItem();
  itemPayMent->setText(QString("%1").arg(payment_dbl_, 0, 'f', 2));
  ui->tableWidget->setItem(row, 0, itemPayMent);

  auto *itemSumMainDebt = new QTableWidgetItem();
  itemSumMainDebt->setText(QString("%1").arg(sum_main_debt, 0, 'f', 2));
  ui->tableWidget->setItem(row, 1, itemSumMainDebt);

  auto *itemSumPercentPay = new QTableWidgetItem();
  itemSumPercentPay->setText(QString("%1").arg(sum_percent_pay, 0, 'f', 2));
  ui->tableWidget->setItem(row, 2, itemSumPercentPay);

  auto *itemBalanceOwed = new QTableWidgetItem();
  itemBalanceOwed->setText(QString("%1").arg(balance_owed, 0, 'f', 2));
  ui->tableWidget->setItem(row, 3, itemBalanceOwed);
}
