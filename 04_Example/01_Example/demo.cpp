#include "demo.h"

Demo::Demo(QWidget *parent) : QWidget(parent) {
    {
        this->vLayout           = new QVBoxLayout(this);
        this->fLayout           = new QFormLayout();
        this->hLayout           = new QHBoxLayout();
        this->gLayout           = new QGridLayout();

        this->gBoxLeft          = new QGroupBox(this);
        this->gBoxCenter        = new QGroupBox(this);
        this->gBoxRight         = new QGroupBox(this);

        this->gLayoutLeft       = new QGridLayout(this->gBoxLeft);
        this->vLayoutCenter     = new QVBoxLayout(this->gBoxCenter);
        this->gLayoutRight      = new QGridLayout(this->gBoxRight);

        this->labelStr1         = new QLabel(QString("Str1:"), this);
        this->labelStr2         = new QLabel(QString("Str2:"), this);
        this->comboStr1         = new QComboBox(this);
        this->comboStr2         = new QComboBox(this);

        this->buttonAppend      = new QPushButton(QString("Append"), this->gBoxLeft);
        this->buttonPrepend     = new QPushButton(QString("Prepend"), this->gBoxLeft);
        this->buttonToUpper     = new QPushButton(QString("toUpper"), this->gBoxLeft);
        this->buttonToLower     = new QPushButton(QString("toLower"), this->gBoxLeft);
        this->buttonLeft        = new QPushButton(QString("Left"), this->gBoxLeft);
        this->buttonRight       = new QPushButton(QString("Right"), this->gBoxLeft);
        this->buttonSection     = new QPushButton(QString("Section"), this->gBoxLeft);
        this->buttonSimplified  = new QPushButton(QString("Simplified"), this->gBoxLeft);
        this->buttonTrimmed     = new QPushButton(QString("Trimmed"), this->gBoxLeft);

        this->buttonCount       = new QPushButton(QString("Count"), this->gBoxCenter);
        this->buttonSize        = new QPushButton(QString("Size"), this->gBoxCenter);
        this->buttonIndexOf     = new QPushButton(QString("indexOf"), this->gBoxCenter);
        this->buttonLastIndexOf = new QPushButton(QString("lastIndexOf"), this->gBoxCenter);

        this->buttonEndsWith    = new QPushButton(QString("endsWith"), this->gBoxRight);
        this->buttonStartsWith  = new QPushButton(QString("startsWith"), this->gBoxRight);
        this->buttonContains    = new QPushButton(QString("Contains"), this->gBoxRight);
        this->buttonIsNull      = new QPushButton(QString("isNull"), this->gBoxRight);
        this->buttonIsEmpty     = new QPushButton(QString("isEmpty"), this->gBoxRight);

        this->labelResult       = new QLabel(QString("Result:"), this);
        this->lineEdit          = new QLineEdit(this);
        this->checkBox          = new QCheckBox(QString("CheckBox"), this);
        this->labelSpin         = new QLabel(this);
        this->spinBox           = new QSpinBox(this);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
        Demo::setFixedSize(QWidget::sizeHint().width(), QWidget::sizeHint().height());
    }
}

void Demo::setProperties() {
    {
        this->fLayout->setWidget(0, QFormLayout::LabelRole, this->labelStr1);
        this->fLayout->setWidget(1, QFormLayout::LabelRole, this->labelStr2);
        this->fLayout->setWidget(0, QFormLayout::FieldRole, this->comboStr1);
        this->fLayout->setWidget(1, QFormLayout::FieldRole, this->comboStr2);
    }

    {
        this->labelSpin->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    }

    {
        this->comboStr1->setEditable(true);
        this->comboStr2->setEditable(true);

        this->comboStr1->addItem(QString("G:\\Qt5Book\\QT5, 9Study"));
        this->comboStr1->addItem(QString("学生姓名，男，1988-3-17，俄罗斯人， 俄罗斯圣彼得堡"));

        this->comboStr2->addItem(QString("\\"));
        this->comboStr2->addItem(QString(".cpp"));
        this->comboStr2->addItem(QString(";"));
        this->comboStr2->addItem(QString(","));
    }
}

