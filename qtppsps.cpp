#include "qtppsps.h"
using namespace GitHub::Nircek;
qtppsps::qtppsps(QString host, QString pass, QObject *parent):
    host(host),pass(pass),parent(parent){

}

qtppsps::~qtppsps(){

}
QString GitHub::Nircek::readPPSReplyType(PPSReplyType type){
    switch(type){
    case good:          return "good";
    case paramerror:    return "paramERR";
    case dberror:       return "dbERR";
    case httperror:     return "httpERR";
    case error:         return "unexceptedERR";
    }
    return "impossibleERR";
}

PPSReply::PPSReply(char c, QString s):
    reply(s){
    switch(c){
    case '0':   construct(good,s);          break;
    case '-':   construct(paramerror,s);    break;
    case '+':   construct(dberror,s);       break;
    case '/':   construct(httperror,s);     break;
    default:    construct(error,s);         break;
    }
}

PPSReply::PPSReply(PPSReplyType type, QString s){
    construct(type,s);
}

void PPSReply::construct(PPSReplyType type, QString s){
    replyType=type;
    reply=s;
}

PPSReply qtppsps::toReply(QString s){
    return PPSReply(s.mid(0,1).toLatin1()[0],s.mid(1));
}
