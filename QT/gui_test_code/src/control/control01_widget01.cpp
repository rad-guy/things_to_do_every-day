#include "control/control01_widget01.h"
#include "ui_control01_widget01.h"

#include <QDebug>

CControl01Widget01::CControl01Widget01(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CControl01Widget01)
{
    ui->setupUi(this);
}

CControl01Widget01::~CControl01Widget01()
{
    delete ui;
}

void CControl01Widget01::testVerticalLayout()
{
    qInfo() << "结论：";
}

