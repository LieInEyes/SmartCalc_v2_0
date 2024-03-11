#include "depositcalc.h"

#include "ui_depositcalc.h"

DepositCalc::DepositCalc(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::DepositCalc),
      error_("0"),
      deposit_term_str_("0"),
      deposit_sum_dbl_(0.0),
      deposit_term_int_(0),
      percent_rate_dbl_(0.0),
      tax_rate_dbl_(0.0),
      deposit_refill_dbl_(0.0),
      deposit_withdrawal_dbl_(0.0),
      monthly_rate_(0.0),
      percent_accrued_(0.0),
      percent_sum_temp_(0.0),
      row_(0),
      remaining_months_(0.0),
      parcent_rate_temp_(0.0),
      rowl_(0),
      percent_accrued_sum_dbl_(0.0),
      total_sum_end_term_dbl_(0.0) {
  ui->setupUi(this);
}

DepositCalc::~DepositCalc() { delete ui; }

//// КНОПКА СБРОСИТЬ
void DepositCalc::on_button_clear_clicked() {
  resize(600, 443);

  error_ = "0";
  deposit_term_str_ = "0";

  deposit_sum_dbl_ = 0.0;
  deposit_term_int_ = 0;
  percent_rate_dbl_ = 0.0;
  tax_rate_dbl_ = 0.0;
  deposit_refill_dbl_ = 0.0;
  deposit_withdrawal_dbl_ = 0.0;

  monthly_rate_ = 0.0;
  percent_accrued_ = 0.0;
  percent_sum_temp_ = 0.0;
  remaining_months_ = 0.0;
  parcent_rate_temp_ = 0.0;

  row_ = 0;
  rowl_ = 0;

  percent_accrued_sum_dbl_ = 0.0;
  total_sum_end_term_dbl_ = 0.0;

  ui->deposit_sum->setText("0.0");
  ui->deposit_term->setText("0");
  ui->percent_rate->setText("0.0");
  ui->tax_rate->setText("13.0");
  ui->check_box_capitalization->setChecked(false);
  ui->check_box_refill->setChecked(false);
  ui->check_box_withdrawal->setChecked(false);
  ui->select_periodicity->setCurrentIndex(0);
  ui->select_refill->setCurrentIndex(0);
  ui->select_withdrawal->setCurrentIndex(0);
  ui->deposit_refill->setText("0.0");
  ui->deposit_withdrawal->setText("0.0");
  ui->percent_accrued->setText("0.0");
  ui->nalog->setText("0.0");
  ui->total_sum_end_term->setText("0.0");

  ClearTable();
}

//// КНОПКА РАСЧИТАТЬ
void DepositCalc::on_button_calculate_clicked() {
  ClearTable();
  InitializationInputField();
  ValidInput();
  monthly_rate_ = percent_rate_dbl_ / 12 / 100;
  remaining_months_ = fmod(deposit_term_int_, 12);
  parcent_rate_temp_ = remaining_months_ * (percent_rate_dbl_ / 12 / 100);
  if (error_ == "0") {
    resize(1230, 443);
    PreparingTableTemplate();
    ChoosingCalculationMethod();
  } else {
    resize(600, 443);
    QMessageBox::warning(this, "Ошибка", error_);
  }
}

//// ОЧИЩАЕМ ТАБЛИЦУ
void DepositCalc::ClearTable() {
  ui->tableWidget->clearSelection();
  ui->tableWidget->disconnect();
  ui->tableWidget->clearContents();
  ui->tableWidget->setRowCount(0);
}

