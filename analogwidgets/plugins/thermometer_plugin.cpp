    #include "thermometer.h"
    #include "thermometer_plugin.h"
    #include "defines.h"
    /*------------------------------------------------------------------------------------------------
     *			     			MANOMETER
     *------------------------------------------------------------------------------------------------*/


    ThermoMeterPlugin::ThermoMeterPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void ThermoMeterPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool ThermoMeterPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *ThermoMeterPlugin::createWidget(QWidget *parent)
    {
        return new ThermoMeter(parent);
    }

    QString ThermoMeterPlugin::name() const
    {
        return QLatin1String("ThermoMeter");
    }

    QString ThermoMeterPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon ThermoMeterPlugin::icon() const
    {
        return QIcon();
    }

    QString ThermoMeterPlugin::toolTip() const
    {
        return QString();
    }

    QString ThermoMeterPlugin::whatsThis() const
    {
        return QString();
    }

    bool ThermoMeterPlugin::isContainer() const
    {
        return false;
    }

    QString ThermoMeterPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"ThermoMeter\" name=\"thermometer\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>40</width>\n"
                             "   <height>160</height>\n"
                             "  </rect>\n"
                             " </property>\n"
                             " <property name=\"toolTip\" >\n"
                             "  <string>Shows the pressure</string>\n"
                             " </property>\n"
                             " <property name=\"whatsThis\" >\n"
                             "  <string>The bar meter widget displays "
                             "the pressure attached to it</string>\n"
                             " </property>\n"
                             "</widget>\n");
    }

    QString ThermoMeterPlugin::includeFile() const
    {
        return QLatin1String("analogwidgets/thermometer.h");
    }

    QString ThermoMeterPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS
    Q_EXPORT_PLUGIN(ThermoMeterPlugin)
#endif
