#include <qmmp/qmmp.h>
#include "visualewavefactory.h"
#include "ewave.h"

const VisualProperties VisualEWaveFactory::properties() const
{
    VisualProperties properties;
    properties.name = tr("EWave Plugin");
    properties.shortName = "espewave";
    properties.hasSettings = true;
    properties.hasAbout = false;
    return properties;
}

Visual *VisualEWaveFactory::create(QWidget *parent)
{
    return new EWave(parent);
}
