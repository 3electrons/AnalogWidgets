#include "scalegrid.h"

using namespace chart;

ScaleGrid::ScaleGrid ( )
{
    m_xMesh=7; m_xSubMesh=1;
    m_yMesh=7;  m_ySubMesh=1;
    pos=0; size=1000;
    //m_min=min; m_max=max;
    m_showGrid=true;
    m_font.setPointSize(10);
}