//// ИНИЦИАЛИЗАЦИЯ ПОЛЕЙ, ЧИСЛА ОБНУЛЯЕМ, СТРОКИ ЗАБИРАЕМ С ФРОНТА
void DepositCalc::InitializationInputField() {
  error_ = "0";

  deposit_sum_dbl_ = 0.0;
  deposit_term_int_ = 0;
  percent_rate_dbl_ = 0.0;
  tax_rate_dbl_ = 0.0;
  deposit_refill_dbl_ = 0.0;
  deposit_withdrawal_dbl_ = 0.0;

  monthly_rate_ = 0.0;
  percent_accrued_ = 0.0;
  percent_sum_temp_ = 0.0;
  remaining_months_ = 0.0;
  parcent_rate_temp_ = 0.0;

  row_ = 0;
  rowl_ = 0;

  percent_accrued_sum_dbl_ = 0.0;
  total_sum_end_term_dbl_ = 0.0;

  deposit_term_str_ = ui->deposit_term->text();
}

//// ВАЛИДАЦИЯ ВХОДНЫХ ПАРАМЕТРОВ
void DepositCalc::ValidInput() {
  ValidInputDepositTerm();
  if (error_ == "0") {
    deposit_sum_dbl_ =
        ValidInputNumber("поле сумма вклада", ui->deposit_sum->text());
    if (error_ == "0") {
      percent_rate_dbl_ =
          ValidInputNumber("поле процентная ставка", ui->percent_rate->text());
      if (error_ == "0") {
        tax_rate_dbl_ =
            ValidInputNumber("поле налоговая ставка", ui->tax_rate->text());
        if (error_ == "0" && ui->check_box_refill->isChecked()) {
          deposit_refill_dbl_ = ValidInputNumber("поле частичные пополнения",
                                                 ui->deposit_refill->text());
          if (error_ == "0" && ui->check_box_withdrawal->isChecked()) {
            deposit_withdrawal_dbl_ = ValidInputNumber(
                "поле частичные снятия", ui->deposit_withdrawal->text());
          }
        }
      }
    }
  }
}

void DepositCalc::ValidInputDepositTerm() {
  for (int i = 0; i < deposit_term_str_.size(); ++i) {
    if (!(deposit_term_str_[i] >= '0' && deposit_term_str_[i] <= '9')) {
      error_ =
          "Ошибка: некорректно введён период (должно быть положительное целое "
          "число)";
      break;
    }
  }
  if (error_ == "0") {
    deposit_term_int_ = deposit_term_str_.toInt();
    if (deposit_term_int_ < 1) {
      error_ = "Ошибка: заданный период не может быть меньше 1 месяца";
    }
  }
}

double DepositCalc::ValidInputNumber(const QString &name_parameter,
                                     const QString &parameter) {
  int count_point = 0;
  int i = 0;
  double result = 0;
  if (parameter[i] >= '0' && parameter[i] <= '9') {
    ++i;
    for (; i < parameter.size(); ++i) {
      if (!((parameter[i] >= '0' && parameter[i] <= '9') ||
            parameter[i] == '.')) {
        error_ = "Ошибка: некорректно введено " + name_parameter +
                 " (должно быть положительное вещественное число)";
        break;
      } else {
        if (parameter[i] == '.') {
          ++count_point;
          if (count_point > 1) {
            error_ = "Ошибка: некорректно введено " + name_parameter +
                     " (в числе присутствует больше одной '.')";
            break;
          }
          if (i + 1 == parameter.size()) {
            error_ = "Ошибка: некорректно введено " + name_parameter +
                     " (число не может заканчиваться '.')";
            break;
          }
        }
      }
    }
  } else {
    error_ = "Ошибка: некорректно введено " + name_parameter +
             " (1ый символ, должно быть положительное вещественное число)";
  }
  if (error_ == "0") {
    result = parameter.toDouble();
    if (result < 0.01) {
      error_ = "Ошибка: некорректно введено " + name_parameter +
               " (должна быть больше 0.01)";
    }
  }
  return result;
}

