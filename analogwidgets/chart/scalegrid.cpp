#include "scalegrid.h"

using namespace chart;

ScaleGrid::ScaleGrid ( )
{
    m_xMesh=14; m_xSubMesh=1;
    m_yMesh=14;  m_ySubMesh=1;
    pos=0; size=1000;
    m_min=pos; m_max=pos + size;
    m_showGrid=true;
    m_font.setPointSize(10);
}
