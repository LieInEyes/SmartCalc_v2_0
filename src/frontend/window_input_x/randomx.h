#ifndef CPP3_SMARTCALC_V2_0_1_SRC_RANDOMX_H
#define CPP3_SMARTCALC_V2_0_1_SRC_RANDOMX_H

#include <QMessageBox>

namespace Ui {
class RandomX;
}

class RandomX : public QDialog {
  Q_OBJECT

 public:
  explicit RandomX(QWidget *parent = nullptr);
  RandomX(const RandomX &other) = delete;
  RandomX(RandomX &&other) noexcept = delete;
  ~RandomX() override;

  RandomX &operator=(const RandomX &other) = delete;
  RandomX &operator=(RandomX &&other) noexcept = delete;

 public slots:
  std::string on_button_ok_clicked();

 private:
  void ValidInputX(const QString &x_str);

 private:
  Ui::RandomX *ui;

  QString error_;
};

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_RANDOMX_H
