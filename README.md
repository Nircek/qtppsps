# QTPPSPS
###### Qt Pseudo PHP Server's Pseudo Server
### Example
```c++
#include "qtppsps.h"
using namespace GitHub::Nircek;
PPSReply rr(PPSReply rep){//readReply
    qDebug()<<readPPSReplyType(rep.replyType)<<' '<<rep.reply.toUtf8()<<'\n';
    return rep;
}

PPSReply saveReply(PPSReply rep,PPSReply &sv){
    sv=rep;
    return rep;
}

int main(int argc, char *argv[])
{
    QApplication qapp(argc,argv);
    qtppsps ps("http://localhost","super tajne hasło", &qapp);
    rr(ps.pop());
    rr(ps.reply("admin","nic"));
	
	//increment ps::var::admin::stats
    PPSReply sv(0,"");
    rr(saveReply(ps.varread("admin","stats"),sv));
    rr(ps.varwrite("admin","stats",QString::number(sv.reply.toInt()+1)));
    rr(ps.varread("admin","stats"));
	
    rr(ps.log("it works"));
    PPSReply event(0,"");

    while(rr(saveReply(ps.pop(),event)).replyType!=good);   //get good event
    QStringList parts=event.reply.split(qtppsps::splitter); //split to user and event
    std::reverse(parts[1].begin(),parts[1].end());          //reverse event
    ps.reply(parts[0],parts[1]);							//reply reversed event
    return 0;
}

```
