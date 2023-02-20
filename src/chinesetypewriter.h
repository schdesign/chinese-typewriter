// chinesetypewriter.h
// Copyright (C) 2023 Alexander Karpeko

#ifndef CHINESETYPEWRITER_H
#define CHINESETYPEWRITER_H

#include "ui_chinesetypewriter.h"
#include <QMainWindow>

class ChineseTypeWriter : public QMainWindow, private Ui::ChineseTypeWriter
{
    Q_OBJECT

public:
    explicit ChineseTypeWriter(QWidget *parent = nullptr);
};

#endif  // CHINESETYPEWRITER_H
