#ifndef _NFO_SOFTWARESERVICE_H_
#define _NFO_SOFTWARESERVICE_H_

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
 * A service published by a piece of software, either by an operating 
 * system or an application. Examples of such services may include 
 * calendar, addressbook and mailbox managed by a PIM application. 
 * This category is introduced to distinguish between data available 
 * directly from the applications (Via some Interprocess Communication 
 * Mechanisms) and data available from files on a disk. In either 
 * case both DataObjects would receive a similar interpretation 
 * (e.g. a Mailbox) and wouldn't differ on the content level. 
 */
class SoftwareService : public NIE::DataObject
{
public:
    SoftwareService(Nepomuk::SimpleResource* res)
      : NIE::DataObject(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
