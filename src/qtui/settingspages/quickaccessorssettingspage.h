#ifndef QUICKACCESSORSSETTINGSPAGE_H
#define QUICKACCESSORSSETTINGSPAGE_H

#include <QWidget>

#include "settingspage.h"
#include "ui_quickaccessorssettingspage.h"

#include "action.h"
#include "actioncollection.h"
#include "types.h"
#include "bufferviewconfig.h"
#include "shortcutsmodel.h"

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
    QHash<int, BufferId> _jumpKeyMap;
    ShortcutsModel *_shortcutsModel;
    ActionCollection *_actionCollection;
};

#endif // QUICKACCESSORSSETTINGSPAGE_H
