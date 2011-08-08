#ifndef QUICKACCESSORSSETTINGSPAGE_H
#define QUICKACCESSORSSETTINGSPAGE_H

#include <QWidget>

#include "settingspage.h"
#include "ui_quickaccessorssettingspage.h"

/*namespace Ui {
    class QuickAccessorsSettingsPage;
}*/

class QuickAccessorsSettingsPage : public SettingsPage
{
    Q_OBJECT

public:
    explicit QuickAccessorsSettingsPage(QWidget *parent = 0);
    ~QuickAccessorsSettingsPage();

public slots:
    void save();
    void load();
    void defaults();

private:
    Ui::QuickAccessorsSettingsPage ui;
    BufferViewConfig *_config;
};

#endif // QUICKACCESSORSSETTINGSPAGE_H
