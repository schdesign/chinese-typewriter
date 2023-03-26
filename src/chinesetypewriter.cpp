// chinesetypewriter.cpp
// Copyright (C) 2023 Alexander Karpeko

#include "chinesetypewriter.h"
#include <QFileDialog>
#include <QFont>
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

    hanziParts = QString::fromUtf8(
        "⼗⼚ナ⼕⼐⺅⼈⼋丷⼉⼏⼇⼍⼙⺋⼑⺉⼌⼘⼓⺇⼎⺈⻈⾔⼒⼜⼛⼵⻏"
        "⻖.⼟⺘⼿龵⼨⺐⼤⼝⺦⼭⼯⺾⼶⼩⼞⼱⼺⼢⼻⽝⺨⻠⾷⻔⺖⼼⺗⻌"
        "⼫⼸⼴⺡⽔⼧⼣⺕⼦孑⻢.⼥⺰⽷⺯.⺍⺌龸⽊⽇⻉⻅⺙⽁⽉⽍⼽⻋"
        "⽌⽈⺜⽜牜⽖⺤⽎.⽕⺣⽰⺭⽋⽅⼾⽃⽄⽚⽐⽗⺧⽓⽑⻛⽛⽯⽥⻐⾦"
        "⽩⽧⽳龹⽬⽫⽲⻦⽴⻂⾐⽪⽨⺢戊⽮⺫王⽟⽢⽠⽾⻚⺮⽶⽿⾍⾈⽺⺶"
        "⺷⽻⻄⻃⾌⽸⾆.⾄⾛⾜⻊⾘⾝⾣.⾟⾖⻗⻥⻣⿊⾫⻘⾰⻤⿇⿐");

    simpleHanzi = QString::fromUtf8(
        "一乙八匕卜厂刀刁丁儿二几九了力乜乃七人入十义又才叉..川寸大"
        "飞干个工弓广及己几孑巾久孓口马么门女千刃三山士尸巳土丸万亡"
        "卫兀习夕下乡小丫幺也.义已于与丈之子巴办贝币卞不长车尺丑歹丹"
        "斗方丰夫父丐.互户火见斤井巨开毛木内廿牛.片气欠犬壬日卅少升"
        "氏手书水太天屯瓦王韦为文无毋勿五午乌心牙夭尹尤予月曰爪止中专"
        "凹白半本必丙册斥出匆氐电东弗甘瓜禾乎甲.乐立龙矛民皿末目母鸟"
        "皮平且丘冉申生示世史矢失石术甩田头凸未戊央业用永由玉乍正主百"
        "产臣虫而耳缶艮亥.臼耒吏米年农乓乒曲肉西血亚羊页曳夷聿再兆舟"
        "州朱自严求串甫更系来里良两身豕束酉.秉承垂果隶事肃臾雨重鬼柬"
        "韭面食彖禺禹象");

    QFont buttonFont("Sans", 15);
    QFont buttonFont2("Sans", 20);

    for (int i = 0; i < maxButton; i++) {
        int j = i / 30;
        QString buttonName = QString::fromUtf8("button") + QString::number(i);
        toolButton[i] = new QToolButton(centralwidget);
        toolButton[i]->setObjectName(buttonName);
        toolButton[i]->setGeometry(QRect(40 + 40 * (i % 30), 460 + 40 * j, 32, 32));
        toolButton[i]->setFont(buttonFont2);
    }

    textType = 0;
    setToolButtonsText(textType);

    selectorButton->setFont(buttonFont);
    selectorButton->setText(QString::fromUtf8("偏旁/独体字"));
    connect(selectorButton, SIGNAL(clicked()), this, SLOT(selectTextType()));

    for (int i = 0; i < maxButton; i++)
        connect(toolButton[i], &QToolButton::clicked, [=] () { selectHanzi(i); });

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

void ChineseTypewriter::selectHanzi(int i)
{

}

void ChineseTypewriter::selectTextType()
{
    textType = (textType + 1) % 2;
    setToolButtonsText(textType);
}

void ChineseTypewriter::setToolButtonsText(int type)
{
    if (type < 0 || type > 1)
        return;

    QString buttonsText;

    if (type == 0)
        buttonsText = hanziParts;
    else
        buttonsText = simpleHanzi;

    for (int i = 0; i < maxButton; i++) {
        if (i < buttonsText.size())
            if (QString(buttonsText[i]) != QString::fromUtf8(".")) {
                toolButton[i]->setText(QString(buttonsText[i]));
                continue;
            }
        toolButton[i]->setText(QString(""));
    }
}
