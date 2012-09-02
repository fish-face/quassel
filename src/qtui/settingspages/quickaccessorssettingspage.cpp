#include "quickaccessorssettingspage.h"

#include "qtui.h"
#include "client.h"
#include "clientsettings.h"
#include "bufferviewconfig.h"
#include "buffermodel.h"
#include "bufferview.h"

QuickAccessorsSettingsPage::QuickAccessorsSettingsPage(const QHash<QString, ActionCollection*> &colls, QWidget *parent)
    : SettingsPage(tr("Interface"), tr("Quick Accessors"), parent),
      _shortcutsModel(new ShortcutsModel(colls, this))
{
    ui.setupUi(this);

    _shortcutsModel = new ShortcutsModel(colls, this);
    ui.quickAccessorsView->setModel(_shortcutsModel);
//    _config = new BufferViewConfig(-667, this);
//    _config->setBufferViewName("tmpChatMonitorAvailableBuffers");
//    _config->setSortAlphabetically(true);
//    _config->setDisableDecoration(true);
//    _config->setNetworkId(NetworkId());
//    _config->setInitialized();
}

QuickAccessorsSettingsPage::~QuickAccessorsSettingsPage()
{
    delete _shortcutsModel;
    //delete _actionCollection;
}

void QuickAccessorsSettingsPage::load() {
  delete _shortcutsModel;
  QList<BufferId> allBufferIds = Client::networkModel()->allBufferIds();
//  QList<NetworkId> networkIds = Client::networkIds();
//  QHash<NetworkId, ActionCollection *> networkToColl;
  QHash<QString, ActionCollection *> colls = QtUi::quickAccessorActionCollections();

//  QListIterator<NetworkId> netIter(networkIds);
//  NetworkId networkId;

//  while(netIter.hasNext()) {
//    networkId = netIter.next();
//    if(!colls.value(Client::networkModel()->networkName(networkId))) {
//      colls[networkId] = new ActionCollection(this);
//    }
//  }
//  _jumpKeyMap = CoreAccountSettings().jumpKeyMap();
//  int jumpModifier = Qt::AltModifier;

  QListIterator<BufferId> bufIter(allBufferIds);
  BufferId id;
  BufferInfo info;

//    //We got some quickaccessors when created, but there might be buffers not in that collection we need to show so we add them now.
//    while(bufIter.hasNext()) {
//        id = bufIter.next();
//        info = Client::networkModel()->bufferInfo(id);
//        if(info.type() & (BufferInfo::ChannelBuffer | BufferInfo::QueryBuffer)) {
//            QString networkName = Client::networkModel()->networkName(id);
//            if(!colls.value(networkName)) {
//                colls[networkName] = new ActionCollection(this);
//                colls[networkName]->setProperty("Category", networkName);
//            }
//            if(colls[networkName]->action(QString("QuickAccessor%1").arg(id.toInt())) == 0)
//            {
//                colls[networkName]->addAction(QString("QuickAccessor%1").arg(id.toInt()), new Action(info.bufferName(),
//                                                                                                     _actionCollection, parent(), SLOT(onJumpKey())));
//            }
//        }
//    }

  _shortcutsModel = new ShortcutsModel(colls, this);
  ui.quickAccessorsView->setModel(_shortcutsModel);

  setChangedState(false);
}

void QuickAccessorsSettingsPage::save() {
    _shortcutsModel->commit();
    SettingsPage::save();
}

void QuickAccessorsSettingsPage::defaults() {

}
