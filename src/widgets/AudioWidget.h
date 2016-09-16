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

public:
    AudioWidget(QWidget *parent = 0);

private slots:
    void onRaiseButtonClicked() { Model::request().raiseAudio(5); }
    void onLowerButtonClicked() {Model::request().lowerAudio(5); }
};
