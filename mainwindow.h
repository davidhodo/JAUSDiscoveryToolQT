#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DEBUG 1

#include <QMainWindow>
#include "JTS/include/DiscoveryClient.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbQueryIdent_clicked();

    void on_pbQueryServices_clicked();

private:
    Ui::MainWindow *ui;
    DiscoveryClient *discClient;
    JTS::InternalEventHandler *ieHandler;

};

#endif // MAINWINDOW_H
