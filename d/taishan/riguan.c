// Room: /d/taishan/riguan.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "日观峰");
	set("long", @LONG
日观峰位于玉皇顶东南，古称介丘岩，因可观日出而名。相传在峰
巅西可望秦，南可望越，故又称秦观峰、越观峰。这里怪石攒簇，最高
的地方一石卓立，名为君子峰。往东走便是通往泰山东天门的山路。
LONG );
	set("exits", ([
		"south"     : __DIR__"aishen",
		"eastup"    : __DIR__"tanhai",
		"eastdown"  : __DIR__"riguanroad1",
		"northwest" : __DIR__"yuhuang",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/tianmen" : 1,
	]));
	set("valid_startroom", 1);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 770);
	set("coor/z", 210);
	setup();
	"/clone/board/taishan_b"->foo();
}

int valid_leave(object me, string dir)
{
	if (dir != "northwest" &&
		me->query("family/family_name") !="泰山派" &&
		present("tianmen daoren", environment(me)) &&
		living(present("tianmen daoren", environment(me))))
	{
		return notify_fail("天门道人喝道：后面是本派重地，这位" + RANK_D->query_respect(me) + "请止步。\n");
	}
	else return ::valid_leave(me, dir);

}
