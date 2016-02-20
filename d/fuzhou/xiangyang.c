// Room: /d/fuzhou/xiangyang.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "向阳巷");
	set("long", @LONG
这里是福州城西向阳巷。北面有一所破败的宅子。西面有一家杂货
铺，专卖女人家用的东西，男人不可以进去。
LONG );

	set("exits", ([
                "east"  : __DIR__"shiqiao",
                "north" : __DIR__"laozhai",
                "west"  : __DIR__"zahuopu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1820);
	set("coor/y", -6320);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && ((string)me->query("gender") =="男性") && !wizardp(me))
                return notify_fail("你个大老爷们儿去那干嘛！！\n");
        return 1;
}
