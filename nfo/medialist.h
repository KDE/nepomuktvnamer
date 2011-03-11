#ifndef _NFO_MEDIALIST_H_
#define _NFO_MEDIALIST_H_

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
 * A file containing a list of media files.e.g. a playlist 
 */
class MediaList : public NIE::InformationElement
{
public:
    MediaList(Nepomuk::SimpleResource* res)
      : NIE::InformationElement(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasMediaFileListEntry. 
     * This property is intended to point to an RDF list of MediaFiles. 
     */
    QList<QUrl> hasMediaFileListEntrys() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasMediaFileListEntry", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasMediaFileListEntry. 
     * This property is intended to point to an RDF list of MediaFiles. 
     */
    void setHasMediaFileListEntrys(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaList", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasMediaFileListEntry", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasMediaFileListEntry. 
     * This property is intended to point to an RDF list of MediaFiles. 
     */
    void addHasMediaFileListEntry(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaList", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#hasMediaFileListEntry", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
