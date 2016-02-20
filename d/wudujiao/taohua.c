// Room: /d/wudujiao/taohua.c

inherit ROOM;

void create()
{
        set("short", "桃花峪");
        set("long", @LONG
你走在两山相夹的峡谷中，山上山下全是无边的野桃树，一阵
山风吹来，落英缤纷。数百年落下的桃花，桃枝都堆积在地上，人
走在上面软软的。日近正午了，远处山林间似乎飘荡着一股轻雾，
越来越浓。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"wdsl1",
                "northwest" : __DIR__"xiao3",
        ]));

	set("coor/x", -44980);
	set("coor/y", -81050);
	set("coor/z", 0);
	setup();
}
int valid_leave (object who, string dir)
{
        if(dir=="northwest"){
//      who->move("d/wudujiao/xiao3");
//      return 1;
            return ::valid_leave(who, dir);
        }
        else{
            if ((string)who->query("family/family_name")!="五毒教")
            {
                if(!(present("xingjun san", who))){
                    message_vision ("一阵浓香袭来，$N顿时觉得头重脚轻。\n",who);
                    who->receive_damage("qi", 50);
                    remove_call_out ("fall_down");
                    call_out ("fall_down",1,who,environment(who));
                    who->start_busy(1,1);
                    return notify_fail("你禁不住踉跄了几下，两腿突然一软。\n");
//    who->unconcious();
                }
            }
            return 1;
        }
}

void fall_down (object who, object where)
{
        who->move(where);
        this_player()->unconcious();
}
void fall_down1 (object who, object where)
{
        this_player()->unconcious();
}