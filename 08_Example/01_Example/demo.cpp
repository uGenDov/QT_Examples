#include "demo.h"

Demo::Demo(QWidget *parent) : QWidget(parent) {
    {
        this->gridLayoutMain          = new QGridLayout(this);

        this->gBoxTopLeft             = new QGroupBox(QString("Simple ComboBox"), this);
        this->gBoxTopRight            = new QGroupBox(QString("ComboBox with user data"), this);
        this->gBoxBottom              = new QGroupBox(QString("Add text content to ComboBox"), this);

        this->gLayoutTopLeft          = new QGridLayout(this->gBoxTopLeft);
        this->vLayoutTopRight         = new QVBoxLayout(this->gBoxTopRight);
        this->gLayoutBottom           = new QGridLayout(this->gBoxBottom);

        this->buttonInitList          = new QPushButton(QString("Initialize List"), this->gBoxTopLeft);
        this->buttonClearList         = new QPushButton(QString("Clear List"), this->gBoxTopLeft);
        this->buttonInitCityRegion    = new QPushButton(QString("Initialize city and region"), this->gBoxTopRight);
        this->buttonAddContentToCombo = new QPushButton(QString("Add Content to List"), this->gBoxBottom);
        this->buttonClearContent      = new QPushButton(QString("Clear Content"), this->gBoxBottom);

        this->cBoxCanEdit             = new QCheckBox(QString("Can Edit"), this->gBoxTopLeft);
        this->cBoxReadOnly            = new QCheckBox(QString("Read Only"), this->gBoxBottom);

        this->comboItems              = new QComboBox(this->gBoxTopLeft);
        this->comboCity               = new QComboBox(this->gBoxTopRight);

        this->plainText               = new QPlainTextEdit(this->gBoxBottom);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
    }
}

void Demo::setProperties() {
    items << "Moscow" << "St. Petersburg" << "Novosibirsk" << "Yekaterinburg" << "Saratov";
    comboItems->addItems(items);

    for (int index{}; index < items.length(); ++index) {
        comboItems->setItemIcon(index, QIcon("D:/images/city.png"));
    }
}

void Demo::setLayout() {
    {
        this->gLayoutTopLeft->addWidget(this->buttonInitList, 0, 0);
        this->gLayoutTopLeft->addWidget(this->buttonClearList, 0, 1);
        this->gLayoutTopLeft->addWidget(this->cBoxCanEdit, 0, 2);
        this->gLayoutTopLeft->addWidget(this->comboItems, 1, 0, 1, 3);
    }

    {
        this->vLayoutTopRight->addWidget(this->buttonInitCityRegion);
        this->vLayoutTopRight->addWidget(this->comboCity);
    }

    {
        this->gLayoutBottom->addWidget(this->buttonAddContentToCombo, 0, 0);
        this->gLayoutBottom->addWidget(this->buttonClearContent, 0, 1);
        this->gLayoutBottom->addWidget(this->cBoxReadOnly, 0, 2);
        this->gLayoutBottom->addWidget(this->plainText, 1, 0, 1, 3);
    }

    {
        this->gridLayoutMain->addWidget(this->gBoxTopLeft, 0, 0);
        this->gridLayoutMain->addWidget(this->gBoxTopRight, 0, 1);
        this->gridLayoutMain->addWidget(this->gBoxBottom, 1, 0, 1, 2);
    }
}

void Demo::signalsAndSlots() {
    QObject::connect(this->buttonInitList, &QPushButton::clicked, this->comboItems, [&](int i = 0) {
        this->comboItems->clear();
        QIcon icon("D:/images/city.png");
        for (; i < 20; ++i) {
            this->comboItems->addItem(icon, QString::asprintf("Item %d", i));
        }
    });

    QObject::connect(this->buttonClearList, &QPushButton::clicked, this->comboItems, [&]() {
        this->comboItems->clear();
    });

    QObject::connect(this->buttonInitCityRegion, &QPushButton::clicked, this->comboCity, [&]() {
        this->comboCity->clear();
        QMap<QString, int> cityZone;
        cityZone.insert("Moscow", 10);
        cityZone.insert("St. Petersburg", 20);
        cityZone.insert("Novosibirsk", 30);

        foreach(auto str, cityZone.keys()) {
            this->comboCity->addItem(QIcon("D:/images/city.png"), str, cityZone.value(str));
        }
    });

    QObject::connect(this->cBoxCanEdit, &QCheckBox::clicked, this->comboItems, [&](bool checked) {
        this->comboItems->setEditable(checked);
    });

    QObject::connect(this->cBoxReadOnly, &QCheckBox::clicked, this->plainText, [&](bool checked) {
        this->plainText->setReadOnly(checked);
    });

    QObject::connect(this->comboItems, SIGNAL(currentIndexChanged(QString)), SLOT(comboItemsIndexChanged(QString)));

    QObject::connect(this->comboCity, SIGNAL(currentIndexChanged(QString)), SLOT(comboCityRegionChanged(QString)));

    QObject::connect(this->buttonAddContentToCombo, &QPushButton::clicked, this->comboItems, [&](int i = 0) {
        this->comboItems->clear();
        QTextDocument *document = this->plainText->document();
        for (; i < document->blockCount(); ++i) {
            this->comboItems->addItem(QIcon("D:/images/city.png"), document->findBlockByNumber(i).text());
        }
    });

    QObject::connect(this->buttonClearContent, &QPushButton::clicked, this->plainText, [&]() {
        this->plainText->clear();
    });

    QObject::connect(this->plainText, &QPlainTextEdit::customContextMenuRequested, this, [&](const QPoint &pos) {
        QMenu *menu = this->plainText->createStandardContextMenu();
        menu->exec(pos);
    });
}

void Demo::comboItemsIndexChanged(const QString &arg) {
    if (!arg.isEmpty()) this->plainText->appendPlainText(arg);
}

void Demo::comboCityRegionChanged(const QString &arg) {
    if (!arg.isEmpty()) this->plainText->appendPlainText(arg + ", Region: " + comboCity->currentData().toString());
}

Demo::~Demo() = default;