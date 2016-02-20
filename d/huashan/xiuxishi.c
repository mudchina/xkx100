// Room: xiuxishi.c
// Last Modified by winder on Aug. 1 2002

inherit RESTROOM_IN;

void create()
{
	set("short", "华山小筑");
	set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG );

	set("sleep_room", 1);
	set("no_clean_up", 0);
	set("no_fight", 1);

	set("coor/x", -830);
	set("coor/y", 210);
	set("coor/z", 120);
  set("door_name","竹门");
	set("door_dir","west");
	set("force_name","陆大有");
  set("outroom",__DIR__"xiaolu2");
	setup();
}

void init()
{
  object me = this_player();
  ::init();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/yunu", 1);
}

