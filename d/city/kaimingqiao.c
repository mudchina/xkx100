// Room: /yangzhou/kaimingqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","开明桥");
    set("long",@LONG
拾级而上，步上开明桥头。桥两侧围以石栏，每块石栏板雕刻着四
时花木，雕刻精致，神形俱美。正处河心的石栏镶着一匾额「开明桥」。
开明桥据说是扬州城里最古老的桥，能在五代战火之中幸存下来，扬州
的老人对开明桥多有感慨。下了东边的石阶，就是彩衣街口；西边是琼
花街，通向府学「崇雅书院」。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"qionghuajie",
		"east"  : __DIR__"caiyijiekou",
	]));
	set("objects", ([
		"/d/village/npc/kid": random(4),
		"/d/village/npc/girl": random(3),
		"/d/village/npc/boy": random(3),
	]));
	set("coor/x", 30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}