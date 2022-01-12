#include "demo.h"

Demo::Demo(QWidget *parent) : QMainWindow(parent) {
    {
        this->centralWidget     = new QWidget(this);

        this->gridLayout        = new QGridLayout(this->centralWidget);

        this->menubar           = new QMenuBar(this);

        this->menuFile          = new QMenu(QString("&File"), this->menubar);
        this->menuEdit          = new QMenu(QString("&Edit"), this->menubar);
        this->menuAbout         = new QMenu(QString("About"), this->menubar);

        this->actionNew         = new QAction(QIcon("D:/images/create.png"), QString("New"), this);
        this->actionOpen        = new QAction(QIcon("D:/images/open.png"), QString("Open"), this);
        this->actionSaveAs      = new QAction(QIcon("D:/images/save_as.png"), QString("Save As..."), this);
        this->actionExit        = new QAction(QIcon("D:/images/exit.png"), QString("Exit"), this);
        this->actionCut         = new QAction(QIcon("D:/images/cut.png"), QString("Cut"), this);
        this->actionCopy        = new QAction(QIcon("D:/images/copy.png"), QString("Copy"), this);
        this->actionPaste       = new QAction(QIcon("D:/images/paste.png"), QString("Paste"), this);
        this->actionBold        = new QAction(QIcon("D:/images/bold.png"), QString("Bold"), this);
        this->actionItalic      = new QAction(QIcon("D:/images/italic.png"), QString("Italic"), this);
        this->actionUnderline   = new QAction(QIcon("D:/images/underline.png"), QString("Underline"), this);

        this->spinBox           = new QSpinBox(this);
        this->comboFont         = new QFontComboBox(this);

        this->textEdit          = new QTextEdit(this->centralWidget);
        this->label             = new QLabel(QString("   Current font size: "), this);
        this->progressBar       = new QProgressBar(this);

        this->toolBar           = new QToolBar(this);
        this->statusbar         = new QStatusBar(this);
    }

    {
        Demo::setProperties();
        Demo::setLayout();
        Demo::signalsAndSlots();
        Demo::setFont(QFont("Arial", 9, -1, false));
        Demo::setWindowTitle(QString("Notepad"));
        Demo::setWindowIcon(QIcon("D:/images/notepad.png"));
        Demo::setMinimumSize(1024, 768);
    }
}

void Demo::setLayout() {
    {
        this->gridLayout->addWidget(this->textEdit);
    }

    {
        this->menubar->addAction(this->menuFile->menuAction());
        this->menubar->addAction(this->menuEdit->menuAction());
        this->menubar->addAction(this->menuAbout->menuAction());
    }

    {
        this->menuFile->addAction(this->actionNew);
        this->menuFile->addAction(this->actionOpen);
        this->menuFile->addAction(this->actionSaveAs);
        this->menuFile->addSeparator();
        this->menuFile->addAction(this->actionExit);
    }

    {
        this->menuEdit->addAction(this->actionCut);
        this->menuEdit->addAction(this->actionCopy);
        this->menuEdit->addAction(this->actionPaste);
    }

    {
        this->toolBar->addAction(this->actionNew);
        this->toolBar->addAction(this->actionOpen);
        this->toolBar->addAction(this->actionSaveAs);
        this->toolBar->addSeparator();
        this->toolBar->addAction(this->actionCut);
        this->toolBar->addAction(this->actionCopy);
        this->toolBar->addAction(this->actionPaste);
        this->toolBar->addSeparator();
        this->toolBar->addAction(this->actionBold);
        this->toolBar->addAction(this->actionItalic);
        this->toolBar->addAction(this->actionUnderline);
        this->toolBar->addSeparator();
        this->toolBar->addWidget(new QLabel(QString(" Font Size ")));
        this->toolBar->addWidget(this->spinBox);
        this->toolBar->addSeparator();
        this->toolBar->addWidget(new QLabel(QString(" Font ")));
        this->toolBar->addWidget(this->comboFont);
        this->statusbar->addWidget(this->label);
        this->statusbar->addWidget(this->progressBar);
    }

    {
        this->setCentralWidget(this->centralWidget);
        this->setMenuBar(this->menubar);
        this->addToolBar(this->toolBar); // this->addToolBar(Qt::TopToolBarArea, this->toolBar);
        this->setStatusBar(this->statusbar);
    }
}

