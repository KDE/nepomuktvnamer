#ifndef _NFO_DATACONTAINER_H_
#define _NFO_DATACONTAINER_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nie/informationelement.h"
namespace Nepomuk {
namespace NFO {
/**
 * A superclass for all entities, whose primary purpose is to serve 
 * as containers for other data object. They usually don't have 
 * any "meaning" by themselves. Examples include folders, archives 
 * and optical disc images. 
 */
class DataContainer : public NIE::InformationElement
{
public:
    DataContainer(Nepomuk::SimpleResource* res)
      : NIE::InformationElement(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
