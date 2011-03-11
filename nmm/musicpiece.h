#ifndef _NMM_MUSICPIECE_H_
#define _NMM_MUSICPIECE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/media.h"
namespace Nepomuk {
namespace NMM {
/**
 * Used to assign music-specific properties such a BPM to video 
 * and audio 
 */
class MusicPiece : public NFO::Media
{
public:
    MusicPiece(Nepomuk::SimpleResource* res)
      : NFO::Media(res), m_res(res)
    {}

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID. 
     * MusicBrainz track ID 
     */
    QList<qint64> musicBrainzTrackIDs() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID. 
     * MusicBrainz track ID 
     */
    void setMusicBrainzTrackIDs(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID. 
     * MusicBrainz track ID 
     */
    void addMusicBrainzTrackID(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicBrainzTrackID", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber. 
     * Track number of the music in its album 
     */
    QList<qint64> trackNumbers() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber. 
     * Track number of the music in its album 
     */
    void setTrackNumbers(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber. 
     * Track number of the music in its album 
     */
    void addTrackNumber(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#trackNumber", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist. 
     * Lyricist 
     */
    QList<QUrl> lyricists() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist. 
     * Lyricist 
     */
    void setLyricists(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist. 
     * Lyricist 
     */
    void addLyricist(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#lyricist", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum. 
     * Album the music belongs to 
     */
    QUrl musicAlbum() const {
        QUrl value;
        if(m_res->contains(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode)))
            value = m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode)).first().value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum. 
     * Album the music belongs to 
     */
    void setMusicAlbum(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        values << value;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum. 
     * Album the music belongs to 
     */
    void addMusicAlbum(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#musicAlbum", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer. 
     * Performer 
     */
    QList<QUrl> performers() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer. 
     * Performer 
     */
    void setPerformers(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer. 
     * Performer 
     */
    void addPerformer(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#performer", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute. 
     * beats per minute 
     */
    QList<qint64> beatsPerMinutes() const {
        QList<qint64> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute", QUrl::StrictMode)))
            value << v.value<qint64>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute. 
     * beats per minute 
     */
    void setBeatsPerMinutes(const QList<qint64>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        foreach(const qint64& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute. 
     * beats per minute 
     */
    void addBeatsPerMinute(const qint64& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#beatsPerMinute", QUrl::StrictMode), value);
    }

    /**
     * Get property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer. 
     * Composer 
     */
    QList<QUrl> composers() const {
        QList<QUrl> value;
        foreach(const QVariant& v, m_res->property(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer", QUrl::StrictMode)))
            value << v.value<QUrl>();
        return value;
    }

    /**
     * Set property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer. 
     * Composer 
     */
    void setComposers(const QList<QUrl>& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        QVariantList values;
        foreach(const QUrl& v, value)
            values << v;
        m_res->setProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer", QUrl::StrictMode), values);
    }

    /**
     * Add value to property http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer. 
     * Composer 
     */
    void addComposer(const QUrl& value) {
        m_res->addProperty(Soprano::Vocabulary::RDF::type(), QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece", QUrl::StrictMode));
        m_res->addProperty(QUrl::fromEncoded("http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#composer", QUrl::StrictMode), value);
    }

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
