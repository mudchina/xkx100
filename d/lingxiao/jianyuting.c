// Room: /d/lingxiao/jianyuting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "监狱小厅");
	set("long", @LONG
这里就是凌霄城的监狱入口。凌霄城的监狱专门用来关押犯了门规
的弟子，一些城中的作奸犯科，鸡鸣狗盗之徒也顺便收押在此。凌霄向
来一派所成，所以门规森严，倒也少有犯事者，但这里是凌霄重地，防
守自也严密。
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("exits", ([
		"west" : __DIR__"iceroad3",
		"down" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/yan" : 1,
		__DIR__"npc/dizi" : 3,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup(); 
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["master_id"] != "bai zizai") &&
		dir == "down" &&
		objectp(present("yan wanpeng", environment(me))))
		return notify_fail("燕万鹏大喝一声：此处乃本派禁地，这位" + RANK_D->query_respect(me) + "请止步！\n");
	return ::valid_leave(me, dir);
}

