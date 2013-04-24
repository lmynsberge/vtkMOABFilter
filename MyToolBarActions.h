
#include <QActionGroup>
#include <QComboBox>
#include <QString>
#include <QtGui>
#include "modelwidget.h"

class MyToolBarActions : public QActionGroup
{
  Q_OBJECT
public:
  MyToolBarActions(QObject* p);
  ~MyToolBarActions();
  //  void populateMats(QString *fname, QComboBox *comboBox);  

private:
  ModelWidget* modelWidget;  

public slots:
  void onAction();
  
};

