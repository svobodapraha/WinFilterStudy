#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "twinfilter.h"

namespace Ui {
class MainWindow;
}


#define LOG_SIZE 2000
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void paintEvent(QPaintEvent *);
  byte CurrentLog[LOG_SIZE];
  byte CurrentLogFiltered[LOG_SIZE];
  TFWinVar CurrentFilter;

private slots:
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
