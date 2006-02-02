#include "analogwidgets_plugin.h"
#include "defines.h"

#include "wallclock/wallclock_plugin.h"
#include "manometer/manometer_plugin.h"
#include "thermometer/thermometer_plugin.h" 
#include "chart/chart_plugin.h" 
#include "mnemonics/mnemonicbox_plugin.h" 

AnalogWidgetsPlugin::AnalogWidgetsPlugin()
{
  m_pluginList.push_back(new WallClockPlugin(NULL));
  m_pluginList.push_back(new ManoMeterPlugin(NULL));
  m_pluginList.push_back(new ThermoMeterPlugin(NULL));
  m_pluginList.push_back(new ChartPlugin(NULL)); 
  m_pluginList.push_back(new MnemonicBoxPlugin(NULL)); 
  
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
