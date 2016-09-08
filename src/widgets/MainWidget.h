#pragma once

#include <QWidget>
#include <QHostInfo>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);

private slots:
    void onNetworkError(const QString& msg);
};
