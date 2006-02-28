    #include "wallclock.h"
    #include "wallclock_plugin.h" 
    #include "defines.h" 
    /*------------------------------------------------------------------------------------------------
     *			     			WALLCLCOCK    
     *------------------------------------------------------------------------------------------------*/

    WallClockPlugin::WallClockPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void WallClockPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool WallClockPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *WallClockPlugin::createWidget(QWidget *parent)
    {
        return new WallClock(parent);
    }

    QString WallClockPlugin::name() const
    {
        return QLatin1String("WallClock");
    }

    QString WallClockPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon WallClockPlugin::icon() const
    {
        return QIcon();
    }

    QString WallClockPlugin::toolTip() const
    {
        return QString();
    }

    QString WallClockPlugin::whatsThis() const
    {
        return QString();
    }

    bool WallClockPlugin::isContainer() const
    {
        return false;
    }

    QString WallClockPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"WallClock\" name=\"wallclock\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>100</width>\n"
                             "   <height>100</height>\n"
                             "  </rect>\n"
                             " </property>\n"
                             " <property name=\"toolTip\" >\n"
                             "  <string>The current time and date</string>\n"
                             " </property>\n"
                             " <property name=\"whatsThis\" >\n"
                             "  <string>The analog clock widget displays "
                             "the current time and date.</string>\n"
                             " </property>\n"
                             "</widget>\n");
    }

    QString WallClockPlugin::includeFile() const
    {
        return QLatin1String("analogwidgets/wallclock.h");
    }

    QString WallClockPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS
    Q_EXPORT_PLUGIN(WallClockPlugin)
#endif // SINGLEPLUGINS  
