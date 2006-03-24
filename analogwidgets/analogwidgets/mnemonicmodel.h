#include <QAbstractListModel> 
#include <QStringList> 
#include <QVector> 
#include "mnemonicbox.h" 


/** Model reprezentuj±cy system mnemoników */ 
class MnemonicBoxModel: public QAbstractListModel 
{ 
  
  public:
   MnemonicBoxModel(QObject * parent = NULL); 
   
   int rowCount ( const QModelIndex & parent = QModelIndex() ) const ;
   QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
   QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
   int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
  
  /** Zwraca listê w³a¶ciwo¶ci które s± wy¶wietlane w modelu */
   QStringList properties(); 
  
  public slots:
  /** Ustawia now± listê w³a¶ciwo¶ci do wyswietlania */ 
   void setProperties(QStringList & properties); 
  
  
  protected:
   void init(); 
   QStringList  m_properties; 
   QVector<MnemonicBox *> m_mnemonics; 
  
};
