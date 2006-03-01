#include <QtGui>
#include <cmath>


#include "chart.h"
#include "chart/standard/scalegriddecorator.h"
#include "chart/standard/glassdecorator.h"
#include "chart/standard/channeldecorator.h"
#include "chart/standard/legenddecorator.h"



//
//      public
//
Chart::Chart(QWidget *parent)
	: QMyWidgetWithBackground(parent)
{
   setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
   setWindowTitle(tr("Chart diagram"));
   m_channel=0;
   timer = new QTimer(this);
   timer->setInterval(1000);
   m_isPaintOver = false;
   connect(timer,SIGNAL(timeout()),this,SLOT(setPaintOver()));
   InitDecorators();
  // setChannel(1); 
   m_showLegend = true;
   m_zoom = 1.0; 
   m_xsize = m_scalegrid.size=1000.0; 

}

Chart::~Chart()
{
  if (timer) delete timer;
  timer = NULL;
}
void Chart::addChannel(Channel & channel)
{
  m_channels.push_back(channel);
  updateWithBackground();
}


//
//      private
//

void Chart::InitDecorators()
{
       m_painterDecorator.reset
	(
           new Standard::ScalesGridDecorator
          (
            new Standard::ChannelDecorator
		( new Standard::LegendDecorator(NULL) ) // new Standard::GlassDecorator(NULL)
          )
        );
}

void Chart::setPaintOver()
	{
          m_isPaintOver = true;
          timer->stop();
	  //cout<<"Uaktualniam"<<endl;
          update();
          // By malowalo normalnie wygladzone no chyba ze malujemy z duza czestoliwoscia ...
          m_isPaintOver = true; // kiedy ma byc malowane w antialiasingu jak czesto sie da ...

	}
void Chart::paintEvent(QPaintEvent * /*event */)
{
   //cout<<"paintEvent"<<endl;
   drawBackground();
   QPainter painter(this);
   //initCoordinateSystem(painter);
   if (m_painterDecorator.get()) m_painterDecorator->paint(painter,this);
   if (!m_isPaintOver) timer->start();
   m_isPaintOver = false;

}

void Chart::paintBackground(QPainter & painter)
{

   //initCoordinateSystem(painter);
   if (m_painterDecorator.get()) m_painterDecorator->paint(painter,this);
}

void Chart::initCoordinateSystem(QPainter & /*painter*/)
{
   	;

}

//***************************
//	Public Properties 
//***************************

// position 
int Chart::position()          const 	
{ 
  return static_cast<int>( m_scalegrid.pos );   
}

void Chart::setPosition(double i)
{
	m_scalegrid.pos=i; 
        update();
        positionChanged( i ); 
        positionChanged(static_cast<int> (i));  
}

void Chart::setPosition(int i)
{
   setPosition(static_cast<double>(i)); 
}

// size 
double Chart::size()           const	
{
  return m_xsize; 
}

void Chart::setSize(double i)
{
      	if (i>0.00001)
      	{
      	 m_xsize = i; 
      	 m_scalegrid.size=m_xsize*m_zoom;
	 update();
	}
	sizeChanged( i ); 
	sizeChanged( static_cast<int> (i)); 
}

void Chart::setSize(int i)
{
  setSize(static_cast<double>(i)); 
}

// ***** channelMinimum 
double Chart::channelMinimum() const   
{ 
  if (m_channels.size())
   return m_channels[m_channel].minimum();
  return 0.0; 
}

void Chart::setChannelMinimum(double i) 
{ 
  if (m_channels.size())
  {
    m_channels[m_channel].setMinimum(i);
    updateWithBackground(); 
  }
}

// ****** channelMaximum 
double Chart::channelMaximum() const   
{ 
  if (m_channels.size())
   return m_channels[m_channel].maximum();
  
  return 0.0; 
}
      	
void Chart::setChannelMaximum(double i) 
{
  if (m_channels.size())
  {
    m_channels[m_channel].setMaximum(i);  
    updateWithBackground(); 
  }
}

