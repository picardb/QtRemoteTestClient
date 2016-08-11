#include "DnsServiceRecordList.h"

DnsServiceRecordList::DnsServiceRecordList(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int DnsServiceRecordList::rowCount(const QModelIndex &) const
{
    return m_list.size();
}

int DnsServiceRecordList::columnCount(const QModelIndex &) const
{
    return DnsServiceRecord::membersCount();
}

QVariant DnsServiceRecordList::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case DnsServiceRecord::MEMBER_INDEX_NAME:
            return m_list.at(index.row()).name();

        case DnsServiceRecord::MEMBER_INDEX_TYPE:
            return m_list.at(index.row()).type();

        case DnsServiceRecord::MEMBER_INDEX_DOMAIN:
            return m_list.at(index.row()).domain();

        case DnsServiceRecord::MEMBER_INDEX_INTERFACE:
            return m_list.at(index.row()).interfaceAlias();

        default:
            return QVariant();
        }
    }
    else {
        return QVariant();
    }
}

QVariant DnsServiceRecordList::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            return DnsServiceRecord::membersName(section);
        }
    }
    else {
        return QVariant();
    }
}

void DnsServiceRecordList::add(const DnsServiceRecord &record) {
    beginInsertRows(QModelIndex(), m_list.size(), m_list.size());
    m_list.append(record);
    endInsertRows();
}

void DnsServiceRecordList::remove(const DnsServiceRecord &record) {
    while (m_list.contains(record)) {
        int index = m_list.indexOf(record);
        beginRemoveRows(QModelIndex(), index, index);
        m_list.remove(index);
        endRemoveRows();
    }
}
