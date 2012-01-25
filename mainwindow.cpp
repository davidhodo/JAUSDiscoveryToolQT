#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "JTS/include/urn_is4s_discovery_client_1_0/InternalEvents/GuiControlEntered.h"
#include <iostream>
using namespace std;
using namespace urn_is4s_discovery_client_1_0;
using namespace JTS;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up Discovery Service list
    ui->trwDiscoveryServices->setColumnCount(3);
    QStringList discHeaderLabels;
    discHeaderLabels.append(QString("Name."));
    discHeaderLabels.append(QString("Type"));
    discHeaderLabels.append(QString("Address."));
    ui->trwDiscoveryServices->setHeaderLabels(discHeaderLabels);

    // Set up services list
    ui->trwServices->setColumnCount(4);
    QStringList servHeaderLabels;
    servHeaderLabels.append(QString("Name"));
    servHeaderLabels.append(QString("Subsys."));
    servHeaderLabels.append(QString("Node"));
    servHeaderLabels.append(QString("Comp."));
    ui->trwServices->setHeaderLabels(servHeaderLabels);

    // create new discovery component
    discClient = new DiscoveryClient(126,1,117);
    discClient->startComponent();
    // get pointer to event handler for passing internal events
    ieHandler=discClient->getIEHandler();

    // set up callbacks to read data out of discovery client
    discClient->setIdentCallback(boost::bind(&MainWindow::reportIdentCallback, this, _1, _2));
}
MainWindow::~MainWindow()
{
    discClient->shutdownComponent();
    delete ui;
    delete discClient;
}

void MainWindow::on_pbQueryIdent_clicked()
{
    // Find discovery services - leaving the address blank broadcasts the query
    discClient->queryIdentification();

}

void MainWindow::on_pbQueryServices_clicked()
{

}

void MainWindow::reportIdentCallback(ReportIdentification msg, unsigned int sender)
{
    ui->trwDiscoveryServices->clear();

    QTreeWidgetItem *temp = new QTreeWidgetItem(ui->trwDiscoveryServices);
    temp->setText(0,QString(msg.getBody()->getReportIdentificationRec()->getIdentification().c_str()));
    temp->setText(1,QString::number((msg.getBody()->getReportIdentificationRec()->getType())));
    QString address=QString::number((sender>>16)&0xFFFF)+ ":" + QString::number((sender>>8)&0xFF) + ":" + QString::number(sender&0xFF);
    temp->setText(2,address);
}
