    #include "bitmapbutton.h"
    #include "bitmapbutton_plugin.h" 
    #include "defines.h" 
    /*------------------------------------------------------------------------------------------------
     *			     			WALLCLCOCK    
     *------------------------------------------------------------------------------------------------*/

    BitmapButtonPlugin::BitmapButtonPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void BitmapButtonPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool BitmapButtonPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *BitmapButtonPlugin::createWidget(QWidget *parent)
    {
        return new BitmapButton(parent);
    }

    QString BitmapButtonPlugin::name() const
    {
        return QLatin1String("BitmapButton");
    }

    QString BitmapButtonPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon BitmapButtonPlugin::icon() const
    {
        return QIcon();
    }

    QString BitmapButtonPlugin::toolTip() const
    {
        return QString();
    }

    QString BitmapButtonPlugin::whatsThis() const
    {
        return QString();
    }

    bool BitmapButtonPlugin::isContainer() const
    {
        return false;
    }

    QString BitmapButtonPlugin::domXml() const
    {
        return QLatin1String("<widget class=\"BitmapButton\" name=\"wallclock\">\n"
                             " <property name=\"geometry\">\n"
                             "  <rect>\n"
                             "   <x>0</x>\n"
                             "   <y>0</y>\n"
                             "   <width>64</width>\n"
                             "   <height>64</height>\n"
                             "  </rect>\n"
                             " </property>\n"
                             " <property name=\"toolTip\" >\n"
                             "  <string></string>\n"
                             " </property>\n"
                             " <property name=\"whatsThis\" >\n"
                             "  <string>"
                             "</string>\n"
                             " </property>\n"
                             "</widget>\n");
    }

    QString BitmapButtonPlugin::includeFile() const
    {
        return QLatin1String("analogwidgets/bitmapbutton.h");
    }

    QString BitmapButtonPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS
    Q_EXPORT_PLUGIN(BitmapButtonPlugin)
#endif // SINGLEPLUGINS  
