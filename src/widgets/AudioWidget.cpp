#include "AudioWidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>

AudioWidget::AudioWidget(QWidget *parent)
    : QWidget(parent)
{
    /* Create layouts */
    QVBoxLayout *pMainLayout = new QVBoxLayout;
    QHBoxLayout *pBoxLayout = new QHBoxLayout;

    /* Create group box */
    QGroupBox *pAudioBox = new QGroupBox("Audio");
    m_pRaiseButton = new QPushButton("Raise volume");
    pBoxLayout->addWidget(m_pRaiseButton);
    connect(m_pRaiseButton, SIGNAL(clicked(bool)),
            this, SLOT(onRaiseButtonClicked()));
    m_pLowerButton = new QPushButton("Lower volume");
    pBoxLayout->addWidget(m_pLowerButton);
    connect(m_pLowerButton, SIGNAL(clicked(bool)),
            this, SLOT(onLowerButtonClicked()));
    pAudioBox->setLayout(pBoxLayout);
    pMainLayout->addWidget(pAudioBox);
    m_pMuteButton = new QPushButton("Mute volume");
    pBoxLayout->addWidget(m_pMuteButton);
    connect(m_pMuteButton, SIGNAL(clicked(bool)),
            this, SLOT(onMuteButtonClicked()));

    /* Setup widget */
    setLayout(pMainLayout);
}
