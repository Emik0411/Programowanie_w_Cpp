#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void koniec_programu();
    void change();
private slots:
    void on_action_O_programie_triggered();

private:
    bool Pauza;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
