#ifndef TEST_H 
#define TEST_H 
#include "ui_testform.h" 

#include <QMainWindow>
    class BarMeter; 
          
    class TestWidget : public QMainWindow,  private Ui::TestForm
    {
    	Q_OBJECT 
    public:
        TestWidget(QMainWindow *parent = 0);
        /** Inicjuje podstawow� geometri� oraz komponenty na formie */ 
        void initialize();
        /** Generuje p��czenia pomi�dzy sygna�ami i slotami */ 
        void connections(); 
    public slots: 
    	void ComboBoxChoiceChanged(int index ); 
        void SpinBoxValueChanged(int val); 
    private:
	/** Gdy zamykane jest okno */ 
	void closeEvent ( QCloseEvent * e );
	// Potencjometr 
	BarMeter * bar; 
    };

   
    
    
    
#endif // TEST_H
