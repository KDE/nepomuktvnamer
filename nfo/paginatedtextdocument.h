#ifndef _NFO_PAGINATEDTEXTDOCUMENT_H_
#define _NFO_PAGINATEDTEXTDOCUMENT_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/textdocument.h"
namespace Nepomuk {
namespace NFO {
/**
 * A file containing a text document, that is unambiguously divided 
 * into pages. Examples might include PDF, DOC, PS, DVI etc. 
 */
class PaginatedTextDocument : public NFO::TextDocument
{
public:
    PaginatedTextDocument(Nepomuk::SimpleResource* res)
      : NFO::TextDocument(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount. 
     * Number of pages. 
     */
    QList<qint64> pageCounts() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount. 
     * Number of pages. 
     */
    void setPageCounts(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount. 
     * Number of pages. 
     */
    void addPageCount(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#pageCount", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
