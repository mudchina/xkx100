// Room: /wuliang/shanlu6.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山坳");
	set("long", @LONG
转过山坳，只见一大堆乱石之中团团坐着二十余人。你小心翼翼地
走近前去，见人丛中一个瘦小的老者坐在一块高岩之上，高出旁人，颏
下一把山羊胡子，神态甚是倨傲，料来便是神农帮主司空玄了。
LONG );
	set("outdoors", "wuliang");
	set("exits", ([
		"eastup"  : __DIR__"shanlu5",
		"northup" : __DIR__"shanlu7",
	]));
	set("objects", ([
		__DIR__"npc/shennongdizi" : 3,
		__DIR__"npc/hong" : 1,
		__DIR__"npc/sheng" : 1,
		__DIR__"npc/sikongxuan" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79980);
	set("coor/z", 50);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (objectp(present("sikong xuan", environment(me))))
		return notify_fail("司空玄拦住你说：既来此处，必与无量派有关，奉童姥之命，杀无\n赦，你还想走？\n");
	return ::valid_leave(me, dir);
}
