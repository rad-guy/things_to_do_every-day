#include "part01/part01_widget01.h"
#include "ui_part01_widget01.h"

#include <QTime>
#include <QTimer>
#include <QDebug>

CPart01Widget01::CPart01Widget01(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CPart01Widget01)
    , m_pTestTimer(nullptr)
{
    ui->setupUi(this);
}

CPart01Widget01::~CPart01Widget01()
{
    delete ui;
}

void CPart01Widget01::testQTimerClass()
{
    m_pTestTimer = new QTimer(this);
    // 获取 QTimer 的id
    int id = m_pTestTimer->timerId();
    // 设置 间隔 3秒
    m_pTestTimer->setInterval(3000);
    // 设置 单次
    m_pTestTimer->setSingleShot(true);
    connect(m_pTestTimer,&QTimer::timeout,this,[this]{ onTimerOut(); });

    QTime time;
    qInfo() << "test QTimer -s, cur time = " << time.currentTime().toString();
    m_pTestTimer->start();
    // qt 休眠，不卡 Ui 线程
    time.start();
    while(time.elapsed() < 2000)             // 睡眠 2 秒
        QCoreApplication::processEvents();   // 处理事件

    qInfo() << "time end -e,cur timer = " << time.currentTime().toString();
    // 测试是否刷新
    m_pTestTimer->start();
}

void CPart01Widget01::onTimerOut()
{
    QTime time;
    qInfo() << "QTimer out timer, cur time = " << time.currentTime().toString();
    delete m_pTestTimer;
    m_pTestTimer = nullptr;
    qInfo() << tr("结论：QTime 中的 start 函数可以刷新定时器时间");
}

