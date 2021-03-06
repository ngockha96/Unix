#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtCore/QTextStream>
#include <QtCore/QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString path = ui->lineEdit->text();
    QString date = ui->lineEdit_2->text();

    QString program = "/home/kha/shell/final3/part1_3a_3b/part1_3a";
    QStringList arguments;
    arguments << path << date;

    QProcess *process = new QProcess;
    process->start(program, arguments);
    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit->setPlainText(output);   //display text in textEdit
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString path = ui->lineEdit->text();
    QString date = ui->lineEdit_2->text();

    QString program = "/home/kha/shell/final3/part1_3a_3b/part1_3b";
    QStringList arguments;
    arguments << path << date;

    QProcess *process = new QProcess;
    process->start(program, arguments);
    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit_2->setPlainText(output);   //display text in textEdit
    QTextCursor textCursor = ui->textEdit_2->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();

}

void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}


