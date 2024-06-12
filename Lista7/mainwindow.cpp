#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    this->Pauza = true;
    ui->setupUi(this);
    connect(ui->action_Koniec, SIGNAL(triggered()), this, SLOT(koniec_programu()) );
    connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(change()));
    ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change()
{
    this->Pauza = !this->Pauza;
    if (this->Pauza)
    {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-pause.png"));
    }
    else
    {
        ui->przycisk->setIcon(QIcon(":/img/media-playback-start.png"));
    }
}

void MainWindow::koniec_programu()
{
    QMessageBox question;
    question.setText("Czy napewno chcesz wyjść?");
    QAbstractButton *myYesButton = question.addButton("Tak", QMessageBox::YesRole);
    QAbstractButton *myNoButton = question.addButton("Nie", QMessageBox::NoRole);
    question.setIcon(QMessageBox::Question);
    question.exec();

    if(question.clickedButton() == myYesButton)
    {
        qApp->quit();
    }
}


void MainWindow::on_action_O_programie_triggered()
{
 QMessageBox::aboutQt(this,"O wspaniałym programie");
}
