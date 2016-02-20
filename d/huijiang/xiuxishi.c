// Room: /d/huijiang/xiuxishi.c
// Last Modified by winder on Sep. 12 2001

inherit RESTROOM_IN;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的厢房，房里别无他物，只有中间放着一张收拾得舒舒
服服的大床，看着就让人想睡觉。
LONG );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -50070);
	set("coor/y", 9130);
	set("coor/z", 10);
  set("door_name","门");
	set("door_dir","north");
	set("force_name","心砚");
  set("outroom",__DIR__"zoulang2");
	setup();
}
