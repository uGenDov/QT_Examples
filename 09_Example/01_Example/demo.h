#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QVBoxLayout>
#include <QSplitter>
#include <QToolBox>
#include <QToolButton>

class Demo : public QMainWindow {
public:
    explicit Demo(QMainWindow *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:
    QAction *actionInitList;
    QAction *actionClear;
    QAction *actionInput;
    QAction *actionAddItem;
    QAction *actionDeleteItem;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hLayoutMain;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page1;
    QVBoxLayout *verticalLayout_2;
    QToolButton *toolButtonInit;
    QToolButton *toolButtonClear;
    QToolButton *toolButtonInput;
    QToolButton *toolButtonAdd;
    QToolButton *toolButtonDelete;
    QWidget *page2;
    QWidget *page3;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *tab2;
    QWidget *tab3;
    QToolBar *toolBar;
};