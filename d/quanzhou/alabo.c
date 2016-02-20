// Room: /d/quanzhou/alabo.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "阿拉伯宅区");
	set("long", @LONG
由于泉州与世界的商贸往来，许多阿拉伯人来到此地居住和劳作，
久而久之形成了这聚居地。远远望去白色的圆形尖顶突兀而起，显得格
外抢眼。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"northwest" : __DIR__"southroad2",
		"south"     : __DIR__"qingjingsi",
	]));
	set("objects", ([
		__DIR__"npc/alabo" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
