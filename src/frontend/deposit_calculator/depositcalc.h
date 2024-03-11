#ifndef CPP3_SMARTCALC_V2_0_1_SRC_DEPOSITCALC_H
#define CPP3_SMARTCALC_V2_0_1_SRC_DEPOSITCALC_H

#include <QDialog>
#include <QMessageBox>
#include <cmath>

namespace Ui {
class DepositCalc;
}

class DepositCalc : public QDialog {
  Q_OBJECT

 public:
  explicit DepositCalc(QWidget *parent = nullptr);
  DepositCalc(const DepositCalc &other) = delete;
  DepositCalc(DepositCalc &&other) noexcept = delete;
  ~DepositCalc() override;

  DepositCalc &operator=(const DepositCalc &other) = delete;
  DepositCalc &operator=(DepositCalc &&other) noexcept = delete;

 private slots:
  void on_button_clear_clicked();
  void on_button_calculate_clicked();

 private:
  void ClearTable();
  void InitializationInputField();

  void ValidInput();
  void ValidInputDepositTerm();
  double ValidInputNumber(const QString &name_parameter,
                          const QString &parameter);

  void PreparingTableTemplate();

  void ChoosingCalculationMethod();
  void RefillWithdrawalWithCap();
  void RefillWithdrawalWOCap();
  void RefillNotWithdrawalWithCap();
  void RefillNotWithdrawalWOCap();
  void NotRefillWithdrawalWithCap();
  void NotRefillWithdrawalWOCap();
  void NotRefillNotWithdrawalWithCap();
  void NotRefillNotWithdrawalWOCap();

  void SelectRefillWithdrawal();
  void SelectRefillNotWithdrawal();
  void SelectNotRefillWithdrawal();

  void RecordingOfTheTotal();
  void RecordTable(int credit_term, double percent_accrued, double nalog);

 private:
  Ui::DepositCalc *ui;

  QString error_;
  QString deposit_term_str_;

  double deposit_sum_dbl_;
  int deposit_term_int_;
  double percent_rate_dbl_;
  double tax_rate_dbl_;
  double deposit_refill_dbl_;
  double deposit_withdrawal_dbl_;

  double monthly_rate_;
  double percent_accrued_;
  double percent_sum_temp_;
  double remaining_months_;
  double parcent_rate_temp_;

  double percent_accrued_sum_dbl_;
  double total_sum_end_term_dbl_;

  int row_;
  int rowl_;
};

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_DEPOSITCALC_H
