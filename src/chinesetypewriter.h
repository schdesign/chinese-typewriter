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

private slots:
    void about();
    void closeFile();
    void newFile();
    void openFile();
    void quit();
    void saveFile();
};

#endif  // CHINESETYPEWRITER_H
