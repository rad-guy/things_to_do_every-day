#ifndef CONTROL01_WIDGET01_h
#define CONTROL01_WIDGET01_h

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CControl01Widget01; }
QT_END_NAMESPACE

class CControl01Widget01 : public QWidget
{
    Q_OBJECT
public:
    CControl01Widget01(QWidget *parent = nullptr);
    ~CControl01Widget01();

public:

    void    testVerticalLayout();

private:
    Ui::CControl01Widget01*    ui;

};
#endif // CONTROL01_WIDGET01_h
