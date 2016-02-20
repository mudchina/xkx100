// Room: /d/baituo/dongnei.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "洞内");
	set("long", @LONG
这里是山贼的老窝的所在。阴森湿冷的土壁上，插着一些松明子。光
亮下，居中的虎皮大椅格外显目。旁边有一侧洞，里面隐隐传来女子的哭
声。
LONG	);
	set("exits", ([
		"west" : __DIR__"cedong",
		"south" : __DIR__"dongkou",
	]));
	set("objects",([
		__DIR__"npc/shanzei3" : 1,
	]));
	set("coor/x", -49960);
	set("coor/y", 20040);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
	if (  (dir == "west") &&
		objectp(present("shanzei tou", environment(me))) )
	return notify_fail("山贼头操起拳头：你想占我老婆的便宜？快滚！\n");
	return ::valid_leave(me, dir);
}
