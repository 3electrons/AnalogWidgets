#include "mnemonicmodel.h" 
#include "comm/engine.h" // z Bartkom/src/comm/

MnemonicBoxModel::MnemonicBoxModel(QObject * parent):QAbstractListModel(parent)
{
  init();  
}

int MnemonicBoxModel::rowCount ( const QModelIndex & parent  ) const 
{
  if (parent.isValid())
    return 0; 
  else 
    return m_mnemonics.size(); 
}

QVariant MnemonicBoxModel::data ( const QModelIndex & index, int role  ) const
{
  if (!index.isValid())
        return QVariant();
  
  if ( Qt::ToolTipRole == role ) 
     return ( m_mnemonics[index.row()]->bridge()->property("description") ).c_str(); 
     
  
  if ( Qt::DisplayRole == role )
   {   
    string property,value; 
    property = m_properties[index.column()].toLocal8Bit().data(); 
    value = m_mnemonics[index.row()]->bridge()->property(property); 
    return value.c_str(); 
   }
  return QVariant();
}

QVariant MnemonicBoxModel::headerData ( int section, Qt::Orientation orientation, int role  ) const
{
  // Zwraca nazwy nag³ówków ?? 
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
      return m_properties[section]; 
     
          
  return QVariant();
}

int MnemonicBoxModel::columnCount ( const QModelIndex & parent  ) const
{
  if (parent.isValid()) return 0; 
   else return m_properties.size();   
}

void MnemonicBoxModel::init()
{
    mnemonic_map::iterator i = MnemonicBox::widgets.begin(); 
    while (i!=MnemonicBox::widgets.end())
      m_mnemonics.push_back(*i++); 
    
    m_properties.push_back("name"); 
    m_properties.push_back("type"); 
    m_properties.push_back("value"); 
    m_properties.push_back("register"); 
    m_properties.push_back("min"); 
    m_properties.push_back("max"); 
    m_properties.push_back("default");     
} 

QStringList MnemonicBoxModel::properties()
{
  return m_properties; 
}

void MnemonicBoxModel::setProperties( QStringList & properties )
{
  m_properties = properties;
}
