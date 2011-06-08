#ifndef _NFO_OPERATINGSYSTEM_H_
#define _NFO_OPERATINGSYSTEM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/software.h"
namespace Nepomuk {
namespace NFO {
/**
 * An OperatingSystem 
 */
class OperatingSystem : public NFO::Software
{
public:
    OperatingSystem(Nepomuk::SimpleResource* res)
      : NFO::Software(res), m_res(res)
    {}

    virtual ~OperatingSystem() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
