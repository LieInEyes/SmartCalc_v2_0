#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CREDITCALC_H
#define CPP3_SMARTCALC_V2_0_1_SRC_CREDITCALC_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <cmath>

namespace Ui {
class CreditCalc;
}

class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  CreditCalc(const CreditCalc &other) = delete;
  CreditCalc(CreditCalc &&other) noexcept = delete;
  ~CreditCalc() override;

  CreditCalc &operator=(const CreditCalc &other) = delete;
  CreditCalc &operator=(CreditCalc &&other) noexcept = delete;

 private slots:
  void on_button_clear_clicked();
  void on_button_calculate_clicked();

 private:
  void ValidInput();
  double ValidInputNumber(const QString &name_parameter,
                          const QString &parameter);
  void ValidInputCreditTerm();
  void ResultAnnuity();
  void AnnuityWriteTable();
  void DifferentiatedWriteTable();
  void RecordTable(int row, double sum_main_debt, double sum_percent_pay,
                   double balance_owed);

 private:
  Ui::CreditCalc *ui;

  QString error_;

  double sum_credit_dbl_;
  double percent_rate_dbl_;
  int credit_term_dbl_;

  double payment_dbl_;
  double accrued_percentages_dbl_;
  double total_amount_dbl_;
};

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_CREDITCALC_H
