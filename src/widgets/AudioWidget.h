#pragma once

#include <QWidget>
#include <QPushButton>
#include "model/Model.h"

class AudioWidget : public QWidget
{
    Q_OBJECT

private:
    QPushButton     *m_pRaiseButton;
    QPushButton     *m_pLowerButton;
    QPushButton     *m_pMuteButton;

public:
    AudioWidget(QWidget *parent = 0);

private slots:
    void onRaiseButtonClicked() { Model::control().audioRaiseVolume(5); }
    void onLowerButtonClicked() { Model::control().audioLowerVolume(5); }
    void onMuteButtonClicked() { Model::control().audioMuteVolume(); }
};
