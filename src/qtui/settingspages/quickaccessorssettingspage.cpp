#include "quickaccessorssettingspage.h"

#include "qtui.h"
#include "client.h"
#include "clientsettings.h"
#include "bufferviewconfig.h"
#include "buffermodel.h"
#include "buffersettings.h"
#include "bufferview.h"

QuickAccessorsSettingsPage::QuickAccessorsSettingsPage(const QHash<QString, ActionCollection*> &colls, QWidget *parent)
    : ShortcutsSettingsPage(colls, parent, tr("Interface"), tr("Quick Accessors"))
{

}

void QuickAccessorsSettingsPage::load() {
    delete _shortcutsModel;

    QList<BufferId> allBufferIds = Client::networkModel()->allBufferIds();
    QHash<QString, ActionCollection *> colls = QtUi::quickAccessorActionCollections();

    QListIterator<BufferId> bufIter(allBufferIds);
    BufferId id;
    BufferInfo info;

    _shortcutsModel = new QuickAccessorsModel(colls, this);
    _shortcutsModel->load();
    _shortcutsFilter->setSourceModel(_shortcutsModel);
    connect(_shortcutsModel, SIGNAL(hasChanged(bool)), SLOT(setChangedState(bool)));

    ui.shortcutsView->expandAll();

    setChangedState(false);

    SettingsPage::load();
}



QuickAccessorsModel::QuickAccessorsModel(const QHash<QString, ActionCollection *> &colls, QWidget *parent)
    : ShortcutsModel(colls, parent)
{

}

void QuickAccessorsModel::commit() {
    BufferId id;
    foreach(Item *catItem, _categoryItems) {
        foreach(Item *actItem, catItem->actionItems) {
            // Save the shortcut to the buffer's settings.
            // NOTE: This could break if the user invalidates the BufferId in between
            // showing the settingspage and saving it. (Do we care?),
            id = qvariant_cast<BufferId>(actItem->action->property("BufferId"));
            BufferSettings s(id);
            s.setShortcut(actItem->shortcut);
        }
    }
    ShortcutsModel::commit();
}
