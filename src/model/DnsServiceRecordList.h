#pragma once

#include <QAbstractTableModel>
#include "DnsServiceRecord.h"

class DnsServiceRecordList : public QAbstractTableModel
{
private:
    QVector<DnsServiceRecord>   m_list;

public:
    DnsServiceRecordList(QObject *parent = Q_NULLPTR);

    int rowCount(const QModelIndex & = QModelIndex()) const;
    int columnCount(const QModelIndex & = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void add(const DnsServiceRecord& record);
    void remove(const DnsServiceRecord& record);
};
