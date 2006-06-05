#include "analogwidgets_plugin.h"
#include "defines.h"

#include "wallclock_plugin.h"
#include "manometer_plugin.h"
#include "thermometer_plugin.h" 
#include "chart_plugin.h" 
//#include "wheel/wheel_plugin.h"
//#include "mnemonicbox_plugin.h" 
#include "led_plugin.h" 

AnalogWidgetsPlugin::AnalogWidgetsPlugin()
{
  m_pluginList.push_back(new WallClockPlugin(NULL));
  m_pluginList.push_back(new ManoMeterPlugin(NULL));
  m_pluginList.push_back(new ThermoMeterPlugin(NULL));
  m_pluginList.push_back(new ChartPlugin(NULL)); 
  m_pluginList.push_back(new LedPlugin(NULL)); 
 // m_pluginList.push_back(new WheelPlugin(NULL)); 
 // m_pluginList.push_back(new MnemonicBoxPlugin(NULL)); 
  
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
