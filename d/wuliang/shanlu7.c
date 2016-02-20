// Room: /wuliang/shanlu7.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
上山的山路从这里开始有了青石铺垫。不过脚底仍是生涩难耐。
向下的山路转入一个山坳。山坳里冒着青烟，竟有十几束之多，在这
山清水秀的地方，隐隐觉得有点不对劲。
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"northup"   : __DIR__"shanlu8",
		"southdown" : __DIR__"shanlu6",
	]));
	set("objects", ([
		__DIR__"npc/rong" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79970);
	set("coor/z", 60);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (objectp(present("rong ziju", environment(me))) &&
		dir == "northup")
           return notify_fail("容子矩拦住你说：神农帮肆虐，你是何人？难保不是奸细，不得上山！\n");
        return ::valid_leave(me, dir);
}