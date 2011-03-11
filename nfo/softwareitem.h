#ifndef _NFO_SOFTWAREITEM_H_
#define _NFO_SOFTWAREITEM_H_

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
 * A DataObject representing a piece of software. Examples of 
 * interpretations of a SoftwareItem include an Application 
 * and an OperatingSystem. 
 */
class SoftwareItem : public NIE::DataObject
{
public:
    SoftwareItem(Nepomuk::SimpleResource* res)
      : NIE::DataObject(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
