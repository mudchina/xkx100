// Room: /d/lingxiao/.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "石崖客栈");
	set("long", @LONG
这里是雪山山路上的一间客栈，虽然店面简单朴实，平日也不可能
有什么游客来这雪域游山玩水，但在这大雪山上，却也是独一无二的客
栈。到了这地方，要是不想冻死在这万里冰川上，只怕还是得照顾一下
这里的生意。所以这家店倒也是生意兴隆。
LONG );
	set("exits", ([
		"west" : __DIR__"shiya",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -30990);
	set("coor/y", -8980);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

