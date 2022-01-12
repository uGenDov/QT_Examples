#include "demo.h"

Demo::Demo(QWidget *parent) : QWidget(parent) {
    {
        this->vLayout         = new QVBoxLayout(this);
        this->gLayoutTop      = new QGridLayout();
        this->gLayoutBottom   = new QGridLayout();

        this->labelNumber     = new QLabel(QString("Number:"), this);
        this->labelUnit       = new QLabel(QString("Unit price:"), this);
        this->labelTotal      = new QLabel(QString("Total price:"), this);

        this->lineEditNumber  = new QLineEdit(this);
        this->lineEditUnit    = new QLineEdit(this);
        this->lineEditTotal   = new QLineEdit(this);

        this->buttonCalculate = new QPushButton(QString("Calculate"), this);

        this->labelDec        = new QLabel(QString("Decimal:"), this);
        this->labelBin        = new QLabel(QString("Binary:"), this);
        this->labelHex        = new QLabel(QString("Hexadecimal:"), this);
        this->lineEditDec     = new QLineEdit(this);
        this->lineEditBin     = new QLineEdit(this);
        this->lineEditHex     = new QLineEdit(this);
        this->buttonDec       = new QPushButton(QString("Transform"), this);
        this->buttonBin       = new QPushButton(QString("Transform"), this);
        this->buttonHex       = new QPushButton(QString("Transform"), this);

        this->vSpacer         = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalAndSlots();
        Demo::setWindowTitle(QString("Demo"));
        Demo::setFont(QFont("Arial", 9, -1, false));
    }
}

void Demo::setLayout() {
    {
        this->gLayoutTop->addWidget(this->labelNumber, 0, 0);
        this->gLayoutTop->addWidget(this->lineEditNumber, 0, 1);
        this->gLayoutTop->addWidget(this->labelUnit, 0, 2);
        this->gLayoutTop->addWidget(this->lineEditUnit, 0, 3);
        this->gLayoutTop->addWidget(this->buttonCalculate, 1, 1);
        this->gLayoutTop->addWidget(this->labelTotal, 1, 2);
        this->gLayoutTop->addWidget(this->lineEditTotal, 1, 3);
    }

    {
        this->gLayoutBottom->addWidget(this->labelDec, 0, 0);
        this->gLayoutBottom->addWidget(this->lineEditDec, 0, 1);
        this->gLayoutBottom->addWidget(this->buttonDec, 0, 2);
        this->gLayoutBottom->addWidget(this->labelBin, 1, 0);
        this->gLayoutBottom->addWidget(this->lineEditBin, 1, 1);
        this->gLayoutBottom->addWidget(this->buttonBin, 1, 2);
        this->gLayoutBottom->addWidget(this->labelHex, 2, 0);
        this->gLayoutBottom->addWidget(this->lineEditHex, 2, 1);
        this->gLayoutBottom->addWidget(this->buttonHex, 2, 2);
    }

    {
        this->vLayout->addLayout(this->gLayoutTop);
        this->vLayout->addItem(this->vSpacer);
        this->vLayout->addLayout(this->gLayoutBottom);
    }
}

void Demo::setProperties() {
    {
        this->lineEditNumber->setText(QString("12"));
        this->lineEditUnit->setText(QString("5.3"));
        this->lineEditDec->setText(QString("15"));
    }

    {
        this->labelNumber->setBuddy(this->lineEditNumber);
        this->labelUnit->setBuddy(this->lineEditUnit);
        this->labelTotal->setBuddy(this->lineEditTotal);
        this->labelDec->setBuddy(this->lineEditDec);
        this->labelBin->setBuddy(this->lineEditBin);
        this->labelHex->setBuddy(this->lineEditHex);
    }
}

void Demo::signalAndSlots() {
    QObject::connect(this->buttonCalculate, &QPushButton::clicked, this, [&]() {
        unsigned int num = this->lineEditNumber->text().toInt();
        float price = this->lineEditUnit->text().toFloat();
        QString str;
        str.setNum(static_cast<float>(num) * price, 'f', 2);
        this->lineEditTotal->setText(str);
    });

    QObject::connect(this->buttonDec, &QPushButton::clicked, this, [&]() {
        int value = this->lineEditDec->text().toInt();
        QString str;
        str.setNum(value, 2);
        this->lineEditBin->setText(str);
        str.setNum(value, 16);
        this->lineEditHex->setText(str.toUpper());
    });

    QObject::connect(this->buttonBin, &QPushButton::clicked, [&]() {
        bool ok;
        int value = this->lineEditBin->text().toInt(&ok, 2);
        this->lineEditDec->setText(QString::number(value));
        this->lineEditHex->setText(QString::number(value, 16).toUpper());
    });

    QObject::connect(this->buttonHex, &QPushButton::clicked, [&]() {
        // TODO
    });
}

Demo::~Demo() = default;