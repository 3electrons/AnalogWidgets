    #include <QApplication>
    #include <QObject> 

    #include "test.h" 
      
    
    int main(int argc, char *argv[])
    {
        QApplication app(argc, argv);
        TestWidget widget;
        widget.show();
       // app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
        return app.exec();
    }
