#ifndef _NFO_ARCHIVE_H_
#define _NFO_ARCHIVE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/datacontainer.h"
namespace Nepomuk {
namespace NFO {
/**
 * A compressed file. May contain other files or folder inside. 
 */
class Archive : public NFO::DataContainer
{
public:
    Archive(Nepomuk::SimpleResource* res)
      : NFO::DataContainer(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize. 
     * Uncompressed size of the content of a compressed file. 
     */
    QList<qint64> uncompressedSizes() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize. 
     * Uncompressed size of the content of a compressed file. 
     */
    void setUncompressedSizes(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize. 
     * Uncompressed size of the content of a compressed file. 
     */
    void addUncompressedSize(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#uncompressedSize", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
