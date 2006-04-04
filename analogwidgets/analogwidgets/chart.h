#ifndef CHART_H
#define CHART_H

#include <vector>
#include <memory> // auto_ptr
#include <QTimer>
#include <QPen> 
#include <QMenu> 

#include "qmywidgetwithbackground.h"

#include "chart/channel.h"
#include "chart/scalegrid.h"
#include "chart/chartdecorator.h"


using namespace std;
using namespace chart;
typedef  vector<chart::Channel> Channels;

    class Chart :  public QMyWidgetWithBackground
    	{
      Q_OBJECT
      Q_PROPERTY (int channel     	 	READ channel      WRITE setChannel   )
      Q_PROPERTY (int position  		READ position     WRITE setPosition  )
      Q_PROPERTY (double size     		READ size         WRITE setSize      )
      Q_PROPERTY (double zoom			READ zoom         WRITE setZoom      ) 

      Q_PROPERTY ( int xMesh        READ xMesh        WRITE setXMesh         )
      Q_PROPERTY ( int yMesh        READ yMesh        WRITE setYMesh         )
      Q_PROPERTY ( int xSubMesh     READ xSubMesh     WRITE setXSubMesh      )
      Q_PROPERTY ( int ySubMesh     READ ySubMesh     WRITE setYSubMesh      )

 // Dot±d jest przetestowane 

      Q_PROPERTY (double channelMinimum    READ channelMinimum   WRITE setChannelMinimum    )
      Q_PROPERTY (double channelMaximum    READ channelMaximum   WRITE setChannelMaximum    )
      Q_PROPERTY (bool   channelShowScale  READ channelShowScale WRITE setChannelShowScale  )
      Q_PROPERTY (QColor channelColor	   READ channelColor     WRITE setChannelColor      )   
      Q_PROPERTY (QString channelName      READ channelName      WRITE setChannelName	    )
     // Q_PROPERTY (QFont  scaleFont              READ scaleFont  WRITE setScaleFont  )
      Q_PROPERTY (bool   showGrid	        READ showGrid   WRITE setShowGrid   )
      Q_PROPERTY (bool   showScale   		READ showScale  WRITE setShowScale  )
      Q_PROPERTY (bool   showLegend   		READ showLegend WRITE setShowLegend )
      
      // Z w³a¶ciwo¶ci QWidget 
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

        int position()          const; 	
	double size()           const;	
      	double channelMinimum() const;   
      	double channelMaximum() const;   
        QColor channelColor()   const; 
        QString channelName()   const; 
        
       
        double zoom()		const; 

         int channel()  const;   
      	 int yMesh()    const;
       	 int xMesh()    const;
      	 int ySubMesh() const;
       	 int xSubMesh() const;

	bool showGrid()         const;
	bool isPaintOver()      const;
      	bool channelShowScale() const;
      	bool showScale()        const;
      	bool showLegend()       const; 

     	/** Buduje zwyk³e menu */ 
      	QMenu * contextMenu(); 

	
	//QFont scaleFont()       const;

      	public slots:
      	/**
      	* Ustawia pozycje na wykresie na osi X
      	* param i Nowa pozycja na wykresie pozycja to najmnijesza wartosc
      	* wskazywana na wykresie
      	*/
      	void setPosition      (double i);
      	void setPosition      (int i); 
	void setSize          (double i);
	void setSize 	      (int i); 
	
      	void setChannelMinimum(double i); 
      	void setChannelMaximum(double i); 
        void setChannelColor  (QColor i);
        void setChannelName   (QString i); 
        
        
        void setChannel ( int i);
  	void setYMesh   ( int i); 
     	void setXMesh   ( int i); 
   	void setYSubMesh( int i); 
      	void setXSubMesh( int i); 

      	void setChannelShowScale(bool i); 
      	void setShowScale       (bool i); 
        void setShowGrid        (bool i); 
	void setShowLegend      (bool i);
	
	// Zaslania ustawianie fontu QWidget 
	// i odmalowywuje wszystko od nowa 
	void setFont       (QFont i);	 
	

      	/**
      	* Powieksza/pomniejsza widok na osi x
      	* @param factor Wspó³czynnik powiêkszenia
      	*/
      	void setZoom(double factor);

	signals: 
	void sizeChanged(int i); 
	void sizeChanged(double i); 
	void positionChanged(int i); 
	void positionChanged(double i); 
	
                
	protected slots:



	/** Ustawia znacznik koñca malowania i przmalowuje kontrolkê w trybie z antialiasingiem */
	void setPaintOver();


        /** Wywo³ana zosta³a konkretna akcja z menu */ 
        void contextMenuActionTriggered(QAction * a);

      	protected:
      	//////////// E V E N T S /////////////
      	/** Wywo³anie menu kontekstowego */ 
      	void contextMenuEvent ( QContextMenuEvent * e );
      	
      	/** Ruch mysz± */ 
      	void mouseMoveEvent ( QMouseEvent * e ); 
      	
      	
	/** Informacje na temat skali oraz siatki wykresu */
	ScaleGrid m_scalegrid;
	/** Pointer do pierwszego dekoratora do malowania wykresu */
	auto_ptr<ChartDecorator> m_painterDecorator;

      	/** Wektor kana³ów na dane */
      	Channels m_channels;
      	unsigned int m_channel;
        /** Timer który po okre¶lonym czasie ma uaktualniæ obraz na wyg³adzony (antialiasing) */
	QTimer * timer;

        /** Czy pokazywaæ legendê */
        bool m_showLegend; 
        
        /* Warto¶æ zoom oraz m_xsize po wymono¿enu daj± warto¶æ m_scalegrid.size 
        * W ten sposób ³atwo mo¿na sterowaæ zoomem z zewn±trz */ 
        
        /** Warto¶æ zoom */
        double m_zoom;
        /** Wielko¶æ osi X - to warto¶æ nie zmienna */
        double m_xsize;
        bool m_isPaintOver;
      	// Drawing data
      	//QMatrix baseMatrix;
    };
#endif // CHART_H
