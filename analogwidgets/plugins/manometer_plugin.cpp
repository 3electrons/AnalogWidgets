    #include "manometer.h" 
    #include "manometer_plugin.h"     
    #include "../defines.h"  
    /*------------------------------------------------------------------------------------------------
     *			     			MANOMETER    
     *------------------------------------------------------------------------------------------------*/
    
    
    ManoMeterPlugin::ManoMeterPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void ManoMeterPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool ManoMeterPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *ManoMeterPlugin::createWidget(QWidget *parent)
    {
        return new ManoMeter(parent);
    }

    QString ManoMeterPlugin::name() const
    {
        return QLatin1String("ManoMeter");
    }

    QString ManoMeterPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon ManoMeterPlugin::icon() const
    {
        return QIcon();
    }

    QString ManoMeterPlugin::toolTip() const
    {
        return QString();
    }

    QString ManoMeterPlugin::whatsThis() const
    {
        return QString();
    }

    bool ManoMeterPlugin::isContainer() const
    {
        return false;
    }

    QString ManoMeterPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"ManoMeter\" name=\"manometer\">\n"
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

    QString ManoMeterPlugin::includeFile() const
    {
        return QLatin1String("analogwidgets/manometer/manometer.h");
    }

    QString ManoMeterPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS     
    Q_EXPORT_PLUGIN(ManoMeterPlugin)
#endif 
