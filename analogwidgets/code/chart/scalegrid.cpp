#include "chart/scalegrid.h"

using namespace chart;

ScaleGrid::ScaleGrid ( )
{
    m_xMesh=7; m_xSubMesh=1;
    m_yMesh=7;  m_ySubMesh=1;
    pos=0; size=1000;
    m_min=pos; m_max=pos + size;
    showGrid=true;
    showScale=true;
    //m_font.setPointSize(10);
    m_pen.setColor(QColor(255,255,255));
}
