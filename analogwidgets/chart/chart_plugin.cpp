    #include "chart.h" 
    #include "chart_plugin.h"     
    #include "../defines.h"  
    /*------------------------------------------------------------------------------------------------
     *			     			CHART  
     *------------------------------------------------------------------------------------------------*/
    
    ChartPlugin::ChartPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void ChartPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool ChartPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *ChartPlugin::createWidget(QWidget *parent)
    {
        return new Chart(parent);
    }

    QString ChartPlugin::name() const
    {
        return QLatin1String("Chart");
    }

    QString ChartPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon ChartPlugin::icon() const
    {
        return QIcon();
    }

    QString ChartPlugin::toolTip() const
    {
        return QString();
    }

    QString ChartPlugin::whatsThis() const
    {
        return QString();
    }

    bool ChartPlugin::isContainer() const
    {
        return false;
    }

    QString ChartPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"Chart\" name=\"Chart\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>150</width>\n"
                             "   <height>100</height>\n"
                             "  </rect>\n"
                             " </property>\n"
                             " <property name=\"toolTip\" >\n"
                             "  <string>Draws an charts</string>\n"
                             " </property>\n"
                             " <property name=\"whatsThis\" >\n"
                             "  <string>The chart draws "
                             "time diagrams</string>\n"
                             " </property>\n"
                             "</widget>\n");
    }

    QString ChartPlugin::includeFile() const
    {
        return QLatin1String("chart.h");
    }

    QString ChartPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS     
    Q_EXPORT_PLUGIN(ChartPlugin)
#endif 
