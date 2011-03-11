#ifndef _NFO_REMOTEDATAOBJECT_H_
#define _NFO_REMOTEDATAOBJECT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/filedataobject.h"
namespace Nepomuk {
namespace NFO {
/**
 * A file data object stored at a remote location. Don't confuse 
 * this class with a RemotePortAddress. This one applies to a particular 
 * resource, RemotePortAddress applies to an address, that can 
 * have various interpretations. 
 */
class RemoteDataObject : public NFO::FileDataObject
{
public:
    RemoteDataObject(Nepomuk::SimpleResource* res)
      : NFO::FileDataObject(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
