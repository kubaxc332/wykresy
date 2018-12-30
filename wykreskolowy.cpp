#include "wykreskolowy.h"
#include "mainwindow.h"
#include "ui_wykreskolowy.h"

wykresKolowy::wykresKolowy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wykresKolowy)
{
    ui->setupUi(this);

     mainLayout = new QGridLayout;


     series = new QPieSeries();

     m = 1; //domyslna wartosc
     if(col2Avl) m = 1;
     if(col3Avl) m = 2;
     if(col4Avl) m = 3;

     for(int j = 0; j < presentRows ; j++)
     {
        series->append(dataVector[j+1], dataVector[j+1+(m*presentRows)].toInt());
     }

     slice = series->slices().at(1);
     slice->setExploded();
     slice->setLabelVisible();
     slice->setPen(QPen(Qt::darkGreen, 2));
     slice->setBrush(Qt::green);

     chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Wykres");
     chart->legend()->hide();

     chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     mainLayout->addWidget(chartView, 0, 0);
     setLayout(mainLayout);

     setWindowTitle(tr("Wykres kolowy"));
}

wykresKolowy::~wykresKolowy()
{
    delete ui;
}
