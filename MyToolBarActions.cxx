

#include "MyToolBarActions.h"
#include <fstream>

#include <QtGui>
#include <QApplication>
#include <QStyle>
#include <QMessageBox>
#include <QWidgetAction>
#include <QPushButton>
#include <QComboBox>
#include <QStackedWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QLabel>
#include <QRadioButton>
#include <QWidget>

MyToolBarActions::MyToolBarActions(QObject* p)
  : QActionGroup(p)
{
  // Default icon in toolbar
  QIcon icon = qApp->style()->standardIcon(QStyle::SP_MessageBoxCritical);

  // Initialize QWidgetActions to be used on toolbar
  QWidgetAction *widgetAction = new QWidgetAction(this);
  
  modelWidget = new ModelWidget;
  QString vol = "1";
  QString mat = "Steel";
  QString dens = "0.00";
  QString fileN = "volumes";
  modelWidget->readFromFile(fileN);
  
  ModelWidget *matModWidget = new ModelWidget;
  ModelWidget *talModWidget = new ModelWidget;
  ModelWidget *boundModWidget = new ModelWidget; 
  

  // Initialize the QTabWidget and a widget for each page
  QTabWidget *tabWidget = new QTabWidget();
  QWidget *matWidget = new QWidget();
  QWidget *talWidget = new QWidget();
  QWidget *boundWidget = new QWidget();
  
  // Initialize a QGridLayout for each tab of the QTabWidget
  QGridLayout *matGridLayout = new QGridLayout(matWidget);

    QGridLayout *talGridLayout = new QGridLayout(talWidget);
      QGridLayout *boundGridLayout = new QGridLayout(boundWidget);
  matWidget->setLayout(matGridLayout);
  talWidget->setLayout(talGridLayout);
  boundWidget->setLayout(boundGridLayout);
				      
  // Initialize widgets for use in each tab
  QComboBox *matComboBox = new QComboBox();
  QLineEdit *matLoadFile = new QLineEdit();  
  QLineEdit *matDensVal = new QLineEdit();
  QLabel *matLoadLabel = new QLabel("Material file path:");
  QLabel *matDensTypeLabel = new QLabel("Type of Density");
  QLabel *matDensValLabel = new QLabel("Value of Density");
  QRadioButton *matDensAtom = new QRadioButton("Atom Density");
  QRadioButton *matDensMass = new QRadioButton("Mass Density");
  QPushButton *matAdd = new QPushButton("Add");
  QPushButton *matRemove = new QPushButton("Remove");
  QPushButton *matLoad = new QPushButton("Load");
  
  QComboBox *talComboBox = new QComboBox();
  QLineEdit *talMultiValue = new QLineEdit();
  QPlainTextEdit *talCommentValue = new QPlainTextEdit();
  QLabel *talCommentLabel = new QLabel("Comment");
  QLabel *talMultiLabel = new QLabel("Multiplier");
  QPushButton *talAdd = new QPushButton("Add");
  QPushButton *talRemove = new QPushButton("Remove");

  QComboBox *boundComboBox = new QComboBox();
  QPushButton *boundAdd = new QPushButton("Add");
  QPushButton *boundRemove = new QPushButton("Remove");
  
  // Add QGridLayouts to QTabWidget
  tabWidget->addTab(matWidget,"Materials");
  tabWidget->addTab(talWidget,"Tallies");
  tabWidget->addTab(boundWidget,"Boundaries");
  
  // Add widgets to QGridLayouts
  matGridLayout->addWidget(matLoadLabel,5,1);
  matGridLayout->addWidget(matLoadFile,6,1,1,2);
  matGridLayout->addWidget(matLoad,7,1);
  matGridLayout->addWidget(matComboBox,8,1,1,2);
  matGridLayout->addWidget(matDensTypeLabel,9,1);
  matGridLayout->addWidget(matDensAtom,10,2);
  matGridLayout->addWidget(matDensMass,11,2);
  matGridLayout->addWidget(matDensValLabel,12,1);
  matGridLayout->addWidget(matDensVal,13,2);
  matGridLayout->addWidget(matAdd,14,1);
  matGridLayout->addWidget(matRemove,14,2);

  matGridLayout->addWidget(matModWidget,1,1,4,2);  


  talGridLayout->addWidget(talComboBox,5,1,1,2);
  talGridLayout->addWidget(talMultiLabel,6,1);
  talGridLayout->addWidget(talMultiValue,7,2);
  talGridLayout->addWidget(talCommentLabel,8,1);
  talGridLayout->addWidget(talCommentValue,9,2); 
  talGridLayout->addWidget(talAdd,10,1);
  talGridLayout->addWidget(talRemove,10,2);

  talGridLayout->addWidget(talModWidget,1,1,4,2); 

  boundGridLayout->addWidget(boundComboBox,5,1,1,2);
  boundGridLayout->addWidget(boundAdd,6,1);
  boundGridLayout->addWidget(boundRemove,6,2);
  
  boundGridLayout->addWidget(boundModWidget,1,1,4,2);

  // Here we send the textfile, which contains the materials to be loaded.
  // This then populates the QComboBox with the proper materials.
  //populateMats(matLoadFile->displayText(),matComboBox);
  
  // Add items to matCombBox
  matComboBox->addItem("Steel");
  matComboBox->addItem("LiPb");
  matComboBox->addItem("New...");
  
  // Add items to talCombObx
  talComboBox->addItem("Surface");
  talComboBox->addItem("Flux");
  talComboBox->addItem("Heating");

  // Add items to boundComboBox
  boundComboBox->addItem("Reflecting");
  boundComboBox->addItem("Graveyard");
  boundComboBox->addItem("New...");

  matModWidget->addEntry(vol, mat, dens);
  
  // Set the widget actions

  widgetAction->setDefaultWidget(tabWidget);
  QAction* a = this->addAction(new QAction(icon, "MyAction", this));
  QAction* b = this->addAction(widgetAction);
  
  QObject::connect(a, SIGNAL(triggered(bool)), this, SLOT(onAction()));
  QObject::connect(b, SIGNAL(triggered(bool)), this, SLOT(onAction()));

}

MyToolBarActions::~MyToolBarActions()
{
}

void MyToolBarActions::onAction()
{
  QMessageBox::information(NULL, "MyAction", "Boundary condition was added.\n");
}
/*
void MyToolBarActions::getEntities(
				   vtkInformation *vtkNotUsed(request),
				   vtkInformationVector **inputVector,
				   vtkInformationVector *outputVector)
{
  
  vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  vtkDataSet *input = vtkDataSet::SafeDownCast(
					       inInfo->Get(vtkDataObject::DATA_OBJECT()));
  vtkPolyData *output = vtkPolyData::SafeDownCast(
						  outInfo->Get(vtkDataObject::DATA_OBJECT()));
  vtkIdType cellId;
  vtkIdType numCells=input->GetNumberOfCells();
  vtkIdList *cellIds;
  vtkCellData *cd = input->GetCellData();
  vtkCellData *outputCD = output->GetCellData();
  
  vtkGenericCell *cell;

  cell = vtkGenericCell::New();
  cellIds = vtkIdList::New();

  for(cellId=0; cellId < numCells; cellId++)
    {
    input->GetCell(cellId,cell); 
    ptIds = cell->GetPointIds();
    switch (cell->GetCellDimension())
      { 
      case 0: case 1:
	break;
      case 2:
        
	break;
      case 3:

	break;  
      }
    }

}
//*/
