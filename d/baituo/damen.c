// Room: /d/baituo/damen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
这就是闻名天下的『白驼山庄』的大门。大门梁上雕龙刻凤，美奂
美仑，不知凝聚着多少能工巧匠的心血。更显出庄主的富有与显贵。门
前左右各蹲着一只威武庄严的石狮子。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"kongdi",
		"southdown" : __DIR__"shijie",
	]));
	set("objects",([
		__DIR__"npc/menwei" : 2,
		CLASS_D("baituo")+"/first" :1,
	]));
	set("coor/x", -50010);
	set("coor/y", 20010);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "north") && ((int)me->query("shen") > 300) &&
		objectp(present("men wei", environment(me))) &&
		living(present("men wei", environment(me))))
		return notify_fail("门卫把手一拦：你这种正派人物，老子一看就恶心，快滚！\n");
	return ::valid_leave(me, dir);
}
