#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <QTextBlock>
#include <QMenu>

class Demo : public QWidget {
private:
    Q_OBJECT
public:
    explicit Demo(QWidget *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

    void comboItemsIndexChanged(const QString &arg);

    void comboCityRegionChanged(const QString &arg);

private:
    QGridLayout    *gridLayoutMain;
    QGridLayout    *gLayoutTopLeft;
    QGridLayout    *gLayoutBottom;
    QVBoxLayout    *vLayoutTopRight;
    QGroupBox      *gBoxTopLeft;
    QGroupBox      *gBoxTopRight;
    QGroupBox      *gBoxBottom;
    QPushButton    *buttonInitList;
    QPushButton    *buttonClearList;
    QPushButton    *buttonInitCityRegion;
    QPushButton    *buttonAddContentToCombo;
    QPushButton    *buttonClearContent;
    QCheckBox      *cBoxCanEdit;
    QCheckBox      *cBoxReadOnly;
    QComboBox      *comboItems;
    QComboBox      *comboCity;
    QPlainTextEdit *plainText;

private:
    QStringList    items;
};