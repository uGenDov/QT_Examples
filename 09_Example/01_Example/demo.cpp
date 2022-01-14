#include "demo.h"

Demo::Demo(QMainWindow *parent) : QMainWindow(parent) {
    {
        this->centralWid          = new QWidget(this);
        this->hLayoutMain         = new QHBoxLayout();
        this->toolBar             = new QToolBar(this);

        this->verticalLayout      = new QVBoxLayout(this->centralWid);

        this->actionInitList      = new QAction(QIcon("D:/images/bold.png"), QString("Initialize List"), this);
        this->actionClear         = new QAction(QIcon("D:/images/bold.png"), QString("Clear List"), this);
        this->actionInput         = new QAction(QIcon("D:/images/bold.png"), QString("Input"), this);
        this->actionAddItem       = new QAction(QIcon("D:/images/bold.png"), QString("Add item"), this);
        this->actionDeleteItem    = new QAction(QIcon("D:/images/bold.png"), QString("Delete item"), this);

        this->splitter            = new QSplitter(this->centralWid);
        this->toolBox             = new QToolBox(this->splitter);
        this->tabWidget           = new QTabWidget(this->splitter);

        this->page1               = new QWidget();
        this->page2               = new QWidget();
        this->page3               = new QWidget();
        this->tab1                = new QWidget();
        this->tab2                = new QWidget();
        this->tab3                = new QWidget();

        this->vLayout1Page1       = new QVBoxLayout(this->page1);

        this->toolButtonInit      = new QToolButton(this->page1);
        this->toolButtonClear     = new QToolButton(this->page1);
        this->toolButtonInput     = new QToolButton(this->page1);
        this->toolButtonAdd       = new QToolButton(this->page1);
        this->toolButtonDelete    = new QToolButton(this->page1);

       this->vLayout2Page1        = new QVBoxLayout(this->tab1);

       this->gBox1Tab1            = new QGroupBox(this->tab1);
       this->hLayoutBoxTab1       = new QHBoxLayout(this->gBox1Tab1);
       this->label                = new QLabel(QString("Current item"), this->gBox1Tab1);
       this->lineEdit             = new QLineEdit(this->gBox1Tab1);
       this->checkBox             = new QCheckBox(this->gBox1Tab1);
       this->gBox2Tab1            = new QGroupBox(this->tab1);
       this->hLayoutBoxTab2       = new QHBoxLayout(this->gBox2Tab1);
       this->toolButtonSelectItem = new QToolButton(this->gBox2Tab1);
       this->toolButtonSelectAll  = new QToolButton(this->gBox2Tab1);
       this->toolButtonSelectNone = new QToolButton(this->gBox2Tab1);
       this->toolButtonSelectInv  = new QToolButton(this->gBox2Tab1);
       this->listWidget           = new QListWidget(this->tab1);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::setFont(QFont("Arial", 9, -1, false));
//        Demo::setFixedSize(QWidget::sizeHint().width(), QWidget::sizeHint().height());
    }
}

void Demo::setProperties() {
    this->toolBar->setMovable(false);
    this->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    this->toolBox->setMaximumWidth(200);
    this->toolBox->setMinimumWidth(200);

    this->splitter->setOrientation(Qt::Horizontal);

    this->toolButtonInit->setText(QString("ToolButtonInit"));
    this->toolButtonClear->setText(QString("ToolButtonClear"));
    this->toolButtonInput->setText(QString("ToolButtonInput"));
    this->toolButtonAdd->setText(QString("ToolButtonAdd"));
    this->toolButtonDelete->setText(QString("ToolButtonDelete"));

    this->toolButtonSelectItem->setPopupMode(QToolButton::MenuButtonPopup);

    this->toolButtonSelectItem->setText(QString("ToolButton Select Item"));
    this->toolButtonSelectAll->setText(QString("ToolButton Select All"));
    this->toolButtonSelectNone->setText(QString("ToolButton Select None"));
    this->toolButtonSelectInv->setText(QString("TooButton Select Inv"));
}

void Demo::setLayout() {
    this->toolBar->addAction(this->actionInitList);
    this->toolBar->addAction(this->actionClear);
    this->toolBar->addAction(this->actionInput);
    this->toolBar->addAction(this->actionAddItem);
    this->toolBar->addAction(this->actionDeleteItem);
    this->toolBar->addSeparator();

    this->addToolBar(Qt::TopToolBarArea, this->toolBar);

    this->toolBox->addItem(this->page1, QString("QListWidget"));
    this->toolBox->addItem(this->page2, QString("QTreeWidget"));
    this->toolBox->addItem(this->page3, QString("QTableWidget"));

    this->tabWidget->addTab(this->tab1, QString("QListWidget"));
    this->tabWidget->addTab(this->tab2, QString("QTreeWidget"));
    this->tabWidget->addTab(this->tab3, QString("QTableWidget"));

    this->vLayout1Page1->addWidget(this->toolButtonInit);
    this->vLayout1Page1->addWidget(this->toolButtonClear);
    this->vLayout1Page1->addWidget(this->toolButtonInput);
    this->vLayout1Page1->addWidget(this->toolButtonAdd);
    this->vLayout1Page1->addWidget(this->toolButtonDelete);

    this->splitter->addWidget(this->toolBox);
    this->splitter->addWidget(this->tabWidget);

    this->hLayoutBoxTab1->addWidget(this->label);
    this->hLayoutBoxTab1->addWidget(this->lineEdit);
    this->hLayoutBoxTab1->addWidget(this->checkBox);
    this->vLayout2Page1->addWidget(this->gBox1Tab1);
    this->hLayoutBoxTab2->addWidget(this->toolButtonSelectItem);
    this->hLayoutBoxTab2->addWidget(this->toolButtonSelectAll);
    this->hLayoutBoxTab2->addWidget(this->toolButtonSelectNone);
    this->hLayoutBoxTab2->addWidget(this->toolButtonSelectInv);
    this->vLayout2Page1->addWidget(this->gBox2Tab1);
    this->vLayout2Page1->addWidget(this->listWidget);

    this->hLayoutMain->addWidget(this->splitter);
    this->verticalLayout->addLayout(this->hLayoutMain);

    this->setCentralWidget(this->centralWid);
}

void Demo::signalsAndSlots() {

}

Demo::~Demo() = default;