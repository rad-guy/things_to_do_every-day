#include "utils/system_utils.h"

#include <QHostAddress>
#include <QList>
#include <QNetworkInterface>

QString CSystemUtils::getLocalIp()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
    {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost && ipAddressesList.at(i).toIPv4Address())
        {
            ipAddress = ipAddressesList.at(i).toString();
            qDebug() << ipAddress;
        }
    }
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return ipAddress;

}

void CSystemUtils::testNetInfo()
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    foreach(QNetworkInterface interface, list) //遍历每一个网络接口
    {
        //设备名
        QString name = interface.name();
        // 硬件地址
        QString hardwareAddress = interface.hardwareAddress();
        //一个子网掩码和一个广播地址
        QList<QNetworkAddressEntry> entryList= interface.addressEntries();
        foreach(QNetworkAddressEntry entry,entryList)//遍历每个IP地址条目
        {
            //IP地址
            QString ipAddress = entry.ip().toString();
            //子网掩码
            QString netMask = entry.netmask().toString();
            //广播地址
            QString broadCast = entry.broadcast().toString();
            QString sss = "";
        }
    }


}
