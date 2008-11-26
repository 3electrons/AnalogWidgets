/***************************************************************************
 *   Copyright (C) 2006-2008 by Tomasz Ziobrowski                          *
 *   http://www.3electrons.com                                             *
 *   e-mail: t.ziobrowski@3electrons.com                                   *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

    #include "dial.h" 
    #include "dial_plugin.h"
    #include "defines.h"
    /*------------------------------------------------------------------------------------------------
     *			     			DIAL PLUGIN 
     *------------------------------------------------------------------------------------------------*/

    DialPlugin::DialPlugin(QObject *parent)
        : QObject(parent)
    {
        initialized = false;
    }

    void DialPlugin::initialize(QDesignerFormEditorInterface * /*core*/)
    {
        if (initialized)
            return;

        initialized = true;
    }

    bool DialPlugin::isInitialized() const
    {
        return initialized;
    }

    QWidget *DialPlugin::createWidget(QWidget *parent)
    {
        return new Dial(parent);
    }

    QString DialPlugin::name() const
    {
        return QLatin1String("Dial");
    }

    QString DialPlugin::group() const
    {
        return QLatin1String("Analog Widgets");
    }

    QIcon DialPlugin::icon() const
    {
        return QIcon();
    }

    QString DialPlugin::toolTip() const
    {
        return QString();
    }

    QString DialPlugin::whatsThis() const
    {
        return QString();
    }

    bool DialPlugin::isContainer() const
    {
        return false;
    }

    QString DialPlugin::domXml() const
    {
       return QLatin1String("<widget class=\"Dial\" name=\"dial\">\n"
                        " <property name=\"geometry\">\n"
                        "  <rect>\n"
                        "   <x>0</x>\n"
                        "   <y>0</y>\n"
                        "   <width>100</width>\n"
                        "   <height>40</height>\n"
                        "  </rect>\n"
                        " </property>\n"
                        " <property name=\"toolTip\" >\n"
                        "  <string></string>\n"
                        " </property>\n"
                        " <property name=\"whatsThis\" >\n"
                        "  <string></string>\n"
                        " </property>\n"
                        "</widget>\n");
    }

    QString DialPlugin::includeFile() const
    {
        return QLatin1String("analogwidgets/dial.h");
    }

    QString DialPlugin::codeTemplate() const
    {
        return QString();
    }

#ifdef SINGLEPLUGINS     
    Q_EXPORT_PLUGIN(DialPlugin)
#endif 
