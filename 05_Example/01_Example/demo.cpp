#include "demo.h"

Demo::Demo(QWidget *parent) : QWidget(parent) {
    {
        this->verticalLayout  = new QVBoxLayout(this);
        this->gLayoutTop      = new QGridLayout();
        this->gLayoutBottom   = new QGridLayout();

        this->labelNumber     = new QLabel(QString("Number:"), this);
        this->labelUnit       = new QLabel(QString("Unit price:"), this);
        this->labelTotal      = new QLabel(QString("Total price:"), this);

        this->buttonCalculate = new QPushButton(QString("Calculate"), this);

        this->spinBoxNumber   = new QSpinBox(this);
        this->dSpinBoxUnit    = new QDoubleSpinBox(this);
        this->dSpinBoxTotal   = new QDoubleSpinBox(this);

        this->vSpacer         = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        this->labelDec        = new QLabel(QString("Decimal:"), this);
        this->labelBin        = new QLabel(QString("Binary:"), this);
        this->labelHex        = new QLabel(QString("Hexadecimal:"), this);

        this->spinBoxDec      = new QSpinBox(this);
        this->spinBoxBin      = new QSpinBox(this);
        this->spinBoxHex      = new QSpinBox(this);

        this->buttonDec       = new QPushButton(QString("Transform"), this);
        this->buttonBin       = new QPushButton(QString("Transform"), this);
        this->buttonHex       = new QPushButton(QString("Transform"), this);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
        Demo::setFixedWidth(400);
    }
}

void Demo::setLayout() {
    {
        this->gLayoutTop->addWidget(this->labelNumber, 0, 0);
        this->gLayoutTop->addWidget(this->spinBoxNumber, 0, 1);
        this->gLayoutTop->addWidget(this->labelUnit, 0, 2);
        this->gLayoutTop->addWidget(this->dSpinBoxUnit, 0, 3);
        this->gLayoutTop->addWidget(this->buttonCalculate, 1, 1);
        this->gLayoutTop->addWidget(this->labelTotal, 1, 2);
        this->gLayoutTop->addWidget(this->dSpinBoxTotal, 1, 3);
    }

    {
        this->gLayoutBottom->addWidget(this->labelDec, 0, 0);
        this->gLayoutBottom->addWidget(this->spinBoxDec, 0, 1);
        this->gLayoutBottom->addWidget(this->buttonDec, 0, 2);
        this->gLayoutBottom->addWidget(this->labelBin, 1, 0);
        this->gLayoutBottom->addWidget(this->spinBoxBin, 1, 1);
        this->gLayoutBottom->addWidget(this->buttonBin, 1, 2);
        this->gLayoutBottom->addWidget(this->labelHex, 2, 0);
        this->gLayoutBottom->addWidget(this->spinBoxHex, 2, 1);
        this->gLayoutBottom->addWidget(this->buttonHex, 2, 2);
    }

    {
        this->verticalLayout->addLayout(this->gLayoutTop);
        this->verticalLayout->addItem(this->vSpacer);
        this->verticalLayout->addLayout(this->gLayoutBottom);
    }
}

void Demo::setProperties() {
    {
        this->spinBoxNumber->setSuffix(QString(" kg"));
        this->dSpinBoxUnit->setPrefix(QString("$ "));
        this->dSpinBoxTotal->setPrefix(QString("$ "));
        this->spinBoxDec->setPrefix(QString("Dec "));
        this->spinBoxBin->setPrefix(QString("Bin "));
        this->spinBoxHex->setPrefix(QString("Hex "));
    }

    {
        this->spinBoxNumber->setSingleStep(1);
        this->dSpinBoxUnit->setSingleStep(0.01);
        this->dSpinBoxTotal->setReadOnly(true);
    }

    {
        this->spinBoxNumber->setValue(4);
        this->dSpinBoxUnit->setValue(12.43);
        this->dSpinBoxTotal->setMaximum(9'999.99);
        this->spinBoxDec->setValue(12);
    }

    {
        this->spinBoxDec->setDisplayIntegerBase(10);
        this->spinBoxBin->setDisplayIntegerBase(2);
        this->spinBoxHex->setDisplayIntegerBase(16);
    }
}

void Demo::signalsAndSlots() {
    QObject::connect(this->buttonCalculate, &QPushButton::clicked, this->dSpinBoxTotal, [&]() {
        this->dSpinBoxTotal->setValue(this->spinBoxNumber->value() * this->dSpinBoxUnit->value());
    });

    QObject::connect(this->buttonDec, &QPushButton::clicked, this, [&]() {
        this->spinBoxBin->setValue(this->spinBoxDec->value());
        this->spinBoxHex->setValue(this->spinBoxDec->value());
    });

    QObject::connect(this->buttonBin, &QPushButton::clicked, this, [&]() {
        this->spinBoxDec->setValue(this->spinBoxBin->value());
        this->spinBoxHex->setValue(this->spinBoxBin->value());
    });

    QObject::connect(this->buttonHex, &QPushButton::clicked, this, [&]() {
        this->spinBoxDec->setValue(this->spinBoxHex->value());
        this->spinBoxBin->setValue(this->spinBoxHex->value());
    });
}

Demo::~Demo() = default;