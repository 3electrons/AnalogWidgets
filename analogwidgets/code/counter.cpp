#include <QPainter> 
#include <QPen>
#include <QSvgRenderer> 
#include "counter.h" 


Counter::Counter (QWidget * parent):QWidget(parent)
{
  init();
}

int Counter::digits() const
{
  return m_digits;
}

int Counter::value() const
{
  return m_value; 
}

const QString Counter::digitsFile() const
{
  return m_digitsFile; 
}

/*--------------------------------------------------------------------------------------------
			      P U B L I C   S L O T S 
--------------------------------------------------------------------------------------------*/
void Counter::setValue(int i) 
{
   m_value = i; 
   update();
}

void Counter::setDigits(int i)
{
  m_digits = i; 
  update(); 
}

void Counter::setDigitsFile(const QString & i )
{
   m_digitsFile = i;
   delete m_svg; 
   m_svg = new QSvgRenderer(this); 
   if (!m_svg->load(i)) 
   {
     m_digitsFile = ":/default/resources/train_digits.svg"; 
     m_svg->load(m_digitsFile);
     update(); 
   }
}

/*--------------------------------------------------------------------------------------------
				  P R O T E C T E D 
--------------------------------------------------------------------------------------------*/
#define X_OFFSET 10
#define Y_OFFSET 10

void Counter::paintEvent (QPaintEvent *)
{
  QPainter p(this); 
  p.setRenderHint(QPainter::Antialiasing,true); 
  
  p.save(); 
  int side = this->height();
  p.scale(side/100.0,side/100.0);

  double width = 100.0 * this->width()/this->height(), height = 100.0; 


  //p.setPen(Qt::NoPen); 
  QPen pen = p.pen(); 
  
  pen.setColor(QColor(32,32,32));
  pen.setWidthF(6.0); 
  p.setPen(pen);
  p.setBrush(Qt::black);
  p.drawRoundRect(3,3,width-6,height-6,7,(7*width)/(double)height);


  int w = (width-2*X_OFFSET)/m_digits; 
  int x = (m_digits-1) * w; 
  int h = height-2*Y_OFFSET; 
  int r, c = m_value; 

	for (int i=0 ; i<m_digits ; i++) 
	{
	  r = c % 10; 
	  c = c/10; 
	  QRect rect(x+X_OFFSET,Y_OFFSET,w,h); 
	  m_svg->render(&p,QString("d%1").arg(r),rect); 
	  x -= w; 
	} 
  p.restore(); 
}


void Counter::init()
{  
   Q_INIT_RESOURCE(analogwidgets); 
   m_digits = 4; 
   m_value = 0; 
   m_svg = new QSvgRenderer(this);
   setDigitsFile("");
}
