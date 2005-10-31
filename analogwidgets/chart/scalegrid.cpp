#include "scalegrid.h"

using namespace chart;

ScaleGrid::ScaleGrid ( )
{
    m_xMesh=14; m_xSubMesh=1;
    m_yMesh=14;  m_ySubMesh=1;
    pos=0; size=1000;
    m_min=pos; m_max=pos + size;
    showGrid=true;
    showScale=true;
    m_font.setPointSize(10);
    m_fontColor.setRgb(255,255,255);
}
