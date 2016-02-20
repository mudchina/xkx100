// snpnpc.c
int main(object me, string arg)
{
        string cname,ccmds;
        object ob,snpee;
        string snoopee;
        seteuid(getuid());
        if( !arg ) return notify_fail("你要监听谁?\n");
        if( arg == "none" )
        {
                snoopee = me->query_temp("snoopee");
                if( !snoopee ) return notify_fail("你没有监听任何人.\n");
                snpee = find_player(snoopee);
                if( !snpee )
                snpee = find_living(snoopee);
                if( !snpee ) return notify_fail("找不到你所监听的人.\n");
                snpee->set_temp("is_snooped",0);
                me->set_temp("snoopee",0);
                return notify_fail("你现在停止监听"+snpee->name()+"所收到的信息\n");
        }
        if( me->query_temp("snoopee") )
                return notify_fail("你已经在监听中了.\n");
        ob = find_player(arg);
        if( !ob )
                ob = find_living(arg);
        if( !ob )
                return notify_fail("找不到这个人。\n");
        ob->set_temp("is_snooped",1);
        ob->set_temp("snooper",me->query("id"));
        me->set_temp("snoopee",ob->query("id"));
        write("你现在开始监听"+ob->name()+"所收到的信息.\n");
        return 1;
}

int help(object me)
{
   write( @HELP
指令格式: snp <someone> 开始监听.
        或 snp none 取消监听.
HELP
   );
   return 1;
}
