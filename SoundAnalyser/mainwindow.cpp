/*
    This file is part of libbeat - a lightweight beat detection library
    Copyright (c) 2011 by Maximilian Güntner <maximilian.guentner@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList windowFunctions;
    windowFunctions << "No Window" << "Hanning" << "Blackman";
    ui->windowFunctionComboBox->addItems(windowFunctions);
    connect(this->ui->startButton,SIGNAL(clicked()),ui->widget,SLOT(start()));
    connect(this->ui->stopButton,SIGNAL(clicked()),ui->widget,SLOT(stop()));
    connect(this->ui->windowFunctionComboBox,SIGNAL(currentIndexChanged(QString)),ui->widget, SLOT(windowFunctionChanged(QString)));
    ui->startButton->click();
    //start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    ui->startButton->setDown(true);
}

