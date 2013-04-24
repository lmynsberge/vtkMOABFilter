#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent=0);
    QLineEdit *volumeText;
    QTextEdit *materialText;
	QLineEdit *densityText;

private:
    QLabel *volumeLabel;
    QLabel *materialLabel;
	QLabel *densityLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif