#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CPart01Widget01; }
QT_END_NAMESPACE

class CPart01Widget01 : public QWidget
{
    Q_OBJECT
public:
    CPart01Widget01(QWidget *parent = nullptr);
    ~CPart01Widget01();

public:
    // 测试 QTimer start 是否会刷新时间间隔
    void testQTimerClass();




private:
    void onTimerOut();


private:
    Ui::CPart01Widget01*    ui;

    QTimer*                 m_pTestTimer;
};
#endif // WIDGET_H