void DepositCalc::PreparingTableTemplate() {
  ui->tableWidget->setColumnCount(3);
  if (ui->check_box_withdrawal->isChecked() ||
      ui->check_box_refill->isChecked()) {
    ui->tableWidget->setRowCount(deposit_term_int_ * 3);
  } else {
    ui->tableWidget->setRowCount(deposit_term_int_);
  }
  ui->tableWidget->setHorizontalHeaderLabels(QStringList()
                                             << "Начислено процентов, руб."
                                             << "Вклад пополнен, руб."
                                             << "Остаток на вкладе, руб.");
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
}

//// РАСЧЁТ В ЗАВИСИМОСТИ ОТ ЗАДАННЫХ ПАРАМЕТРОВ НА ФРОНТЕ
void DepositCalc::ChoosingCalculationMethod() {
  if (ui->check_box_refill->isChecked() &&
      ui->check_box_withdrawal->isChecked()) {
    if (ui->check_box_capitalization->isChecked()) {
      RefillWithdrawalWithCap();
    } else {
      RefillWithdrawalWOCap();
    }
  } else if (ui->check_box_refill->isChecked() &&
             !ui->check_box_withdrawal->isChecked()) {
    if (ui->check_box_capitalization->isChecked()) {
      RefillNotWithdrawalWithCap();
    } else {
      RefillNotWithdrawalWOCap();
    }
  } else if (!ui->check_box_refill->isChecked() &&
             ui->check_box_withdrawal->isChecked()) {
    if (ui->check_box_capitalization->isChecked()) {
      NotRefillWithdrawalWithCap();
    } else {
      NotRefillWithdrawalWOCap();
    }
  } else {
    if (ui->check_box_capitalization->isChecked()) {
      NotRefillNotWithdrawalWithCap();
    } else {
      NotRefillNotWithdrawalWOCap();
    }
  }
}

