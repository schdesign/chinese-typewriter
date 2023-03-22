// main.cpp
// Copyright (C) 2023 Alexander Karpeko

#include "chinesetypewriter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChineseTypewriter w;
    w.show();
    return a.exec();
}
