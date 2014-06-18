#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QVariant>
#include <QLabel>
#include <QPushButton>

#include "datathread.h"

#include <xlsxdocument.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void read();
    QList<QVariant> fabricData;
    int curPage;
    int numPerPage;

    DataThread *thread;

private:
    Ui::MainWindow *ui;
    QLabel *label;
    QPushButton *btn;

    void genExcel();

signals:
    void loadNextPage(int page);
    void loadImage(QStringList list);

public slots:
    void pageDataIsComplete(QList<QVariant> pageData, int totalNum);
    void imageLoadedSlot(int num);
    void startLoadImage();
};

#endif // MAINWINDOW_H
