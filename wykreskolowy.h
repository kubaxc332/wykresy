#ifndef WYKRESKOLOWY_H
#define WYKRESKOLOWY_H

#include <QDialog>
#include <QtCharts>
#include <QtWidgets>
#include "globals.h"

namespace Ui {
class wykresKolowy;
}

class wykresKolowy : public QDialog
{
    Q_OBJECT

public:
    explicit wykresKolowy(QWidget *parent = nullptr);
    ~wykresKolowy();

private:
    int m;

    QGridLayout *mainLayout;
    QChartView *chartView;
    QPieSeries *series;
    QPieSlice *slice;
    QChart *chart;
    Ui::wykresKolowy *ui;
};

#endif // WYKRESKOLOWY_H
