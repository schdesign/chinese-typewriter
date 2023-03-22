// chinesetypewriter.cpp
// Copyright (C) 2023 Alexander Karpeko

#include "chinesetypewriter.h"
#include <QFileDialog>
#include <QMessageBox>

ChineseTypewriter::ChineseTypewriter(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(actionCloseFile, SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(actionNewFile, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(actionOpenFile, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(actionQuit, SIGNAL(triggered()), this, SLOT(quit()));
    connect(actionSaveFile, SIGNAL(triggered()), this, SLOT(saveFile()));

    //plainTextEdit->installEventFilter(this);

    QDir::setCurrent(QCoreApplication::applicationDirPath());
}

void ChineseTypewriter::about()
{
    QMessageBox::information(this, tr("About Chinese Typewriter"),
        tr("Chinese Typewriter\n""Copyright (C) 2023 Alexander Karpeko"));
}

void ChineseTypewriter::closeFile()
{

}

void ChineseTypewriter::newFile()
{

}

void ChineseTypewriter::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt file"),
                       "", tr("txt files (*.txt)"));
    if (fileName.isNull()) {
        QMessageBox::warning(this, tr("Error"), tr("No file was selected"));
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QByteArray array = file.readAll();
    file.close();

    QString text(array);
    //plainTextEdit->setPlainText(text);
}

void ChineseTypewriter::quit()
{
    close();
}

void ChineseTypewriter::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save txt file"),
                       "", tr("txt files (*.txt)"));
    if (fileName.isNull()) {
        QMessageBox::warning(this, tr("Error"), tr("No file was selected"));
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
        return;

    //QString text = plainTextEdit->toPlainText();
    //QByteArray array = text.toUtf8();

    //file.write(array);
    file.close();
}
