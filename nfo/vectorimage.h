#ifndef _NFO_VECTORIMAGE_H_
#define _NFO_VECTORIMAGE_H_

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
 * 
 */
class VectorImage : public NFO::Image
{
public:
    VectorImage(Nepomuk::SimpleResource* res)
      : NFO::Image(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
