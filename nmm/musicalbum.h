#ifndef _NMM_MUSICALBUM_H_
#define _NMM_MUSICALBUM_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/medialist.h"
namespace Nepomuk {
namespace NMM {
/**
 * The music album as provided by the publisher. Not to be confused 
 * with media lists or collections. 
 */
class MusicAlbum : public NFO::MediaList
{
public:
    MusicAlbum(Nepomuk::SimpleResource* res)
      : NFO::MediaList(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID. 
     * MusicBrainz album ID 
     */
    QStringList musicBrainzAlbumIDs() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID. 
     * MusicBrainz album ID 
     */
    void setMusicBrainzAlbumIDs(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID. 
     * MusicBrainz album ID 
     */
    void addMusicBrainzAlbumID(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzAlbumID", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode. 
     * ISRC ID. Format: 'CC-XXX-YY-NNNNN' 
     */
    QStringList internationalStandardRecordingCodes() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode. 
     * ISRC ID. Format: 'CC-XXX-YY-NNNNN' 
     */
    void setInternationalStandardRecordingCodes(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode. 
     * ISRC ID. Format: 'CC-XXX-YY-NNNNN' 
     */
    void addInternationalStandardRecordingCode(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#internationalStandardRecordingCode", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier. 
     * Music CD identifier to for databases like FreeDB.org. This 
     * property is intended for music that comes from a CD, so that the 
     * CD can be identified in external databases. 
     */
    QStringList musicCDIdentifiers() const {
        QStringList value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier", QUrl::StrictMode)))
            value << v.value<QString>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier. 
     * Music CD identifier to for databases like FreeDB.org. This 
     * property is intended for music that comes from a CD, so that the 
     * CD can be identified in external databases. 
     */
    void setMusicCDIdentifiers(const QStringList& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        QVariantList values;
        foreach(const QString& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier. 
     * Music CD identifier to for databases like FreeDB.org. This 
     * property is intended for music that comes from a CD, so that the 
     * CD can be identified in external databases. 
     */
    void addMusicCDIdentifier(const QString& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicCDIdentifier", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
