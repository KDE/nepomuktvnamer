#ifndef _NFO_EXECUTABLE_H_
#define _NFO_EXECUTABLE_H_

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
 * An executable file. 
 */
class Executable : public NIE::InformationElement
{
public:
    Executable(Nepomuk::SimpleResource* res)
      : NIE::InformationElement(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
