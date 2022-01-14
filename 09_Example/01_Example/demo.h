#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QVBoxLayout>
#include <QSplitter>
#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QListWidget>

class Demo : public QMainWindow {
public:
    explicit Demo(QMainWindow *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:
    QAction     *actionInitList;
    QAction     *actionClear;
    QAction     *actionInput;
    QAction     *actionAddItem;
    QAction     *actionDeleteItem;
    QWidget     *centralWid;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hLayoutMain;
    QSplitter   *splitter;
    QToolBox    *toolBox;
    QWidget     *page1;
    QVBoxLayout *vLayout1Page1;
    QToolButton *toolButtonInit;
    QToolButton *toolButtonClear;
    QToolButton *toolButtonInput;
    QToolButton *toolButtonAdd;
    QToolButton *toolButtonDelete;
    QWidget     *page2;
    QWidget     *page3;
    QTabWidget  *tabWidget;
    QWidget     *tab1;
    QVBoxLayout *vLayout2Page1;
    QGroupBox   *gBox1Tab1;
    QHBoxLayout *hLayoutBoxTab1;
    QLabel      *label;
    QLineEdit   *lineEdit;
    QCheckBox   *checkBox;
    QGroupBox   *gBox2Tab1;
    QHBoxLayout *hLayoutBoxTab2;
    QToolButton *toolButtonSelectItem;
    QToolButton *toolButtonSelectAll;
    QToolButton *toolButtonSelectNone;
    QToolButton *toolButtonSelectInv;
    QListWidget *listWidget;
    QWidget     *tab2;
    QWidget     *tab3;
    QToolBar    *toolBar;
};