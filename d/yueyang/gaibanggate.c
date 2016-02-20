// Room: /d/yueyang/gaibanggate.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
你来到一栋大屋前，大门口进进出出的都是一身乞丐打扮，于是你
突然醒悟，这里就是江湖中的丐儿帮吧。大门破破旧旧的，久经风雨的
横梁发黑开裂，长上了绿苔，只有两个铜门环磨蹭得金光闪闪。
LONG );
	set("outdoors", "yueyang");
	set("exits", ([
		"north" : __DIR__"gaibangyuan",
		"south" : __DIR__"xijie",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/xi" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 5,
	]));
	set("coor/x", -1420);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "丐帮") && dir == "north" &&
		objectp(present("xi zhanglao", environment(me))))
		return notify_fail("奚长老拦住你说：此处乃本帮禁地，请止步。\n");

	return ::valid_leave(me, dir);
}
