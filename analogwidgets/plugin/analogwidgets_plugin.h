#ifndef ANALOGWIDGETS_PLUGIN_H
#define ANALOGWIDGETS_PLUGIN_H

#include <QtDesigner/QDesignerCustomWidgetCollectionInterface>
#include <QtCore/QList>

class AnalogWidgetsPlugin : public QObject, public QDesignerCustomWidgetCollectionInterface
{
  Q_OBJECT
  Q_INTERFACES (QDesignerCustomWidgetCollectionInterface)

  QList<QDesignerCustomWidgetInterface *> m_pluginList;

  public:
     AnalogWidgetsPlugin();
    ~AnalogWidgetsPlugin();

    QList<QDesignerCustomWidgetInterface *> customWidgets () const;

}; // AnalogWidgetPlugin

#endif // ANALOGWIDGETS_PLUGIN_H
