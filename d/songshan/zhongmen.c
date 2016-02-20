// Room: /d/songshan/zhongmen.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "中门");
	set("long", @LONG
这里是峻极禅院通往后庭的中门，门厚三寸，红松铜箍，门上两幅
门神经多年风雨，多有剥落，现下颜色尚新，想来是嵩山派新近油漆了
的。外派人士到此就该回头了。
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"south" : __DIR__"chanyuan",
		"north" : __DIR__"huimengtang",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/yao": 1,
	]));
	set("coor/x", -20);
	set("coor/y", 880);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if ( me->query("combat_exp") < 1000 ) return 1;
	if ( (!myfam || (myfam["family_name"] != "嵩山派")) &&
		(dir == "north") &&
		objectp(present("yao hou", environment(me))))
		return notify_fail("乐厚一抬手拦住了你：非嵩山弟子，到此止步吧。\n");
	else return 1;
}

