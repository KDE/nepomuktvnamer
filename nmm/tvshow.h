#ifndef _NMM_TVSHOW_H_
#define _NMM_TVSHOW_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/video.h"
namespace Nepomuk {
namespace NMM {
/**
 * A TV Show 
 */
class TVShow : public NFO::Video
{
public:
    TVShow(Nepomuk::SimpleResource* res)
      : NFO::Video(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber. 
     */
    qint64 episodeNumber() const {
        qint64 value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber. 
     */
    void setEpisodeNumber(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber. 
     */
    void addEpisodeNumber(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#episodeNumber", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season. 
     */
    qint64 season() const {
        qint64 value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode)).first().value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season. 
     */
    void setSeason(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season. 
     */
    void addSeason(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#season", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series. 
     * series 
     */
    QUrl series() const {
        QUrl value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series. 
     * series 
     */
    void setSeries(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series. 
     * series 
     */
    void addSeries(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#series", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
