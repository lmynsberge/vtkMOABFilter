#include <QtGui>
#include "adddialog.h"

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
{
    volumeLabel = new QLabel("Volume");
    materialLabel = new QLabel("Material");
    densityLabel = new QLabel("Density");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    volumeText = new QLineEdit;
    materialText = new QTextEdit;
	densityText = new QLineEdit;

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
	
    gLayout->addWidget(volumeLabel, 0, 0);
    gLayout->addWidget(volumeText, 0, 1);
	
	gLayout->addWidget(materialLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(materialText, 1, 1, Qt::AlignLeft);
	
	gLayout->addWidget(densityLabel, 2, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(densityText, 2, 1, Qt::AlignLeft);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, SIGNAL(clicked()),
            this, SLOT(accept()));

    connect(cancelButton, SIGNAL(clicked()),
            this, SLOT(reject()));

    setWindowTitle(tr("Edit an Entity"));
}
