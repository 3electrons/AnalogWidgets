    #include "led.h" 
    #include "led_plugin.h"     
    #include "defines.h"  
    /*------------------------------------------------------------------------------------------------
     *			     			MANOMETER    
     *------------------------------------------------------------------------------------------------*/
    
    
    LedPlugin::LedPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void LedPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool LedPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *LedPlugin::createWidget(QWidget *parent)
    {
        return new Led(parent);
    }

    QString LedPlugin::name() const
    {
        return QLatin1String("Led");
    }

    QString LedPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon LedPlugin::icon() const
    {
        return QIcon();
    }

    QString LedPlugin::toolTip() const
    {
        return QString();
    }

    QString LedPlugin::whatsThis() const
    {
        return QString();
    }

    bool LedPlugin::isContainer() const
    {
        return false;
    }

    QString LedPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"Led\" name=\"led\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>16</width>\n"
                             "   <height>16</height>\n"
                             "  </rect>\n"
                             " </property>\n"
                             " <property name=\"toolTip\" >\n"
                             "  <string>Color Led component</string>\n"
                             " </property>\n"
                             " <property name=\"whatsThis\" >\n"
                             "  <string>Led indicator</string>\n"
                             " </property>\n"
                             "</widget>\n");
    }

    QString LedPlugin::includeFile() const
    {
        return QLatin1String("analogwidgets/les/led.h");
    }

    QString LedPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS     
    Q_EXPORT_PLUGIN(LedPlugin)
#endif 
