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
    discHeaderLabels.append(QString("Subsys."));
    discHeaderLabels.append(QString("Node"));
    discHeaderLabels.append(QString("Comp."));
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
    ieHandler=discClient->getIEHandler();
    cout << "Set ieHandler to: " << ieHandler << endl;
    //QTreeWidgetItem *temp = new QTreeWidgetItem(ui->trwDiscoveryServices);
    //temp->setText(0,"col1");
    //temp->setText(1,"col2");
    //temp->setText(2,"col3");
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
