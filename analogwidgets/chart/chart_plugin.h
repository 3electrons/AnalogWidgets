    #include <QtDesigner/QDesignerContainerExtension>
    #include <QtDesigner/QDesignerCustomWidgetInterface>
    #include <QtCore/qplugin.h>
    #include <QtGui/QIcon>
   
    class ChartPlugin : public QObject, public QDesignerCustomWidgetInterface
    {
        Q_OBJECT
        Q_INTERFACES(QDesignerCustomWidgetInterface)
    public:
        ChartPlugin(QObject *parent = 0);
        bool isContainer() const;
        bool isInitialized() const;
        QIcon icon() const;
        QString codeTemplate() const;
        QString domXml() const;
        QString group() const;
        QString includeFile() const;
        QString name() const;
        QString toolTip() const;
        QString whatsThis() const;
        QWidget *createWidget(QWidget *parent);
        void initialize(QDesignerFormEditorInterface *core);

    private:
        bool initialized;
    };
