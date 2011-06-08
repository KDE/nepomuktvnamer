#ifndef _NFO_CURSOR_H_
#define _NFO_CURSOR_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/rasterimage.h"
namespace Nepomuk {
namespace NFO {
/**
 * A Cursor. 
 */
class Cursor : public NFO::RasterImage
{
public:
    Cursor(Nepomuk::SimpleResource* res)
      : NFO::RasterImage(res), m_res(res)
    {}

    virtual ~Cursor() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Cursor", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
