#include "demo.h"

Demo::Demo(QMainWindow *parent) : QMainWindow(parent) {
    {

    }

    {
        Demo::setFont(QFont("Arial", 9, -1, false));
    }
}

void Demo::setProperties() {

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