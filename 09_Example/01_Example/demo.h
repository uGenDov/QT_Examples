#include <QMainWindow>
#include <QWidget>

class Demo : public QMainWindow {
public:
    explicit Demo(QWidget *parent = nullptr);

    void setProperties();

    void setLayout();

    ~Demo() override;

public slots:
    void signalsAndSlots();

private:

};