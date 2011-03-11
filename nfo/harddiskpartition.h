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

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