void Demo::setLayout() {
    {
        this->hLayout->addWidget(this->gBoxLeft);
        this->hLayout->addWidget(this->gBoxCenter);
        this->hLayout->addWidget(this->gBoxRight);
    }

    {
        this->gLayoutLeft->addWidget(this->buttonAppend, 0, 0);
        this->gLayoutLeft->addWidget(this->buttonPrepend, 0, 1);
        this->gLayoutLeft->addWidget(this->buttonToUpper, 1, 0);
        this->gLayoutLeft->addWidget(this->buttonToLower, 1, 1);
        this->gLayoutLeft->addWidget(this->buttonLeft, 2, 0);
        this->gLayoutLeft->addWidget(this->buttonRight, 2, 1);
        this->gLayoutLeft->addWidget(this->buttonSection, 3, 1);
        this->gLayoutLeft->addWidget(this->buttonSimplified, 4, 0);
        this->gLayoutLeft->addWidget(this->buttonTrimmed, 4, 1);
    }

    {
        this->vLayoutCenter->addWidget(this->buttonCount);
        this->vLayoutCenter->addWidget(this->buttonSize);
        this->vLayoutCenter->addWidget(this->buttonIndexOf);
        this->vLayoutCenter->addWidget(this->buttonLastIndexOf);
    }

    {
        this->gLayoutRight->addWidget(this->buttonEndsWith, 0, 0);
        this->gLayoutRight->addWidget(this->buttonStartsWith, 0, 1);
        this->gLayoutRight->addWidget(this->buttonContains, 1, 0);
        this->gLayoutRight->addWidget(this->buttonIsNull, 2, 0);
        this->gLayoutRight->addWidget(this->buttonIsEmpty, 2, 1);
    }

    {
        this->gLayout->addWidget(this->labelResult, 0, 0);
        this->gLayout->addWidget(this->checkBox, 1, 0);
        this->gLayout->addWidget(this->labelSpin, 1, 2);
        this->gLayout->addWidget(this->spinBox, 1, 3);
        this->gLayout->addWidget(this->lineEdit, 0, 1, 1, 3);
    }

    {
        this->vLayout->addLayout(this->fLayout);
        this->vLayout->addLayout(this->hLayout);
        this->vLayout->addLayout(this->gLayout);
    }
}

void Demo::signalsAndSlots() {
    QObject::connect(this->buttonAppend, &QPushButton::clicked, this, [&]() {
        this->lineEdit->setText(this->comboStr1->currentText().append(this->comboStr2->currentText()));
        this->labelSpin->setText(this->buttonAppend->text() + "()");
    });

    QObject::connect(this->buttonPrepend, &QPushButton::clicked, this, [&]() {
        this->lineEdit->setText(this->comboStr1->currentText().prepend(this->comboStr2->currentText()));
        this->labelSpin->setText(this->buttonPrepend->text() + "()");
    });

    QObject::connect(this->buttonToUpper, &QPushButton::clicked, this, [&]() {
        this->lineEdit->setText(this->comboStr1->currentText().toUpper());
        this->labelSpin->setText(this->buttonToUpper->text() + "()");
    });

    QObject::connect(this->buttonToLower, &QPushButton::clicked, this, [&]() {
        this->lineEdit->setText(this->comboStr1->currentText().toLower());
        this->labelSpin->setText(this->buttonToLower->text() + "()");
    });

    // TODO QObject::connect(this->buttonLeft, &QPushButton::clicked, this, [&]() {});
    // TODO QObject::connect(this->buttonRight, &QPushButton::clicked, this, [&]() {});
    // TODO QObject::connect(this->buttonSection, &QPushButton::clicked, this, [&]() {});
    // TODO QObject::connect(this->buttonSimplified, &QPushButton::clicked, this, [&]() {});
    // TODO QObject::connect(this->buttonTrimmed, &QPushButton::clicked, this, [&]() {});

    QObject::connect(this->buttonCount, &QPushButton::clicked, this, [&]() {
        this->spinBox->setValue(this->comboStr1->currentText().count());
        this->labelSpin->setText(this->buttonCount->text() + "()");
    });

    QObject::connect(this->buttonSize, &QPushButton::clicked, this, [&]() {
        this->spinBox->setValue(this->comboStr1->currentText().size());
        this->labelSpin->setText(this->buttonSize->text() + "()");
    });

    QObject::connect(this->buttonIndexOf, &QPushButton::clicked, this, [&]() {
        this->spinBox->setValue(this->comboStr1->currentText().indexOf(this->comboStr2->currentText()));
        this->labelSpin->setText(this->buttonIndexOf->text() + "()");
    });

    QObject::connect(this->buttonLastIndexOf, &QPushButton::clicked, this, [&]() {
        this->spinBox->setValue(this->comboStr1->currentText().lastIndexOf(this->comboStr2->currentText()));
        this->labelSpin->setText(this->buttonLastIndexOf->text() + "()");
    });

    QObject::connect(this->buttonEndsWith, &QPushButton::clicked, this, [&]() {
        this->checkBox->setChecked(this->comboStr1->currentText().endsWith(this->comboStr2->currentText()));
        this->checkBox->setText(this->buttonEndsWith->text() + "()");
    });

    QObject::connect(this->buttonStartsWith, &QPushButton::clicked, this, [&]() {
        this->checkBox->setChecked(this->comboStr1->currentText().startsWith(this->comboStr2->currentText()));
        this->checkBox->setText(this->buttonStartsWith->text() + "()");
    });

    QObject::connect(this->buttonContains, &QPushButton::clicked, this, [&]() {
        this->checkBox->setChecked(this->comboStr1->currentText().contains(this->comboStr2->currentText()));
        this->checkBox->setText(this->buttonContains->text() + "()");
    });

    QObject::connect(this->buttonIsNull, &QPushButton::clicked, this, [&]() {
        this->checkBox->setChecked(this->comboStr1->currentText().isNull());
        this->checkBox->setText(this->buttonIsNull->text() + "()");
    });

    QObject::connect(this->buttonIsEmpty, &QPushButton::clicked, this, [&]() {
        this->checkBox->setChecked(this->comboStr1->currentText().isEmpty());
        this->checkBox->setText(this->buttonIsEmpty->text() + "()");
    });
}

Demo::~Demo() = default;