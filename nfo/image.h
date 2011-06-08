#ifndef _NFO_IMAGE_H_
#define _NFO_IMAGE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/visual.h"
namespace Nepomuk {
namespace NFO {
/**
 * A file containing an image. 
 */
class Image : public NFO::Visual
{
public:
    Image(Nepomuk::SimpleResource* res)
      : NFO::Visual(res), m_res(res)
    {}

    virtual ~Image() {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#verticalResolution. 
     * Vertical resolution of an Image (if printed). Expressed in 
     * DPI 
     */
    QList<qint64> verticalResolutions() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#verticalResolution", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#verticalResolution. 
     * Vertical resolution of an Image (if printed). Expressed in 
     * DPI 
     */
    void setVerticalResolutions(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#verticalResolution", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#verticalResolution. 
     * Vertical resolution of an Image (if printed). Expressed in 
     * DPI 
     */
    void addVerticalResolution(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#verticalResolution", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#horizontalResolution. 
     * Horizontal resolution of an image (if printed). Expressed 
     * in DPI. 
     */
    QList<qint64> horizontalResolutions() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#horizontalResolution", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#horizontalResolution. 
     * Horizontal resolution of an image (if printed). Expressed 
     * in DPI. 
     */
    void setHorizontalResolutions(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#horizontalResolution", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#horizontalResolution. 
     * Horizontal resolution of an image (if printed). Expressed 
     * in DPI. 
     */
    void addHorizontalResolution(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), resourceType());
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#horizontalResolution", QUrl::StrictMode), value);
    }

protected:
    virtual QUrl resourceType() const { return QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Image", QUrl::StrictMode); }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
