// kickout.c
inherit F_CLEAN_UP;


#include <ansi.h>
#include <command.h>


int main(object me, string arg)
{
        object ob,login_ob;
        string wiz_status;
        string tmpstr;

        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("argument error!\n");


        wiz_status=SECURITY_D->get_status(me) ;

//      if (wiz_status != "(admin)" && !me->query("marks/踢人") )
//              return notify_fail("you r not admin!\n");

        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 有这个人吗?\n");

//              if (    !living(ob)
//              ||      !ob->is_character()
//              ||      ob==me )
        if (ob==me)          
	      return notify_fail("ob error!\n");
        log_file("kickout_player", sprintf("[%s] %s kickout %s\n",
                        ctime(time()), geteuid(me), geteuid(ob)));
//      message_vision( HIW "\n$N把$n踢了出去\n\n" NOR, me,ob);
        tell_object( me, "你把 " + ob->query("name") + " 踢了出去!\n");
//      seteuid(getuid(ob));
//      command("quit");
//me->save();
        seteuid(ROOT_UID);
        ob->save();
        if (login_ob=ob->query_temp("link_ob"))
        {
        	login_ob->save();
          destruct(login_ob);
        }
        destruct(ob);
        
        seteuid(getuid());

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : kickout <某人>

HELP
    );
    return 1;
}
