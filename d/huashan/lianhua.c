// Room: /d/huashan/lianhua.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "莲花峰");
	set("long", @LONG
太华西峰又名莲花峰，也叫芙蓉峰，峰顶有一块巨石，状如莲花，
覆盖崖巅。该处由此得名。这里悬崖陡峭，壁立千仞，登临远眺，秦川
莽莽，渭、洛二水盘屈如带。峰顶有石名“摘星石”，取“手可摘星辰”
之意，以状西峰之高。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"eastdown" : __DIR__"chengxiang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");

	set("coor/x", -910);
	set("coor/y", 180);
	set("coor/z", 140);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/lianhua", 1);
	return;
}
