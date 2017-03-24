#ifndef QTPPSPS_H
#define QTPPSPS_H
#include "nircek-qteasyhttpclient/nircek-qteasyhttpclient.h"
namespace GitHub {
    namespace Nircek {

        typedef enum PPSReplyType{
            good,paramerror,dberror,httperror,error
        } PPSReplyType;
        QString readPPSReplyType(PPSReplyType);

        typedef struct PPSReply{
            PPSReplyType replyType;
            QString reply;

            PPSReply(PPSReplyType,QString);
            PPSReply(char, QString);
        private:
            void construct(PPSReplyType,QString);
        } PPSReply;

        class qtppsps {
            QString host,pass;
            QObject *parent;
            PPSReply toReply(QString);
        public:
            qtppsps(QString host, QString pass, QObject *parent=nullptr);
            ~qtppsps();
            PPSReply pop();
            PPSReply reply(QString reply);
            PPSReply varread(QString user, QString name, QString value);
            PPSReply varwrite(QString user, QString name);
            PPSReply log(QString log);
        };
    }
}
#endif // QTPPSPS_H
