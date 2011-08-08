#include "quickaccessorssettingspage.h"

#include "client.h"
#include "bufferviewconfig.h"
#include "buffermodel.h"
#include "bufferview.h"

QuickAccessorsSettingsPage::QuickAccessorsSettingsPage(QWidget *parent)
    : SettingsPage(tr("Interface"), tr("Quick Accessors"), parent)
{
    ui.setupUi(this);

    _config = new BufferViewConfig(-667, this);
    _config->setBufferViewName("tmpChatMonitorAvailableBuffers");
    _config->setSortAlphabetically(true);
    _config->setDisableDecoration(true);
    _config->setNetworkId(NetworkId());
    _config->setInitialized();
}

QuickAccessorsSettingsPage::~QuickAccessorsSettingsPage()
{
//    delete ui;
}

void QuickAccessorsSettingsPage::load() {
  // get all available buffer Ids
  QList<BufferId> allBufferIds = Client::networkModel()->allBufferIds();

  Client::networkModel()->sortBufferIds(allBufferIds);
  _config->initSetBufferList(allBufferIds);
  ui.quickAccessorsView->setFilteredModel(Client::bufferModel(), _config);

  setChangedState(false);
}

void QuickAccessorsSettingsPage::save() {

}

void QuickAccessorsSettingsPage::defaults() {

}