void DepositCalc::RefillWithdrawalWithCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  RecordTable(rowl_, 0, deposit_sum_dbl_);
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      total_sum_end_term_dbl_ += percent_accrued_;
      rowl_++;
      RecordTable(rowl_, percent_accrued_, 0);
      percent_accrued_sum_dbl_ += percent_accrued_;
      SelectRefillWithdrawal();
      ++row_;
    }
  } else {
    if (deposit_term_int_ > 11) {
      while (row_ < deposit_term_int_) {
        percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
        percent_sum_temp_ += percent_accrued_;
        if (fmod(row_, 11) == 0 && row_ != 0) {
          ++rowl_;
          RecordTable(rowl_, percent_sum_temp_, 0);
          percent_accrued_sum_dbl_ += percent_sum_temp_;
          total_sum_end_term_dbl_ += percent_sum_temp_;
          percent_sum_temp_ = percent_accrued_;
        }
        SelectRefillWithdrawal();
        ++row_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        total_sum_end_term_dbl_ += percent_accrued_;
        ++rowl_;
        RecordTable(rowl_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::RefillWithdrawalWOCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  RecordTable(rowl_, 0, deposit_sum_dbl_);
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      ++rowl_;
      RecordTable(rowl_, percent_accrued_, 0);
      percent_accrued_sum_dbl_ += percent_accrued_;
      SelectRefillWithdrawal();
      ++row_;
    }
  } else {
    if (deposit_term_int_ > 11) {
      while (row_ < deposit_term_int_) {
        percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
        percent_sum_temp_ += percent_accrued_;
        if (fmod(row_, 11) == 0 && row_ != 0) {
          ++rowl_;
          RecordTable(rowl_, percent_sum_temp_, 0);
          percent_accrued_sum_dbl_ += percent_sum_temp_;
          percent_sum_temp_ = percent_accrued_;
        }
        SelectRefillWithdrawal();
        ++row_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        ++rowl_;
        RecordTable(rowl_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::RefillNotWithdrawalWithCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  RecordTable(rowl_, 0, deposit_sum_dbl_);
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      total_sum_end_term_dbl_ += percent_accrued_;
      ++rowl_;
      RecordTable(rowl_, percent_accrued_, 0);
      percent_accrued_sum_dbl_ += percent_accrued_;
      SelectRefillNotWithdrawal();
      ++row_;
    }
  } else {
    if (deposit_term_int_ > 11) {
      while (row_ < deposit_term_int_) {
        percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
        percent_sum_temp_ += percent_accrued_;
        SelectRefillNotWithdrawal();
        if (fmod(row_, 11) == 0 && row_ != 0) {
          total_sum_end_term_dbl_ += percent_sum_temp_;
          ++rowl_;
          RecordTable(rowl_, percent_sum_temp_, 0);
          percent_accrued_sum_dbl_ += percent_sum_temp_;
          percent_sum_temp_ = percent_accrued_;
        }
        ++row_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        total_sum_end_term_dbl_ += percent_accrued_;
        ++rowl_;
        RecordTable(rowl_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::RefillNotWithdrawalWOCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  RecordTable(rowl_, 0, deposit_sum_dbl_);
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      ++rowl_;
      RecordTable(rowl_, percent_accrued_, 0);
      percent_accrued_sum_dbl_ += percent_accrued_;
      SelectRefillNotWithdrawal();
      ++row_;
    }
  } else {
    if (deposit_term_int_ > 11) {
      while (row_ < deposit_term_int_) {
        percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
        percent_sum_temp_ += percent_accrued_;
        SelectRefillNotWithdrawal();
        if (fmod(row_, 11) == 0 && row_ != 0) {
          ++rowl_;
          RecordTable(rowl_, percent_sum_temp_, 0);
          percent_accrued_sum_dbl_ += percent_sum_temp_;
          percent_sum_temp_ = percent_accrued_;
        }
        ++row_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        ++rowl_;
        RecordTable(rowl_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::NotRefillWithdrawalWithCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  RecordTable(rowl_, 0, deposit_sum_dbl_);
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      total_sum_end_term_dbl_ += percent_accrued_;
      ++rowl_;
      RecordTable(rowl_, percent_accrued_, 0);
      percent_accrued_sum_dbl_ += percent_accrued_;
      SelectNotRefillWithdrawal();
      ++row_;
    }
  } else {
    if (deposit_term_int_ > 11) {
      while (row_ < deposit_term_int_) {
        percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
        percent_sum_temp_ += percent_accrued_;
        SelectNotRefillWithdrawal();
        if (fmod(row_, 11) == 0 && row_ != 0) {
          total_sum_end_term_dbl_ += percent_sum_temp_;
          ++rowl_;
          RecordTable(rowl_, percent_sum_temp_, 0);
          percent_accrued_sum_dbl_ += percent_sum_temp_;
          percent_sum_temp_ = percent_accrued_;
        }
        row_++;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        total_sum_end_term_dbl_ += percent_accrued_;
        ++rowl_;
        RecordTable(rowl_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::NotRefillWithdrawalWOCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  RecordTable(rowl_, 0, deposit_sum_dbl_);
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      ++rowl_;
      RecordTable(rowl_, percent_accrued_, 0);
      percent_accrued_sum_dbl_ += percent_accrued_;
      SelectNotRefillWithdrawal();
      ++row_;
    }
  } else {
    if (deposit_term_int_ > 11) {
      while (row_ < deposit_term_int_) {
        percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
        percent_sum_temp_ += percent_accrued_;
        SelectNotRefillWithdrawal();
        if (fmod(row_, 11) == 0 && row_ != 0) {
          ++rowl_;
          RecordTable(rowl_, percent_sum_temp_, 0);
          percent_accrued_sum_dbl_ += percent_sum_temp_;
          percent_sum_temp_ = percent_accrued_;
        }
        ++row_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        ++rowl_;
        RecordTable(rowl_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::NotRefillNotWithdrawalWithCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      total_sum_end_term_dbl_ += percent_accrued_;
      RecordTable(row_, percent_accrued_, percent_accrued_);
      ++row_;
      percent_accrued_sum_dbl_ += percent_accrued_;
    }
    total_sum_end_term_dbl_ = deposit_sum_dbl_ + percent_accrued_sum_dbl_;
  } else {
    if (deposit_term_int_ >= 12) {
      int year = deposit_term_int_ / 12;
      while (row_ < year) {
        percent_accrued_ = total_sum_end_term_dbl_ * percent_rate_dbl_ / 100;
        total_sum_end_term_dbl_ += percent_accrued_;
        RecordTable(row_, percent_accrued_, percent_accrued_);
        ++row_;
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        total_sum_end_term_dbl_ = total_sum_end_term_dbl_ + percent_accrued_;
        RecordTable(row_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

void DepositCalc::NotRefillNotWithdrawalWOCap() {
  total_sum_end_term_dbl_ = deposit_sum_dbl_;
  if (ui->select_periodicity->currentText() == "раз в месяц") {
    while (row_ < deposit_term_int_) {
      percent_accrued_ = total_sum_end_term_dbl_ * monthly_rate_;
      RecordTable(row_, percent_accrued_, 0);
      ++row_;
      percent_accrued_sum_dbl_ += percent_accrued_;
    }
  } else {
    if (deposit_term_int_ >= 12) {
      int year = deposit_term_int_ / 12;
      while (row_ < year) {
        percent_accrued_ = total_sum_end_term_dbl_ * percent_rate_dbl_ / 100;
        RecordTable(row_, percent_accrued_, 0);
        ++row_;
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
      if (remaining_months_ > 0) {
        percent_accrued_ = total_sum_end_term_dbl_ * parcent_rate_temp_;
        RecordTable(row_, percent_accrued_, 0);
        percent_accrued_sum_dbl_ += percent_accrued_;
      }
    } else {
      error_ = "срок размещения должен быть больше 12 месяцев";
    }
  }
  RecordingOfTheTotal();
}

//// ВСПОМОГАТЕЛЬНЫЕ МЕТОДЫ ДЛЯ РАСЧЕТА ЧАСТИЧНЫХ ПОПОЛНЕНИЙ И СНЯТИЙ
void DepositCalc::SelectRefillWithdrawal() {
  if (ui->select_withdrawal->currentText() == "раз в месяц" &&
      ui->select_refill->currentText() == "раз в месяц") {
    ++rowl_;
    total_sum_end_term_dbl_ += deposit_refill_dbl_;
    RecordTable(rowl_, 0, deposit_refill_dbl_);
    if (deposit_withdrawal_dbl_ <= total_sum_end_term_dbl_) {
      ++rowl_;
      total_sum_end_term_dbl_ -= deposit_withdrawal_dbl_;
      RecordTable(rowl_, 0, deposit_withdrawal_dbl_ * -1);
    }
  } else if (ui->select_withdrawal->currentText() == "раз в месяц" &&
             ui->select_refill->currentText() == "раз в год") {
    if (fmod(row_, 11) == 0 && row_ != 0) {
      ++rowl_;
      total_sum_end_term_dbl_ += deposit_refill_dbl_;
      RecordTable(rowl_, 0, deposit_refill_dbl_);
    }
    if (deposit_withdrawal_dbl_ <= total_sum_end_term_dbl_) {
      ++rowl_;
      total_sum_end_term_dbl_ -= deposit_withdrawal_dbl_;
      RecordTable(rowl_, 0, deposit_withdrawal_dbl_ * -1);
    }
  } else if (ui->select_withdrawal->currentText() == "раз в год" &&
             ui->select_refill->currentText() == "раз в месяц") {
    ++rowl_;
    total_sum_end_term_dbl_ += deposit_refill_dbl_;
    RecordTable(rowl_, 0, deposit_refill_dbl_);
    if (fmod(row_, 11) == 0 && row_ != 0) {
      if (deposit_withdrawal_dbl_ <= total_sum_end_term_dbl_) {
        ++rowl_;
        total_sum_end_term_dbl_ -= deposit_withdrawal_dbl_;
        RecordTable(rowl_, 0, deposit_withdrawal_dbl_ * -1);
      }
    }
  } else {
    if (fmod(row_, 11) == 0 && row_ != 0) {
      ++rowl_;
      total_sum_end_term_dbl_ += deposit_refill_dbl_;
      RecordTable(rowl_, 0, deposit_refill_dbl_);
      if (deposit_withdrawal_dbl_ <= total_sum_end_term_dbl_) {
        ++rowl_;
        total_sum_end_term_dbl_ -= deposit_withdrawal_dbl_;
        RecordTable(rowl_, 0, deposit_withdrawal_dbl_ * -1);
      }
    }
  }
}

void DepositCalc::SelectRefillNotWithdrawal() {
  if (ui->select_refill->currentText() == "раз в месяц") {
    total_sum_end_term_dbl_ += deposit_refill_dbl_;
    ++rowl_;
    RecordTable(rowl_, 0, deposit_refill_dbl_);
  } else {
    if (fmod(row_, 11) == 0 && row_ != 0) {
      total_sum_end_term_dbl_ += deposit_refill_dbl_;
      ++rowl_;
      RecordTable(rowl_, 0, deposit_refill_dbl_);
    }
  }
}

void DepositCalc::SelectNotRefillWithdrawal() {
  if (ui->select_withdrawal->currentText() == "раз в месяц") {
    if (deposit_withdrawal_dbl_ <= total_sum_end_term_dbl_) {
      total_sum_end_term_dbl_ -= deposit_withdrawal_dbl_;
      ++rowl_;
      RecordTable(rowl_, 0, deposit_withdrawal_dbl_ * -1);
    }
  } else {
    if (fmod(row_, 11) == 0 && row_ != 0) {
      if (deposit_withdrawal_dbl_ <= total_sum_end_term_dbl_) {
        total_sum_end_term_dbl_ -= deposit_withdrawal_dbl_;
        ++rowl_;
        RecordTable(rowl_, 0, deposit_withdrawal_dbl_ * -1);
      }
    }
  }
}

//// ЗАПОЛНЯЕМ ТАБЛИЦУ
void DepositCalc::RecordTable(int credit_term, double percent_accrued,
                              double nalog) {
  auto *item_percent_accrued = new QTableWidgetItem();
  item_percent_accrued->setText(QString("%1").arg(percent_accrued, 0, 'f', 2));
  ui->tableWidget->setItem(credit_term, 0, item_percent_accrued);

  auto *item_nalog = new QTableWidgetItem();
  item_nalog->setText(QString("%1").arg(nalog, 0, 'f', 2));
  ui->tableWidget->setItem(credit_term, 1, item_nalog);

  auto *item_total_sum = new QTableWidgetItem();
  item_total_sum->setText(
      QString("%1").arg(total_sum_end_term_dbl_, 0, 'f', 2));
  ui->tableWidget->setItem(credit_term, 2, item_total_sum);
}

//// ВЫВОДИМ ОСНОВНЫЕ РЕЗУЛЬТАТЫ
void DepositCalc::RecordingOfTheTotal() {
  if (error_ == "0") {
    if (percent_accrued_sum_dbl_ > 42500) {
      double nalog_dbl =
          (percent_accrued_sum_dbl_ - 42500) * (tax_rate_dbl_ / 100);
      ui->nalog->setText(QString::number(nalog_dbl, 'f', 2));
    }
    ui->total_sum_end_term->setText(
        QString::number(total_sum_end_term_dbl_, 'f', 2));
    ui->percent_accrued->setText(
        QString::number(percent_accrued_sum_dbl_, 'f', 2));
  } else {
    QMessageBox::warning(this, "Ошибка", error_);
  }
}
