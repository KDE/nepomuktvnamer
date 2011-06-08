#ifndef _NFO_WEBSITE_H_
#define _NFO_WEBSITE_H_

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
 * A website, usually a container for remote resources, that may 
 * be interpreted as HTMLDocuments, images or other types of content. 
 */
class Website : public NIE::InformationElement
{
public:
    Website(Nepomuk::SimpleResource* res)
      : NIE::InformationElement(res), m_res(res)
    {}

    virtual ~Website() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Website", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
