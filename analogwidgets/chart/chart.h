#ifndef CHART_H
#define CHART_H

#include <vector>
#include <memory> // auto_ptr

#include "qmywidgetwithbackground.h"
#include "channel.h"
#include "scalegrid.h"
#include "chartdecorator.h"


using namespace std;
using namespace chart;

    class Chart : public QMyWidgetWithBackground
    {
      Q_OBJECT
      Q_PROPERTY (unsigned int channel      READ channel      WRITE setChannel       )
      /*
      Q_PROPERTY (double channelXMinimum    READ chXMinimum   WRITE setChXMinimum    )
      Q_PROPERTY (double channelXMaximum    READ chXMaximum   WRITE setChXMaximum    )
      Q_PROPERTY (bool   channelShowXScale  READ chShowXScale WRITE setChShowXScale  )


      Q_PROPERTY (double channelYMinimum    READ chYMinimum   WRITE setChYMinimum    )
      Q_PROPERTY (double channelYMaximum    READ chYMaximum   WRITE setChYMaximum    )
      Q_PROPERTY (bool   channelShowYScale  READ chShowYScale WRITE setChShowYScale  )

      Q_PROPERTY (QColor  channelColor 	    READ chColor        WRITE setChColor     )
      Q_PROPERTY (double  channelLineWidth  READ chLineWidth    WRITE setChLineWidth )

      Q_PROPERTY (unsigned int xGrid        READ xGrid        WRITE setYGrid         )
      Q_PROPERTY (unsigned int yGrid        READ yGrid        WRITE setXGrid         )
      Q_PROPERTY (QFont font                READ font         WRITE setFont          )
      */

      public:
    	Chart(QWidget *parent = 0);


      protected:
        void paintEvent(QPaintEvent *event); 	 // inherited from QMyWidgetWithBackground
	void paintBackground(QPainter & painter);// inherited form QMyWidgetWithBackground
	void initCoordinateSystem(QPainter & painter);

	/** Metoda ta ma za zadanie zainicjalizowa� wszystkie dekoratory wykresu - normalnie powinna zbudowa�
        * ca�� struktur� dekorator�w na podstawie infomracji z plugin�w lub innych �r�de� ...
        */
	void InitDecorators();

	// accesors and getters
        unsigned int channel() const
        		{ return m_channel; }
        void setChannel(unsigned int i)
        		{ m_channel = i;
        		  if (m_channel > m_channels.size())
        		       m_channels.push_back(Channel());
        		}

	/*
      	unsigned int yGrid() const
      			{ return m_yGrid;}
   	void setYGrid(unsigned int i)
   			{ m_yGrid = i;updateWithBackground(); }

       	unsigned int xGrid() const
       			{ return m_xGrid;}
      	void setXGrid(unsigned int i)
      			{ m_xGrid = i; updateWithBackground(); }

        // Channel Y
      	double chYMinimum() const
      			{ return m_Ychannels[m_channel].minimum;}
      	void setChYMinimum(double i)
      			{ m_Ychannels[m_channel].minimum = i; updateWithBackground(); }


      	double chYMaximum() const
      			{ return m_Ychannels[m_channel].maximum;}
      	void setChYMaximum(double i)
      			{ m_Ychannels[m_channel].maximum = i; updateWithBackground(); }

      	bool chShowYScale() const
      			{ return m_Ychannels[m_channel].showScale; }
      	void setChShowYScale(bool i)
      			{ m_Ychannels[m_channel].showScale = i; updateWithBackground(); }
      	// Channel X

      	double chXMinimum() const
      			{ return m_Xchannel.minimum;}
      	void setChXMinimum(double i)
      			{ m_Xchannel.minimum = i; updateWithBackground(); }

      	double chXMaximum() const
      			{ return m_Xchannel.maximum;}
      	void setChXMaximum(double i)
      			{ m_Xchannel.maximum = i; updateWithBackground(); }

      	bool chShowXScale() const
      			{ return m_Xchannel.showScale;}
      	void setChShowXScale(bool i)
      			{ m_Xchannel.showScale = i; updateWithBackground(); }

      	QColor chColor() const
      			{ return m_Ychannels[m_channel].color; }
      	void setChColor(QColor color)
      			{ m_Ychannels[m_channel].color = color; updateWithBackground(); }
      	double chLineWidth() const
      			{ return m_Ychannels[m_channel].lineWidth; }
      	void setChLineWidth(double i)
      			{ m_Ychannels[m_channel].lineWidth = i; updateWithBackground(); }

	QFont font() const
			{ return m_font; }
	void setFont(QFont i)
			{ m_font = i; updateWithBackground(); }

	*/
      	// Pola w�a�ciwo�ci.
      	protected:
	/** Informacje na temat skali oraz siatki wykresu */
	ScaleGrid m_scalegrid;
	/** Pointer do pierwszego dekoratora do malowania wykresu */
	auto_ptr<ChartDecorator> m_painterDecorator;

      	/** Wektor kana��w na dane */
      	vector<Channel> m_channels;
      	unsigned int m_channel;


      	// Drawing data
      	//QMatrix baseMatrix;
    };
#endif // CHART_H
