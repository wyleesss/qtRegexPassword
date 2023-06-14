
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(525, 340);

    pattern = new QString("^(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[*#+@])(?!.*\\s).{4,6}$");
    regex = new QRegularExpression(*pattern);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    ui->lineEdit->setFocus();

    if (ui->regexEdit->text().isEmpty())
    {
        *regexMatch = regex->match(ui->lineEdit->text());

        if (regexMatch->hasMatch())
        {
            ui->resultLabel->setText("вірний синтаксис");
            ui->resultLabel->setStyleSheet("QLabel { color : green; }");
        }
        else
        {
            ui->resultLabel->setText("невірний синтаксис");
            ui->resultLabel->setStyleSheet("QLabel { color : red; }");
        }
    }
    else
    {
        QRegularExpression* uRegex = new QRegularExpression(ui->regexEdit->text());

        *regexMatch = uRegex->match(ui->lineEdit->text());

        if (regexMatch->hasMatch())
        {
            ui->resultLabel->setText("вірний синтаксис");
            ui->resultLabel->setStyleSheet("QLabel { color : green; }");
        }
        else
        {
            ui->resultLabel->setText("невірний синтаксис");
            ui->resultLabel->setStyleSheet("QLabel { color : red; }");
        }
    }
}

