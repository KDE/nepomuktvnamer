#ifndef _NFO_PRESENTATION_H_
#define _NFO_PRESENTATION_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/document.h"
namespace Nepomuk {
namespace NFO {
/**
 * A Presentation made by some presentation software (Corel Presentations, 
 * OpenOffice Impress, MS Powerpoint etc.) 
 */
class Presentation : public NFO::Document
{
public:
    Presentation(Nepomuk::SimpleResource* res)
      : NFO::Document(res), m_res(res)
    {}

    virtual ~Presentation() {}

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
