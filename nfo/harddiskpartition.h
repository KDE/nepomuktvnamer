#ifndef _NFO_HARDDISKPARTITION_H_
#define _NFO_HARDDISKPARTITION_H_

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
 * A partition on a hard disk 
 */
class HardDiskPartition : public NIE::DataObject
{
public:
    HardDiskPartition(Nepomuk::SimpleResource* res)
      : NIE::DataObject(res), m_res(res)
    {}

    virtual ~HardDiskPartition() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HardDiskPartition", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
