#ifndef CPP3_SMARTCALC_V2_0_1_SRC_GRAPH_H
#define CPP3_SMARTCALC_V2_0_1_SRC_GRAPH_H

#include <QMessageBox>
#include <QVector>

#include "backend/back/model_calculator.h"
#include "ui_model_graph.h"

namespace Ui {
class ModelGraph;
}

class ModelGraph : public QDialog {
  Q_OBJECT

 public:
  explicit ModelGraph(QWidget *parent = nullptr,
                      std::string k_original_line = "", std::string k_x = "");
  ModelGraph(const ModelGraph &other) = delete;
  ModelGraph(ModelGraph &&other) noexcept = delete;
  ~ModelGraph() override;

  ModelGraph &operator=(const ModelGraph &other) = delete;
  ModelGraph &operator=(ModelGraph &&other) noexcept = delete;
 private slots:

  void on_buttonOk_clicked();

 private:
  void ValidInputParametr();
  void ValidInputNumber(const QString &number_str, const std::string &parametr);

 private:
  Ui::Graph *ui;

  std::string error_;
  const std::string k_x_;

  double x_min_dbl_;
  double x_max_dbl_;
  double y_min_dbl_;
  double y_max_dbl_;

  const int k_iter_ = 10000;
  double step_, value_variable_, result_;
  std::string k_original_line_;

  QVector<double> coordinate_x_, coordinate_y_;
};

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_GRAPH_H