void Demo::setProperties() {
    this->actionCut->setEnabled(false);
    this->actionCopy->setEnabled(false);

    this->actionNew->setShortcuts(QKeySequence::New);
    this->actionOpen->setShortcuts(QKeySequence::Open);
    this->actionSaveAs->setShortcuts(QKeySequence::Save);
    this->actionExit->setShortcuts(QKeySequence::Close);

    this->actionCut->setShortcuts(QKeySequence::Cut);
    this->actionCopy->setShortcuts(QKeySequence::Copy);
    this->actionPaste->setShortcuts(QKeySequence::Paste);

    this->actionBold->setShortcuts(QKeySequence::Bold);
    this->actionItalic->setShortcuts(QKeySequence::Italic);
    this->actionUnderline->setShortcuts(QKeySequence::Underline);

    this->spinBox->setMinimum(5);
    this->spinBox->setMaximum(50);
    this->spinBox->setValue(this->textEdit->font().pointSize());

    this->actionBold->setCheckable(true);
    this->actionItalic->setCheckable(true);
    this->actionUnderline->setCheckable(true);

    this->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    this->progressBar->setMinimum(5);
    this->progressBar->setMaximum(50);
    this->progressBar->setTextVisible(false);
    this->progressBar->setValue(this->spinBox->value());

    this->toolBar->setMovable(false);
    this->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void Demo::signalsAndSlots() {
    QObject::connect(this->actionNew, &QAction::triggered, this->textEdit, [&]() { this->textEdit->clear(); });
    QObject::connect(this->actionCut, &QAction::triggered, this->textEdit, [&]() { this->textEdit->cut(); });
    QObject::connect(this->actionCopy, &QAction::triggered, this->textEdit, [&]() { this->textEdit->copy(); });
    QObject::connect(this->actionPaste, &QAction::triggered, this->textEdit, [&]() { this->textEdit->paste(); });
    QObject::connect(this->actionExit, &QAction::triggered, this, &Demo::close);

    QObject::connect(this->actionOpen, &QAction::triggered, this->textEdit, [&]() {
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/home",
                                                        "All Files (*.*) ;; Text Files (*.txt) ;; Cpp Files (*.cpp)");
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        } else {
            QTextStream in(&file);
            QString text = in.readAll();
            this->setWindowTitle(fileName);
            this->textEdit->setText(text);
            file.close();
        }
    });

    QObject::connect(this->actionSaveAs, &QAction::triggered, this->textEdit, [&]() {
        QString fileName = QFileDialog::getSaveFileName(this, "Save as", "/home", "Text Files (*.txt)");

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        } else {
            QTextStream out(&file);
            QString text = this->textEdit->toPlainText();
            out << text;
            file.flush();
            file.close();
        }
    });

    QObject::connect(this->actionBold, &QAction::triggered, this->textEdit, [&](bool checked) {
        fmt.setFontWeight(checked ? QFont::Bold : QFont::Normal);
        this->textEdit->mergeCurrentCharFormat(fmt);
    });

    QObject::connect(this->actionItalic, &QAction::triggered, this->textEdit, [&](bool checked) {
        this->textEdit->setFontItalic(checked);
    });

    QObject::connect(this->actionUnderline, &QAction::triggered, this->textEdit, [&](bool checked) {
        this->textEdit->setFontUnderline(checked);
    });

    QObject::connect(this->textEdit, &QTextEdit::copyAvailable, this->textEdit, [&](bool b) {
        this->actionCut->setEnabled(b);
        this->actionCopy->setEnabled(b);
        this->actionPaste->setEnabled(this->textEdit->canPaste());
    });

    QObject::connect(this->textEdit, &QTextEdit::selectionChanged, this->textEdit, [&]() {
        this->actionBold->setChecked(this->textEdit->currentCharFormat().font().bold());
        this->actionItalic->setChecked(this->textEdit->currentCharFormat().fontItalic());
        this->actionUnderline->setChecked(this->textEdit->currentCharFormat().fontUnderline());
    });

    QObject::connect(this->spinBox, SIGNAL(valueChanged(int)), this, SLOT(fontSizeChanged(int)));
    QObject::connect(this->comboFont, SIGNAL(currentIndexChanged(QString)), this, SLOT(fontFamilyChanged(QString)));
}

void Demo::fontSizeChanged(int size) {
    fmt.setFontPointSize(size);
    this->textEdit->mergeCurrentCharFormat(fmt);
    this->progressBar->setValue(size);
}

void Demo::fontFamilyChanged(const QString &myFont) {
    fmt.setFontFamily(myFont);
    this->textEdit->mergeCurrentCharFormat(fmt);
}

Demo::~Demo() = default;