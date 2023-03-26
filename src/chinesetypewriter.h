// chinesetypewriter.h
// Copyright (C) 2023 Alexander Karpeko

#ifndef CHINESETYPEWRITER_H
#define CHINESETYPEWRITER_H

#include "ui_chinesetypewriter.h"
#include <QMainWindow>

class ChineseTypewriter : public QMainWindow, private Ui::ChineseTypewriter
{
    Q_OBJECT

public:
    explicit ChineseTypewriter(QWidget *parent = nullptr);

private:
    void selectHanzi(int i);
    void setToolButtonsText(int type);

private slots:
    void about();
    void closeFile();
    void newFile();
    void openFile();
    void quit();
    void saveFile();
    void selectTextType();

private:
    static constexpr int maxButton = 300;
    int textType;
    QString hanziParts;
    QString simpleHanzi;
    QToolButton *toolButton[maxButton];
};

#endif  // CHINESETYPEWRITER_H
