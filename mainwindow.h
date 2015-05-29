#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QKeyEvent>
#include<QVector>
#include<QTime>
#include<QT>
#include<QFont>
#include<QtMath>
#include<QPixmap>
#include<QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
     bool check();

private slots:
    void on_pushButton_clicked();

    void on_quit_clicked();

    void on_continue_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public slots:


private:
    Ui::MainWindow *ui;
    QVector<QLabel *>qvec;
    QVector<int> array;
    QVector<int> undo;

    int score;
    int undoscore;

};

#endif // MAINWINDOW_H
