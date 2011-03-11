#ifndef _NMM_TVSERIES_H_
#define _NMM_TVSERIES_H_

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
namespace NMM {
/**
 * A TV Series has multiple seasons and episodes 
 */
class TVSeries : public NIE::InformationElement
{
public:
    TVSeries(Nepomuk::SimpleResource* res)
      : NIE::InformationElement(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hasEpisode. 
     * A TVSeries has many episodes 
     */
    QList<QUrl> hasEpisodes() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hasEpisode", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hasEpisode. 
     * A TVSeries has many episodes 
     */
    void setHasEpisodes(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVSeries", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hasEpisode", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hasEpisode. 
     * A TVSeries has many episodes 
     */
    void addHasEpisode(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVSeries", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#hasEpisode", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
