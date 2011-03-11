#ifndef _NFO_ICON_H_
#define _NFO_ICON_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/image.h"
namespace Nepomuk {
namespace NFO {
/**
 * An Icon (regardless of whether it's a raster or a vector icon. 
 * A resource representing an icon could have two types (Icon and 
 * Raster, or Icon and Vector) if required. 
 */
class Icon : public NFO::Image
{
public:
    Icon(Nepomuk::SimpleResource* res)
      : NFO::Image(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
