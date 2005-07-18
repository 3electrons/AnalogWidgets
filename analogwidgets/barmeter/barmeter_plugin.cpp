    #include "barmeter.h" 
    #include "barmeter_plugin.h"     
    #include "../defines.h"  
    /*------------------------------------------------------------------------------------------------
     *			     			BARMETER    
     *------------------------------------------------------------------------------------------------*/
    
    
    BarMeterPlugin::BarMeterPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void BarMeterPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool BarMeterPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *BarMeterPlugin::createWidget(QWidget *parent)
    {
        return new BarMeter(parent);
    }

    QString BarMeterPlugin::name() const
    {
        return QLatin1String("BarMeter");
    }

    QString BarMeterPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon BarMeterPlugin::icon() const
    {
        return QIcon();
    }

    QString BarMeterPlugin::toolTip() const
    {
        return QString();
    }

    QString BarMeterPlugin::whatsThis() const
    {
        return QString();
    }

    bool BarMeterPlugin::isContainer() const
    {
        return false;
    }

    QString BarMeterPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"BarMeter\" name=\"BarMeter\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>100</width>\n"
                             "   <height>100</height>\n"
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

    QString BarMeterPlugin::includeFile() const
    {
        return QLatin1String("BarMeter.h");
    }

    QString BarMeterPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS     
    Q_EXPORT_PLUGIN(BarMeterPlugin)
#endif 
