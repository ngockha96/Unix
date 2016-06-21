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
    QString keyword = ui->lineEdit_2->text();

    QString program = "/home/kha/shell/final3/part1_1_2/Part1-1.sh";
    QStringList arguments;
    arguments << path << keyword;

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
    QString keyword = ui->lineEdit_2->text();

    QString program = "/home/kha/shell/final3/part1_1_2/Part1-2.sh";
    QStringList arguments;
    arguments << path << keyword;

    QProcess *process = new QProcess;
    process->start(program, arguments);
    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit_2->setPlainText(output);   //display text in textEdit
    QTextCursor textCursor = ui->textEdit_2->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString path = ui->lineEdit->text();
    QString keyword = ui->lineEdit_2->text();

    QString program = "/home/kha/shell/final3/part1_1_2/Part2-1.sh";
    QStringList arguments;
    arguments << path << keyword;

    QProcess *process = new QProcess;
    process->start(program, arguments);
    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit_3->setPlainText(output);   //display text in textEdit
    QTextCursor textCursor = ui->textEdit_3->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void MainWindow::on_pushButton_4_clicked()
{
    QString path = ui->lineEdit->text();
    QString keyword = ui->lineEdit_2->text();

    QString program = "/home/kha/shell/final3/part1_1_2/Part2-2.sh";
    QStringList arguments;
    arguments << path << keyword;

    QProcess *process = new QProcess;
    process->start(program, arguments);
    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit_4->setPlainText(output);   //display text in textEdit
    QTextCursor textCursor = ui->textEdit_4->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
}

void MainWindow::on_pushButton_6_clicked()
{
    QApplication::quit();
}
