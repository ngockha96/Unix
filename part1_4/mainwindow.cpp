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
//    QFile myFile(":/part1_4_md");
//    myFile.open(QIODevice::ReadOnly);
//    QTextStream textStream(&myFile);
//    QString cmd = textStream.readAll();
//    myFile.close();

    QString path = ui->lineEdit->text();

    QObject *parent;
    QString program = "/home/kha/Unix/part1_4/part1_4_md";
    QStringList arguments;
    arguments << path;

    QProcess *process = new QProcess(parent);
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

    QObject *parent;
    QString program = "/home/kha/Unix/part1_4/part1_4_size";
    QStringList arguments;
    arguments << path;

    QProcess *process = new QProcess(parent);
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

    QObject *parent;
    QString program = "/home/kha/Unix/part1_4/part1_4_name";
    QStringList arguments;
    arguments << path;

    QProcess *process = new QProcess(parent);
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
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
}

void MainWindow::on_pushButton_5_clicked()
{
    QApplication::quit();
}
