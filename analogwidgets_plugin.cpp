#include "analogwidgets_plugin.h"
#include "defines.h"

#include "wallclock/wallclock_plugin.h"
#include "barmeter/barmeter_plugin.h"

AnalogWidgetsPlugin::AnalogWidgetsPlugin()
{
  m_pluginList.push_back(new WallClockPlugin(NULL));
  m_pluginList.push_back(new BarMeterPlugin(NULL));
}

AnalogWidgetsPlugin::~AnalogWidgetsPlugin()
{
  QList<QDesignerCustomWidgetInterface *>::Iterator i = m_pluginList.begin();
  while (i != m_pluginList.end())
  delete *i++;
  m_pluginList.clear();
}

QList<QDesignerCustomWidgetInterface *>
AnalogWidgetsPlugin:: customWidgets() const
{
  return m_pluginList;
}

#ifndef SINGLEPLUGINS
Q_EXPORT_PLUGIN(AnalogWidgetsPlugin)
#endif
