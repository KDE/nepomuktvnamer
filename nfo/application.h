#ifndef _NFO_APPLICATION_H_
#define _NFO_APPLICATION_H_

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
 * An application 
 */
class Application : public NFO::Software
{
public:
    Application(Nepomuk::SimpleResource* res)
      : NFO::Software(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
