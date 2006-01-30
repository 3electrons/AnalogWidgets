    #include "chart.h"
    #include "chart_plugin.h"
    #include "../defines.h"
    #include <iostream>
    using namespace std;
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

    QWidget * ChartPlugin::createWidget(QWidget *parent)
    {
      cout<<"New Komponent"<<endl;
      return new Chart(parent);
    }

    QString ChartPlugin::name() const
    {
        cout<<"name()"<<endl;
        return QLatin1String("Chart");
    }

    QString ChartPlugin::group() const
    {
        cout<<"group()"<<endl;
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
       cout<<"isContainer()"<<endl;
       return false;
    }

    QString ChartPlugin::domXml() const
    {
        cout<<"domXml()"<<endl;
	 return QLatin1String("<widget class=\"Chart\" name=\"Chart\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>300</width>\n"
                             "   <height>200</height>\n"
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
       cout<<"includeFile()"<<endl;
       return QLatin1String("chart.h");
    }

    QString ChartPlugin::codeTemplate() const
    {
        cout<<"codeTemplate()"<<endl;
        return QString();
    }

#ifdef SINGLEPLUGINS
    Q_EXPORT_PLUGIN(ChartPlugin)
#endif
