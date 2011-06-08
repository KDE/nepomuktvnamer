#ifndef _NFO_REMOTEPORTADDRESS_H_
#define _NFO_REMOTEPORTADDRESS_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nie/dataobject.h"
namespace Nepomuk {
namespace NFO {
/**
 * An address specifying a remote host and port. Such an address 
 * can be interpreted in many ways (examples of such interpretations 
 * include mailboxes, websites, remote calendars or filesystems), 
 * depending on an interpretation, various kinds of data may be 
 * extracted from such an address. 
 */
class RemotePortAddress : public NIE::DataObject
{
public:
    RemotePortAddress(Nepomuk::SimpleResource* res)
      : NIE::DataObject(res), m_res(res)
    {}

    virtual ~RemotePortAddress() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemotePortAddress", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
