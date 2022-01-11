#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QProgressBar>
#include <QAction>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QSpinBox>
#include <QFontComboBox>
#include <QFileDialog>
#include <QTextStream>

class Demo : public QMainWindow {
private:
    Q_OBJECT
public:
    explicit Demo(QWidget *parent = nullptr);

    void setLayout();

    void setProperties();

    ~Demo() override;

public slots:

    void signalsAndSlots();

    void fontSizeChanged(int size);

    void fontFamilyChanged(const QString& myFont);

private:
    QAction         *actionNew;
    QAction         *actionOpen;
    QAction         *actionSaveAs;
    QAction         *actionExit;
    QAction         *actionCut;
    QAction         *actionCopy;
    QAction         *actionPaste;
    QAction         *actionBold;
    QAction         *actionItalic;
    QAction         *actionUnderline;
    QWidget         *centralWidget;
    QGridLayout     *gridLayout;
    QLabel          *label;
    QTextEdit       *textEdit;
    QProgressBar    *progressBar;
    QMenuBar        *menubar;
    QMenu           *menuFile;
    QMenu           *menuEdit;
    QMenu           *menuAbout;
    QStatusBar      *statusbar;
    QToolBar        *toolBar;
    QSpinBox        *spinBox;
    QFontComboBox   *comboFont;

private:
    QTextCharFormat fmt;
};