// ***** channel 
int Chart::channel()  const   
{ 
  return m_channel; 
}

void Chart::setChannel( int i)
{
	m_channel = i;
        if (m_channel >= m_channels.size())
        {
          m_channels.push_back(Channel());
          updateWithBackground();
        }
}

 

// channelColor
QColor Chart::channelColor()      const
{
  QColor C(255,255,255); 
  if (m_channels.size())
  C = m_channels[m_channel].pen().color();
 
  return C;
}

void Chart::setChannelColor( QColor i )
{
  if (m_channels.size())
   {
     m_channels[m_channel].pen().setColor(i);
     updateWithBackground(); 
   }
   
}

// ****** yMesh 
int Chart::yMesh()    const   { return m_scalegrid.m_yMesh;}

void Chart::setYMesh   ( int i) 
{  
  if (i>0)
  {
    m_scalegrid.m_yMesh = i;
    updateWithBackground(); 
  }
}

// ****** x Mesh 
int Chart::xMesh()    const   { return m_scalegrid.m_xMesh;}

void Chart::setXMesh   ( int i) 
{ 
  if (i>0)
  {
    m_scalegrid.m_xMesh = i; 
    updateWithBackground(); 
  }
}

// ****** ySubMesh 
 int Chart::ySubMesh() const   { return m_scalegrid.m_ySubMesh;}

void Chart::setYSubMesh( int i) 
{
   if (i>=0)
   {
     m_scalegrid.m_ySubMesh = i;
     updateWithBackground(); 
   }
}
// ****** xSubMesh 
int Chart::xSubMesh() const   { return m_scalegrid.m_xSubMesh;}

void Chart::setXSubMesh( int i) 
{ 
  if (i>=0)
  {
    m_scalegrid.m_xSubMesh = i; 
    updateWithBackground(); 
  }
}

// ***** channelShowScale 
bool Chart::channelShowScale() const	
{ 
 if (m_channels.size())
  return m_channels[m_channel].showScale(); 
  return false; 
}

void Chart::setChannelShowScale(bool i) 
{
   if (m_channels.size())
   { 
     m_channels[m_channel].setShowScale(i);
     updateWithBackground(); 
   }
}

// ***** channelName 
QString Chart::channelName () const
{
  QString name; 
  if (m_channels.size())
    name = m_channels[m_channel].name() ; 
  return name ;
}

void Chart::setChannelName (QString i) 
{
  if (m_channels.size())
  {
    m_channels[m_channel].setName(i); 
    update(); 
  }
}
// ***** showScale 
bool Chart::showScale()        const	{ return m_scalegrid.showScale;}

void Chart::setShowScale(bool i) 
{
   m_scalegrid.showScale = i; 
   updateWithBackground(); 
}

// ****** showLegend 
bool Chart::showLegend()       const    { return m_showLegend; } 

void Chart::setShowLegend(bool i)
{
  m_showLegend = i;
  updateWithBackground(); 
}

// ****** showGrid 
bool Chart::showGrid()         const	{ return m_scalegrid.showGrid; }

void Chart::setShowGrid(bool i) 
{ 
  m_scalegrid.showGrid = i;
  updateWithBackground();  
}

// ***** zoom 
double Chart::zoom()	       const
{
  return m_zoom; 
}

void Chart::setZoom(double factor)
{
  if (fabs(factor)>0.01)
  {
    m_zoom = factor;
    m_scalegrid.size = m_xsize*m_zoom; 
    update();
  }
}

// Zas³ania setFont QWidget by mo¿na by³o od¶wie¿yæ ca³y komponent 
void Chart::setFont(QFont i) 
{ 
   QWidget::setFont(i);
   updateWithBackground(); 
}

// Ustawia koniec malowania i nastêpuje malownie z antialiasingiem 
bool Chart::isPaintOver()      const    { return m_isPaintOver; }




