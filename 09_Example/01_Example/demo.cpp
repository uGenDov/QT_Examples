#include "demo.h"

Demo::Demo(QMainWindow *parent) : QMainWindow(parent) {
    {
        this->centralwidget = new QWidget(this);
        this->hLayoutMain = new QHBoxLayout();
        this->toolBar = new QToolBar(this);

        this->verticalLayout = new QVBoxLayout(centralwidget);

        this->actionInitList = new QAction(QIcon("D:/images/bold.png"), QString("Initialize List"), this);
        this->actionClear = new QAction(QIcon("D:/images/bold.png"), QString("Clear List"), this);
        this->actionInput = new QAction(QIcon("D:/images/bold.png"), QString("Input"), this);
        this->actionAddItem = new QAction(QIcon("D:/images/bold.png"), QString("Add item"), this);
        this->actionDeleteItem = new QAction(QIcon("D:/images/bold.png"), QString("Delete item"), this);

        this->splitter = new QSplitter(this->centralwidget);
        this->toolBox = new QToolBox(this->splitter);
        this->tabWidget = new QTabWidget(this->splitter);

        this->page1 = new QWidget();
        this->page2 = new QWidget();
        this->page3 = new QWidget();
        this->tab1 = new QWidget();
        this->tab2 = new QWidget();
        this->tab3 = new QWidget();

        this->verticalLayout_2 = new QVBoxLayout(this->page1);

        this->toolButtonInit = new QToolButton(this->page1);
        this->toolButtonClear = new QToolButton(this->page1);
        this->toolButtonInput = new QToolButton(this->page1);
        this->toolButtonAdd = new QToolButton(this->page1);
        this->toolButtonDelete = new QToolButton(this->page1);
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

    this->verticalLayout_2->addWidget(this->toolButtonInit);
    this->verticalLayout_2->addWidget(this->toolButtonClear);
    this->verticalLayout_2->addWidget(this->toolButtonInput);
    this->verticalLayout_2->addWidget(this->toolButtonAdd);
    this->verticalLayout_2->addWidget(this->toolButtonDelete);

    this->splitter->addWidget(this->toolBox);
    this->splitter->addWidget(this->tabWidget);

    this->hLayoutMain->addWidget(this->splitter);
    this->verticalLayout->addLayout(this->hLayoutMain);

    this->setCentralWidget(this->centralwidget);
}

void Demo::signalsAndSlots() {

}

Demo::~Demo() = default;