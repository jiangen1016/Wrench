/****************************************************************************************
 * Copyright (c) 2010 Patrick von Reth <patrick.vonreth@gmail.com>                      *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 2 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#ifndef FreedesktopNotification_H
#define FreedesktopNotification_H

#include "core/notification.h"

#include <QtDBus>
#include <QMetaType>


class FreedesktopImageHint;

class FreedesktopNotification{
public:
    static void registerTypes();

public:
    FreedesktopNotification();
    FreedesktopNotification(QSharedPointer<Notification> noti);
    
    QSharedPointer<Notification> notification;
};

Q_DECLARE_METATYPE(FreedesktopNotification);

QDBusArgument &operator<<(QDBusArgument &a,const FreedesktopNotification &i);
const QDBusArgument & operator >>(const QDBusArgument &a,  FreedesktopNotification &i) ;

class FreedesktopImageHint
{
public:
    static QHash<QString,void*> hasedImages;
public:    
    FreedesktopImageHint();
    FreedesktopImageHint(const QImage &img);
    QString hash()const;
    QString computeHash();

    QImage toQImage()const;

    int width;
    int height;
    int rowstride;
    bool hasAlpha;
    int bitsPerSample;
    int channels;
    QByteArray imageData;
    QString _hash;


};

Q_DECLARE_METATYPE(FreedesktopImageHint);

QDBusArgument &operator<<(QDBusArgument &a,  const FreedesktopImageHint &i);
const QDBusArgument & operator >>(const QDBusArgument &a,  FreedesktopImageHint  &i) ;

#endif // FreedesktopNotification_H
