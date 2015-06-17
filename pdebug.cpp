/***************************************************************************
 *  Copyright (C) 2014  Evgeniy Alekseev                                      *
 *                                                                         *
 *  This library is free software; you can redistribute it and/or          *
 *  modify it under the terms of the GNU Lesser General Public             *
 *  License as published by the Free Software Foundation; either           *
 *  version 3.0 of the License, or (at your option) any later version.     *
 *                                                                         *
 *  This library is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU       *
 *  Lesser General Public License for more details.                        *
 *                                                                         *
 *  You should have received a copy of the GNU Lesser General Public       *
 *  License along with this library.                                       *
 ***************************************************************************/


#include <pdebug.h>

#if QT_VERSION >= 0x050000


void debugString(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context)
    Q_UNUSED(type)

    QByteArray localMsg = msg.toLocal8Bit();
    QByteArray timeNow = QDateTime::currentDateTime().toString(QString("yyyy-MM-ddTHH:mm:ss.zzzZ")).toLocal8Bit();
    fprintf(stderr, "[%s]%s\n", timeNow.constData(), localMsg.constData());
}


#endif
