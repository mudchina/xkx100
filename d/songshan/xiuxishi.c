// Room: /d/songshan/xiuxishi.c
// Last Modified by winder on Aug. 5 2001

inherit RESTROOM_IN;
void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的厢房，是嵩山弟子休息起居的地方。因为门窗常年闭
着，房间难免昏暗。房里靠窗处摆设桌椅，里边靠墙放着一张收拾得舒
舒服服的大床，看着就让人想睡觉。
LONG );

        set("sleep_room", 1);
        set("no_clean_up", 0);
        set("no_fight", 1);
	set("coor/x", 10);
	set("coor/y", 910);
	set("coor/z", 90);
  set("door_name","门");
	set("door_dir","west");
	set("force_name","汤英鹄");
  set("outroom",__DIR__"eastpath2");
	setup();
}
