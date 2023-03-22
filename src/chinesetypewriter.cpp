// chinesetypewriter.cpp
// Copyright (C) 2023 Alexander Karpeko

#include "chinesetypewriter.h"
#include <QFileDialog>
#include <QFont>
#include <QMessageBox>

ChineseTypewriter::ChineseTypewriter(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);

    QString buttonsText = QString::fromUtf8(
            "⼗⼚ナ⼕⼐⺅⼈⼋丷⼉⼏⼇⼍⼙⺋⼑⺉⼌⼘⼓⺇⼎⺈⻈⾔⼒⼜⼛⼵⻏"
            "⻖.⼟⺘⼿龵⼨⺐⼤⼝⺦⼭⼯⺾⼶⼩⼞⼱⼺⼢⼻⽝⺨⻠⾷⻔⺖⼼⺗⻌"
            "⼫⼸⼴⺡⽔⼧⼣⺕⼦孑⻢.⼥⺰⽷⺯.⺍⺌龸⽊⽇⻉⻅⺙⽁⽉⽍⼽⻋"
            "⽌⽈⺜⽜牜⽖⺤⽎.⽕⺣⽰⺭⽋⽅⼾⽃⽄⽚⽐⽗⺧⽓⽑⻛⽛⽯⽥⻐⾦"
            "⽩⽧⽳龹⽬⽫⽲⻦⽴⻂⾐⽪⽨⺢戊⽮⺫王⽟⽢⽠⽾⻚⺮⽶⽿⾍⾈⽺⺶"
            "⺷⽻⻄⻃⾌⽸⾆.⾄⾛⾜⻊⾘⾝⾣.⾟⾖⻗⻥⻣⿊⾫⻘⾰⻤⿇⿐");

    QFont buttonFont("Sans", 20);

    for (int i = 0; i < hanziParts; i++) {
        int j = i / 30;
        QString buttonName = QString::fromUtf8("button") + QString::number(i);
        QString buttonText;
        if (i < buttonsText.size())
            if (QString(buttonsText[i]) != QString::fromUtf8("."))
                buttonText = QString(buttonsText[i]);
        toolButtons[i] = new QToolButton(centralwidget);
        toolButtons[i]->setObjectName(buttonName);
        toolButtons[i]->setGeometry(QRect(40 + 40 * (i % 30), 490 + 40 * j, 32, 32));
        toolButtons[i]->setFont(buttonFont);
        toolButtons[i]->setText(buttonText);
    }

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
