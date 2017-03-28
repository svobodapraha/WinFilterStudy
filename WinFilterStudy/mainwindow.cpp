#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  memset(CurrentLog, 0, sizeof(CurrentLog));
  memset(CurrentLogFiltered, 0, sizeof(CurrentLogFiltered));
  memset(&CurrentFilter, 0, sizeof(CurrentFilter));
  ui->setupUi(this);

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //create field


  memset(CurrentLog, 0, sizeof(CurrentLog));
  int iCurrentTestValue = 0;
  int iSweep = 0;
  for (int i = 0; i < LOG_SIZE; ++i)
  {
    iCurrentTestValue++;
    iSweep = i & 0x10;
    int iTemp;
    if(iCurrentTestValue >= iSweep)
      iTemp = iCurrentTestValue - iSweep;
    else
      iTemp = iCurrentTestValue;
    CurrentLog[i] = (byte)iTemp;
    CurrentLogFiltered[i] = FilterWindow32(CurrentLog[i], &CurrentFilter);


  }
  this->repaint();
}

void MainWindow::paintEvent(QPaintEvent *)
{
  QPainter *painter = new QPainter (this);
  QPen myPen;
  myPen.setWidth(2);
  myPen.setStyle(Qt::SolidLine);
  int iCurrentTestValue = 0;
  int iCurrentTestValue_last = 0;
  int iCurrentFilteredTestValue = 0;
  int iCurrentFilteredTestValue_last = 0;


  int i_last = 0;
  for (int i = 0; i < LOG_SIZE; ++i)
  {
#define OSAX 300
    iCurrentTestValue = OSAX - CurrentLog[i];
    iCurrentFilteredTestValue = OSAX - CurrentLogFiltered[i];
    myPen.setColor(Qt::black);
    painter->setPen(myPen);
    painter->drawLine (QPointF (i_last, iCurrentTestValue_last),         QPointF (i, iCurrentTestValue));
    myPen.setColor(Qt::red);
    painter->setPen(myPen);
    painter->drawLine (QPointF (i_last, iCurrentFilteredTestValue_last), QPointF (i, iCurrentFilteredTestValue));

    //remember last values
    iCurrentTestValue_last = iCurrentTestValue;
    iCurrentFilteredTestValue_last = iCurrentFilteredTestValue;
    i_last = i;
  }

  delete painter;

}
