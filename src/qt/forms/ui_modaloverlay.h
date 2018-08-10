/********************************************************************************
** Form generated from reading UI file 'modaloverlay.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODALOVERLAY_H
#define UI_MODALOVERLAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "modaloverlay.h"

QT_BEGIN_NAMESPACE

class Ui_ModalOverlay
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *bgWidget;
    QVBoxLayout *verticalLayoutMain;
    QWidget *contentWidget;
    QVBoxLayout *verticalLayoutSub;
    QHBoxLayout *horizontalLayoutIconText;
    QVBoxLayout *verticalLayoutIcon;
    QPushButton *warningIcon;
    QSpacerItem *verticalSpacerWarningIcon;
    QVBoxLayout *verticalLayoutInfoText;
    QLabel *infoText;
    QLabel *infoTextStrong;
    QSpacerItem *verticalSpacerInTextSpace;
    QSpacerItem *verticalSpacerAfterText;
    QFormLayout *formLayout;
    QLabel *labelNumberOfBlocksLeft;
    QLabel *numberOfBlocksLeft;
    QLabel *labelLastBlockTime;
    QLabel *newestBlockDate;
    QLabel *labelSyncDone;
    QHBoxLayout *horizontalLayoutSync;
    QLabel *percentageProgress;
    QProgressBar *progressBar;
    QLabel *labelProgressIncrease;
    QLabel *progressIncreasePerH;
    QLabel *labelEstimatedTimeLeft;
    QLabel *expectedTimeLeft;
    QHBoxLayout *horizontalLayoutButtons;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(ModalOverlay *ModalOverlay)
    {
        if (ModalOverlay->objectName().isEmpty())
            ModalOverlay->setObjectName(QString::fromUtf8("ModalOverlay"));
        ModalOverlay->resize(640, 385);
        verticalLayout = new QVBoxLayout(ModalOverlay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bgWidget = new QWidget(ModalOverlay);
        bgWidget->setObjectName(QString::fromUtf8("bgWidget"));
        bgWidget->setStyleSheet(QString::fromUtf8("#bgWidget { background: rgba(0,0,0,220); }"));
        verticalLayoutMain = new QVBoxLayout(bgWidget);
        verticalLayoutMain->setObjectName(QString::fromUtf8("verticalLayoutMain"));
        verticalLayoutMain->setContentsMargins(60, 60, 60, 60);
        contentWidget = new QWidget(bgWidget);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        contentWidget->setStyleSheet(QString::fromUtf8("#contentWidget { background: rgba(255,255,255,240); border-radius: 6px; }\n"
"\n"
"QLabel { color: rgb(40,40,40);  }"));
        verticalLayoutSub = new QVBoxLayout(contentWidget);
        verticalLayoutSub->setSpacing(0);
        verticalLayoutSub->setObjectName(QString::fromUtf8("verticalLayoutSub"));
        verticalLayoutSub->setContentsMargins(10, 10, 10, 10);
        horizontalLayoutIconText = new QHBoxLayout();
        horizontalLayoutIconText->setObjectName(QString::fromUtf8("horizontalLayoutIconText"));
        horizontalLayoutIconText->setContentsMargins(-1, 20, -1, -1);
        verticalLayoutIcon = new QVBoxLayout();
        verticalLayoutIcon->setObjectName(QString::fromUtf8("verticalLayoutIcon"));
        verticalLayoutIcon->setContentsMargins(0, -1, -1, -1);
        warningIcon = new QPushButton(contentWidget);
        warningIcon->setObjectName(QString::fromUtf8("warningIcon"));
        warningIcon->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/warning"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icons/warning"), QSize(), QIcon::Disabled, QIcon::Off);
        warningIcon->setIcon(icon);
        warningIcon->setIconSize(QSize(48, 48));
        warningIcon->setFlat(true);

        verticalLayoutIcon->addWidget(warningIcon);

        verticalSpacerWarningIcon = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutIcon->addItem(verticalSpacerWarningIcon);


        horizontalLayoutIconText->addLayout(verticalLayoutIcon);

        verticalLayoutInfoText = new QVBoxLayout();
        verticalLayoutInfoText->setObjectName(QString::fromUtf8("verticalLayoutInfoText"));
        verticalLayoutInfoText->setContentsMargins(0, 0, -1, -1);
        infoText = new QLabel(contentWidget);
        infoText->setObjectName(QString::fromUtf8("infoText"));
        infoText->setTextFormat(Qt::RichText);
        infoText->setWordWrap(true);

        verticalLayoutInfoText->addWidget(infoText);

        infoTextStrong = new QLabel(contentWidget);
        infoTextStrong->setObjectName(QString::fromUtf8("infoTextStrong"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        infoTextStrong->setFont(font);
        infoTextStrong->setTextFormat(Qt::RichText);
        infoTextStrong->setWordWrap(true);

        verticalLayoutInfoText->addWidget(infoTextStrong);

        verticalSpacerInTextSpace = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutInfoText->addItem(verticalSpacerInTextSpace);


        horizontalLayoutIconText->addLayout(verticalLayoutInfoText);

        horizontalLayoutIconText->setStretch(1, 1);

        verticalLayoutSub->addLayout(horizontalLayoutIconText);

        verticalSpacerAfterText = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutSub->addItem(verticalSpacerAfterText);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(6);
        formLayout->setContentsMargins(-1, 10, -1, -1);
        labelNumberOfBlocksLeft = new QLabel(contentWidget);
        labelNumberOfBlocksLeft->setObjectName(QString::fromUtf8("labelNumberOfBlocksLeft"));
        labelNumberOfBlocksLeft->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNumberOfBlocksLeft);

        numberOfBlocksLeft = new QLabel(contentWidget);
        numberOfBlocksLeft->setObjectName(QString::fromUtf8("numberOfBlocksLeft"));

        formLayout->setWidget(0, QFormLayout::FieldRole, numberOfBlocksLeft);

        labelLastBlockTime = new QLabel(contentWidget);
        labelLastBlockTime->setObjectName(QString::fromUtf8("labelLastBlockTime"));
        labelLastBlockTime->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelLastBlockTime);

        newestBlockDate = new QLabel(contentWidget);
        newestBlockDate->setObjectName(QString::fromUtf8("newestBlockDate"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newestBlockDate->sizePolicy().hasHeightForWidth());
        newestBlockDate->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, newestBlockDate);

        labelSyncDone = new QLabel(contentWidget);
        labelSyncDone->setObjectName(QString::fromUtf8("labelSyncDone"));
        labelSyncDone->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelSyncDone);

        horizontalLayoutSync = new QHBoxLayout();
        horizontalLayoutSync->setObjectName(QString::fromUtf8("horizontalLayoutSync"));
        percentageProgress = new QLabel(contentWidget);
        percentageProgress->setObjectName(QString::fromUtf8("percentageProgress"));
        percentageProgress->setText(QString::fromUtf8("~"));

        horizontalLayoutSync->addWidget(percentageProgress);

        progressBar = new QProgressBar(contentWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayoutSync->addWidget(progressBar);

        horizontalLayoutSync->setStretch(1, 1);

        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayoutSync);

        labelProgressIncrease = new QLabel(contentWidget);
        labelProgressIncrease->setObjectName(QString::fromUtf8("labelProgressIncrease"));
        labelProgressIncrease->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelProgressIncrease);

        progressIncreasePerH = new QLabel(contentWidget);
        progressIncreasePerH->setObjectName(QString::fromUtf8("progressIncreasePerH"));

        formLayout->setWidget(4, QFormLayout::FieldRole, progressIncreasePerH);

        labelEstimatedTimeLeft = new QLabel(contentWidget);
        labelEstimatedTimeLeft->setObjectName(QString::fromUtf8("labelEstimatedTimeLeft"));
        labelEstimatedTimeLeft->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, labelEstimatedTimeLeft);

        expectedTimeLeft = new QLabel(contentWidget);
        expectedTimeLeft->setObjectName(QString::fromUtf8("expectedTimeLeft"));

        formLayout->setWidget(5, QFormLayout::FieldRole, expectedTimeLeft);


        verticalLayoutSub->addLayout(formLayout);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName(QString::fromUtf8("horizontalLayoutButtons"));
        horizontalLayoutButtons->setContentsMargins(10, 10, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer);

        closeButton = new QPushButton(contentWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayoutButtons->addWidget(closeButton);


        verticalLayoutSub->addLayout(horizontalLayoutButtons);

        verticalLayoutSub->setStretch(0, 1);

        verticalLayoutMain->addWidget(contentWidget);

        verticalLayoutMain->setStretch(0, 1);

        verticalLayout->addWidget(bgWidget);


        retranslateUi(ModalOverlay);

        QMetaObject::connectSlotsByName(ModalOverlay);
    } // setupUi

    void retranslateUi(ModalOverlay *ModalOverlay)
    {
        ModalOverlay->setWindowTitle(QApplication::translate("ModalOverlay", "Form", 0, QApplication::UnicodeUTF8));
        warningIcon->setText(QString());
        infoText->setText(QApplication::translate("ModalOverlay", "Recent transactions may not yet be visible, and therefore your wallet's balance might be incorrect. This information will be correct once your wallet has finished synchronizing with the bitcoin network, as detailed below.", 0, QApplication::UnicodeUTF8));
        infoTextStrong->setText(QApplication::translate("ModalOverlay", "Attempting to spend bitcoins that are affected by not-yet-displayed transactions will not be accepted by the network.", 0, QApplication::UnicodeUTF8));
        labelNumberOfBlocksLeft->setText(QApplication::translate("ModalOverlay", "Number of blocks left", 0, QApplication::UnicodeUTF8));
        numberOfBlocksLeft->setText(QApplication::translate("ModalOverlay", "Unknown...", 0, QApplication::UnicodeUTF8));
        labelLastBlockTime->setText(QApplication::translate("ModalOverlay", "Last block time", 0, QApplication::UnicodeUTF8));
        newestBlockDate->setText(QApplication::translate("ModalOverlay", "Unknown...", 0, QApplication::UnicodeUTF8));
        labelSyncDone->setText(QApplication::translate("ModalOverlay", "Progress", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QString());
        labelProgressIncrease->setText(QApplication::translate("ModalOverlay", "Progress increase per hour", 0, QApplication::UnicodeUTF8));
        progressIncreasePerH->setText(QApplication::translate("ModalOverlay", "calculating...", 0, QApplication::UnicodeUTF8));
        labelEstimatedTimeLeft->setText(QApplication::translate("ModalOverlay", "Estimated time left until synced", 0, QApplication::UnicodeUTF8));
        expectedTimeLeft->setText(QApplication::translate("ModalOverlay", "calculating...", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("ModalOverlay", "Hide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModalOverlay: public Ui_ModalOverlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODALOVERLAY_H
