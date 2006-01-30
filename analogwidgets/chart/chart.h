#ifndef CHART_H
#define CHART_H

#include <vector>
#include <memory> // auto_ptr
#include <QTimer>

#include "qmywidgetwithbackground.h"
#include "channel.h"
#include "scalegrid.h"
#include "chartdecorator.h"


using namespace std;
using namespace chart;

typedef  vector<Channel> Channels;

    class Chart : public QMyWidgetWithBackground
    {
      Q_OBJECT

      Q_PROPERTY (unsigned int channel      	READ channel      WRITE setChannel   )
      Q_PROPERTY (double position 		READ position     WRITE setPosition  )
      Q_PROPERTY (double size     		READ size         WRITE setSize      )

      Q_PROPERTY (unsigned int xMesh        READ xMesh        WRITE setYMesh         )
      Q_PROPERTY (unsigned int yMesh        READ yMesh        WRITE setXMesh         )
      Q_PROPERTY (unsigned int xSubMesh     READ xSubMesh     WRITE setYSubMesh      )
      Q_PROPERTY (unsigned int ySubMesh     READ ySubMesh     WRITE setXSubMesh      )



      Q_PROPERTY (double channelMinimum    READ channelMinimum   WRITE setChannelMinimum     )
      Q_PROPERTY (double channelMaximum    READ channelMaximum   WRITE setChannelMaximum    )
      Q_PROPERTY (bool   channelShowScale  READ channelShowScale WRITE setChannelShowScale  )


      Q_PROPERTY (QFont  scaleFont              READ scaleFont WRITE setScaleFont  )
      Q_PROPERTY (bool   showGrid	        READ showGrid  WRITE setShowGrid   )
      Q_PROPERTY (bool   showScale   		READ showScale WRITE setShowScale  )


      Q_PROPERTY (unsigned int xMesh        READ xMesh        WRITE setYMesh         )
      Q_PROPERTY (unsigned int yMesh        READ yMesh        WRITE setXMesh         )
      Q_PROPERTY (QFont font                READ font         WRITE setFont          )


      public:
    	Chart(QWidget *parent = 0);
	~Chart();

	 ScaleGrid & scaleGrid() { return m_scalegrid; } // @TODO to by by³o dobrze wywalic lub przenie¶æ do cze¶ci prywatnej
	 Channels & channels() { return m_channels; } // @TODO to by by³o dobrze wywaliæ

	 /** Dodaje kana³ z danymi */
	 void addChannel(Channel & channel);

      protected:
        void paintEvent(QPaintEvent *event); 	 // inherited from QMyWidgetWithBackground
	void paintBackground(QPainter & painter);// inherited form QMyWidgetWithBackground
	void initCoordinateSystem(QPainter & painter);

	/** Metoda ta ma za zadanie zainicjalizowaæ wszystkie dekoratory wykresu - normalnie powinna zbudowaæ
        * ca³± strukturê dekoratorów na podstawie infomracji z pluginów lub innych ¼róde³ ...
        */
	void InitDecorators();

	// accesors and getters
      public:

        double position()       const 	{ return m_scalegrid.pos;   }
	double size()           const	{ return m_scalegrid.size; }
      	double channelMinimum() const   { return m_channels[m_channel].min;}
      	double channelMaximum() const   { return m_channels[m_channel].max;}

        unsigned int channel()  const   { return m_channel; }
      	unsigned int yMesh()    const   { return m_scalegrid.m_yMesh;}
       	unsigned int xMesh()    const   { return m_scalegrid.m_xMesh;}
      	unsigned int ySubMesh() const   { return m_scalegrid.m_ySubMesh;}
       	unsigned int xSubMesh() const   { return m_scalegrid.m_xMesh;}

	bool showGrid()         const	{ return m_scalegrid.showGrid; }
	bool isPaintOver()      const   { return m_isPaintOver; }
      	bool channelShowScale() const	{ return m_channels[m_channel].showScale; }
      	bool showScale()        const	{ return m_scalegrid.showScale;}

	QFont scaleFont()       const	{ return m_scalegrid.m_font; }




      	public slots:
      	/**
      	* Ustawia pozycje na wykresie na osi X
      	* param i Nowa pozycja na wykresie pozycja to najmnijesza wartosc
      	* wskazywana na wykresie
      	*/
      	void setPosition      (double i);
	void setSize          (double i);
      	void setChannelMinimum(double i) { m_channels[m_channel].min = i; updateWithBackground(); }
      	void setChannelMaximum(double i) { m_channels[m_channel].max = i; updateWithBackground(); }

        void setChannel (unsigned int i);
  	void setYMesh   (unsigned int i) { m_scalegrid.m_yMesh = i;updateWithBackground(); }
     	void setXMesh   (unsigned int i) { m_scalegrid.m_xMesh = i; updateWithBackground(); }
   	void setYSubMesh(unsigned int i) { m_scalegrid.m_ySubMesh = i;updateWithBackground(); }
      	void setXSubMesh(unsigned int i) { m_scalegrid.m_xSubMesh = i; updateWithBackground(); }

      	void setChannelShowScale(bool i) { m_channels[m_channel].showScale = i; updateWithBackground(); }
      	void setShowScale       (bool i) { m_scalegrid.showScale = i; updateWithBackground(); }
        void setShowGrid        (bool i) { m_scalegrid.showGrid = i; }
	void setScaleFont(QFont i)	 { m_scalegrid.m_font = i; updateWithBackground(); }




      	/**
      	* Powieksza/pomniejsza widok na osi x
      	* @param factor Wspó³czynnik powiêkszenia
      	*/
      	void zoom(double factor);


	protected slots:

	/** Ustawia znacznik koñca malowania i przmalowuje kontrolkê w trybie z antialiasingiem */
	void setPaintOver();


      	protected:
	/** Informacje na temat skali oraz siatki wykresu */
	ScaleGrid m_scalegrid;
	/** Pointer do pierwszego dekoratora do malowania wykresu */
	auto_ptr<ChartDecorator> m_painterDecorator;

      	/** Wektor kana³ów na dane */
      	Channels m_channels;
      	unsigned int m_channel;
        /** Timer który po okre¶lonym czasie ma uaktualniæ obraz na wyg³adzony (antialiasing) */
	QTimer * timer;

        bool m_isPaintOver;
      	// Drawing data
      	//QMatrix baseMatrix;
    };
#endif // CHART_H
