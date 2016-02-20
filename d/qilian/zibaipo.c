// Room: /d/qilian/zibaipo.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "紫柏坡");
	set("long", @LONG
紫柏坡在祈连山脉中是座小山峰，但风景绝佳。漫山小溪潺潺，有
山鱼悠游其中。周山盛开一种紫色山花，四季不谢，相传是由紫德真人
所种，但以讹传讹，得名紫柏，其实山上一颗柏树也没有。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"east"      : __DIR__"tieshishan",
		"westup"    : __DIR__"qitianfeng",
		"northeast" : __DIR__"ailaoshan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -14000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}