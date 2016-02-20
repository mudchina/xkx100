// Room: /d/baituo/fang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","练功房");
	set("long", @LONG
这里是白驼山弟子的练功房。里面有几个单间，是练功室。弟子们
在里边砌磋武艺，绝对不允许外人打搅。
LONG	);
	set("exits",([
		"west" : __DIR__"liangong",
		"1" : __DIR__"room1",
		"2" : __DIR__"room2",
		"3" : __DIR__"room3",
	]));
	set("objects",([
		__DIR__"npc/trainer" : 1,
	]));
	set("coor/x", -50000);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}
int valid_leave(object who ,string dir)
{
	if((string)who->query("family/family_name")!="白驼山派" &&
		(dir!="west"))
		return notify_fail("那里禁止外人进入！\n");
	return 1 ;
}
