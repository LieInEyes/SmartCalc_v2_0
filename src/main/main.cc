#include <QApplication>

#include "frontend/main_window/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  View w;
  w.show();
  return a.exec();
}
