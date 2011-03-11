#ifndef _NFO_FILESYSTEMIMAGE_H_
#define _NFO_FILESYSTEMIMAGE_H_

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/QUrl>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <Soprano/Vocabulary/RDF>

#include <nepomuk/simpleresource.h>

#include "nfo/filesystem.h"
namespace Nepomuk {
namespace NFO {
/**
 * An image of a filesystem. Instances of this class may include 
 * CD images, DVD images or hard disk partition images created 
 * by various pieces of software (e.g. Norton Ghost). Deprecated 
 * in favor of nfo:Filesystem. 
 */
class FilesystemImage : public NFO::Filesystem
{
public:
    FilesystemImage(Nepomuk::SimpleResource* res)
      : NFO::Filesystem(res), m_res(res)
    {}

private:
    Nepomuk::SimpleResource* m_res;
};
}
}

#endif
